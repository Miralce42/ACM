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
		//��������ʹ���
		int m=0;
		for(int i = 0 ; i < n ;i++)
		{
			cin >> fn[i];
			m = max(m,fn[i].length());//��ȡ�ļ����Ƶ���󳤶�,ע�ⲻҪ�����㷨�������÷�
		}
		int cols = (maxCol - m) / (m+2) + 1;//��ȡ����
		int rows = (n - 1) / cols +1;//��ȡ����
		sort(fn,fn+n);//���ֵ�������
		//���
		print("",60,'-');
		printf("\n");
		for(int r = 0 ; r < rows ; r++)
		{
			for(int c = 0 ; c < cols ; c++)
			{
				int i = rows*c + r ;
				if(i < n) 
					print(fn[i],r == rows ? m : m+2 ,' ');//����Ǹ������һ���򳤶�Ϊm��ȻΪm+2
			}
			printf("\n");
		}
	}
	return 0;
}

//�Զ�����������������s��������lenλ������ռλ��extra����
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