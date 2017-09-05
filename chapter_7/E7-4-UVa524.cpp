//UVa524-AC-P194-E7-4 
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

bool is_prime(int n);
void solve(int cur);

const int MAXN = 16 + 4;

int order[MAXN], vis[MAXN];//order：用来存储序列，记录第i个位置的数值；vis来记录i是否在已经在order中
int n;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int kase = 0;
	while (cin >> n) {
		if (kase++) cout << endl;
		cout << "Case " << kase << ":\n";
		memset(vis, 0, sizeof(vis));	//每一轮都要初始化vis 
		order[1] = 1;
		solve(2);
	}
	return 0;
}

void solve(int cur) 
{
	if (cur == n+1 && is_prime(order[1]+order[n])) { 	//输出之前要判断 order[1]+order[n]是否为质数 
		for (int i = 1; i <= n; i++) {
			if (i != 1) cout << " ";
			cout << order[i];
		}
		cout << endl;
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (!vis[i] && is_prime(order[cur-1]+i)) { 	//既符合条件，又不在环中 
				vis[i] = 1;
				order[cur] = i;
				solve(cur+1);
				vis[i] = 0;				//要恢复全局变量 
			}
		}
	}
}

bool is_prime(int n)					//判断是否为素数（伪） 
{
	for (int i = 2; i <= sqrt(n)+1; i++)
		if (n%i == 0) return false;
	return true;
}
