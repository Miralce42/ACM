#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 30 + 5;

int cube[MAXN][3];
int d[MAXN][3], n;

bool can_stack(int a ,int b,int c,int d)//�жϣ�c��d��״̬�ܲ��ܷ��ڣ�a��b��״̬֮��
{
	int p[2], q[2], j = 0, k = 0;//p����, q���ϱ�
	for (int i = 0; i < 3; i++) {
		if (i != b) p[j++] = cube[a][i];
		if (i != d) q[k++] = cube[c][i];
	}
	return q[0] < p[0] && q[1] < p[1];//�ϸ�С��,�����Ѿ����������������˳��Ƚ�
}

//������d(a,b)Ϊ�׵�״̬�����߶ȣ��Է���a�ĵ�b���߳�Ϊ��,����������ΪΪ�׵�״̬
int dp(int a,int b)
{
	if (d[a][b] > 0) return d[a][b];	//�Ѹ�״̬Ϊ��ʼ�����߶��Ѿ��ҵ�
	d[a][b] = cube[a][b];
	for (int i = 0; i < n; i++) 		
		for (int j = 0; j < 3; j++) 
			if (can_stack(a, b, i, j)) 
				d[a][b] = max(d[a][b], dp(i, j) + cube[a][b]);
	return d[a][b];
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int kase = 0;
	while (cin >> n && n) {
		for (int i = 0; i < n; i++) {//���룬����ÿ��������ı߳���������
			for (int j = 0; j < 3; j++) {
				cin >> cube[i][j];
			}
			sort(cube[i], cube[i] + 3);
		}
		memset(d, 0, sizeof(d));
		int max_hgt = 0;
		for (int i = 0; i < n; i++) 	//��ÿ��״̬����dp
			for (int j = 0; j < 3; j++) 
				max_hgt = max(max_hgt, dp(i, j));
		cout << "Case " << ++kase << ": maximum height = " << max_hgt << endl;
	}
	return 0;
}
