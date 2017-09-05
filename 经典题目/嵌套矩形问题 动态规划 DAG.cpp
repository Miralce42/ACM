#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void show();
void crt_adj_table();
bool if_contain(int a, int b, int c, int d);
int dp(int i);
void print_ans(int i);


const int MAXN = 1000 + 10;

int rec[2][MAXN], G[MAXN][MAXN], d[MAXN];
int n, m;

int main()
{
	cin >> m;
	while (m--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> rec[0][i] >> rec[1][i];
		}
		memset(G, 0, sizeof(G));
		crt_adj_table();//构造有向无环图的邻接矩阵 
						//show(n);
		dp(1);
		print_ans(1);
	}
	return 0;
}

void print_ans(int i)
{
	cout << i << " : " << rec[0][i] << " " << rec[1][i] << endl;
	for (int j = 1; j <= n; j++) {
		if (G[i][j] && d[i] == d[j] + 1) {
			print_ans(j);
			break;
		}
	}
}

//计算以i开头的最长矩阵数目
int dp(int i)
{
	int &ans = d[i];//将d[i]使用引用的赋值给ans，使用因为是为了改变ans的同时改变d[i];
	if (ans > 0) return ans;//如果d[i]>0说明，d[i]已经求出，已经是以i开头的最长矩阵数目，可以直接使用
	ans = 1;			//d的长度至少为1，没有嵌套只有一个的时候
	for (int j = 1; j <= n; j++) {//对每一个矩形j都进行循环
		if (G[i][j])			//看i是否能嵌套在j中
			ans = max(ans, dp(j) + 1);//如果可以取当前d[i]和j的最长加一更大的那个
	}
	return ans;//返回结果
}

void show()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
}

void crt_adj_table()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j &&if_contain(rec[0][i], rec[1][i], rec[0][j], rec[1][j]))
				G[i][j] = 1;
		}
	}
}

bool if_contain(int a, int b, int c, int d)
{
	return (a < c && b < d) || (a < d && b < c);
}
