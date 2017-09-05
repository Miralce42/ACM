#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 50 + 5;
const int MAXT = 1000000 + 10;
const int INF = 1 << 30;

int d[MAXN][MAXT], time[MAXN];

bool cmp(int a, int b) { return a > b; }

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int m, n, t, kase = 0;
	cin >> m;
	while (m--) {
		cin >> n >> t;
		int used_time = 0, num = 0;
		for (int i = 1; i <= n; i++) cin >> time[i];
		sort(time + 1, time + n +1, cmp);
		for (int i = 0; i < t; i++) d[0][i] = -1;
		d[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			bool first = true;
			for (int j = 0; j <= t; j++) {
				if (j > time[i] && d[i - 1][j - time[i]] >= 0) {
					d[i][j] = max(d[i][j], d[i - 1][j - time[i]] + 1);
					if (d[i][j] == num + 1 && first) {
						num++; used_time += time[i]; first = false;
					}
				}
			}
		}
		cout <<"Case "<<++kase<<": "<< num + 1 <<" "<< used_time + 678<<endl;
	}
	return 0;
}

