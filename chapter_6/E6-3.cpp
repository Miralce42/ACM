#include<iostream>
#include<cstring>
#include<string> 
#include<stack>

using namespace std;

void read();
void cal(string s);

struct Matrix
{
	int x;
	int y;
	Matrix(){}
};

const int MAXN = 26 + 4;

Matrix m[MAXN];

int main()
{
	memset(m, 0, sizeof(m)); //��ʼ��m
	int n;
	cin >> n;
	getchar();
	while (n--)
	{
		read();//�����������n������
	}
	string s;
	while (cin >> s)
	{
		cal(s);//����������˱�ﲢ��� 
	}
	return 0;
}


void cal(string s)
{
	int sum = 0;
	stack<Matrix> st;
	if (s.length() == 1)  //���ֻ��һ��������������Ϊ0 
	{
		cout << sum << endl;
		return;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			continue;
		else if (s[i] == ')') //����')'��Ҫ����ջ�����ϲ���������� 
		{
			Matrix a, b, t;
			b = st.top(); st.pop();//������ȳ�
			a = st.top(); st.pop();
			if (a.y != b.x) 	//�޷����� 
			{
				cout << "error" << endl;
				return;
			}
			else     			//�������ɵ��¾���Ȼ�����ջ�� 
			{
				t.x = a.x;
				t.y = b.y;
				st.push(t);
				sum += a.x * a.y * b.y;
			}
		}
		else
			st.push(m[s[i] - 'A']);
	}
	cout << sum << endl;
}

void read()
{
	string s;
	int a,b;
	cin >> s >> a >> b;
	m[s[0] - 'A'].x = a;
	m[s[0] - 'A'].y = b;
}
