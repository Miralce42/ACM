#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

using namespace std;

map<string, int> words;
vector<pair<string, int>> list;

int cmp(const pair<string, int> &a, const pair<string, int> &b) {
	if (a.second == b.second) {
		a.first > b.first;
	}
	return a.second > b.second;
}

int main()
{
	string str;
	while (cin >> str && str != "") {
		int last = str.length() - 1;
		if (str[last] == ',' || str[last] == '.') {
			str = str.substr(0, last);
		}
		if (words.count(str) == 0) words[str] = 0;
		words[str]++;
	}

	for (map<string, int>::iterator iter = words.begin(); iter != words.end(); iter++) {
		list.push_back(make_pair(iter->first, iter->second));
	}

	sort(list.begin(), list.end(),cmp);

	for (int i = 0; i < 10; i++) {
		cout << list[i].first << " " << list[i].second << endl;
	}
	return 0;
}
