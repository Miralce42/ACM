//数据输出正常，但是WA 
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<sstream>

using namespace std;

void inti();
int read(int *list);
int crt(int in1, int in2, int R1, int R2);

const int MAXN = 10000 + 100;
const int INF = 10000000000;

int in_order[MAXN];
int post_order[MAXN];
int r[MAXN];
int l[MAXN];
int min_sum,sum,min_node;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	inti();
	while (read(in_order))
	{
		min_sum = min_node = INF; sum = 0;
		int n = read(post_order);
/*		for (int i = 0; i < n ; i++)
			cout << "in_order " << i + 1 << " = " << in_order[i] << endl;
		for (int i = 0; i < n; i++)
			cout << "post_order " << i + 1 << " = " << post_order[i] << endl;
*/
		crt(0,n-1,0,n-1);
		cout <<  min_node << endl;
		inti();
	}
	return 0;
}

int crt(int in1, int in2,int po1,int po2)//在in_order[in1...in2],post_order[po1...po2]之间寻找，从0开始
{
	if (in1 > in2)
		return 0;
	int root = post_order[po2];//在后序排列中，根在最后一个
	sum += root;
	if (in1 == in2 && sum < min_sum)
	{
			min_sum = sum;
			min_node = root;
	}
	int rt_pos = in1;
	while (in_order[rt_pos] != root) rt_pos++;
	int cnt = rt_pos - in1;
	l[root] = crt(in1, rt_pos - 1,po1, po1+cnt-1);
	r[root] = crt(rt_pos + 1, in2, po1+cnt,po2-1);
	sum -= root;
	return root;
}

int read(int *list)
{
	string s;
	getline(cin, s);
	if (s == "")
		return 0;
	stringstream ss(s);
	int n=0;
	while(ss >> list[n++]);
	return n-1;
}

void inti()
{
	memset(in_order, 0, sizeof(in_order));
	memset(post_order, 0, sizeof(post_order));
	memset(r, 0, sizeof(r));
	memset(l, 0, sizeof(l));
}
