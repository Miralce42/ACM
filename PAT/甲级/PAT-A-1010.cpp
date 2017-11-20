#include<iostream>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

typedef long long LL;

//将字符rdx换成其所对应的十进制数
int get_dex(char rdx)
{
	return rdx > '9' ? rdx - 'a' + 10 : rdx - '0';
}

//获取rdx进制下的a的十进制的值
LL get_a(string a, LL rdx)
{
	LL num = 0;
	for (int i = 0; i < a.length(); i++) {
		num = num * rdx + get_dex(a[i]);
	}
	return num;
}

//利用二分法寻找结果
LL btsearch(const string a, LL left, LL right, LL res)
{
	while (left <= right) {
		LL mid = (left + right) / 2;
		LL a_dex = get_a(a, mid);
		if (a_dex == res) return mid;
		else if (a_dex > res || a_dex < 0) right = mid - 1;//防止radix溢出
		else left = mid + 1;
	}
	return -1;
}

int main()
{
	LL a, rdx, high;
	int tag;
	string n1, n2, b;
	cin >> n1 >> n2 >> tag >> rdx;
	if (tag == 1) {			//根据tag获取基数
		a = get_a(n1, rdx);
		b = n2;
	}
	else {
		a = get_a(n2, rdx);
		b = n1;
	}
	rdx = 0 ;
	//寻找b（要转换的值）中每位对应的最大的值
	for (int i = 0; i < b.length(); i++)
		rdx = get_dex(b[i]) > rdx ? get_dex(b[i]) : rdx;
	rdx++;
	high = a > rdx ? a : rdx + 1;// eg:11 b 1 10 处理仅一位且相等的情况
	rdx = btsearch(b, rdx, high, a);//用二分法寻找相应的基数
	if (rdx != -1) cout << rdx << endl;
	else cout << "Impossible\n";
	return 0;
}