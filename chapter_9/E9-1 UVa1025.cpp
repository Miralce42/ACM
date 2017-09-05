#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void read();
void init();
void test();
void dp();

const int MAXS = 50 + 5;
const int MAXT = 200 + 10;
const int INF = 1000000000;

int d[MAXT][MAXS];//������ʾ��iʱ�̣���j��վ�����1-n�������ٻ���Ҫ�ȴ��೤ʱ��
int has_train[MAXT][MAXS][2];//������ʾ��iʱ�̣���j��վ����ʱ�Ƿ��г�
int n, T, train_num[2], depart_t[2][MAXT], travel_t[MAXS];//n:վ̨����  T:Ԥ������ʱ��   train_num:�����յ���Եķ�����
// depart_t[2][MAXT]:����ʱ��   travel_t[MAXS]����iվ����һ��վ����Ҫ��ʱ��

int main()
{
	int kase = 0;
	while (cin >> n && n) {
		init();
		read();
		//test();
		dp();
		cout << "Case Number " << ++kase << ": ";
		if (d[0][1] >= INF) cout << "impossible" << endl;
		else cout << d[0][1] << endl;
	}
	return 0;
}

void dp()
{
	for (int i = 1; i <= n - 1; i++)	d[T][i] = INF;//��ʼ��d
	d[T][n] = 0;
	for (int i = T - 1; i >= 0; i--) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = d[i + 1][j] + 1;
			if (j < n && has_train[i][j][0] && i + travel_t[j] <= T)
				d[i][j] = min(d[i][j], d[i + travel_t[j]][j + 1]);
			if (j > 1 && has_train[i][j][1] && i + travel_t[j - 1] <= T)
				d[i][j] = min(d[i][j], d[i + travel_t[j - 1]][j - 1]);
		}
	}

}

void read()
{	
	int time = 0;
	cin >> T;
	for (int i = 1; i <= n - 1; i++) cin >> travel_t[i];
	travel_t[0] = travel_t[n] = 0;			//��ֵ0������֮�����
	//��ȡ����ķ���ʱ���������has_train[][][0]
	cin >> train_num[0];
	for (int i = 1; i <= train_num[0]; i++) { 
		cin >> depart_t[0][i]; time = depart_t[0][i];
		for (int j = 0; j < n - 1; j++) {//j:վ��
			time += travel_t[j];//��i������  j+1  վ��ʱ��ʱ��
			if(time <= T) has_train[time][j + 1][0] = 1;
		}
	}
	//��ȡ����ķ���ʱ���������has_train[][][1]
	cin >> train_num[1];
	for (int i = 1; i <= train_num[1]; i++) {
		cin >> depart_t[1][i]; time = depart_t[1][i];
		for (int j = n; j > 1; j--) {//j:վ��,����
			time += travel_t[j];//��i������  j  վ��ʱ��ʱ��
			if (time <= T) has_train[time][j][1] = 1;
		}
	}
}

void init()
{
	memset(has_train, 0, sizeof(has_train));
}

void test()
{
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < T; i++){
			for (int j = 1; j <= n; j++) {
				if (has_train[i][j][k]) {
					cout <<k<< " ����:  time: " << i << " ,station: " << j << endl;
				}
			}
		}
	}
}
