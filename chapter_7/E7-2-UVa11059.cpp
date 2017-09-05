//UVa11059,AC,P183,暴力枚举
//求乘积最大的连续子序列 
#include<iostream>

using namespace std;

const int MAXN = 18 + 2;

int main()
{
	//freopen("input.txt","r",stdin); 
	//freopen("output.txt","w",stdout);
	int n, kase = 0;
	while (cin >> n){
		int number[MAXN];
		long long max = 0, pro;
		for (int i = 0; i < n; i++) cin >> number[i];
		for (int i = 0; i < n; i++){
			pro = 1;
			for (int j = i; j < n; j++) {
				pro = pro * number[j];
				max = pro > max ? pro : max;
			}
		}
		cout << "Case #" << ++kase << ": The maximum product is " << max << ".\n\n";
	}
}
