#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	string numbers[] = {
		"zero","one","two","three","four","five","six","seven","eight","nine"
	};
	int sum = 0;
	string num = "";
	stringstream ss;
	char ch = getchar();
	while (ch != '\n') {
		sum += ch - '0';
		ch = getchar();
	}
	ss << sum;
	ss >> num;
	for (int i = 0; i < num.length(); i++) {
		if (i != 0) cout << " ";
		cout << numbers[num[i] - '0'];
	}
	cout << endl;
	return 0;
}