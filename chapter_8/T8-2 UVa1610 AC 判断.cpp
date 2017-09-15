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
		for (int i = 0; i < n; i++) cin >> name[i];//input
		sort(name, name + n);						//sorting all the strings by ascending order
		str1 = name[n / 2 - 1]; str2 = name[n / 2];	//selecting middle two string£¬smaller to str1 ,bigger to str2
		for (int i = 0; i < str1.length() && i < str2.length(); i++) {
			if (str1[i] == str2[i]) cout << str1[i];
			else {
				if (i == str1.length() - 1) cout << str1[i];
				else if (str2[i] - str1[i] > 1 || i != str2.length() - 1) cout << (char)(str1[i] + 1);
				else {
					cout << str1[i];
					for (int j = i+1; j < str1.length(); j++) {
						 if(j == str1.size() - 1) {  
                            cout << str1[j];  
                            break;  
                        }  
                        if(str1[j] != 'Z') {  
                            cout << (char)(str1[j] + 1);
                            break;  
                        }  
                        cout << 'Z'; 
					}
				}
				break;
			}
		}
		cout << endl;
	}
	return 0;
}
