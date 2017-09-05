//移动迷宫
#include<stdio.h>
#include<string>

#define n 5

void move(char ins);
void show();

char puzzle[n][n] = {'T','R','G','S','J',
					 'X','D','O','K','I',
					 'M',' ','V','L','N',
					 'W','P','A','B','E',
					 'U','Q','H','C','F'
					};
int x=2,y=1;//横纵坐标，从0开始

int main()
{
	char ins;
	while(1)
	{
		scanf("%c",&ins);
		if(ins == '0')
			break;
		else if(ins == 'A' || ins == 'B' || ins == 'L' || ins == 'R')
		{
			move(ins);
			show();
		}
		else
		{
			printf("This puzzle has no final configuration.\n");
		}
	}
	return 0;
}

void move(char ins)
{
	int suc = 1;
	if(ins == 'A')
	{
		if(x-1 < 0) 
			suc = 0;
		else
		{
			puzzle[x][y] = puzzle[x-1][y];
			puzzle[x-1][y] = ' ';
			x--;
		}
	}
	if(ins == 'B')
	{
		if(x+1 > n-1) 
			suc = 0;
		else
		{
			puzzle[x][y] = puzzle[x+1][y];
			puzzle[x+1][y] = ' ';
			x++;
		}
	}
	if(ins == 'L')
	{
		if(y-1 < 0) 
			suc = 0;
		else
		{
			puzzle[x][y] = puzzle[x][y-1];
			puzzle[x][y-1] = ' ';
			y--;
		}
	}
	if(ins == 'R')
	{
		if(y+1 > n-1) 
			suc = 0;
		else
		{
			puzzle[x][y] = puzzle[x][y+1];
			puzzle[x][y+1] = ' ';
			y++;
		}
	}
	if(!suc)
		printf("Will over the border!\n");
}

void show()
{
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			printf("%2c",puzzle[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

