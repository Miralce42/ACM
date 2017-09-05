#include<iostream>
#include<sstream>
#include<string>

using namespace std;

void solve(int n);
void flip(int n);
int find_max(int n);

const int MAXN = 30;
const int INF = 0x7fffffff;

int pc[MAXN];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		int cnt = 0;
		while (ss >> pc[cnt++]);
		cout << s << endl;
		solve(cnt - 1);
		cout << "0\n";
	}
	return 0;
}

void solve(int n)
{
	for (int i = n - 1; i >= 0; i--) {//对每个煎饼都进行如下操作 
		int max = find_max(i);//寻找pc[0..i]最大值
		if (pc[i] != max) {//如果最大值已经在最底部，不用进行任何操作,不在的话进行如下操作 
			if (pc[0] != max){			//pc[0..i]中的最大值既不在底部也不在顶部 
				int j;
				for (j= i; j >= 0; j--) if (pc[j] == max) break;//先找到最大值所在的位置 
				flip(j); cout << n - j << " ";					//反转到顶部 
			}
			flip(i); cout << n - i << " ";					//最大值在在最顶部则可以直接反转 
		}
	}
}

//反转pc[0]...pc[n]
void flip(int n)
{
	int mid = (n + 1) / 2;
	for (int i = 0, j = n; i < mid; i++, j--) {
		int t = pc[i]; pc[i] = pc[j]; pc[j] = t;
	}
}

//找到pc[0..n]中最大值
int find_max(int n)
{
	int max = -INF;
	for (int i = 0; i <= n; i++) max = max > pc[i] ? max : pc[i];
	return max;
}
