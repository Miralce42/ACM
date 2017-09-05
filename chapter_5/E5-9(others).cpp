#include<iostream>  
#include<cstdio>  
#include<map>  
#include<string>  
#include<vector>  
using namespace std;  
  
const int ROW = 10000 + 10;  //定义最大行数
const int COL = 10 + 5;  //定义最大列数
int n,m;  //定义输入的行列数
map<string,int>IDcache;  //每个字符串对应一个数字，该数字是该字符串在Strcache中的下标
vector<string>Strcache;  //用于存储所有字符串
vector<int>Text[ROW];	//存储字符串方阵，用数字表示
  
struct node  //点 结构体
{  
    int x,y;  
    node(int x,int y):x(x),y(y){}  
    bool operator < (const node& r) const { return x<r.x || x==r.x && y<r.y; }  
};  
map<node,int> data;  //每个点对应字符串对应的数字的映射
  
int ID_alloc(string str){  //给每个字符串分配对应的数字
    if(IDcache.count(str)) return IDcache[str];  //如果如果字符串对应的数字已经存在，则直接返回
    Strcache.push_back(str);				  //新字符串放入字符串存储vector中
    return IDcache[str] = Strcache.size()-1;  //将该字符串与Strcache中所处的位置映射起来
}  
  
void read() 
{  
    string str;  //定义字符串
    char ch=getchar();  //获取数字后面的/n //
    for(int i=0;i<n;i++)  
    {  
        for(;;)  
        {  
            ch=getchar();  //获取单个字符
            if(ch=='\n'||ch=='\r'){  //如果出现换行
                if(!str.empty()) Text[i].push_back(ID_alloc(str));  //先获取该字符串的编号，然后放入存储二维int数组的第i行中
                str="";//临时字符串清空
				break;  
            }  
            if(ch!=',') str += ch;  //除了‘，’之外的字符，存入str中
            else
			{ 
				Text[i].push_back(ID_alloc(str)); //出现‘，’说明一句话结束，先获取该字符串的编号，然后放入存储二维int数组的第i行中
				str=""; //临时字符串清空
			}  
        }  
    }  
}  
  
void solve()  
{  
    int x,y,c1,c2;  
    for(c1=0;c1<m;c1++){		//对列进行循环
        for(c2=c1+1;c2<m;c2++){  
            data.clear();		//清空date的数据
            for(int r=0;r<n;r++){  //对行进行循环
                x=Text[r][c1]; y=Text[r][c2];  //根据字符串对应的数字，判断两个字符串是否相同
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
