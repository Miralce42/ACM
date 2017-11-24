#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

typedef pair<string, int> P;

int cmp(const P x, const P y) {//编写排序方法
	return x.second > y.second;
}

int main()
{
	map<string,int> w_Map;
	string word;
	while (cin >> word) {	    //读取文章
		char letter = word[word.length() - 1];
		if (letter == ',' || letter == '.') {	//提取单词
			word.erase(word.length() - 1, 1);
		}
		if (!w_Map.count(word)) w_Map[word] = 0;
		w_Map[word]++;
	}
	//由于map不能直接使用value排序，
	//需要将map中的key和value分别存放在一个pair类型的vector中，
	vector<P> pair_vec;
	for (map<string, int>::iterator it = w_Map.begin(); it != w_Map.end(); it++) {
		pair_vec.push_back(make_pair(it->first, it->second));
	}
	//然后利用vector的sort函数排序
	sort(pair_vec.begin(), pair_vec.end(), cmp);
	//最后输出前十个
	int cnt = 10;
	for (vector<P>::iterator vec_it = pair_vec.begin(); vec_it != pair_vec.end(); vec_it++) {
		cout << vec_it->first << " " << vec_it->second << endl;
		if (--cnt == 0) break;
	}
	return 0;
}