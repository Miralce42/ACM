//Êä³öµ¹Èý½Ç
#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i <= n ;i++)
	{
		for(int j = 0; j < 2*n-1 ; j++)
		{
		 	if(j<i)
				printf(" ");
			else if(j>=2*n-1-i)
				printf(" ");
			else
				printf("#");
		}
	printf("\n");
	}
	return 0;
}