#include<stdio.h>
#include<string.h>

#define maxn 10100

int main()
{
	char s[maxn],t[maxn];
	memset(s,0,sizeof(s));
	memset(t,0,sizeof(t));
	scanf("%s %s",s,t);
	char *sp=s,*tp=t;
	int len = strlen(s);
	while(*sp!=0 && *tp!=0)//�κ�һ��Ϊ0����Ҫ����ѭ����������&&��
	{
		if(*sp == *tp)
			tp++;
		sp++;
	}
	if(*tp == 0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}