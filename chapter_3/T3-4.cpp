#include<stdio.h>
#include<string.h>

#define maxn 90

int main()
{
	char str[maxn];
	scanf("%s",str);
	int sign ,len = strlen(str),cycle;
	for(int i = 1 ; i <= len ;i++)//i:���ܵ����ڳ���
	{
		cycle = i;
		sign = 1;
		if(len%i)
			continue;//�������򲻿���Ϊ����
		for(int j = 1 ; j <= i ;j++)//һ�������ڵ���ĸλ��
		{
			for(int k = j+i ; k <= len ; k += i )
			{
				if(str[j-1] != str[k-1])//ע���±�Ŀ�ʼ
				{
					sign =0;
					break;
				}
			}
			if(!sign)
				break;
		}
		if(sign == 1 && j-1 == i)//ע�����ϱߵ�ѭ�����j�Ѿ�+1����������Ҫ��һ
			break;
	}
	printf("%d\n",cycle);
	return 0;
}