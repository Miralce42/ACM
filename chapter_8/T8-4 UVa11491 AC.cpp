//T8-4 UVa11491 AC
//每次判断当前数值与其之前数组的大小关系，小于的删去 
//删除数达到之后退出，若到最后一个元素仍然还有删除数，则优先输出前边的数字 
#include<iostream>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m; string s;
	while(cin >> n >> m && n){
		cin >> s;
		int cnt = n - m;
		for (int i = 0; i < n; i++) {
			if (!m)break;
			for (int j = i - 1; j >= 0; j--) {
				if (s[i] > s[j]) {
					if (s[j] != ' ')m--;
					s[j] = ' ';
					if (!m) break;
				}
				else break;
			}
		}
		for (int i = 0; i < n && cnt; i++) {
			if (s[i] != ' ') {
				cout << s[i]; cnt--;
			}
		}
		cout << endl;
	}
	return 0;
}
