//ˮ�⣬����ѧϰ�������Դ�����
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100;

int main()
{
	int num,n,kase=0;
	int marbles[maxn];
	int wanted;
	while(cin >> num >> n && num)
	{
		for(int i = 0 ; i < num ; i++)
			cin >> marbles[i];
		sort(marbles,marbles+num);//�Դ�����
		cout << "CASE# "<<++kase<<":\n";
		while(n--)
		{
			cin >> wanted;
			int loc = lower_bound(marbles,marbles+num,wanted) - marbles;//��������ǵݼ�marbles[]���ܲ���wanted����Сλ��
																		//ע��ú������ص�ָ�룬��Ҫ��ȥԭ������ܻ�����λ��
			if(marbles[loc] == wanted)
				cout << wanted << " found at " << loc+1 << endl;//lower_bound���ص�λ����Ϣ�Ǵ�0��ʼ
			else
				cout << wanted << " not found" << endl;
		}
	}
	return 0;
}