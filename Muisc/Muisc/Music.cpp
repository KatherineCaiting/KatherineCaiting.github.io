#include"MusicPlayer.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HICON hIcon;
	TCHAR musicPos[10] = L"";
	switch (message)
	{
		HANDLE_MSG(hDlg, WM_INITDIALOG, Cls_OnInitDialog);
		HANDLE_MSG(hDlg, WM_COMMAND, Cls_OnCommand);
		HANDLE_MSG(hDlg, WM_CLOSE, Cls_OnClose);
	case WM_TIMER:
	{
					 int pos = GetMusicPos(currentMusic) / 1000;
					 wsprintf(musicPos, L"%02d:%02d", pos / 60, pos % 60);
					 SetWindowText(GetDlgItem(hDlg, IDC_TIME), musicPos);
					 //MessageBox(hDlg, L"", L"", 0);
					 SendMessage(GetDlgItem(hDlg, IDC_SLIDER1), TBM_SETPOS, TRUE, pos);
					 if (pos == musiclenI)//歌曲播放完成
					 {
						 KillTimer(hDlg, TIMEID);
						 lstrcpy(currentMusic, L"");
					 }
	}
		break;
	case WM_HSCROLL:
	{
					   StopMusic(currentMusic);
					   int pos = SendMessage(GetDlgItem(hDlg, IDC_SLIDER1), TBM_GETPOS, 0, 0);
					   PlayMusicFromPos(currentMusic, pos * 1000);
	}
		break;
	case WM_CONTEXTMENU:
	{
						   if (wParam == GetDlgItem(hDlg, IDC_LIST1))
						   {
							   int xPos = GET_X_LPARAM(lParam);
							   int yPos = GET_Y_LPARAM(lParam);
							   TrackPopupMenuEx(hMenu, TPM_LEFTALIGN | TPM_TOPALIGN, xPos, yPos, hDlg, NULL);
						   }
	}
		break;
	}
	return FALSE;
}

BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	SkinH_Attach();
	//程序图标
	HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
	SetClassLong(hwnd, GCL_HICON, (long)hIcon);  //SetWindowLong  (子类化窗口）

	//给list box插入条目
	/*SendMessage(GetDlgItem(hwnd, IDC_LIST1),LB_INSERTSTRING,-1,(LPARAM)L"C:\\Users\\ASUS\\Desktop\\Songs\\Beautiful In White - Demo.mp3");
	SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_INSERTSTRING, -1, (LPARAM)L"C:\\Users\\ASUS\\Desktop\\Songs\\Red - Taylor Swift.mp3");
	SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_INSERTSTRING, -1, (LPARAM)L"C:\\Users\\ASUS\\Desktop\\Songs\\讲真的 - 曾惜.mp3");
	SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_INSERTSTRING, -1, (LPARAM)L"C:\\Users\\ASUS\\Desktop\\Songs\\爱丫爱丫 - BY2.mp3");
	SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_INSERTSTRING, -1, (LPARAM)L"C:\\Users\\ASUS\\Desktop\\Songs\\我怀恋的 - 林俊杰.mp3");*/


	hMenu = CreatePopupMenu();
	AppendMenu(hMenu, MF_STRING, MENUADD, L"添加歌曲");
	AppendMenu(hMenu, MF_STRING, MENUDEL, L"删除歌曲");
	AppendMenu(hMenu, MF_STRING, MENUCLE, L"清空歌曲");

	TCHAR musicNames[MAX_PATH] = L"";
	GetPrivateProfileString(appName, NULL, NULL, musicNames, MAX_PATH, L"D://musicList.ini");
	TCHAR *p = musicNames;
	while (*p)
	{
		SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_INSERTSTRING, -1, (LPARAM)p);
		p = p + lstrlen(p) + 1;
	}
	return TRUE;
}

void Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch (id)
	{
	case IDC_LIST1:
	{
					  if (LBN_DBLCLK == codeNotify)
					  {
						  Start(hwnd);
					  }
	}
		break;
	case IDSTART:
	{
					Start(hwnd);
	}
		break;
	case IDPAUSE:
	{
					Pause(hwnd);
	}
		break;
	case MENUDEL:
	{
					DelMusics(hwnd);
	}
		break;
	case MENUCLE:
	{
					CleMusics(hwnd);
	}
		break;
	case MENUADD:
	{
					AddMusics(hwnd);
	}
		break;
	default:
		break;
	}
}


void Start(HWND hwnd)
{
	TCHAR musicLongPath[MAX_PATH] = L"";
	TCHAR musicShortPath[MAX_PATH] = L"";
	TCHAR buttonText[3] = L"";
	TCHAR musicLen[10];
	TCHAR musicName[20] = L"";
	int ret = SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_GETCURSEL, 0, 0);
	if (LB_ERR != ret)
	{
		Button_GetText(GetDlgItem(hwnd, IDPAUSE), buttonText, 4);
		if (lstrcmp(buttonText, L"继续") == 0)
		{
			Button_SetText(GetDlgItem(hwnd, IDPAUSE), L"暂停");
		}
		if (lstrlen(currentMusic) != 0)
		{
			StopMusic(currentMusic);
		}
		SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_GETTEXT, ret, (LPARAM)musicName);
		GetPrivateProfileString(appName, musicName, NULL, musicLongPath, MAX_PATH, iniPath);
		GetShortPathName(musicLongPath, musicShortPath, MAX_PATH);
		PlayMusic(musicShortPath);
		lstrcpy(currentMusic, musicShortPath);
		//MessageBox(hwnd, musicPath, L"", MB_OK);

		//歌曲长度
		musiclenI = GetMusicLength(currentMusic) / 1000;
		wsprintf(musicLen, L"%02d:%02d", musiclenI / 60, musiclenI % 60);
		SetWindowText(GetDlgItem(hwnd, IDC_LEN), musicLen);

		SetTimer(hwnd, TIMEID, 500, NULL);

		SendMessage(GetDlgItem(hwnd, IDC_SLIDER1), TBM_SETRANGE, TRUE, MAKELONG(0, musiclenI));


	}
	else
	{
		MessageBox(hwnd, L"请选择歌曲", L"", MB_OK);
	}
	//MessageBox(hwnd,L"",L"",0);
}


void PlayMusic(TCHAR* musicPath)
{
	TCHAR order[MAX_PATH] = L"";
	wsprintf(order, L"open %s", musicPath);
	mciSendString(order, NULL, 0, NULL);
	wsprintf(order, L"play %s", musicPath);
	mciSendString(order, NULL, 0, NULL);

}

void PlayMusicFromPos(TCHAR* musicPath, int pos)
{
	TCHAR order[MAX_PATH] = L"";
	wsprintf(order, L"play %s from %d", musicPath, pos);
	mciSendString(order, NULL, 0, NULL);

}

void StopMusic(TCHAR* musicPath)
{
	TCHAR order[MAX_PATH] = L"";
	wsprintf(order, L"stop %s", musicPath);
	mciSendString(order, NULL, 0, NULL);
	wsprintf(order, L"close %s", musicPath);
	mciSendString(order, NULL, 0, NULL);
}

void Pause(HWND hwnd)
{
	TCHAR buttonText[3] = L"";
	Button_GetText(GetDlgItem(hwnd, IDPAUSE), buttonText, 4);
	if (lstrcmp(buttonText, L"暂停") == 0)
	{
		PauseMusic(currentMusic);
		Button_SetText(GetDlgItem(hwnd, IDPAUSE), L"继续");
	}
	else if (lstrcmp(buttonText, L"继续") == 0)
	{
		ResumeMusic(currentMusic);
		Button_SetText(GetDlgItem(hwnd, IDPAUSE), L"暂停");
	}
	//PauseMusic(currentMusic);
}

