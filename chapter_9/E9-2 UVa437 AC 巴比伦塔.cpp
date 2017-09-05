#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 30 + 5;

int cube[MAXN][3];
int d[MAXN][3], n;

bool can_stack(int a ,int b,int c,int d)//判断（c，d）状态能不能放在（a，b）状态之上
{
	int p[2], q[2], j = 0, k = 0;//p：底, q：上边
	for (int i = 0; i < 3; i++) {
		if (i != b) p[j++] = cube[a][i];
		if (i != d) q[k++] = cube[c][i];
	}
	return q[0] < p[0] && q[1] < p[1];//严格小于,由于已经排序，所以无需调换顺序比较
}

//计算以d(a,b)为底的状态的最大高度：以方块a的第b个边长为高,其他两条边为为底的状态
int dp(int a,int b)
{
	if (d[a][b] > 0) return d[a][b];	//已该状态为起始的最大高度已经找到
	d[a][b] = cube[a][b];
	for (int i = 0; i < n; i++) 		
		for (int j = 0; j < 3; j++) 
			if (can_stack(a, b, i, j)) 
				d[a][b] = max(d[a][b], dp(i, j) + cube[a][b]);
	return d[a][b];
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int kase = 0;
	while (cin >> n && n) {
		for (int i = 0; i < n; i++) {//输入，并对每个立方体的边长进行排序
			for (int j = 0; j < 3; j++) {
				cin >> cube[i][j];
			}
			sort(cube[i], cube[i] + 3);
		}
		memset(d, 0, sizeof(d));
		int max_hgt = 0;
		for (int i = 0; i < n; i++) 	//对每个状态进行dp
			for (int j = 0; j < 3; j++) 
				max_hgt = max(max_hgt, dp(i, j));
		cout << "Case " << ++kase << ": maximum height = " << max_hgt << endl;
	}
	return 0;
}
