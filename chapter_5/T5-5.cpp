#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

void find();
void subString(string word,int len,string &sub_front,string &sub_back);

map<string,int> dic;
vector<string> words;

int main()
{
	string word;
	dic.clear();
	words.clear();
	while(cin >> word)
	{
		dic[word] = 1;
		words.push_back(word);
	}
	find();
	return 0;
}

void find()
{
	string sub_front,sub_back;
	for(int i = 0 ; i < words.size() ;i++)
	{
		for(int j = 1 ;j < words[i].length();j++)
		{
			if(words[i].length() < 2)
				continue;
			subString(words[i],j,sub_front,sub_back);
			if(dic[sub_front] && dic[sub_back])
			{
				cout << words[i]<<endl;
				continue;
			}
		}
	}
}

void subString(string word,int len,string &sub_front,string &sub_back)
{
	sub_front = word.substr(0,len);
	sub_back = word.substr(len);
}