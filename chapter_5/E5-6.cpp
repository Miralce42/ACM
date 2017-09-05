#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;

const int maxn = 1000 +10;

int main()
{
	int n,kase=0;
	while(scanf("%d",&n) == 1 && n)
	{
		printf("Scenario #%d\n",++kase);
		map<int,int> team;
		for(int i = 0 ; i < n ;i++)
		{
			int t;
			scanf("%d",&t);//队伍编号
			int num;
			while(t--)
			{
				scanf("%d",&num);
				team[num] = i;//编号为Num的队员所在队伍编号为i
			}
		}
		//模拟
		queue<int> q1,q2[maxn];//q1内存储长队中有的团队的编号，q2存储长队中存在的队员编号；
		string cmd;
		while(cin >> cmd && cmd != "STOP" )
		{
			if(cmd == "DEQUEUE")
			{
				int t = q1.front();
				printf("%d\n",q2[t].front());
				q2[t].pop();
				if(q2[t].empty())//如果长队中没有t团队的人，则需要将团队编号pop出来
					q1.pop();
			}
			else if(cmd == "ENQUEUE")
			{
				int num;
				scanf("%d",&num);
				int t = team[num];
				if(q2[t].empty())//如果长队中还没有t队的人，需要先将编号t push进q1
					q1.push(t);
				q2[t].push(num);
			}
		}
		printf("\n");
	}
	return 0;
}