#include<iostream>
#include<cstring>
#include<map>

using namespace std;

void dfs(int city, int len, int num);

const int MAXN = 500 + 5;
const int INF = 0x7fffffff;

int vis[MAXN], road[MAXN][MAXN], hands[MAXN];
int  n, m, og, des, min_len_num = INF;
map<int, int> shorst_road, max_hands;

int main()
{
	memset(road, 0, sizeof(road));
	memset(vis, 0, sizeof(vis));
	cin >> n >> m >> og >> des;
	for (int i = 0; i < n; i++)cin >> hands[i];
	for (int i = 0; i < m; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		road[a][b] = l; road[b][a] = l;
	}
	dfs(og, 0, 0);
	cout << shorst_road[min_len_num] << " " << max_hands[min_len_num];
	shorst_road.clear(); max_hands.clear();
	return 0;
}

void dfs(int city, int len, int num)
{
	if (city == des) {
		if (len <= min_len_num) {
			min_len_num = len;
			if (shorst_road.count(len) == 0) {
				shorst_road[len] = 0;
				max_hands[len] = 0;
			}
			shorst_road[len]++;
			if (num + hands[des] > max_hands[len]) max_hands[len] = num + hands[des];
		}
		return;
	}
	vis[city] = 1;
	for (int i = 0; i < n; i++) {
		if (!vis[i] && road[city][i] != 0) {
			dfs(i, len + road[city][i], num + hands[city]);
		}
	}
	vis[city] = 0;
}
