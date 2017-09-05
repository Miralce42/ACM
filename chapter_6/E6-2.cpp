#include <iostream>
#include <stack>

using namespace std;

const int maxn = 1000 + 10;

int crg[maxn];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n,sign=0;
	while (cin >> n && n)				//读入车厢个数 
	{
		while (cin >> crg[1] && crg[1]) //如果读入为0，则说明对该列火车的判断结束 
		{
			stack<int> station;
			for (int i = 2; i <= n; i++)
			{
				cin >> crg[i];
			}
			int A, B, ok;
			A = B = ok = 1;
			while (B <= n)
			{
				if (A == crg[B])	//A位置的车厢可以直接到B 
				{
					A++; B++;
				}
				else if (!station.empty() && station.top() == crg[B]) //B位置的车厢正是C栈顶元素 
				{
					B++;
					station.pop();
				}
				else if (A <= n)	//A,C 位置均没有与B对应的车厢，则应该先进站 
				{
					station.push(A);
					A++;
				}
				else				//以上欠款均不符合，A处已经没有车厢 
				{
					ok = 0;
					break;
				}
			}
			if (ok)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		cout << endl;
	}
	return 0;
}

