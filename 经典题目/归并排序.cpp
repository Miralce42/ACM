//归并排序O(nlog(n))  逆序对数问题 
#include<iostream>
#include<cstdio>

using namespace std;

void merge_sort(int L, int R);

const int MAXN = 10000;

int  num[MAXN], res[MAXN],cnt;

int main()
{
	int n;
	while (cin >> n && n) {
		for (int i = 0; i < n; i++) cin >> num[i];
		cnt = 0;
		merge_sort(0, n);
		for (int i = 0; i < n; i++) cout << num[i] << " ";
		cout << endl;
		cout << cnt << endl;
	}
}

//对num数组里的[L,R)进行排序并存入res数组中
void merge_sort(int L, int R)
{
	if(R - L > 1) {
		int mid = L + (R - L) / 2;
		merge_sort(L, mid);
		merge_sort(mid, R);
		int i = L, j = mid, k = L;
		while (i < mid && j < R) {
			if (num[i] <= num[j])
				res[k++] = num[i++];
			else
			{
				res[k++] = num[j++];
				cnt += mid - i;//用来统计左侧比num[j]的元素，也就是逆序对的个数 
			}
		}
		while(i < mid) res[k++] = num[i++];
		while(j < R) res[k++] = num[j++];
		for (int i = L; i < R; i++) num[i] = res[i];
	}
	else res[L] = num[L];
}
