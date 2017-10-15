#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

const int MAXN = 1000 + 5;
const double esp = 0.04;

double ans[MAXN] = { 0 };

void input()
{
	int num, ex;
	double co;
	cin >> num;
	while (num--) {
		cin >> ex >> co;
		ans[ex] += co;
	}
}

int main()
{	
	input();
	input();
	int cnt = 0;
	for (int i = 0; i < MAXN; i++) {
		if (fabs(ans[i]) > esp) cnt++;
	}
	printf("%d", cnt);
	for (int i = 1000; i >= 0; i--) {
		if (fabs(ans[i]) > esp)	printf(" %d %0.1lf", i, ans[i]);
	}
	printf("\n");
	return 0;
}

