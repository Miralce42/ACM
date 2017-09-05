//hiahiahia，我好强
#include<stdio.h>
#include<string.h>

void guess();

#define maxn 20

int rnd = 0;
char s1[maxn],s2[maxn];

int main()
{
	while(scanf("%d %s %s",&rnd,s1,s2) == 3 && rnd != -1)
	{
		printf("Round %d",rnd);
		guess();
	}
	return 0;
}

void guess()
{
	int chance = 7,get = 0,left;//get猜中为1，left原字符串中剩下的字母数
	int len1 = strlen(s1),len2 = strlen(s2);
	left = len1;
	printf("len1 = %d,len2 = %d\n",len1,len2);//测试
	for(int i = 0 ; i < len2 ; i++)
	{
		for(int j = 0 ; j < len1 ; j++)
		{
			if(s2[i] == s1[j])
			{
				get = 1;
				left--;
				s1[j] = '0';
			}
		}
		if(get)
			get = 0;
		else
			chance--;
		if(!chance)
		{
			printf("You lose.\n");
			return ;
		}
		else if(!left)
		{
			printf("You win.\n");
			return ;
		}
	}
	if(chance && left)
		printf("You chickened out.\n");
	return ;
}