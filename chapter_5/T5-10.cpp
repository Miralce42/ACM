//未完成 
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
	cin.get();//获取“\n” 
	read(n);//读入所有文章，并进行预处理 
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
	for(int i = 0 ; i < n ; i++)//一篇一篇的读文章 
	{
		cnt = 0;//每篇文章的字数 
		string s;
		while(getline(cin,s) && s != "**********")//读入一行 
		{
			prep(s,i,cnt);//读入一行之后进行准备 
			atc[i].push_back(s);//将该行放到文章数组里 
		}
	}
}

void prep(string s,int a,int l)
{
	string word;
	for(int i = 0 ; i < s.length() ; i++)//将所有字母换成小写，并且将所有非字母的全部换成空格 
	{
		if(isalpha(s[i])) s[i] = tolower(s[i]);
		else s[i] = ' ';
	}
	stringstream ss(s);
	while (ss >> word)//一次读入一个单词 
	{
		if(dict.count(word))	//判断word是否已经存入dict中 
			dict[word] = inc(); //如果没有则先映射一个空的inc类 
		dict[word].dec.insert(a);//将该字母所在的文章号存入inc类 
		dict[word].line[a].insert(l);//将该字母所在文章对应的行数存入inc类中 
	}
}
