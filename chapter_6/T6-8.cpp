#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<set>

using namespace std;

void matrix_to_num(int r, int c, int len, int dep, int dir, int num);
void num_to_matrix(int r, int c, int len, int dep);
void get_dir(int num);

const int MAXN = 64 + 10;

int matrix[MAXN][MAXN];    //���ڴ洢����������� 
set<int> black;			   //���ڴ洢�ڿ��������� 
int n, dirs[MAXN];			//dirs:���ڴ洢һ�����ִ����5���Ƶĸ�λ���� 

int main()
{
	//freopen("input.txt","r",stdin); 
	//freopen("output.txt","w",stdout); 
	int kase = 0;cin >> n;
	while (n)
	{
		cout << "Image " << ++kase << endl;
		if (n > 0)             	//����ת���� 
		{
			getchar();
			black.clear();
			for (int i = 0; i < n; i++)	
			{
				for (int j = 0; j < n; j++)
				{
					char ch = getchar();
					matrix[i][j] = ch - '0';
				}
				getchar();
			}
			matrix_to_num(0, 0, n, 1, 0, 0);  
			int cnt = 0;
			for(set<int>::iterator it = black.begin() ; it != black.end();it++) //������֣�ע���ʽ 
			{
				if (cnt % 12 == 0 && cnt) cout << endl;
				if (cnt % 12 != 0) cout << " ";
				cout << *it; cnt++;
			}
			if (black.size() != 0) cout << endl;
			cout << "Total number of black nodes = " << black.size()<< endl;
		}
		else											//����ת���� 
		{
			n = -n;
			int num;
			memset(matrix, 0, sizeof(matrix));	//��ʼ������ 
			while (cin >> num && num != -1)				//��ÿ������������������������Ϳ�� ����1�� 
			{
				get_dir(num);					//10����ת5���� 
				num_to_matrix(0, 0, n,1);		 
			}
			for (int i = 0; i < n; i++)		//����������,��Ҫע���ʽ 
			{
				for (int j = 0; j < n; j++)
				{
					if (matrix[i][j]==1) cout << "*";
					else cout << ".";
				}
				cout << endl;
			}
		}
		cin >> n;
		if(n) cout << endl;				//ÿ���������֮���п��У����һ���������Ҫ���� 
	}
	return 0;
}

void num_to_matrix(int r, int c, int len,int dep)  
{
	if(!dirs[dep])						//��ʱ���Ӿ��������������ʾ�ģ�����Ϳ�ڴ��� 
	{
		for (int i = r; i < r + len; i++)
		{
			for (int j = c; j < c + len; j++)
			{
				matrix[i][j] = 1;
			}
		}
	}
	else							//����ÿһ�����5���ƴ���ķ�λѡ����һ���Ӿ����λ�� 
	{
		switch (dirs[dep])
		{
		case 1:num_to_matrix(r, c, len / 2, dep + 1); break;
		case 2:num_to_matrix(r, c + len / 2, len / 2, dep + 1); break;
		case 3:num_to_matrix(r + len / 2, c, len / 2, dep + 1); break;
		case 4:num_to_matrix(r + len / 2, c + len / 2, len / 2, dep + 1); break;
		}
	}
}

void get_dir(int num)					//10����ת5���ƣ�����5���Ƶĸ�λ����dirs�� 
{
	memset(dirs, 0, sizeof(dirs));
	for (int i = 64; i > 0 ; i--)
	{
		int x = num / pow(5, i);
		if (x > 0)
		{
			dirs[i + 1] = x;
			num = num - x * pow(5, i);
		}
		
	}
	dirs[1] = num;
}

void matrix_to_num(int r, int c, int len, int dep,int dir,int num)
{
	int new_num = 0;
	bool hava_white = false, hava_black = false;		//�Ƿ��кڿ���߰׿� 
	for (int i = r; i < r+len; i++)
	{
		for (int j = c; j < c+len; j++)
		{
			if (matrix[i][j] == 0) hava_white = true;
			if (matrix[i][j] == 1) hava_black = true;
		}
		if (hava_white && hava_black) break;
	}
	if (dep > 1)								//����ò�����ʾ��5�������� 
		new_num = pow(5, dep - 2)*dir + num;
	if (hava_white && hava_black)					//����ǻ�ɫ�ģ��ڰ׿춼�У� ���������Ӿ������DFS��ֱ���ҵ���ɫ���� 
	{
		matrix_to_num(r, c, len / 2, dep + 1, 1, new_num);
		matrix_to_num(r, c + len / 2, len / 2, dep + 1, 2, new_num);
		matrix_to_num(r + len / 2, c, len / 2, dep + 1, 3, new_num);
		matrix_to_num(r + len / 2, c + len / 2, len / 2, dep + 1, 4, new_num);
	}
	else if (hava_black)						//�ҵ����ھ��󣨴��ڣ��������� ��������������ֲ���set�� 
		black.insert(new_num);
	return;								//��ɫֱ�ӷ��ء� 
}
