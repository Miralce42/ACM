#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
#include<algorithm> 

using namespace std;

struct Book
{
	string title;
	string author;
	Book(string n,string a){
		title = n;
		author = a;
	}
	bool operator< (const Book b){
		if(this->author == b.author)
			return this->title < b.title;
		return this->author < b.author;
	}
};

map<string,int> value;//存放图书当前状态1：在架，2：归还未上架，0：借出
vector<Book> books;//用于存储图书 

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	string s,title,author;
	while(getline(cin,s) && s != "END")
	{
		int pos = s.find('\"',1);
		title = s.substr(1,pos);
		pos += 5;
		author = s.substr(pos);
		Book b = Book(title,author);
		books.push_back(b);
		value[title] = 1;
	}
	sort(books.begin(),books.end());//对书进行升序排序 
	while(getline(cin,s) && s != "END")
	{
		if(s[0] == 'B')
		{
			title = s.substr(8);
			value[title] = 0;//书借走之后要将标记记为0 
		}
		else if(s[0] == 'R')
		{
			title = s.substr(8);
			value[title] = 2;//归还未上架的书记为2 
		} 
		else
		{
			for(int i = 0 ; i < books.size() ; i++)
			{
				if(value[books[i].title] == 2)
				{
					int j;
					for(j = i-1 ; j >= 0 ;j--)//找到当前第i本书应该插入的位置j 
					{
						if(value[books[j].title] == 1)
							break;
					}
					cout << "Put \""<<books[i].title<<" ";
					if(j != -1)
						cout << "after \"" <<books[j].title <<endl;
					else
				 	 	cout << "first" <<endl;
					value[books[i].title] = 1;
				}
			}
			cout << "END\n";
		} 
	}
	return 0;
} 
