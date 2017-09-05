#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define maxn 100

const double mm[4] = {12.01,1.008,16.00,14.01};//定义原子量

int main()
{
	double mass=0;
	int num = 0,places = 0;//原子个数
	char mf[maxn];//定义分子式
	scanf("%s",mf);
	for(int i = strlen(mf)-1 ; i >= 0  ; i--)
	{
		if(isdigit(mf[i]))
		{
			num += pow(10,places)*(mf[i] - '0');
			places++;
		}
		if(isalpha(mf[i]))
		{
			if(!num) num++;//单个元素
			switch(mf[i])
			{
				case 'C':
				case 'c':mass += num*mm[0];break;
				case 'H':
				case 'h':mass += num*mm[1];break;
				case 'O':
				case 'o':mass += num*mm[2];break;
				case 'N':
				case 'n':mass += num*mm[3];break;
			}
			places = num = 0;
		}
	}
	printf("%.3fg/mol\n",mass);
	return 0;
}