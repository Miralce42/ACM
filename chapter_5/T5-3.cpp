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
		for(int i = 1 ; i <= n ;i++)//构造卡片集合
		{
			cards.push(i);
		}
		printf("Discarded cards:");
		while(cards.size()>1)
		{
			printf(" %d",cards.front());//输出需要扔掉的卡片
			if(cards.size() != 2) //需要扔掉的最后一张卡片后面无需加,号
				printf(",");
			cards.pop();
			cards.push(cards.front());//先将需要放到最后的卡片放入队列
			cards.pop();			  //再扔掉
		}
		printf("\n");
		printf("Remaining card: %d\n",cards.front());
		clear(cards);//清理队列
	}
	return 0;
}

void clear(queue<int> &q)//此函数用于清空队列
{
   queue<int> empty;
   swap( q, empty );
}