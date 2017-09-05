//UVa 127,��������ȫ��ͨ��������WA 
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
		cards[0].push_back(Node(card[0], card[1]));			//���룬����cards�� 
		for (int i = 1; i < 52; i++)
		{
			cin >> card;
			cards[i].push_back(Node(card[0], card[1]));
		}
		int cnt = solve();							//��ֽ�ƽ��в��������ص��Ƕ��� 
		cout << cnt << " piles remaining:";		//��� 
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
		bool moved = false;			//�������Ƿ����ƶ������û��˵���Ѿ�û�п��ƶ��ģ���������� 
		cnt = 0;
		for (int i = 0; i < 52; i++)
		{
			if (cards[i].size())
			{
				cnt++;
				int idx = match(i, cards[i].back(), 3);		//��ֽ�Ƶ����3��1��λ������û�н��пն����ƣ�
				if (idx == -1)								// ���Բ�һ����������λ�����Բ�����match�����Է����±꣬�����Է���-1 
					idx = match(i, cards[i].back(), 1);
				if (idx != -1)								//�жϿ���match�������ƶ������� 
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

int match(int idx, Node card,int n)				//�ж�idxλ�õ�����idx-n(α)λ���Ƿ����match 
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

int find_pos(int idx, int n)			//�ҵ�idx����߲��յ���n��λ�õ� 
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
