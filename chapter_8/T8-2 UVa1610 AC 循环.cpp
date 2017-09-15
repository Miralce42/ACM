#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 1000 + 10;

string name[MAXN], str1, str2;
int n;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (cin >> n && n) {
		string ans, temp;
		for (int i = 0; i < n; i++) cin >> name[i];//input
		sort(name, name + n);						//sorting all the strings by ascending order
		str1 = name[n / 2 - 1]; str2 = name[n / 2];	//selecting middle two string£¬smaller to str1 ,bigger to str2
		bool find_ok = false;
		for (int i = 0; i < str1.length(); i++) {
			for (int j = 0; j < 26; j++) {
				temp =ans + char(j + 65);
				if (temp >= str1 && temp < str2) {
					ans = temp;
					find_ok = true; break;
				}
			}
			if (find_ok) break;
			temp = ans += str1[i];
		}
		cout << ans<< endl;
	}
	return 0;
}
