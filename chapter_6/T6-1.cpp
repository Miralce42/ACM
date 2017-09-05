#include<iostream>
#include<stack>
#include<string>
#include<cstring>

using namespace std;

char rev(char ch);

string str;

int main()
{
	//freopen("input.txt","r",stdin); 
	//freopen("output.txt","w",stdout); 
	int n;
	cin >> n;
	getchar();
	while (n--)
	{
		stack<char> s;
		int is_correct = true;
		getline(cin, str);
		if (str != "")
		{
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == '(' || str[i] == '[')
				{
					s.push(str[i]);
				}
				else
				{
					if (s.empty() || s.top() != rev(str[i]))
					{
						is_correct = false;
						break;
					}
					else
						s.pop();
				}
			}
			if(!s.empty())
				is_correct = false;
		}
		if (is_correct) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}

char rev(char ch)
{
	if (ch == ')') return '(';
	if (ch == ']') return '[';
}
