#include<iostream>
#include<cstring> 
#include<algorithm>

using namespace std;

const int MAXN = 4000 + 100;

int num[4][MAXN], sum[MAXN*MAXN];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n, m;
	cin >> n;
	while (n--) {
		int cnt = 0;
		cin >> m;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < 4; j++)
				cin >> num[j][i];
		int k = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				sum[k++] = num[0][i] + num[1][j];
		sort(sum, sum + k);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				cnt += upper_bound(sum, sum + k, -num[2][i] - num[3][j]) - lower_bound(sum, sum + k, -num[2][i] - num[3][j]);
		cout << cnt << endl;
		if (n != 0) cout << endl;
	}
	return 0;
}
