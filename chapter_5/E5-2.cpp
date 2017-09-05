//不容易啊！
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

void find_block(int x,int &p,int &h);
void clear_above(int p,int h);
void put_block(int p1,int h,int p2);
void print();

const int maxn = 1000;
vector<int> pile[maxn];
int n;

int main()
{
	int a,b;
	string s1,s2;
	cin >> n;
	for(int i = 0 ; i < n ; i++) pile[i].push_back(i);
	while(cin >> s1 && s1 != "quit" && cin >> a >> s2 >> b)
	{
		int pa,pb,ha,hb;
		find_block(a,pa,ha);//找到a所对应的堆和的高度
		find_block(b,pb,hb);//找到b所对应的堆和的高度
		if(pa == pb) continue;//非法输入
		if(s2 == "onto") clear_above(pb,hb);
		if(s1 == "move") clear_above(pa,ha);
		put_block(pa,ha,pb);//移动木块
	}
	print();
	return 0;
}

void find_block(int x,int &p,int &h)
{
	for(p = 0 ; p < n; p++)
	{
		for(h = 0 ; h < pile[p].size() ; h++)
		{
			if(pile[p][h] == x)	return;
		}
	}
} 

void clear_above(int p,int h)//清空p堆h以上的的木块
{
	for(int i = h+1 ; i < pile[p].size() ; i++)
	{
		int x = pile[p][i];
		pile[x].push_back(x);
	}
	pile[p].resize(h+1);
}

void put_block(int p1,int h,int p2)//放置木块
{
	for(int i = h ; i < pile[p1].size() ; i++)
	{
		pile[p2].push_back(pile[p1][i]);
	}
	pile[p1].resize(h);
}

void print()
{
	for(int i = 0 ; i < n ;i++)
	{
		cout << i <<":" ;
		for(int j = 0 ; j  < pile[i].size() ; j++)
		{
			cout << pile[i][j] << " ";
		}
		cout << endl;
	}
}