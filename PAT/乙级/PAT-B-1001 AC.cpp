// PAT-B-1001 
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	long long num;
	while (cin >> num) {
		long long cnt = 0;
		while (num != 1) {
			if (num % 2 == 0) num = num >> 1;
			else num = (3 * num + 1) >> 1;
			cnt++;
		}
		cout << cnt << endl;
	}
}
