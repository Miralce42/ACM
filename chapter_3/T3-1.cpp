#include<stdio.h>
#include<string.h>

#define maxn 90

int main()
{
	int n,score,count;
	scanf("%d",&n);
	while(n--)
	{
		char str[maxn];
		scanf("%s",str); 
			score = count=0;
			for(int i = 0; i < strlen(str) ; i++)
			{
				if(str[i] == 'X')
					count = 0;
				else{
					count++;
					score += count;
				}
			}
			printf("%d\n",score);
	}
	return 0;
}
