//�Ҳ����Ѿ���������  P69
#include<stdio.h>
#include<string.h>

#define maxn 110

bool less3(char a,char b);
void moveLeft( char *b,int lenth);

int maxLen,oldLen,nowLen;//maxLen�ܳ��ȣ�oldLen��b��ԭʼ���ȣ�nowLen���ƶ���b�ĳ���

int main()
{
	char a[maxn],b[maxn],t[maxn];
	while(scanf("%s %s",a,b)!=EOF)
	{
		if(strlen(a) < strlen(b))//�Ƚ����ַ����ĳ��ȣ�����a���ڵ���b
		{
			strcpy(t, a);//a���Ƹ�t
			strcpy(a, b);//b���Ƹ�a
			strcpy(b, t);//t���Ƹ�b
		}
		int aLen = strlen(a);
		nowLen = oldLen = strlen(b);//ԭʼ����
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
	int high = a + b - 2*'0';//����߶�
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
	nowLen++;//b�ĳ�������
	if(maxLen < nowLen)//�����ַ������ܳ���
		maxLen = nowLen;
}
