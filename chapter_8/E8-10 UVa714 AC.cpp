//E8-10 UVa714 AC P244
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

void print(long long mx);
long long find(int maxp, long long sum);
int p(int num);

const int MAXN = 500 + 5;

int arr[MAXN], m, k, n;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n;
	while (n--) {
		cin >> m >> k;
		long long sum = 0;
		int maxp = 0;
		for (int i = 0; i < m; i++) { //输入过程中获取总和及最大值 
			cin >> arr[i];
			sum += arr[i];
			maxp = max(maxp, arr[i]);
		}
		print(find(maxp, sum));
	}
	return 0;
}

void print(long long mx)//打印 
{
	int last[MAXN], remain = k;
	long long sum = 0;
	memset(last, 0, sizeof(last));
	for (int i = m - 1; i >= 0; i--) {//逆序找到每个断点处 
		if (sum + arr[i] > mx || i + 1 < remain) {
			last[i] = 1; remain--; sum = 0;
		}
		sum += arr[i];
	}
	for (int i = 0; i < m - 1; i++) {//输出 
		cout << arr[i] << " ";
		if (last[i]) cout << "/ ";
	}
	cout << arr[m - 1] << endl;
}

long long find(int maxp, long long sum)//找到使得大于等于所有s(i)且最小的值x 
{
	long long mx = sum, mn = maxp;
	while (mn < mx) {// 利用二分法找到x 
		long long mid = (mx + mn) / 2;
		if (p(mid) <= 0) mx = mid;// x <= mid,向下缩短范围 
		else mn = mid + 1;//x > mid,向上缩短范围  
	}
	return mn;
}
//比价使得s(i)均不超过的x与num的关系
//x > num 返回正数，x < num返回负数 ，x=num返回0
int p(int num)
{
	long long sum = 0;
	int cnt = 1;
	for (int i = 0; i < m; i++) {//计算以num为最大s(i)值的情况下，能分割为多少段 
		if (sum + arr[i] > num) {
			sum = 0; cnt++;
		}
		sum += arr[i];
	}
	return cnt - k;//比较cnt 与 k 
}
