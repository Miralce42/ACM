//错误的 
#include <iostream>
#include <iostream>
#include <queue>
#include <deque>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;

void inti(int n);
void run(int i);

const int maxn = 1000 + 10;

deque<int> ex_dq;
queue<int> st_q;
map<char, int> var;
vector<string> prom[maxn];
int t[5], p[maxn], lim;
bool lck;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int kase, n;
	cin >> kase;
	while (kase--)
	{
		cin >> n >> t[0] >> t[1] >> t[2] >> t[3] >> t[4] >> lim;
		getchar();
		inti(n);
		for (int i = 0; i < n; i++)
		{
			string s;
			while (getline(cin, s))
			{
                if(s == "") continue; 
				prom[i].push_back(s);
				if (s == "end")
					break;
			}
			ex_dq.push_back(i);
		}
		while (!ex_dq.empty())
		{
			int i = ex_dq.front();
			ex_dq.pop_front();
			run(i);
		}
	}
	return 0;
}

void run(int i)
{
	int rt = lim;
	while (rt>0)
	{
		string s = prom[i][p[i]];
		if (s[2] == '=')			//赋值语句 
		{
			rt -= t[0];
			char sv = s[0];
			int v = s[4] - '0';//值为一位 
			if (s.length() == 6)
				v = v * 10 + (s[5] - '0');//值为两位 
			var[sv] = v;
		}
		else if (s[2] == 'i')	//输出语句 
		{
			rt -= t[1];
			cout << i+1 << ": " << var[s[6]] << endl;
		}
		else if (s[2] == 'c') //lock语句 
		{
			rt -= t[2];
			if (lck)
			{
				st_q.push(i);
				return;
			}
			else
				lck = true;
		}
		else if (s[2] == 'l')//unlock语句 
		{
			lck = false;
			rt -= t[3];
			if (!st_q.empty())
			{
				i = st_q.front();
				st_q.pop();
				ex_dq.push_front(i);
			}
		}
		else
			return;
		p[i]++;
	}
	ex_dq.push_back(i);
}

void inti(int n)
{
	lck = false;
	ex_dq.clear();
	var.clear();
	memset(p, 0, sizeof(p));
	for (int i = 0; i < n; i++)
		prom[i].clear();
}
