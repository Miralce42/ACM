//E9-4 UVa116  AC 
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 100 + 5;
const int MAXM = 10 + 5;
const int INF = 1 << 30;

int d[MAXM][MAXN], matrix[MAXM][MAXN], row[MAXN];
int m, n;

bool if_this(int r ,int c ,int last)//判断该列是不是取该
{
	int last_row = row[c - 1];
	return (r == ((last_row + m - 1) % m) || r == ((last_row + 1) % m) || r == last_row) && last == (d[r][c] + matrix[row[c - 1]][c - 1]);
}

void print_ans(int last)		//打印路径 ，last上一列的最对应的路径最小值 
{
	cout << row[0] + 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (if_this(j, i, last)) {//如果上一列的最小值等于该点的d值加上一列求得最小值所在的点的值，说明找到该列的取最小值的位置 
				row[i] = j;	last = d[j][i];
				cout << " " << row[i] + 1;
				break; 
			}
		}
	}
}

int dp(int r, int c)		//dp搜素 
{
	if (d[r][c] < INF ) return d[r][c];
	d[r][c] = matrix[r][c];	
	if (c < n-1) {				//判断是否为边界 
		int up = dp((r + m -1 ) % m , c + 1);//计算三个方向上的最小值 
		int down = dp((r + 1 )% m, c + 1);
		int mid = dp(r, c + 1);
		int min_d = min(up,mid );
		d[r][c] = d[r][c] + min(min_d, down);//取最小值 
	}
	return d[r][c];
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	while (cin >> m >> n) {				//输入并初始化d 
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
				d[i][j] = INF;
			}
		}
		int min_len = INF;
		for (int i = 0; i < m; i++){	//对第一列的每个点进行dp，寻找最小值 
			if (dp(i, 0) < min_len) {
				min_len = dp(i, 0);
				row[0] = i;
			}
		}
		print_ans(min_len);		//打印路径 
		cout << endl << min_len << endl;
	}
	return 0;
}
