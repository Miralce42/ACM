#include<iostream>

using namespace std;

void inti();
void swap(int a,int b);

const int maxn = 500000 + 10;
int n,school[maxn];

int main()
{
	int a,b;
	while(cin >> n && n)
	{
		inti();
		for(int i = 0 ; i < n ; i++)
		{
			cin >> a >> b;
			swap(a,b);
		}
		for(int j = 0 ; j < maxn ;j++)
		{
			if(school[j] != j)
			{
				printf("NO\n");
				break;
			}
		}
		if(j == maxn)
			printf("YES\n");
	}
	return 0;
}

void inti()
{
	for(int i = 0 ; i < maxn ;i++)
		school[i] = i;
}

void swap(int a,int b)
{
	int t = school[a];
	school[a] = school[b];
	school[b] = t;
}