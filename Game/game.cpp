#include<stdio.h>
#include<graphics.h>
#include<time.h>
#define KEY_DOWN(vk_c)(GetAsyncKeyState(vk_c)&0x8000)

typedef struct position
{
	int x;
	int y;

}pos;

pos cur;//当前光标位置
pos bothArr[180];//同色小球下标
int index;//同色小球的个数

void init();//初始化界面
void gamebegin();//游戏开始界面
void gameplay();//玩游戏的具体过程
void close();//释放资源
void drawcursor(pos p,COLORREF cl);//重绘光标
void drawtime(int sec);//重绘时间
void drawscore(int sco);//重绘分数
int isValid(pos cur,COLORREF cl);//判断是否合法
void getsamecolorBoth(pos cur,COLORREF cl);//寻找同色小球
void ballfall();//小球下落
void turn();//排序

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
	//绘制边框
	setlinecolor(RGB(50,50,50));
	setlinestyle(PS_SOLID,10);
    rectangle(255,45,745,655);

	//绘制小球
	int i,j;
	setlinestyle(PS_SOLID,1);
	srand((unsigned)time(NULL));//提供随机数种子
	for(i=280;i<740;i+=40)
		for(j=70;j<650;j+=40)
		{
			COLORREF cl=colorArr[rand()%6];
			setlinecolor(cl);
	        setfillcolor(cl);
			fillcircle(i,j,18);
		}
	
	//绘制光标
	cur.x=480;
	cur.y=390;
	drawcursor(cur,RGB(255,255,255));
	//绘制时间
    drawtime(30);

	//绘制分数
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
		//上键按下
		 drawcursor(cur,RGB(0,0,0));
		 cur.y-=40;
         drawcursor(cur,RGB(255,255,255));
		}
		if(KEY_DOWN(VK_DOWN)&&cur.y<630)
		{
		    //下键按下
			drawcursor(cur,RGB(0,0,0));
		    cur.y+=40;
            drawcursor(cur,RGB(255,255,255));
		 
		}
		if(KEY_DOWN(VK_LEFT)&&cur.x>20)
		{
		//左键按下
			drawcursor(cur,RGB(0,0,0));
		    cur.x-=40;
            drawcursor(cur,RGB(255,255,255));
		 
		}
		if(KEY_DOWN(VK_RIGHT)&&cur.x<720)
		{
		//右键按下
			drawcursor(cur,RGB(0,0,0));
		    cur.x+=40;
            drawcursor(cur,RGB(255,255,255));
		 
		}
		if(KEY_DOWN(VK_RETURN)||KEY_DOWN(VK_SPACE))
		{
			//获得光标所在位置周围的同色小球
			getsamecolorBoth(cur,getpixel(cur.x, cur.y));
			//将同色小球消失一段时间
			if(index>1)
			{
				for(int k=0;k<index;k++)
				{
				setlinecolor(RGB(0,0,0));
				setfillcolor(RGB(0,0,0));
				fillcircle(bothArr[k].x,bothArr[k].y,18);
				}
				Sleep(500);//暂停一会
				//上方的小球下落
				ballfall();
				//刷新分数
				score+=index;
                drawscore(score);

			}
			index=0;
			
		}
		Sleep(200);
	}
	//游戏结束
	cleardevice();
	settextcolor(RGB(255,255,255));
    settextstyle(80, 0, _T("黑体"));
	outtextxy(300, 230, "Game over");
	

	char str[30];
	settextcolor(RGB(255,0,0));
	settextstyle(25, 0, _T("黑体"));
	sprintf(str,"您的最终得分为：%d",score);
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
	settextstyle(25, 0, _T("黑体"));
	sprintf(str,"剩余时间：%2d s",sec);   
	outtextxy(30, 50, str);
}

void drawscore(int score)
{
	char str[30];
	settextcolor(RGB(255,0,0));
	settextstyle(25, 0, _T("黑体"));
	sprintf(str,"分数：%d",score);
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
		case 0:p.x=cur.x;p.y=cur.y-40;break;//上
        case 1:p.x=cur.x;p.y=cur.y+40;break;//下
	    case 2:p.x=cur.x-40;p.y=cur.y;break;//左
		case 3:p.x=cur.x+40;p.y=cur.y;break;//右
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