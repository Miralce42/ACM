//UAa-536
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

void crt_tree(int L1, int R1, int L2, int R2, int n);

string preord, inord;

int main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	while (cin >> preord>> inord)
	{
		int len = preord.length();
		crt_tree(0, len - 1, 0, len - 1, 1);
		cout << endl;
  	}
	return 0;
}

void crt_tree(int L1, int R1, int L2, int R2,int n)
{
	if (L1 > R1 || L2 > R2)
		return;
	char root = preord[L1];
	int pos=0;
	while (inord[pos] != root) pos++;
	int len_left = pos - L2;
	int len_right = R2 - pos;
	crt_tree(L1 + 1, L1 + len_left, L2, pos - 1, 2 * n);
	crt_tree(R1 - len_right+1, R1, pos + 1, R2, 2 * n + 1);
	cout << root;
}
