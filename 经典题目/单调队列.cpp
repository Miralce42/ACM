//单调队列
// http://blog.csdn.net/justmeh/article/details/5844650 
#include<iostream>

using namespace std;

const int MAXN = 1000 + 10;

int main()
{
	int n, k; cin >> n >> k;
	int arr[MAXN], a[MAXN], front = 0, rear = 0;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	for (int i = 0; i < n; i++) {
		while (front < rear && arr[a[rear-1]] > arr[i])
			a[--rear] = -1;
		a[rear++] = i;
		if (a[front] < i - k + 1) {
			a[front++] = -1;
		}
		if(i >= k-1) cout << i - k + 2 << " : " << a[front] << endl;
	}
	return 0;
}
