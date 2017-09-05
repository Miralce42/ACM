#include<stdio.h>

int main()
{
	int n;
	float money;
	scanf("%d",&n);
	money = 95*n;
	if(money >= 300)
		money = money * 0.85;
	printf("%.2f\n",money);
	return 0;
}