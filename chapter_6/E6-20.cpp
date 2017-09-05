//UVA1599 样例通过，提交WA 
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

const int MAXN = 100000+100;
const int INF = 0xFFFFFFF;

void bfs(int u,int to_find);
void init();
void find();

struct Node
{
	int v, c;		//该边的另一个端点，和颜色
	Node(int v,int c):v(v),c(c){}
};

vector<Node> edge[MAXN];	//使用邻接表存储所有边（自环除外）
int d[MAXN], res[MAXN];		//d用于存储每个点到终点N的路径长度，res用于最短路径的颜色
bool vis[MAXN], inque[MAXN];//vis表示v点是否被访问过,inque代表当前该点是否在队列中，防止重复放入队列
int n, m, a, b, c;
int main()
{
	freopen("input.txt","r",stdin);
	while (cin >> n >> m)
	{
		while (m--)
		{
			cin >> a >> b >> c;
			if (a != b)
			{
				edge[a].push_back(Node(b, c));
				edge[b].push_back(Node(a, c));
			}
		}
		find();
		init();
	}
	return 0;
}

void bfs(int u,int to_find)
{
	queue<int> q;
	q.push(u);
	vis[u] = true; inque[u] = true;
	while(!q.empty())
	{
		int t = q.front(); q.pop();
		inque[t] = false;
		if (to_find)
		{
			int min_col = INF;
			if (t == n) return;
			for (int j = 0; j < edge[t].size(); j++)
			{
				if(1 == d[t] - d[edge[t][j].v])
					min_col = min(edge[t][j].c, min_col);
			}
			for (int i = 0; i < edge[t].size(); i++)
			{
				int v = edge[t][i].v;
				int c = edge[t][i].c;		//从起点开始的
				if (c == min_col && 1 == d[t] - d[v])//从起点开始，按照每次距离减1的方法寻找接下来的点的编号,
				{				   					 //此时只用检查步数是否相差1和颜色是不是最小，不用检查入栈或是否访问
					if (c <= min_col)			//将颜色最小的路径push到队列中
					{
						min_col = c;
						q.push(v); 
						int index = d[1] - d[t];//获得当前步数对应的下标
						if (res[index] == 0)res[index] = min_col;
						else res[index] = min(res[index], min_col);//获取最小颜色 
					}
				}
			}
		}
		else				//从终点开始的
		{
			for (int i = 0; i < edge[t].size(); i++)
			{
				int v = edge[t][i].v;
				if (!vis[v] && !inque[v])//既没有被访问过也不在队列中
				{
					d[v] = d[t] + 1;
					vis[v] = true; inque[v] = true;
					q.push(v);
				}
			}
		}
	}
}

void find()
{
	bfs(n, 0); //从终点开始倒着bfs一次，得到每个点到终点的距离
	memset(vis, false, sizeof(vis));
	memset(inque, false, sizeof(inque));
	bfs(1, 1);  //从起点开始正着寻找最短路径
	cout << d[1] << endl;
	for (int i = 0; i < d[1]; i++)
	{
		if (i != 0)
			cout << " ";
		cout << res[i];
	}
	cout << endl;
}
		
void init()
{
	memset(d, 0, sizeof(d));
	memset(res, 0, sizeof(res));
	for (int i = 1; i<=n; i++)edge[i].clear();
}
