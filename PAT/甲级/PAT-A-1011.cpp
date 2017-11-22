#include<iostream>

using namespace std;

int main()
{
  char bet[3] = { 'W','T','L' };
  double num, mul = 1;
  for (int i = 0; i < 3; i++) {
    int max_index = 0;
    double max_num = 0.0;
    for (int j = 0; j < 3; j++) {
      cin >> num;
      if (num > max_num) {
        max_num = num;
        max_index = j;
      }
    }
    mul *= max_num;
    cout << bet[max_index] << " ";
  }
  double res = (mul * 0.65 - 1) * 2;
  printf("%.2lf", res);
  return 0;
}