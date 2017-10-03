#include<iostream>
#include<cmath>

using namespace std;

long long f(int k, int r);

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, kase = 0;
	cin >> T;
	while (T--) {
		int k, a, b;
		cin >> k >> a >> b;
		cout << "Case " << ++kase << ": " << f(k, b) - f(k, a - 1) << endl;
	}
	return 0;
}

long long f(int k, int r)
{
	if (r <= 0) return 0;
	if (k == 0) return 1;		//当k=1时，f(k,r) = 1
	int n = pow(2, k - 1);		
	//当i >= 2^(k-1),f(k,r) = f(k - 1,i - 2^(k-1)) + 2*c(k-1) ，其中c(k) = pow(3,k):每次一个红的都会变成三个
	if (r >= n) return f(k - 1, r - n) + 2 * pow(3, k - 1);
	else return 2 * f(k - 1, r);		//i < 2^(k-1) ,f(k,r) = 2 * f(k-1,r)
}
