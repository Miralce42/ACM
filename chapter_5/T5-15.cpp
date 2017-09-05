#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int fib(int n);

int main()
{
	int num;
	num = fib(100000);
	return 0;
}

int fib(int n)
{
	unsigned long long sum,last_sum,prev_sum;
	last_sum = prev_sum = 1;
	sum = 1;
	cout << "1 \n 1 \n";
	for(int i = 0 ; i < n-1 ; i++)
	{
		prev_sum = last_sum;
		last_sum = sum;
		sum = prev_sum + last_sum;
		cout << sum <<endl;
	}
}
