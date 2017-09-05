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
		ss.str(s);		//��s����ss������ת�� 
		cal(0);
		cout << "Case "<< ++kase <<":\n";
		int i = 0;
		for (map<int,int>::iterator it = sum.begin() ; it != sum.end() ; it++)//�������map 
		{
			cout << it->second;
			if(i<sum.size()-1)	//���ڿ�������ո� 
				cout << " ";
			i++;
		}
		cout << endl<<endl;
		sum.clear();//���� 
		ss.clear();
	}
	return 0;
}

//�ݹ鹹��������Ĺ����м���ÿ��������ڵ��е����µ�Ȩֵ�� 
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
