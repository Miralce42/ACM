//δ��� 
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<sstring>

using namespace std;

const int maxd = 100 +10;

struct inc
{
	set<int> dec,line[maxd];
};

map<string,inc> dict;
vector<string> atc[maxd];

int main()
{
	int n,m;
	cin >> n;
	cin.get();//��ȡ��\n�� 
	read(n);//�����������£�������Ԥ���� 
	cin >> m; 
	//cin.get();
	find(n,m);
	return 0; 
} 

void find(int n,int m)
{
	string word;
	for(int i = 0 ; i < m ; i++)
	{
		getline(cin,word);
		if(word.find(" AND ")!=s.nops)
		{
			
		}
		
	}
}

void read(int n)
{
	int cnt;
	for(int i = 0 ; i < n ; i++)//һƪһƪ�Ķ����� 
	{
		cnt = 0;//ÿƪ���µ����� 
		string s;
		while(getline(cin,s) && s != "**********")//����һ�� 
		{
			prep(s,i,cnt);//����һ��֮�����׼�� 
			atc[i].push_back(s);//�����зŵ����������� 
		}
	}
}

void prep(string s,int a,int l)
{
	string word;
	for(int i = 0 ; i < s.length() ; i++)//��������ĸ����Сд�����ҽ����з���ĸ��ȫ�����ɿո� 
	{
		if(isalpha(s[i])) s[i] = tolower(s[i]);
		else s[i] = ' ';
	}
	stringstream ss(s);
	while (ss >> word)//һ�ζ���һ������ 
	{
		if(dict.count(word))	//�ж�word�Ƿ��Ѿ�����dict�� 
			dict[word] = inc(); //���û������ӳ��һ���յ�inc�� 
		dict[word].dec.insert(a);//������ĸ���ڵ����ºŴ���inc�� 
		dict[word].line[a].insert(l);//������ĸ�������¶�Ӧ����������inc���� 
	}
}
