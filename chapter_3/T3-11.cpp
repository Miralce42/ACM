//我猜你已经看不懂了  P69
#include<stdio.h>
#include<string.h>

#define maxn 110

bool less3(char a,char b);
void moveLeft( char *b,int lenth);

int maxLen,oldLen,nowLen;//maxLen总长度，oldLen：b的原始长度，nowLen，移动后b的长度

int main()
{
	char a[maxn],b[maxn],t[maxn];
	while(scanf("%s %s",a,b)!=EOF)
	{
		if(strlen(a) < strlen(b))//比较两字符串的长度，保持a大于等于b
		{
			strcpy(t, a);//a复制给t
			strcpy(a, b);//b复制给a
			strcpy(b, t);//t复制给b
		}
		int aLen = strlen(a);
		nowLen = oldLen = strlen(b);//原始长度
		maxLen = aLen;
		while(1)
		{
			for(int i = 0 ; i < maxLen ; i++)
			{
				if(!less3(a[i],b[i]))
					break;
			}
			if(i == maxLen)
				break;
			else 
				moveLeft(b,oldLen);
		}
		printf("%d\n",maxLen);
		memset(a,'0',sizeof(a));
		memset(b,'0',sizeof(a));
	}
	return 0;
}

bool less3(char a,char b)
{
	int high = a + b - 2*'0';//计算高度
	if(high > 3)
		return false;
	else
		return true;
}

void moveLeft( char *b,int lenth)
{
	for(int i = nowLen ; lenth > 0 ; lenth--,i--)
	{
		b[i] = b[i-1];
	}
	b[i] = '0';
	nowLen++;//b的长度增加
	if(maxLen < nowLen)//两个字符串的总长度
		maxLen = nowLen;
}
