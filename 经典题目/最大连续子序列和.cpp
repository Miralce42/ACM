//������������к�
#include<cstdio>
#include<iostream>

using namespace std;

void scheme_1(int *x , int n);
void scheme_2(int *x , int n);
int scheme_3(int *x, int L, int R);

const int MAXN = 10000;

int main()
{
	int n, x[MAXN];
	while(scanf("%d",&n) && n){
		for (int i = 0; i < n; i++) scanf("%d", &x[i]);
		//scheme_1(x,n);
		//scheme_2(x,n);
		printf("%d\n", scheme_3(x, 0, n));
	}
	return 0;
}

//O(nlog(n))
int scheme_3(int *x, int L, int R)//��һ������ҿ�����[L,R)Ѱ����������к�
{
	if (R - L == 1) return x[L];
	int mid = L + (R - L) / 2, max = 0;
	int L_max = scheme_3(x, L, mid);//Ѱ������������
	max = max > L_max ? max : L_max;
	int R_max = scheme_3(x, mid, R);//Ѱ���Ҳ��������
	max = max > R_max ? max : R_max;
	//Ѱ�ҿ�Խ�е���������
	int a, b , n; a = b = n = 0;
	for (int i = mid - 1; i >= L; i--) {
		n += x[i];
		a = a > n ? a : n;
	}
	n = 0;
	for (int i = mid; i < R; i++) {
		n += x[i];
		b = b > n ? b : n;
	}
	int mid_max = a + b;
	return max > mid_max ? max : mid_max;
}

//O(n^2) 
void scheme_2(int *x , int n)
{
	int s[MAXN],max = 0;
	for (int i = 0; i < n; i++) {
		s[i] = 0;
		for (int j = i; j < n; j++) {
			s[i] += x[j];
			max = max > s[i] ? max : s[i];
		}
	}
	printf("%d\n", max);
} 

//O(n^3) 
void scheme_1(int *x , int n)
{
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int s = 0;
			for (int k = i; k <= j; k++) {//��i�ӵ�j
				s += x[k];
			}
			max = max > s ? max : s;
		}
	}
	printf("%d\n", max);
}
