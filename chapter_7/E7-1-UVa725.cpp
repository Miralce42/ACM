//UVa725,AC,P182
#include<iostream>
#include<cmath>
#include<set>

using namespace std;

int div(int n);
bool judge(int dividend);
int places(int num);

set<int> jdg;

int main()
{
	//freopen("input.txt","r",stdin); 
	//freopen("output.txt","w",stdout);
	int n; cin >> n;
	while (n)
	{
		if (!div(n)) cout << "There are no solutions for " << n << ".\n";
		jdg.clear();
		cin >> n;
		if (n) cout << endl;
	}
	return 0;
}

int div(int n)
{
	int cnt = 0;
	for (int f = 0; f < 10; f++)
	{
		jdg.insert(f);
		for (int g = 0; g < 10; g++)
		{
			if (jdg.count(g)) continue;
			jdg.insert(g);
			for (int h = 0; h < 10; h++)
			{
				if (jdg.count(h)) continue;
				jdg.insert(h);
				for (int i = 0; i < 10; i++)
				{
					if (jdg.count(i)) continue;
					jdg.insert(i);
					for (int j = 0; j < 10; j++)
					{
						if (jdg.count(j)) continue;
						jdg.insert(j);
						int divisor = f * 10000 + g * 1000 + h * 100 + i * 10 + j;
						int dividend = n * divisor;
						int divisor_size = places(divisor);
						int dividend_size = places(dividend);
						if (divisor_size + dividend_size > 10)
							return cnt;
						if (judge(dividend))
						{
							if (dividend_size < 5) cout << "0";
							cout << dividend << " / ";
							if(divisor_size < 5) cout << "0";
							cout << divisor << " = " << n << endl;
							cnt++;
						}
						jdg.erase(j);
					}
					jdg.erase(i);
				}
				jdg.erase(h);
			}
			jdg.erase(g);
		}
		jdg.erase(f);
	}
	return cnt;
}

bool judge(int dividend)
{
	set<int> jgd_cpy = jdg;
	int len = places(dividend),num;
	if(len == 4 && jgd_cpy.count(0)) return false;
	for (int i = len-1; i >= 0 ; i--)
	{
		num = dividend / pow(10, i);
		if (jgd_cpy.count(num)) return false;
		jgd_cpy.insert(num);
		dividend -= num * pow(10, i);
	}
	return true;
}

int places(int num)
{
	if (num < 10000) return 4;
	else if (num < 100000) return 5;
	else if(num < 1000000) return 6;
	else return 7;
}
