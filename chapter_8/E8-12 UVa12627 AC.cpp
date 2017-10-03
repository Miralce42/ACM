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
	if (k == 0) return 1;		//��k=1ʱ��f(k,r) = 1
	int n = pow(2, k - 1);		
	//��i >= 2^(k-1),f(k,r) = f(k - 1,i - 2^(k-1)) + 2*c(k-1) ������c(k) = pow(3,k):ÿ��һ����Ķ���������
	if (r >= n) return f(k - 1, r - n) + 2 * pow(3, k - 1);
	else return 2 * f(k - 1, r);		//i < 2^(k-1) ,f(k,r) = 2 * f(k-1,r)
}
