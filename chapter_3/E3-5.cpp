//生成元问题
#include<stdio.h>
#include<string.h>

int main()
{
	int n,sign,s;
	char num[8];
	memset(num,0,sizeof(num));
	scanf("%d",&n);
	for(int i = 1 ; i < n ;i++)
	{
		sign = 0;
		s = 0;
		sprintf(num,"%d",i);
		int len = strlen(num);
		for(int j = 0 ; j < len ; j++)
		{
			int k = num[j] - '0';
			s += k;
			
		}
		s += i;
		printf("s %d=  ; i = %d\n",s,i);
		if(n == s)
		{
			sign = 1;
			break;
		}
	}
	if(sign)
		printf("%d\n",i);
	else
		printf("0");
	return 0;
}