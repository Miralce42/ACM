#include<iostream>
#include<string>
#include<cstring>
#include<set>

using namespace std;

void connected(int v);
bool degree_to_meet();
void init();

const int MAXN = 26 + 4;
//二维数组g用来存边，    in[i]来存i的出度，out同理，   cnt用来在DFS之后判断是否访问了所有的点，也就是图是否连通 
int g[MAXN][MAXN], in[MAXN], out[MAXN], cnt;
set<int> chr;		//用来存所有的点 
bool vis[MAXN];		//DFS时用来判断是否访问过i 

int main()
{
	//freopen("input.txt","r",stdin); 
	//freopen("output.txt","w",stdout); 
	int n, m;
	string s;
	cin >> n;
	while (n--)
	{
		cin >> m;
		while (m--)							//输入初始化 
		{
			cin >> s;
			int ch_in = s[0] - 'a', ch_out = s[s.size()-1] - 'a';
			g[ch_in][ch_out] = 1;g[ch_out][ch_in] = 1;
			in[ch_in]++; out[ch_out]++;
			chr.insert(ch_in); chr.insert(ch_out);
		}
		cnt = 1;
		connected(*chr.begin());		//进行DFS 
		if (cnt == chr.size() && degree_to_meet()) //判断两个条件是否满足 
			cout << "Ordering is possible.\n";
		else cout << "The door cannot be opened.\n";
		init();
	}
	return 0;
}

bool degree_to_meet()				//判断是否满足欧拉通路（回路）出度和入度的关系 
{
	bool ch_begin = false, ch_end = false;
	for (set<int>::iterator it = chr.begin(); it != chr.end(); it++)
	{
		int dv = in[*it] - out[*it];
		if (dv)
		{	//如果存在出入度之差不为1或-1，或者多个出入度为1或-1的点，则说明不是欧拉通路
			if ((dv != 1 && dv != -1) || (ch_begin && dv == 1) || (ch_end && dv == -1))
				return false;
			if (dv == 1) ch_begin = true;
			if (dv == -1) ch_end = true;
		}
	}
	return true;
}

void connected(int v)			//进行DFS 
{
	vis[v] = true;
	for (set<int>::iterator it = chr.begin(); it != chr.end(); it++)
	{
		if (g[v][*it] && !vis[*it])
		{
			cnt++;				//每次访问一个新的点都要计数，以便以后判断是否所有点都被访问 
			connected(*it);
		}
	}
	return ;
}

void init()			//初始化所有数组和set 
{
	chr.clear();
	memset(g, 0, sizeof(g));
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	memset(vis, 0, sizeof(vis));
}
