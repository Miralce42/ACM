//T8-1 UVa1149 AC 
#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 100000 + 10;

int arr[MAXN], n, m, len;

int main()
{
	cin >> m;
	while (m--) {
		int num = 0;
		cin >> n >> len;
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr + n);
		int i, j, k = n - 1; //k : the idx of maximum which can store with minimum 
		for (i = 0; i < n; i++) {
			if (arr[i] == -1)continue;	//has visited
			for (j = k; j > i; j--) {
				if (arr[i] + arr[j] <= len) {
					k = j - 1; break;   //arr[j] too big to store with other,so next i will try begin lesser one(j-1).
				}
			}
			arr[i] = arr[j] = -1;//already stored,value -1 to avoid repeat visit
			num++;
		}
		cout << num << "\n";
		if(m) cout<<"\n";
	}
	return 0;
}
