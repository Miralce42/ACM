#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	long long a, b;
	cin >> a >> b;
	int sum = a + b;
	if(sum < 0){
		cout << "-";
		sum = -sum;
	}
	stringstream ss;
	ss << sum;
	string s;
	s = ss.str();
	int len = s.length();
	int num = len;
	if (a + b < 0) num++;
	for (int i = 0; i < len; i++) {
		if ((len - i) % 3 == 0 && i != 0) cout << ",";
		cout << s[i];
	}
	cout << endl;
	return 0;
}