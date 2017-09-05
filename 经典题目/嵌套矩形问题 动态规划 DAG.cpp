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
		crt_adj_table();//���������޻�ͼ���ڽӾ��� 
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

//������i��ͷ���������Ŀ
int dp(int i)
{
	int &ans = d[i];//��d[i]ʹ�����õĸ�ֵ��ans��ʹ����Ϊ��Ϊ�˸ı�ans��ͬʱ�ı�d[i];
	if (ans > 0) return ans;//���d[i]>0˵����d[i]�Ѿ�������Ѿ�����i��ͷ���������Ŀ������ֱ��ʹ��
	ans = 1;			//d�ĳ�������Ϊ1��û��Ƕ��ֻ��һ����ʱ��
	for (int j = 1; j <= n; j++) {//��ÿһ������j������ѭ��
		if (G[i][j])			//��i�Ƿ���Ƕ����j��
			ans = max(ans, dp(j) + 1);//�������ȡ��ǰd[i]��j�����һ������Ǹ�
	}
	return ans;//���ؽ��
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
