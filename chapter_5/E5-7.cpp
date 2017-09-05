//���ϵĴ���Ҳ��һ���ǶԵ�
#include<iostream>
#include<map>
#include<vector>
#include<queue>

typedef unsigned __int64 ll;//long long��__int64����Խ������Ҫ��unsigned

using namespace std;

int main()
{
	int coeff[3] = {2,3,5};
	priority_queue<ll,vector<ll>,greater<ll> >  pq;//STL�ṩ�ġ�ԽС���������ȼ�Խ�ߡ�
	map<ll,ll> ugly;//ugly[i]��ʾ��i�������ĸ���
	ll un=1;//����
	int count = 0;//�Ѿ��ҵ��ĳ����ĸ���
	pq.push(un);
	while(count < 1500)
	{
		un = pq.top();//���ȶ���priority_queueȡͷԪ����top����front
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