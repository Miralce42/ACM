#include<stdio.h>
#include<string.h>

using namespace std;

const int MAXN = 524288 + 100;

int tree[MAXN];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int num,n, m;
	while(scanf("%d",&num) == 1 && num !=-1)
	{
		while (num--) 
		{
			scanf("%d %d",&n,&m);
			int ball;
			memset(tree, 0, sizeof(tree));
			for (int i = 0; i < m; i++)
			{
				ball = 1;
				for (int j = 1; j < n; j++)
				{
					int b = ball;
					if (tree[ball])
						ball = 2 * ball + 1;
					else
						ball = 2 * ball;
					tree[b] = !tree[b];
				}
			}
			printf("%d\n",ball);
		}
	}
	return 0;
}
