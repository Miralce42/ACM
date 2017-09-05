//UVa10763
//�����ⷨ���ﲻ����Ŀ����ĿҪ��
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
			if(ideal[to][at])		//ֱ�Ӳ����Ƿ�����ܽ�����
			{			        	//�������
				ideal[at][to]--;	//�����˵ļ�����--
				ideal[to][at]--;
				count -= 2;			//�Ѿ���������˵����⣬��������-2
			}
		}
		if(count)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}