#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<set>

using namespace std;

const int NUM = 3;
const int INF = 0x7fffffff;

struct Node
{
	int state[NUM];
	int dist;
	Node(int a = 0,int b = 0 ,int c = 0,int d = 0){
		state[0] = a; state[1] = b; state[2] = c; dist = d;
	}
	bool operator < (const Node &b) const {
		return dist > b.dist;
	}
};

int bfs();
string node_to_string(Node n);
void new_near(Node t);

int init_state[NUM+1],near_dis;
set<string> vis;
Node nearest;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	while (n--) {
		for (int i = 0; i <= NUM; i++) cin >> init_state[i];
		int dis = bfs();
		cout << dis << " " << init_state[3] - near_dis << endl;
	}
	return 0;
}

int bfs()
{
	if (init_state[3] == init_state[2]) {
		near_dis = 0;
		return 0;
	}
	vis.clear();
	near_dis = INF;
	priority_queue<Node> pq;
	Node n(0, 0, init_state[2], 0);
	new_near(n);
	pq.push(n);
	string x = node_to_string(n);
	vis.insert(x);
	while (pq.size()) {
		Node t;
		n = pq.top(); pq.pop();
		for(int i = 0 ; i < NUM ;i++){
			if (n.state[i] == init_state[3]) {
				near_dis = 0; return n.dist;
			}
		}
		for (int i = 0; i < NUM; i++) {//i向j中倒水
			if (!n.state[i]) continue;//当杯子是空的时候不进行倒水操作
			for (int j = 0; j < NUM; j++) {
				if (i != j && n.state[j] != init_state[j]) {//当j满的时候不能向j中倒水
					memcpy(&t, &n, sizeof(n));
					int dj = init_state[j] - t.state[j];
					int dv = t.state[i] - dj;//计算i中的水量和j中空气的关系
					if (dv > 0) {
						t.dist += dj;
						t.state[i] -= dj;
						t.state[j] += dj;
					}
					else {
						t.dist += t.state[i];
						t.state[j] += t.state[i];
						t.state[i] = 0;
					}
					new_near(t);
					x = node_to_string(t);
					if (!vis.count(x)) {
						vis.insert(x);
						pq.push(t);
					}
				}
			}
		}
	}
	return nearest.dist;
}

void new_near(Node t)
{
	int ok = false;
	for (int i = 0; i < NUM; i++)
	{
		int d =init_state[3] - t.state[i];
		if (d > 0 && d < near_dis) {
			near_dis = d;
			ok = true;
		}
	}
	if (ok) memcpy(&nearest, &t, sizeof(t));
}

string node_to_string(Node n)
{
	string s;
	char c[10];
	for (int i = 0; i < NUM; i++) {
		sprintf(c,"%d", n.state[i]);
		s = s + c;
	}
	return s;
}
