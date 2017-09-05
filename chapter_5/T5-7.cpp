//uav12100
#include<iostream>
#include<queue>

using namespace std;

struct document
{
	int num;
	int pos;
	document(int n,int p):num(n),pos(p) {}
};

queue<document> doc;
priority_queue<int> pq;


void clear(queue<document> &q )
{
   queue<document> empty;
   swap( q, empty );
}

void clear(priority_queue<int> &q )
{
   priority_queue<int> empty;
   swap( q, empty );
}

int main()
{
	int kase,n,pos,num,count=1;
	cin >> kase;
	while(kase--)
	{
		cin >> n >> pos;
		for(int i = 0 ; i < n ;i++)
		{
			cin >> num;
			doc.push(document(num,i));
			pq.push(num);
		}
		while(1)
		{
			document d = doc.front();
			doc.pop();
			if(d.num == pq.top())
			{
				if(pos == d.pos)
					break;
				else
				{
					pq.pop();
					count++;
				}
			}
			else
			{
				doc.push(d);
				n--;
			}
		}
		printf("%d\n",count);
		clear(doc);
		clear(pq);
		count = 1;
	}
	return 0;
}
