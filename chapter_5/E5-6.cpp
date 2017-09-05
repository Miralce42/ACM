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
			scanf("%d",&t);//������
			int num;
			while(t--)
			{
				scanf("%d",&num);
				team[num] = i;//���ΪNum�Ķ�Ա���ڶ�����Ϊi
			}
		}
		//ģ��
		queue<int> q1,q2[maxn];//q1�ڴ洢�������е��Ŷӵı�ţ�q2�洢�����д��ڵĶ�Ա��ţ�
		string cmd;
		while(cin >> cmd && cmd != "STOP" )
		{
			if(cmd == "DEQUEUE")
			{
				int t = q1.front();
				printf("%d\n",q2[t].front());
				q2[t].pop();
				if(q2[t].empty())//���������û��t�Ŷӵ��ˣ�����Ҫ���Ŷӱ��pop����
					q1.pop();
			}
			else if(cmd == "ENQUEUE")
			{
				int num;
				scanf("%d",&num);
				int t = team[num];
				if(q2[t].empty())//��������л�û��t�ӵ��ˣ���Ҫ�Ƚ����t push��q1
					q1.push(t);
				q2[t].push(num);
			}
		}
		printf("\n");
	}
	return 0;
}