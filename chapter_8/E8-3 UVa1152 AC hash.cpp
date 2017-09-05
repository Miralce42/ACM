//UVa1152 AC hash E8-3 不是很懂hash 
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 4000 + 100;

struct Hash_map
{
	static const int mask = 0x7fffff;
	int p[mask + 1], q[mask + 1];
	void clear(){
		memset(q, 0, sizeof(q));
	}
	int& operator [](int k){
		int i;
		for (i = k&mask; q[i] && p[i] != k; i = (i + 1)&mask);//不是很懂，还要继续就修炼啊 
		p[i] = k;
		return q[i];
	}
};

int num[4][MAXN];
Hash_map hsh;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n, m;
	cin >> n;
	while (n--) {
		int cnt = 0;
		cin >> m;
		hsh.clear();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < 4; j++)
				cin >> num[j][i];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				hsh[num[0][i] + num[1][j]]++;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				cnt += hsh[-num[2][i] - num[3][j]];
		cout << cnt << endl;
		if (n != 0) cout << endl;
	}
	return 0;
}
