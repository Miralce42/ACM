#include<iostream>
#include<map>
#include<cstring>
#include <sstream>
#include<string>

using namespace std;

void cal(int p);

map<int, int> sum;
stringstream ss;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	string s;
	int kase = 0;
	while (getline(cin, s) && s != "-1")  
	{
		ss.str(s);		//将s放入ss，用于转换 
		cal(0);
		cout << "Case "<< ++kase <<":\n";
		int i = 0;
		for (map<int,int>::iterator it = sum.begin() ; it != sum.end() ; it++)//遍历结果map 
		{
			cout << it->second;
			if(i<sum.size()-1)	//用于控制输出空格 
				cout << " ";
			i++;
		}
		cout << endl<<endl;
		sum.clear();//清理 
		ss.clear();
	}
	return 0;
}

//递归构造二叉树的过程中计算每个结点所在的列的最新的权值和 
void cal(int p)
{
	int wgt;
	ss >> wgt;
	if (wgt == -1)
		return;
	if (!sum.count(p)) sum[p] = 0;
	sum[p] += wgt;
	cal(p - 1);
	cal(p + 1);
}
