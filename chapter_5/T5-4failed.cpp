//Ê§°ÜµÄ
#include<iostream>
#include<map>

using namespace std;

struct ideal
{
	int at;
	int to;
	ideal(int a,int t):at(a),to(t) {}
	ideal swep()
	{
		return ideal(this->to,this->at);
	}

	bool operator < (const ideal &b) const
	{
		return (at < b.at)&&(to < b.to);
	}

	bool operator == (const ideal &b) const
	{
		return (at == b.at)&&(to == b.to);
	}
};

map<ideal,int> p;

int main()
{
	int n,a,t,sign=1;
	while(cin >> n && n)
	{
		for(int i = 0 ; i < n ; i++)
		{
			p.clear();
			cin >> a >> t;
			ideal idl(a,t);
			ideal test(199,2);
			if(!p.count(idl)) 
				p[idl] = 0;
			p[idl]++;
			ideal sw_idl = idl.swep();
			printf("----------------%d %d\n",p.count(test),p[test] == 1);
			printf("----------------%d %d\n",p.count(sw_idl),p[sw_idl]);
			if(p.count(sw_idl) && p[sw_idl])
			{
				p[sw_idl]--;
				p[idl]--;
			}
		}
		map<ideal,int>::iterator it;
		for(it = p.begin();it != p.end();i++)
		{
			if((*it).second)
			{
				sign = 0;
				break;
			}
		}
		if(sign)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}