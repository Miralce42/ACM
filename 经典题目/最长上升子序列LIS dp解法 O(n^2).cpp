#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 100000 + 10;

int n, list[MAXN], d[MAXN];//d(i):以i结尾的最长上升子序列的长度
//转移方程d(i) = max{0,d(j)|i >j,Ai > Aj}+1

int dp()
{
	int max_len = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (list[j + 1] > list[j])
				d[i] = max(0, d[j]) + 1;
		}
		max_len = max(max_len, d[i]);
	}
	return max_len;
}

int main()
{
	while (cin >> n) {
		for (int i = 1; i <= n; i++) cin >> list[i];
		list[0] = -1; d[0] = 0;
		cout << dp() << endl;
	}
	return 0;
}
