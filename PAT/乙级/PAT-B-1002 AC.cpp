#include<iostream>
#include<string>
#include<sstream>
#include<cstring>

using namespace std;

string number[10] = { "ling",//store pinyin of the number from 0 to 9 
                        "yi",
                        "er",
                        "san",
                        "si",
                        "wu",
                        "liu",
                        "qi",
                        "ba",
                        "jiu",
                                };

int main()
{
    string input;
    while (cin >> input) {//using getchar() will make TLE
        int sum = 0; bool first = true;
        for (unsigned int i = 0; i < input.length();i++) {
            int n = input[i] - '0';
            sum += n;
        }
        stringstream ss; ss << sum;     //transform int to str
        string s = ss.str();
        for (int i = 0; i < s.length(); i++) {  //output
            if (!first) cout << " ";
            first = false;
            cout << number[s[i] - '0'];
        }
        cout << endl;
    }
    return 0;
}
