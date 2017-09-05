//UVa524-AC-P194-E7-4 
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

bool is_prime(int n);
void solve(int cur);

const int MAXN = 16 + 4;

int order[MAXN], vis[MAXN];//order�������洢���У���¼��i��λ�õ���ֵ��vis����¼i�Ƿ����Ѿ���order��
int n;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int kase = 0;
	while (cin >> n) {
		if (kase++) cout << endl;
		cout << "Case " << kase << ":\n";
		memset(vis, 0, sizeof(vis));	//ÿһ�ֶ�Ҫ��ʼ��vis 
		order[1] = 1;
		solve(2);
	}
	return 0;
}

void solve(int cur) 
{
	if (cur == n+1 && is_prime(order[1]+order[n])) { 	//���֮ǰҪ�ж� order[1]+order[n]�Ƿ�Ϊ���� 
		for (int i = 1; i <= n; i++) {
			if (i != 1) cout << " ";
			cout << order[i];
		}
		cout << endl;
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (!vis[i] && is_prime(order[cur-1]+i)) { 	//�ȷ����������ֲ��ڻ��� 
				vis[i] = 1;
				order[cur] = i;
				solve(cur+1);
				vis[i] = 0;				//Ҫ�ָ�ȫ�ֱ��� 
			}
		}
	}
}

bool is_prime(int n)					//�ж��Ƿ�Ϊ������α�� 
{
	for (int i = 2; i <= sqrt(n)+1; i++)
		if (n%i == 0) return false;
	return true;
}
