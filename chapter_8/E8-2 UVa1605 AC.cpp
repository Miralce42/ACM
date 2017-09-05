#include<iostream>  
  
using namespace std;  
  
int main()  
{  
    int n;  
    while (cin >> n) {  
        cout << "2 " << n << " " << n << endl;  
        for(int i = 0 ; i < n ;i++){  
            for (int j = 0; j < n;j++) {  
                if (i < 26) cout << (char)(i + 65);  
                else cout << (char)(i - 26 + 97);  
            }  
            cout << endl;  
        }  
        cout << endl;  
        for (int i = 0; i < n; i++) {  
            for (int j = 0; j < n; j++) {  
                if (j < 26) cout << (char)(j + 65);  
                else cout << (char)(j - 26 + 97);  
            }  
            cout << endl;  
        }  
        cout << endl;  
    }  
    return 0;  
}  

