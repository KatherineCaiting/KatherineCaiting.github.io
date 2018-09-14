#include <windows.h>
#include<windowsx.h>

#include "resource.h"
#include<mmsystem.h>
#include<Commctrl.h>
#include"SkinH.h"
#pragma comment(lib,"SkinHu.lib")
#pragma comment(lib,"WINMM.LIB")
#define TIMEID 10
#define MENUADD 201
#define MENUDEL 208
#define MENUCLE 220
#define HANDLE_0X010 201

TCHAR currentMusic[MAX_PATH];
int musiclenI;//歌曲长度
HMENU hMenu;//菜单句柄
HBITMAP hBmp;
TCHAR appName[10] = L"MUSIC";
TCHAR iniPath[20] = L"D://musicList.ini";

//消息分流器
BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
void Cls_OnClose(HWND hwnd);
void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);

void PlayMusic(TCHAR* musicPath);
void Start(HWND hwnd);//播放歌曲
void StopMusic(TCHAR* musicPath);
void Pause(HWND hwnd);
void PauseMusic(TCHAR* musicPath);
void ResumeMusic(TCHAR* musicPath);
int GetMusicLength(TCHAR* musicPath);
int GetMusicPos(TCHAR* musicPath);//返回的是毫秒数
void PlayMusicFromPos(TCHAR* musicPath, int pos);
void AddMusics(HWND);//添加歌曲
void DelMusics(HWND);
void CleMusics(HWND);
void CutSuffix(TCHAR *p);