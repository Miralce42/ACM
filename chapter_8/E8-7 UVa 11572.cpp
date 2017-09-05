//E8-7 UVa11572 AC teacher
#include<iostream>
#include<set>

using namespace std;

const int MAXN = 1000000 + 10;

int num[MAXN];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n; cin >> n;
	while (n--) {
		set<int> s;
		int m; cin >> m;
		int L, R,max; max = L = R = 0;
		for (int i = 0; i < m; i++ ) {
			cin >> num[i];
		}
		while(R < m){
			while(R < m && !s.count(num[R])) 
				s.insert(num[R++]);
			max = max > R - L ? max : R - L;
			s.erase(num[L++]);
		}
		cout << max << endl;
	}
	return 0;
}
