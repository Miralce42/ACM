//书上的代码也不一定是对的
#include<iostream>
#include<map>
#include<vector>
#include<queue>

typedef unsigned __int64 ll;//long long和__int64都会越界所以要用unsigned

using namespace std;

int main()
{
	int coeff[3] = {2,3,5};
	priority_queue<ll,vector<ll>,greater<ll> >  pq;//STL提供的“越小的整数优先级越高”
	map<ll,ll> ugly;//ugly[i]表示第i个丑数的个数
	ll un=1;//丑数
	int count = 0;//已经找到的丑数的个数
	pq.push(un);
	while(count < 1500)
	{
		un = pq.top();//优先队列priority_queue取头元素是top不是front
		pq.pop();
		count++;
		for(int i = 0 ; i<3 ;i++)
		{
			int n = coeff[i]*un;
			if(ugly[n] < 1)
			{
				pq.push(n);
				ugly[n]++;
			}
		}
	}
	printf("The 1500'th ugly number is <%I64d>.\n",un);
	return 0;
}