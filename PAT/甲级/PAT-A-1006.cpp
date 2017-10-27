//PAT-¼×¼¶-1006 Sign In and Sign Out 
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	string min_t, max_t, a, b, ID_number, Sign_in_time, Sign_out_time;
	int n;
	cin >> n;
	cin >> a >> min_t >> max_t;
	b = a;
	while (--n) {
		cin >> ID_number >> Sign_in_time >> Sign_out_time;
		if (Sign_in_time < min_t) {
			min_t = Sign_in_time;
			a = ID_number;
		}
		if (Sign_out_time > max_t) {
			max_t = Sign_out_time;
			b = ID_number;
		}
	}
	cout << a << " " << b << endl;
	return 0;
}
