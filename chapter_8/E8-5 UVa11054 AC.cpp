//E8-5 UVa11054 AC ɨ�跨 
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n, num, m = 0;
	while (cin >> n && n) {
		long long cnt = 0;
		while (n--) {
			cin >> num;
			m += num;
			cnt += abs(m);
		}
		cout << cnt << endl;
	}
	return 0;
}
