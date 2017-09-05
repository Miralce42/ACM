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

bool if_this(int r ,int c ,int last)//�жϸ����ǲ���ȡ��
{
	int last_row = row[c - 1];
	return (r == ((last_row + m - 1) % m) || r == ((last_row + 1) % m) || r == last_row) && last == (d[r][c] + matrix[row[c - 1]][c - 1]);
}

void print_ans(int last)		//��ӡ·�� ��last��һ�е����Ӧ��·����Сֵ 
{
	cout << row[0] + 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (if_this(j, i, last)) {//�����һ�е���Сֵ���ڸõ��dֵ����һ�������Сֵ���ڵĵ��ֵ��˵���ҵ����е�ȡ��Сֵ��λ�� 
				row[i] = j;	last = d[j][i];
				cout << " " << row[i] + 1;
				break; 
			}
		}
	}
}

int dp(int r, int c)		//dp���� 
{
	if (d[r][c] < INF ) return d[r][c];
	d[r][c] = matrix[r][c];	
	if (c < n-1) {				//�ж��Ƿ�Ϊ�߽� 
		int up = dp((r + m -1 ) % m , c + 1);//�������������ϵ���Сֵ 
		int down = dp((r + 1 )% m, c + 1);
		int mid = dp(r, c + 1);
		int min_d = min(up,mid );
		d[r][c] = d[r][c] + min(min_d, down);//ȡ��Сֵ 
	}
	return d[r][c];
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	while (cin >> m >> n) {				//���벢��ʼ��d 
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
				d[i][j] = INF;
			}
		}
		int min_len = INF;
		for (int i = 0; i < m; i++){	//�Ե�һ�е�ÿ�������dp��Ѱ����Сֵ 
			if (dp(i, 0) < min_len) {
				min_len = dp(i, 0);
				row[0] = i;
			}
		}
		print_ans(min_len);		//��ӡ·�� 
		cout << endl << min_len << endl;
	}
	return 0;
}
