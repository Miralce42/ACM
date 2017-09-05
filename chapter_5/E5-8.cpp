//uva400
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void print(string s,int len,char extra);
int max(int a,int b);

const int maxn = 100+5;
const int maxCol = 60;  
string fn[maxn];

int main()
{
	int n;
	while(cin >> n && n)
	{
		//名称输入和处理
		int m=0;
		for(int i = 0 ; i < n ;i++)
		{
			cin >> fn[i];
			m = max(m,fn[i].length());//获取文件名称的最大长度,注意不要混淆算法函数的用法
		}
		int cols = (maxCol - m) / (m+2) + 1;//获取列数
		int rows = (n - 1) / cols +1;//获取行数
		sort(fn,fn+n);//按字典序排序
		//输出
		print("",60,'-');
		printf("\n");
		for(int r = 0 ; r < rows ; r++)
		{
			for(int c = 0 ; c < cols ; c++)
			{
				int i = rows*c + r ;
				if(i < n) 
					print(fn[i],r == rows ? m : m+2 ,' ');//如果是改行最后一个则长度为m不然为m+2
			}
			printf("\n");
		}
	}
	return 0;
}

//自定义输出函数，先输出s，若不够len位，则用占位符extra补充
void print(string s,int len,char extra)
{
	cout << s ;
	for(int  i =  0 ; i < (len - s.length()) ; i++)
	{
		printf("%c",extra);
	}
}

int max(int a,int b)
{
	return a>b ? a : b;
}