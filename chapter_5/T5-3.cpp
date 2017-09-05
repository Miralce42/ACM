//UVa10935
#include<iostream>
#include<queue>

using namespace std;

void clear(queue<int> &q);

int main()
{
	queue<int> cards;
	int n = 0;
	while(cin >> n && n )
	{
		for(int i = 1 ; i <= n ;i++)//���쿨Ƭ����
		{
			cards.push(i);
		}
		printf("Discarded cards:");
		while(cards.size()>1)
		{
			printf(" %d",cards.front());//�����Ҫ�ӵ��Ŀ�Ƭ
			if(cards.size() != 2) //��Ҫ�ӵ������һ�ſ�Ƭ���������,��
				printf(",");
			cards.pop();
			cards.push(cards.front());//�Ƚ���Ҫ�ŵ����Ŀ�Ƭ�������
			cards.pop();			  //���ӵ�
		}
		printf("\n");
		printf("Remaining card: %d\n",cards.front());
		clear(cards);//�������
	}
	return 0;
}

void clear(queue<int> &q)//�˺���������ն���
{
   queue<int> empty;
   swap( q, empty );
}