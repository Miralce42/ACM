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

int d[MAXT][MAXS];//用来表示在i时刻，在j车站（编号1-n），最少还需要等待多长时间
int has_train[MAXT][MAXS][2];//用来表示在i时刻，在j车站，此时是否有车
int n, T, train_num[2], depart_t[2][MAXT], travel_t[MAXS];//n:站台总数  T:预定到达时间   train_num:起点和终点各自的发车辆
// depart_t[2][MAXT]:发车时间   travel_t[MAXS]：从i站到下一个站牌需要的时间

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
	for (int i = 1; i <= n - 1; i++)	d[T][i] = INF;//初始化d
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
	travel_t[0] = travel_t[n] = 0;			//赋值0，方便之后计算
	//读取正向的发车时间表，并计算has_train[][][0]
	cin >> train_num[0];
	for (int i = 1; i <= train_num[0]; i++) { 
		cin >> depart_t[0][i]; time = depart_t[0][i];
		for (int j = 0; j < n - 1; j++) {//j:站牌
			time += travel_t[j];//第i辆车到  j+1  站牌时的时间
			if(time <= T) has_train[time][j + 1][0] = 1;
		}
	}
	//读取反向的发车时间表，并计算has_train[][][1]
	cin >> train_num[1];
	for (int i = 1; i <= train_num[1]; i++) {
		cin >> depart_t[1][i]; time = depart_t[1][i];
		for (int j = n; j > 1; j--) {//j:站牌,倒叙
			time += travel_t[j];//第i辆车到  j  站牌时的时间
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
					cout <<k<< " 方向:  time: " << i << " ,station: " << j << endl;
				}
			}
		}
	}
}
