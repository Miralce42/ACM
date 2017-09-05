//UVA1593
#include<iostream>
#include<string>
#include<algorithm> 
#include<sstream>
#include<vector>
using namespace std;

void print(string s,int len);
int max(int a,int b);

const int maxr = 1000+10;
const int maxc = 180 +20;
vector<string> word[maxr];
int max_len[maxc];

int main()
{	int cols=0,rows=0;//ÿ����ĵ��ʵĳ���
	string str,t;
	memset(max_len,0,sizeof(max_len));
	while(getline(cin,str) && str!=""
		)//ʹ��getline������ȡ�����ַ���
	{
		stringstream ss(str);
		while(ss >> t)
		{
			max_len[cols] = max(max_len[cols],t.length());//Ѱ��ÿ�������
			word[rows].push_back(t);//���ַ�������������
			cols++;
		}
		rows++;
		cols = 0;
	}
	//���
	for(int i = 0 ; i < rows ; i++)
	{	
		int j;
		for( j= 0 ; j < word[i].size() - 1 ; j++)
		{
			print(word[i][j],max_len[j]);
		}
		cout << word[i][j] << endl;
	}
	return 0;
}

void print(string s,int len)
{
	cout << s;
	for(int i = 0 ; i <= len-s.size();i++)
	{
		cout << " ";
	}

}

int max(int a,int b)
{
	return a > b ? a : b;
}
