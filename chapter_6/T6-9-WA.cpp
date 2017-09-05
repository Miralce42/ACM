//UVa 127,测试数据全部通过，但是WA 
#include<iostream>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

struct Node
{
	char suit, rank;
	Node(){}
	Node(char s, char r) :suit(s), rank(r) {}
};

int match(int idx, Node card, int n);
int solve();
bool card_cmp(int i, int j);
int find_pos(int idx, int n);

const int MAXN = 52 + 8;

vector<Node> cards[MAXN];

int main()
{
	//freopen("input.txt","r",stdin); 
	//freopen("output.txt","w",stdout); 
	string card;
	while (cin >> card && card != "#")
	{
		cards[0].push_back(Node(card[0], card[1]));			//输入，放入cards中 
		for (int i = 1; i < 52; i++)
		{
			cin >> card;
			cards[i].push_back(Node(card[0], card[1]));
		}
		int cnt = solve();							//对纸牌进行操作，返回的是堆数 
		cout << cnt << " piles remaining:";		//输出 
		for (int i = 0; i < 52; i++)
			if (cards[i].size())
			{
				cout << " " << cards[i].size();
				cards[i].clear();
			}
		cout << endl;
	}
	return 0;
}

int solve()				
{
	int cnt;
	while(1)
	{
		bool moved = false;			//这轮中是否有移动，如果没有说明已经没有可移动的，结束，输出 
		cnt = 0;
		for (int i = 0; i < 52; i++)
		{
			if (cards[i].size())
			{
				cnt++;
				int idx = match(i, cards[i].back(), 3);		//该纸牌的左边3（1）位（由于没有进行空堆左移，
				if (idx == -1)								// 所以不一定正好是三位）可以不可以match，可以返回下标，不可以返回-1 
					idx = match(i, cards[i].back(), 1);
				if (idx != -1)								//判断可以match，进行移动操作。 
				{
					int size = cards[i].size();
					cards[idx].push_back(cards[i].back());
					cards[i].pop_back();
					cards[i].resize(size - 1);//MW
					moved = true;
					break;
				}
			}
		}
		if (!moved) break;
	}
	return cnt;
}

int match(int idx, Node card,int n)				//判断idx位置的牌与idx-n(伪)位置是否可以match 
{
	int pos = find_pos(idx, n);
	if (pos != -1)
	{
		if (card_cmp(idx, pos))
			return pos;
	}
	return -1;
}

bool card_cmp(int i, int j)
{
	return (cards[i].back().rank == cards[j].back().rank || cards[i].back().suit == cards[j].back().suit);
}

int find_pos(int idx, int n)			//找到idx的左边不空的有n个位置的 
{
	while (n>0)
	{
		idx--;
		if (idx >= 0)
		{
			if (cards[idx].size())
				n--;
		}
		else
			break;
	}
	if (!n) return idx;
	else return -1;
}
