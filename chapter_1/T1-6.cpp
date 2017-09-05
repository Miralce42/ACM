//判断是否是三角形，如果是，是否是直角三角形
#include<stdio.h>
#include<math.h>

int sort(int &a,int &b,int &c);

int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	sort(a,b,c);
	if(a+b > c)
	{
		if(pow(a,2)+pow(b,2) == pow(c,2))
			printf("YES\n");
		else
			printf("NO\n");
	}
	else
		printf("not a triangle\n");
	return 0;
}

int sort(int &a,int &b,int &c)
{
	int t;
	if(a > b) {t=a;a=b;b=t; }
	if(a > c) {t=a;a=c;c=t; }
	if(b > c) {t=b;b=c;c=t; }
	return 0;
}