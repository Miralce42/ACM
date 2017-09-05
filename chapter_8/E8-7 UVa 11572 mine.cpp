//E8-7 UVa11572 WA mine,测试数据都正确 
#include<iostream>
#include<set>

using namespace std;

const int MAXN = 1000000 + 10;

int num[MAXN];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n; cin >> n;
	while (n--) {
		set<int> s;
		int m; cin >> m;
		int L, R ,max; max = L = R = 0;
		for (int i = 0; i < m; i++) {
			cin >> num[i];
			if (!s.count(num[i])) {
				R++;
				s.insert(num[i]);
				int d = R - L; 
				max = max > d ? max : d;
			}
			else {
				while (s.count(num[i])) 
					s.erase(num[L++]);
			}
		}
		cout << max << endl;
	}
	return 0;
}
