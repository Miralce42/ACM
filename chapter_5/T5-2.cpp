#include<iostream>
#include<cmath>

using namespace std;

bool judge(int n);

const int maxn = 15+5;
int ducci[maxn];

int main()
{
	int num,n;
	cin >> num;
	while(num--)
	{
		cin >>n;
		for(int i = 0 ; i < n ;i++)
		{
			cin >> ducci[i];
		}
		int count = 1000;
		while(--count)
		{
			if(judge(n))
				break;
			int first = ducci[0];
			for(int j = 0 ; j < n-1 ;j++)
			{
				ducci[j] = abs(ducci[j+1] - ducci[j]);
			}
			ducci[j] = abs(first - ducci[j]);
		}
		if(count)
			cout << "ZERO\n";
		else
			cout << "LOOP\n";
	}
	return 0;
}

bool judge(int n)
{
	for(int i = 0; i < n ;i++)
	{
		if(ducci[i])
			return false;
	}
	return true;
}