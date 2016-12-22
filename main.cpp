#include <stdio.h>
#include <conio.h>
#include <Windows.h>
void gotoxy(int x,int y);
void bug(int a[10][10]);
void check(int a[10][10],int x,int y,int data);

void main()
{
	int x=6,y=3;
	int i,j;
	int key;
	int flag=0;
	int cnt=0;
	int map[10][10]= {
		{1,1,1,1,1,1,9},
		{1,0,2,0,2,0,1},
		{1,3,2,3,2,3,1},
		{1,0,2,0,2,0,1},
		{1,3,2,3,2,3,1},
		{1,0,2,0,2,0,1},
		{1,1,1,1,1,1,9},
	};

	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
		{
			if(map[i][j]==1) printf("%c%c",0xa1,0xe1);
			if(map[i][j]==2) printf("%c",5);
			if(map[i][j]==3) printf("--");
			if(map[i][j]==0) printf("  ");
		}
		printf("\n");
	}
	bug(map);
	while(1)
	{	
		key=getch();
		switch(key)
		{
		case 75:
			gotoxy(x-=3,y=y);
			break;
		case 77 :
			gotoxy(x+=3,y=y);
			break;
		case 72:
			gotoxy(x,y-=2);
			break;
		case 80:
			gotoxy(x,y+=2);
			break;
		case 32:
			if(map[x][y]==0)
			{
				if(flag==0)
				{
					
					printf("O");
					map[x][y]=5;
					check(map,x,y,5);
					cnt++;
					if(cnt==9)
					{
						gotoxy(10,10);
						printf("Draw");
					}
					flag=1;
				}
				else if(flag==1)
				{
					printf("X");
					map[x][y]=6;
					check(map,x,y,6);
					cnt++;
					if(cnt==9)
					{
						gotoxy(10,10);
						printf("Draw");
					}
					flag=0;
				}
			}
			else
			{
				gotoxy(10,10);
				printf("Please choose another location\n");
				gotoxy(10,10);
				Sleep(2000);
				printf("                                  \n");
			}
			break;
		};
	}
}

void check(int a[10][10],int x,int y,int data)
{
	int i;
	for(i=1;i<6;i+=2) //啊肺贸府
	{
		if((a[3][i]==data)&&(a[6][i]==data)&&(a[9][i]==data)) 
		{
			if(data==5)
			{
				gotoxy(10,10);
				printf("O Win!!");
			}
			else if(data==6)
			{
				gotoxy(10,10);
				printf("X Win!!");
			}
		}
	} // 啊肺贸府场

	for(i=3;i<10;i+=3) //技肺贸府
	{
		if((a[i][1]==data)&&(a[i][3]==data)&&(a[i][5]==data))
		{
			if(data==5)
			{
				gotoxy(10,10);
				printf("O Win!!");
			}
			else if(data==6)
			{
				gotoxy(10,10);
				printf("X Win!!");
			}
		}
	}//技肺贸府场
	if((a[3][1]==data)&&(a[6][3]==data)&&(a[9][5]==data))
	{
		if(data==5)
			{
				gotoxy(10,10);
				printf("O Win!!");
			}
			else if(data==6)
			{
				gotoxy(10,10);
				printf("X Win!!");
			}
	}
	if((a[3][5]==data)&&(a[6][3]==data)&&(a[9][1]==data))
	{
		if(data==5)
			{
				gotoxy(10,10);
				printf("O Win!!");
			}
			else if(data==6)
			{
				gotoxy(10,10);
				printf("X Win!!");
			}
	}

}

void gotoxy(int x,int y)
{
	COORD Pos;
	Pos.X=x;
	Pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos); 
}

void bug(int a[10][10])
{
	a[6][1]=0;
	a[6][3]=0;
	a[6][5]=0;
}