//ʱ��̫���� 
#include<iostream>
#include<cstring>
#include<queue>
#include<set>

using namespace std;

int bfs();

const int MAXN = 1000000;
const int SIZE = 9;
struct states
{
	int state[SIZE];
	int dis;
};

states st, goal;
set<int> myArray;	//��������

const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

int main()
{
	for (int i = 0; i < SIZE; i++) cin >> st.state[i];
	for (int i = 0; i < SIZE; i++) cin >> goal.state[i];
	st.dis = 0;
	cout << bfs() <<endl;
	return 0;
}

int bfs()
{
	freopen("input.txt","r",stdin);
	myArray.clear();
	queue<states> q;
	q.push(st);
	int x = 0;
	for (int i = 0; i < SIZE; i++) x = x * 10 + st.state[i];
	myArray.insert(x);
	while (q.size()) {
		states s, t;
		memcpy(&s, &q.front(), sizeof(q.front()));
		memcpy(t.state, s.state, sizeof(t.state));
		q.pop();
		if (memcmp(goal.state, s.state, sizeof(goal.state)) == 0) return s.dis ;//memcmp��ͬ����0
		int k;
		for (k = 0; k < SIZE; k++) if (!s.state[k]) break;
		for (int i = 0; i < 4; i++) {
			int newx = k / 3; int newy = k % 3;
			newx = newx + dx[i];
			newy = newy + dy[i];
			if (newx < 0 || newx > 2|| newy < 0 || newy > 2) continue;
			int n = newx * 3 + newy;
			t.state[k] = t.state[n]; t.state[n] = 0;
			x = 0;
			for (int i = 0; i < SIZE; i++) x = x * 10 + t.state[i];
			if (!myArray.count(x)) {	//��ֹ�ظ�����
				t.dis = s.dis + 1;
				myArray.insert(x);
				q.push(t);
			}
			t.state[n] = t.state[k]; t.state[k] = 0;//��ԭt
		}
	}
	return -1;
}
