#include<stdio.h>
#include<graphics.h>
#include<time.h>
#define KEY_DOWN(vk_c)(GetAsyncKeyState(vk_c)&0x8000)

typedef struct position
{
	int x;
	int y;

}pos;

pos cur;//��ǰ���λ��
pos bothArr[180];//ͬɫС���±�
int index;//ͬɫС��ĸ���

void init();//��ʼ������
void gamebegin();//��Ϸ��ʼ����
void gameplay();//����Ϸ�ľ������
void close();//�ͷ���Դ
void drawcursor(pos p,COLORREF cl);//�ػ���
void drawtime(int sec);//�ػ�ʱ��
void drawscore(int sco);//�ػ����
int isValid(pos cur,COLORREF cl);//�ж��Ƿ�Ϸ�
void getsamecolorBoth(pos cur,COLORREF cl);//Ѱ��ͬɫС��
void ballfall();//С������
void turn();//����

COLORREF colorArr[6]={RGB(225,0,0),RGB(0,220,0),RGB(0,0,220),RGB(225,225,0),RGB(220,0,220),RGB(0,225,255)};
void main()
{
	init();
	gamebegin();
	gameplay();
	close();
}
void init()
{
	initgraph(1000,700);
}
void gamebegin()
{
	//���Ʊ߿�
	setlinecolor(RGB(50,50,50));
	setlinestyle(PS_SOLID,10);
    rectangle(255,45,745,655);

	//����С��
	int i,j;
	setlinestyle(PS_SOLID,1);
	srand((unsigned)time(NULL));//�ṩ���������
	for(i=280;i<740;i+=40)
		for(j=70;j<650;j+=40)
		{
			COLORREF cl=colorArr[rand()%6];
			setlinecolor(cl);
	        setfillcolor(cl);
			fillcircle(i,j,18);
		}
	
	//���ƹ��
	cur.x=480;
	cur.y=390;
	drawcursor(cur,RGB(255,255,255));
	//����ʱ��
    drawtime(30);

	//���Ʒ���
	drawscore(0);
}
void gameplay()
{
	int score=0;
	for(int i=300;i>0;i--)
	{
		if(i%10==0)
		{
			drawtime(i/10);
		}
        if(KEY_DOWN(VK_UP)&&cur.y>70)
		{
		//�ϼ�����
		 drawcursor(cur,RGB(0,0,0));
		 cur.y-=40;
         drawcursor(cur,RGB(255,255,255));
		}
		if(KEY_DOWN(VK_DOWN)&&cur.y<630)
		{
		    //�¼�����
			drawcursor(cur,RGB(0,0,0));
		    cur.y+=40;
            drawcursor(cur,RGB(255,255,255));
		 
		}
		if(KEY_DOWN(VK_LEFT)&&cur.x>20)
		{
		//�������
			drawcursor(cur,RGB(0,0,0));
		    cur.x-=40;
            drawcursor(cur,RGB(255,255,255));
		 
		}
		if(KEY_DOWN(VK_RIGHT)&&cur.x<720)
		{
		//�Ҽ�����
			drawcursor(cur,RGB(0,0,0));
		    cur.x+=40;
            drawcursor(cur,RGB(255,255,255));
		 
		}
		if(KEY_DOWN(VK_RETURN)||KEY_DOWN(VK_SPACE))
		{
			//��ù������λ����Χ��ͬɫС��
			getsamecolorBoth(cur,getpixel(cur.x, cur.y));
			//��ͬɫС����ʧһ��ʱ��
			if(index>1)
			{
				for(int k=0;k<index;k++)
				{
				setlinecolor(RGB(0,0,0));
				setfillcolor(RGB(0,0,0));
				fillcircle(bothArr[k].x,bothArr[k].y,18);
				}
				Sleep(500);//��ͣһ��
				//�Ϸ���С������
				ballfall();
				//ˢ�·���
				score+=index;
                drawscore(score);

			}
			index=0;
			
		}
		Sleep(200);
	}
	//��Ϸ����
	cleardevice();
	settextcolor(RGB(255,255,255));
    settextstyle(80, 0, _T("����"));
	outtextxy(300, 230, "Game over");
	

	char str[30];
	settextcolor(RGB(255,0,0));
	settextstyle(25, 0, _T("����"));
	sprintf(str,"�������յ÷�Ϊ��%d",score);
	outtextxy(360, 400, str);
}
void close()
{
	system("pause");
	closegraph();
}

void drawcursor(pos p,COLORREF cl)
{
	setlinecolor(cl);
	rectangle(p.x-20,p.y-20,p.x+20,p.y+20);
}

void drawtime(int sec)
{
	char str[30];
	settextcolor(RGB(255,255,0));
	settextstyle(25, 0, _T("����"));
	sprintf(str,"ʣ��ʱ�䣺%2d s",sec);   
	outtextxy(30, 50, str);
}

void drawscore(int score)
{
	char str[30];
	settextcolor(RGB(255,0,0));
	settextstyle(25, 0, _T("����"));
	sprintf(str,"������%d",score);
	outtextxy(30, 600, str);
}

void getsamecolorBoth(pos cur,COLORREF cl)
{
	bothArr[index].x=cur.x;
	bothArr[index].y=cur.y;
	index++;

	pos p;
	for(int k=0;k<4;k++)
	{
		switch(k)
		{
		case 0:p.x=cur.x;p.y=cur.y-40;break;//��
        case 1:p.x=cur.x;p.y=cur.y+40;break;//��
	    case 2:p.x=cur.x-40;p.y=cur.y;break;//��
		case 3:p.x=cur.x+40;p.y=cur.y;break;//��
		}
		if(isValid(p,cl))
		{
			getsamecolorBoth(p,cl);

		}
	}
}

int isValid(pos cur,COLORREF cl)
{
		if(getpixel(cur.x,cur.y)!=cl)
			return 0;
		else 
		{
			for(int i=0;i<index;i++)
			{
				if(cur.x==bothArr[i].x&&cur.y==bothArr[i].y)
				   return 0;
			}
			return 1;
		}
}

 void ballfall()
 {
	 turn();
	 for(int i=0;i<index;i++)
	 {
		 for(int k=bothArr[i].y;k>70;k-=40)
		 {
			 COLORREF cl=getpixel(bothArr[i].x,k-40);
             setlinecolor(cl);
			 setfillcolor(cl);
			 fillcircle(bothArr[i].x,k,18);
		 }
		 COLORREF cl=colorArr[rand()%6];
		 setlinecolor(cl);
	     setfillcolor(cl);
		 fillcircle(bothArr[i].x,70,18);
	 }
 }

 void turn()
 {
	 int i,j;
	 pos p;
	 for(i=0;i<index-1;i++)
		 for(j=0;j<index-i-1;j++)
		 {
			 if(bothArr[j].x>bothArr[j+1].x)
			 {
				 p=bothArr[j];
				 bothArr[j]=bothArr[j+1];
				 bothArr[j+1]=p;
			 }
			 if(bothArr[j].y>bothArr[j+1].y)
			 {
				 p=bothArr[j];
				 bothArr[j]=bothArr[j+1];
				 bothArr[j+1]=p;
			 }
		 }
 }