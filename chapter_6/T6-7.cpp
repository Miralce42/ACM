#include<iostream>
#include<cstring>
#include<string>
#include<sstream>

using namespace std;

int deal();

const int MAXN = 100 + 10;

int NP[MAXN];
int NT_in[MAXN][MAXN];
int NT_out[MAXN][MAXN];
int n, m, num;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int kase = 0;
	while (cin >> n && n)
	{
		memset(NT_in,0,sizeof(NT_in));
		memset(NT_out, 0, sizeof(NT_out));
		int k,i, j, x, do_num;
		for (i = 1; i <= n; i++)	cin >> NP[i];
		cin >> m;
		for (i = 0; i < m; i++)
		{
			k = j = 0;
			while (cin >> x && x)
			{
				if (x < 0) NT_in[i][j++] = x;
				else NT_out[i][k++] = x;
			}
		}
		cin >> num;
		do_num = deal();
		if(do_num == num)
			cout << "Case " << ++kase << ": still live after " << do_num << " transitions\n";
		else
			cout << "Case " << ++kase << ": dead after " << do_num << " transitions\n";
		cout << "Places with tokens:";
		for (int i = 1; i <= n; i++)
			if (NP[i] > 0)	cout << " " << i << " (" << NP[i] << ")";
		cout << endl << endl;
	}
	return 0;
}

int deal()
{
	int i, j, n = 1;
	while(1)
	{
		bool had_do = false;
		for (i = 0; i < m; i++)
		{
			j = 0; bool can_do = true;
			while (NT_in[i][j] != 0)
			{
				if (NP[-NT_in[i][j]] > 0)
				{
					NP[-NT_in[i][j]]--;
					j++;
				}
				else
				{
					while (j--)
						NP[-NT_in[i][j]]++;
					can_do = false;
					break;
				}
			}
			if (can_do)
			{
				j = 0; n++;//***
				while (NT_out[i][j] != 0)
				{
					NP[NT_out[i][j]]++;
					j++;
				}
				had_do = true;
				if (n > num)	return num;
			}
			else
				break;
		}
		if (!had_do) return n-1;
	}
}
