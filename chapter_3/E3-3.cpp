//判断是否是回文串和镜像串
#include<stdio.h>
#include<string.h>
#include<ctype.h>

const char *rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *msg[] = {"-- is not a palindrome.","-- is a regular palindrome.","-- is a mirrored string.","-- is a mirrored palindrome."};

char r(char ch)
{
	if(isalpha(ch)) 
		return rev[ch - 'A'];
	else
		return rev[ch - '0' + 25];
}

int main()
{
	char str[100];
	int p = 1,m = 1;
	while(scanf("%s",str) == 1){
		int len = strlen(str);
		for(int i = 0 ; i < len/2;i++)
		{
			if(str[i] != str[len-1-i])
				p = 0;
			if(r(str[i]) != str[len-1-i])
				m = 0;
		}
		printf("%s %s",str,msg[m*2+p]);
	}
	return 0;
}