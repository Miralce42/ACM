#include<iostream>
#include<set>
#include<string>
#include<sstream>

using namespace std;

set<string> dict;

int main()
{
	string s,buf;
	while(cin >> s && s!="-1")
	{
		for(int i = 0 ; i < s.length() ; i++)
		{
			if(isalpha(s[i])) 
				s[i] = tolower(s[i]) ;
			else
				s[i] = ' ';
		}
		stringstream ss(s);
		while(ss >> buf)
			dict.insert(s);
	}
	for(set<string>::iterator it = dict.begin() ; it != dict.end() ; ++it)
		cout << *it << endl;
	return 0;
}