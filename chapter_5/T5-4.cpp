//UVa10763
//暴力解法，达不到题目的数目要求
#include<iostream>
#include<string>

using namespace std;

const int maxn = 1000 + 10;

int ideal[maxn][maxn];

int main()
{
	int n;
	while(cin >> n && n)
	{
		int at,to,count=n;
		memset(ideal,0,sizeof(ideal));
		for(int i = 0 ; i < n ; i++)
		{
			cin >> at >> to;
			ideal[at][to]++;
			if(ideal[to][at])		//直接查找是否存在能交换的
			{			        	//如果存在
				ideal[at][to]--;	//两个人的计数都--
				ideal[to][at]--;
				count -= 2;			//已经解决两个人的问题，所以人数-2
			}
		}
		if(count)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}