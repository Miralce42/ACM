#include<iostream>
#include<cmath>

using namespace std;

const double p = pow(10, -15);
const int MAXN = 10000;

int main()
{
	//freopen("input.txt","r",stdin); 
	//freopen("output.txt","w",stdout);
	int n;
	while (cin >> n) {
		int cnt = 0;
		int x[MAXN], y[MAXN]; 
		int j = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			double num = i*n*1.0 / (i - n);
			if (num - (int)num < p) {
				y[j] = i; x[j] = (int)num;
				cnt++; j++;
			}
		}
		cout << cnt << endl;
		for (int i = 0; i < cnt; i++) cout << "1/" << n << " = 1/" << x[i] << " + 1/" << y[i] << endl;
	}
	return 0;
}

