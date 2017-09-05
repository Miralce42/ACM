#include<iostream>
#include<algorithm>

using namespace std;

void dp(int s, int n);
void print_ans(int * d, int s);

const int MAXS = 100 + 10;
const int MAXN = 10000 + 10;
const int INF = 0x7fffffff;

int v[MAXS], max_num[MAXN], min_num[MAXN], minv[MAXN], maxv[MAXN];

int main()
{
	int n, s; cin >> n;
	for (int i = 1; i <= n; i++) cin >> v[i];
	while (cin >> s) {
		dp(s, n);
		print_ans(min_num, s);
		cout << endl;
		print_ans(max_num, s);
	}
	return 0;
}

void dp(int s, int n)
{
	for (int i = 0; i <= s; i++) {
		minv[i] = INF; maxv[i] = -INF;
		min_num[i] = max_num[i] = 0;
	}
	maxv[0] = minv[0] = 0;
	for (int i = 1; i <= s; i++) {
		for (int j = 1; j <= n; j++) {
			if (i <= v[j] && minv[i] > minv[i - v[j]] + 1) {
				minv[i] = minv[i - v[j]] + 1;
				min_num[i] = j;
			}
			if (i <= v[j] && maxv[i] < maxv[i - v[j]] + 1) {
				maxv[i] = maxv[i - v[j]] + 1;
				max_num[i] = j;
			}
		}
	}
}

void print_ans(int * d ,int s)
{
	while (s) {
		cout << v[d[s]] << " ";
		s -= v[d[s]];
	}
}