void PauseMusic(TCHAR* musicPath)
{
	TCHAR order[MAX_PATH] = L"";
	wsprintf(order, L"pause %s", musicPath);
	mciSendString(order, NULL, 0, NULL);
}

void ResumeMusic(TCHAR* musicPath)
{
	TCHAR order[MAX_PATH] = L"";
	wsprintf(order, L"resume %s", musicPath);
	mciSendString(order, NULL, 0, NULL);
}


int GetMusicLength(TCHAR* musicPath)//返回的是毫秒数
{
	TCHAR order[MAX_PATH] = L"";
	TCHAR len[10] = L"";
	wsprintf(order, L"status %s length", musicPath);
	mciSendString(order, len, sizeof(len), NULL);
	return _wtoi(len);
}

int GetMusicPos(TCHAR* musicPath)//返回的是毫秒数
{
	TCHAR order[MAX_PATH] = L"";
	TCHAR pos[10] = L"";
	wsprintf(order, L"status %s position", musicPath);
	mciSendString(order, pos, sizeof(pos), NULL);
	return _wtoi(pos);
}


void AddMusics(hwnd)
{
	//TCHAR ret[10]=L"";
	//WritePrivateProfileString(L"关羽", L"攻击力", L"1000", L"D://hero.ini");
	//GetPrivateProfileString(L"关羽", L"攻击力", NULL, ret, 10, L"D://hero.ini");

	//MessageBox(hwnd, L"", L"", 0);
	OPENFILENAME ofn;
	TCHAR szFileName[MAX_PATH * 30];
	TCHAR musicDir[MAX_PATH] = L"";
	ZeroMemory(&ofn, sizeof(ofn));
	ZeroMemory(szFileName, sizeof(szFileName));

	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;//父窗口句柄
	ofn.lpstrFilter = TEXT("MP3文件 (*.mp3)\0*.mp3\0WAV文件 (*.wav)\0*.wav\0");
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = sizeof(szFileName);
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT;
	ofn.lpstrInitialDir = TEXT("‪C:\\Users\\ASUS\\Desktop\\Songs\\");//默认的打开的路径文件，这里以当前目录为例


	TCHAR *p;
	if (GetOpenFileName(&ofn))
	{
		lstrcpy(musicDir, szFileName);
		lstrcat(musicDir, L"\\");

		p = szFileName + ofn.nFileOffset;
		while (*p)
		{
			TCHAR musicPath[MAX_PATH] = L"";
			lstrcpy(musicPath, musicDir);
			lstrcat(musicPath, p);
			//MessageBox(hwnd, musicPath, L"", MB_OK);

			TCHAR musicName[50] = L"";
			lstrcpy(musicName, p);
			CutSuffix(musicName);

			SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_INSERTSTRING, -1, (LPARAM)musicName);

			WritePrivateProfileString(appName, musicName, musicPath, iniPath);

			p = p + lstrlen(p) + 1;
		}
		//MessageBox(hwnd, szFileName, L"", MB_OK);
	}
}
void DelMusics(hwnd)
{
	TCHAR musicName[40] = L"";
	int sel = SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_GETCURSEL, 0, 0);
	if (sel > -1)
	{
		SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_GETTEXT, (WPARAM)sel, (LPARAM)musicName);
		SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_DELETESTRING, sel, 0);
		WritePrivateProfileString(appName, musicName, NULL, iniPath);
	}
	else
	{
		MessageBox(hwnd, L"请选择要删除的歌曲", L"", MB_OK);
	}
}
void CleMusics(hwnd)
{
	SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_RESETCONTENT, 0, 0);
	WritePrivateProfileString(appName, NULL, NULL, iniPath);
}
void CutSuffix(TCHAR *p)
{
	int i = lstrlen(p);
	TCHAR* p2 = p + i;
	while (p2>p)
	{
		if (*p2 == TEXT('.'))
		{
			*p2 = TEXT('\0');
			break;
		}
		p2--;
	}
}
