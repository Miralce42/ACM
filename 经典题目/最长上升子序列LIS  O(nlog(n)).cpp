#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 100000 + 10;

int n, list[MAXN], d[MAXN];//d(i):长度为i的最长上升子序列的最小末尾

int main()
{
	while (cin >> n) {
		for (int i = 1; i <= n; i++) cin >> list[i];
		list[0] = -1; d[0] = -1;
		int len = 0;
		for (int i = 1; i <= n; i++) {
			if (list[i] != d[len]) {
				int pos = lower_bound(d + 1, d + len + 1, list[i]) - d;
				d[pos] = list[i];
				if (list[i] > d[len]) len++;
			}
		}
		cout << len << endl;
	}
	return 0;
}
