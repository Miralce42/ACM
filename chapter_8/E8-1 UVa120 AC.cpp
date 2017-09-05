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
	for (int i = n - 1; i >= 0; i--) {//��ÿ��������������²��� 
		int max = find_max(i);//Ѱ��pc[0..i]���ֵ
		if (pc[i] != max) {//������ֵ�Ѿ�����ײ������ý����κβ���,���ڵĻ��������²��� 
			if (pc[0] != max){			//pc[0..i]�е����ֵ�Ȳ��ڵײ�Ҳ���ڶ��� 
				int j;
				for (j= i; j >= 0; j--) if (pc[j] == max) break;//���ҵ����ֵ���ڵ�λ�� 
				flip(j); cout << n - j << " ";					//��ת������ 
			}
			flip(i); cout << n - i << " ";					//���ֵ������������ֱ�ӷ�ת 
		}
	}
}

//��תpc[0]...pc[n]
void flip(int n)
{
	int mid = (n + 1) / 2;
	for (int i = 0, j = n; i < mid; i++, j--) {
		int t = pc[i]; pc[i] = pc[j]; pc[j] = t;
	}
}

//�ҵ�pc[0..n]�����ֵ
int find_max(int n)
{
	int max = -INF;
	for (int i = 0; i <= n; i++) max = max > pc[i] ? max : pc[i];
	return max;
}
