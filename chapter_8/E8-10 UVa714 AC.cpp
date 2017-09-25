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
		for (int i = 0; i < m; i++) { //��������л�ȡ�ܺͼ����ֵ 
			cin >> arr[i];
			sum += arr[i];
			maxp = max(maxp, arr[i]);
		}
		print(find(maxp, sum));
	}
	return 0;
}

void print(long long mx)//��ӡ 
{
	int last[MAXN], remain = k;
	long long sum = 0;
	memset(last, 0, sizeof(last));
	for (int i = m - 1; i >= 0; i--) {//�����ҵ�ÿ���ϵ㴦 
		if (sum + arr[i] > mx || i + 1 < remain) {
			last[i] = 1; remain--; sum = 0;
		}
		sum += arr[i];
	}
	for (int i = 0; i < m - 1; i++) {//��� 
		cout << arr[i] << " ";
		if (last[i]) cout << "/ ";
	}
	cout << arr[m - 1] << endl;
}

long long find(int maxp, long long sum)//�ҵ�ʹ�ô��ڵ�������s(i)����С��ֵx 
{
	long long mx = sum, mn = maxp;
	while (mn < mx) {// ���ö��ַ��ҵ�x 
		long long mid = (mx + mn) / 2;
		if (p(mid) <= 0) mx = mid;// x <= mid,�������̷�Χ 
		else mn = mid + 1;//x > mid,�������̷�Χ  
	}
	return mn;
}
//�ȼ�ʹ��s(i)����������x��num�Ĺ�ϵ
//x > num ����������x < num���ظ��� ��x=num����0
int p(int num)
{
	long long sum = 0;
	int cnt = 1;
	for (int i = 0; i < m; i++) {//������numΪ���s(i)ֵ������£��ָܷ�Ϊ���ٶ� 
		if (sum + arr[i] > num) {
			sum = 0; cnt++;
		}
		sum += arr[i];
	}
	return cnt - k;//�Ƚ�cnt �� k 
}
