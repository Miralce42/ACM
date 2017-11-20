#include<iostream>

using namespace std;

int main()
{
  int n, time = 0, e = 0, f;
  cin >> n;
  while (n--) {
    cin >> f;
    int tmp = f - e;
    if (tmp < 0) time += -tmp * 4;
    else if (tmp > 0) time += tmp * 6;
    time += 5;
    e = f;
  }
  cout << time << endl;
  return 0;
}