//UVA1599 ����ͨ�����ύWA 
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
	int v, c;		//�ñߵ���һ���˵㣬����ɫ
	Node(int v,int c):v(v),c(c){}
};

vector<Node> edge[MAXN];	//ʹ���ڽӱ�洢���бߣ��Ի����⣩
int d[MAXN], res[MAXN];		//d���ڴ洢ÿ���㵽�յ�N��·�����ȣ�res�������·������ɫ
bool vis[MAXN], inque[MAXN];//vis��ʾv���Ƿ񱻷��ʹ�,inque����ǰ�õ��Ƿ��ڶ����У���ֹ�ظ��������
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
				int c = edge[t][i].c;		//����㿪ʼ��
				if (c == min_col && 1 == d[t] - d[v])//����㿪ʼ������ÿ�ξ����1�ķ���Ѱ�ҽ������ĵ�ı��,
				{				   					 //��ʱֻ�ü�鲽���Ƿ����1����ɫ�ǲ�����С�����ü����ջ���Ƿ����
					if (c <= min_col)			//����ɫ��С��·��push��������
					{
						min_col = c;
						q.push(v); 
						int index = d[1] - d[t];//��õ�ǰ������Ӧ���±�
						if (res[index] == 0)res[index] = min_col;
						else res[index] = min(res[index], min_col);//��ȡ��С��ɫ 
					}
				}
			}
		}
		else				//���յ㿪ʼ��
		{
			for (int i = 0; i < edge[t].size(); i++)
			{
				int v = edge[t][i].v;
				if (!vis[v] && !inque[v])//��û�б����ʹ�Ҳ���ڶ�����
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
	bfs(n, 0); //���յ㿪ʼ����bfsһ�Σ��õ�ÿ���㵽�յ�ľ���
	memset(vis, false, sizeof(vis));
	memset(inque, false, sizeof(inque));
	bfs(1, 1);  //����㿪ʼ����Ѱ�����·��
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
