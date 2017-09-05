//E8-4 Uva11134 
//思路：每次先给r最小（右边界最靠左的）进行分配，
//分配可行而且最l最小的（l最靠左边的），
//贪的原理就是因为r越小的区间 其选择的灵活性就越低，所以要先对他进行分配。
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int MAXN = 5000 + 10;

struct Node{
	int l, r, id;
	bool operator < (const Node &b) const {
		return (b.r < r || (r == b.r && b.l < l));
	}
};

Node maze_x[MAXN], maze_y[MAXN];
int rook_x[MAXN], rook_y[MAXN], mx[MAXN], my[MAXN];

int main()
{
	int n;
	while (cin >> n && n) {
		priority_queue<Node> pq_x;
		priority_queue<Node> pq_y;
		memset(mx, 0, sizeof(mx));
		memset(my, 0, sizeof(my));
		for (int i = 0; i < n; i++) {	//读入
			cin >> maze_x[i].l >> maze_y[i].l >> maze_x[i].r >> maze_y[i].r;
			maze_x[i].id = i; maze_y[i].id = i;
			pq_x.push(maze_x[i]); pq_y.push(maze_y[i]);	//放进优先队列中，l值越小越优先，l相等时r越小越优先
		}
		bool ok = true; int i, j;
		while (pq_x.size()) {
			Node rx = pq_x.top(); pq_x.pop();
			Node ry = pq_y.top(); pq_y.pop();
			for (i = rx.l; i <= rx.r; i++) { //按照优选队列中的顺序给每个rook分配x
				if (!mx[i]) {
					rook_x[rx.id] = i;
					mx[i] = 1; break;
				}
			}
			for (j = ry.l; j <= ry.r; j++) {
				if (!my[j]) {
					rook_y[ry.id] = j;
					my[j] = 1; break;
				}
			}
			if (i > rx.r || j > ry.r) {//不满足分配条件
				ok = false; break;
			}
		}
		if (ok)
			for (int i = 0; i < n; i++)
				cout << rook_x[i] << " " << rook_y[i] << endl;
		else
			cout << "IMPOSSIBLE \n";
	}
	return 0;
}
