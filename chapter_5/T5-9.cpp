#include<iostream>
#include<map>
#include<string>
#include<stack>

#define local
#define ll long long 

using namespace std;

int deal(string s);
void partition(string s, string &left, string &right);
void getValue(string s, string &name, string &value);
ll calculateArray(string s);

map<string, ll> array_table;//映射数组名和数组大小 
map<string, map<ll, ll>> array_value_table;//映射数组元素对应的值 
bool isfirst, mark;
int num;

int main()
{
#ifdef local
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	string s;
	mark = false; isfirst = true; num = 0;
	while (cin >> s)
	{
		if (!deal(s))
			break;
	}
	return 0;
}

int deal(string s)
{
	if (s != ".")
	{
		mark = false;
		num++;
		string left, right, name, value;
		partition(s, left, right);
		getValue(left, name, value);
		//		cout << "name=" << name << "\nvalue=" << value << "\nright=" << right <<endl;
		if (right == "")
		{
			array_table[name] = atoi(value.c_str());
		}
		else
		{
			ll ans, idx;
			idx = calculateArray(value);
			ans = calculateArray(right);
			if (idx >= 0 && idx < array_table[name] && ans != -1)
			{
				array_value_table[name][idx] = ans;
			}
			else
			{
				if (isfirst)
				{
					cout << num << endl;
					isfirst = false;
				}
			}
		}
	}
	else
	{
		array_table.clear();
		array_value_table.clear();
		if (mark)
			return 0;
		else
		{
			if (isfirst)
				cout << 0 << endl;
			mark = true;
			isfirst = true;
			num = 0;
		}
	}
	return 1;
}

ll calculateArray(string s)
{
	string name, value;
	getValue(s, name, value);
	stack<string> st;
	ll ans;
	while (name != "")
	{
		string nm, val;
		if (array_table.count(name) == 0)
		{
			return -1;
		}
		getValue(value, nm, val);
		value = val;
		st.push(name);
		name = nm;
	}
	ans = atoi(value.c_str());
	if (ans < 0)
		return -1;
	while (!st.empty())
	{
		string nm = st.top();
		ll num = array_table[nm];
		if (ans >= num)
			return -1;
		if (array_value_table[nm].count(ans) == 0)
			return -1;
		ans = array_value_table[nm][ans];
		st.pop();
	}
	return ans;
}

void getValue(string s, string &name, string &value)
{
	int begin = s.find_first_of('[', 0);
	int end = s.find_last_of(']');
	if (begin != -1)
	{
		name = s[0];
		value = s.substr(begin + 1, end - begin - 1);
	}
	else
	{
		name = "";
		value = s;
	}
}

void partition(string s, string &left, string &right)
{
	int pos = s.find('=');
	if (pos != -1)
	{
		left = s.substr(0, pos);
		right = s.substr(pos + 1);
	}
	else
	{
		left = s;
		right = "";
	}
}
