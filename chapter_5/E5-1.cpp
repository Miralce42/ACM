//水题，不过学习了两个自带函数
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100;

int main()
{
	int num,n,kase=0;
	int marbles[maxn];
	int wanted;
	while(cin >> num >> n && num)
	{
		for(int i = 0 ; i < num ; i++)
			cin >> marbles[i];
		sort(marbles,marbles+num);//自带排序
		cout << "CASE# "<<++kase<<":\n";
		while(n--)
		{
			cin >> wanted;
			int loc = lower_bound(marbles,marbles+num,wanted) - marbles;//返回数组非递减marbles[]中能插入wanted的最小位置
																		//注意该函数返回的指针，需要减去原数组才能获得相对位置
			if(marbles[loc] == wanted)
				cout << wanted << " found at " << loc+1 << endl;//lower_bound返回的位置信息是从0开始
			else
				cout << wanted << " not found" << endl;
		}
	}
	return 0;
}