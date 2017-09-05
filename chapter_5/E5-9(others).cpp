#include<iostream>  
#include<cstdio>  
#include<map>  
#include<string>  
#include<vector>  
using namespace std;  
  
const int ROW = 10000 + 10;  //�����������
const int COL = 10 + 5;  //�����������
int n,m;  //���������������
map<string,int>IDcache;  //ÿ���ַ�����Ӧһ�����֣��������Ǹ��ַ�����Strcache�е��±�
vector<string>Strcache;  //���ڴ洢�����ַ���
vector<int>Text[ROW];	//�洢�ַ������������ֱ�ʾ
  
struct node  //�� �ṹ��
{  
    int x,y;  
    node(int x,int y):x(x),y(y){}  
    bool operator < (const node& r) const { return x<r.x || x==r.x && y<r.y; }  
};  
map<node,int> data;  //ÿ�����Ӧ�ַ�����Ӧ�����ֵ�ӳ��
  
int ID_alloc(string str){  //��ÿ���ַ��������Ӧ������
    if(IDcache.count(str)) return IDcache[str];  //�������ַ�����Ӧ�������Ѿ����ڣ���ֱ�ӷ���
    Strcache.push_back(str);				  //���ַ��������ַ����洢vector��
    return IDcache[str] = Strcache.size()-1;  //�����ַ�����Strcache��������λ��ӳ������
}  
  
void read() 
{  
    string str;  //�����ַ���
    char ch=getchar();  //��ȡ���ֺ����/n //
    for(int i=0;i<n;i++)  
    {  
        for(;;)  
        {  
            ch=getchar();  //��ȡ�����ַ�
            if(ch=='\n'||ch=='\r'){  //������ֻ���
                if(!str.empty()) Text[i].push_back(ID_alloc(str));  //�Ȼ�ȡ���ַ����ı�ţ�Ȼ�����洢��άint����ĵ�i����
                str="";//��ʱ�ַ������
				break;  
            }  
            if(ch!=',') str += ch;  //���ˡ�����֮����ַ�������str��
            else
			{ 
				Text[i].push_back(ID_alloc(str)); //���֡�����˵��һ�仰�������Ȼ�ȡ���ַ����ı�ţ�Ȼ�����洢��άint����ĵ�i����
				str=""; //��ʱ�ַ������
			}  
        }  
    }  
}  
  
void solve()  
{  
    int x,y,c1,c2;  
    for(c1=0;c1<m;c1++){		//���н���ѭ��
        for(c2=c1+1;c2<m;c2++){  
            data.clear();		//���date������
            for(int r=0;r<n;r++){  //���н���ѭ��
                x=Text[r][c1]; y=Text[r][c2];  //�����ַ�����Ӧ�����֣��ж������ַ����Ƿ���ͬ
                node p(x,y);	//
                if(!data.count(p)) data[p]=r;  
                else{  
                    cout<<"NO"<<endl;  
                    cout<<data[p]+1<<" "<<r+1<<endl;  
                    cout<<c1+1<<" "<<c2+1<<endl;  
                    return;  
                }  
            }  
        }  
    }  
    cout<<"YES\n";  
}  
int main()  
{  
    while(cin>>n>>m){  
        read();  
        solve();  
        for(int i=0;i<n;i++) Text[i].clear();  
        IDcache.clear(); Strcache.clear();  
    }  
    return 0;  
}  
