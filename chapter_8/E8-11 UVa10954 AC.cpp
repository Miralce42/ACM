// E8-11 UVa10954 AC 哈夫曼树 
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct cmp {
	bool operator ()(int x, int y){
		return x > y;//小的优先级高  
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	while (cin >> n && n) {
		priority_queue<int, vector<int>, cmp> pq;
		int sum = 0;
		while (n--) { 
			int x; cin >> x;
			pq.push(x);
		}
		while (pq.size() > 1) {
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			int c = a + b;
			sum += c;
			pq.push(c);
		}
		cout << sum << endl;
	}
	return 0;
}
