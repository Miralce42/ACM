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
	while (cin >> n && n)				//���복����� 
	{
		while (cin >> crg[1] && crg[1]) //�������Ϊ0����˵���Ը��л𳵵��жϽ��� 
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
				if (A == crg[B])	//Aλ�õĳ������ֱ�ӵ�B 
				{
					A++; B++;
				}
				else if (!station.empty() && station.top() == crg[B]) //Bλ�õĳ�������Cջ��Ԫ�� 
				{
					B++;
					station.pop();
				}
				else if (A <= n)	//A,C λ�þ�û����B��Ӧ�ĳ��ᣬ��Ӧ���Ƚ�վ 
				{
					station.push(A);
					A++;
				}
				else				//����Ƿ��������ϣ�A���Ѿ�û�г��� 
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

