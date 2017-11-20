#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

const int MAXN = 2000 + 10;
const double esp = 0.04;

int n[10 + 1];
double a[MAXN], ans[MAXN];

int input(int k)
{
	int m, exp;
	double coe;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> exp >> coe;
		if (!k) {
			n[i] = exp;
			a[exp] = coe;
			continue;
		}
		for (int j = 0; j < k; j++) {
			ans[exp + n[j]] += coe * a[n[j]];
		}
	}
	return m;
}

int main()
{
	int cnt = 0;
	memset(ans, 0, sizeof(ans));
	int k = input(0);
	input(k);
	for (int i = 0; i < MAXN; i++)
		if (abs(ans[i]) > esp)
			cnt++;
	printf("%d", cnt);
	for (int i = MAXN - 1; i >= 0; i--) {
		if (abs(ans[i]) > esp) {
			printf(" %d %0.1lf", i, ans[i]);
		}
	}
	return 0;
}