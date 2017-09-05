#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm> 

#define local

using namespace std;

void prer(string s, int is_old);
void judge();
void inti();
void print();
void show(string op,int num);

map<string, string> old_dic;
map<string, string> new_dic;
map<string, int> chgd_key;
map<int, int> chgd_num;
vector<string> old_key;
vector<string> new_key;
int ifchg;

int main()
{
#ifdef local
	//freopen("input.txt", "r", stdin);
	//freopen("output.tet","w",stdout);
#endif
	int n;
	cin >> n;
	getchar();
	while (n--)
	{
		inti();
		string s;
		getline(cin, s);
		prer(s, 1);
		getline(cin, s);
		prer(s, 0);
		sort(old_key.begin(), old_key.end());
		sort(new_key.begin(), new_key.end());
		judge();
		print();
		cout << endl;
	}
	return 0;
}

void print()
{
	if (chgd_num[1] > 0) show("+",1);
	if (chgd_num[2] > 0) show("-",2);
	if (chgd_num[3] > 0) show("*",3);
	if (!ifchg)
		cout << "No changes" << endl;
}

void show(string op,int num)
{
	cout << op;
	for (map<string, int>::iterator it = chgd_key.begin(); it != chgd_key.end(); it++)
	{
		if (it->second == num)
		{
			cout << it->first;
			chgd_num[num]--;
			ifchg = 1;
			if (chgd_num[num])
			cout << ",";
			else
			break;
		}
	}
	cout << endl;
}

void judge()
{
	int o = 0, n = 0;
	while (o<old_key.size() && n < new_key.size())
	{
		if (old_key[o] == new_key[n])
		{
			if (old_dic[old_key[o]] != new_dic[new_key[n]])
			{
				chgd_key[old_key[o]] = 3;
				chgd_num[3]++;
			}
			o++; n++;
		}
		else if (old_key[o] < new_key[n])
		{
			chgd_key[old_key[o]] = 2;
			chgd_num[2]++;
			o++;
		}
		else if (old_key[o] > new_key[n])
		{
			chgd_key[new_key[n]] = 1;
			chgd_num[1]++;
			n++;
		}
	}
	while (o<old_key.size())
	{
		chgd_key[old_key[o]] = 2;
		chgd_num[2]++;
		o++;
	}
	while (n < new_key.size())
	{
		chgd_key[new_key[n]] = 1;
		chgd_num[1]++;
		n++;
	}
}

void prer(string s, int is_old)
{
	int pos1 = 0, pos2 = 0;
	string key, value;
	while (s.find(':', pos1 + 1) != s.npos)//定位并获取字符串key和value 
	{
		pos1 = s.find(':', pos1 + 1);
		key = s.substr(pos2 + 1, pos1 - pos2 - 1);
		if (s.find(',', pos2 + 1) == s.npos)
			pos2 = s.length()-1;
		else
			pos2 = s.find(',', pos2 + 1);
		value = s.substr(pos1 + 1, pos2 - pos1 - 1);
		if (is_old)
		{
			old_key.push_back(key);
			old_dic[key] = value;
		}
		else
		{
			new_key.push_back(key);
			new_dic[key] = value;
		}
	}
}

void inti()
{
	ifchg = 0;
	old_dic.clear();
	new_dic.clear();
	chgd_key.clear();
	chgd_num.clear();
	old_key.clear();
	new_key.clear();
	for (int i = 0; i <= 3; i++)
	{
		chgd_num[i] = 0;
	}
}
