#include<stdio.h>
#include<string.h>

#define maxn 90

int main()
{
	char str[maxn];
	scanf("%s",str);
	int sign ,len = strlen(str),cycle;
	for(int i = 1 ; i <= len ;i++)//i:可能的周期长度
	{
		cycle = i;
		sign = 1;
		if(len%i)
			continue;//除不尽则不可能为周期
		for(int j = 1 ; j <= i ;j++)//一个周期内的字母位置
		{
			for(int k = j+i ; k <= len ; k += i )
			{
				if(str[j-1] != str[k-1])//注意下标的开始
				{
					sign =0;
					break;
				}
			}
			if(!sign)
				break;
		}
		if(sign == 1 && j-1 == i)//注意在上边的循环最后j已经+1，所以这里要减一
			break;
	}
	printf("%d\n",cycle);
	return 0;
}