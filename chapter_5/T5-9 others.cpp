#include <iostream>  
#include <string>  
#include <vector>  
#include <set>  
#include <map>  
#include <sstream>  
#include <fstream>  
#include <stack>  
  
using namespace std;  
  
map<string, long long> array_table;  
map<string,map< long long, long long>> array_value_table;  
  
#define FILE  
  
  
void partition(string origin,string &left,string &right)  
{  
    int index = origin.find_first_of('=',0);  //找到第一个等号 
    if(index!=-1)  //赋值语句 
    {  
        left = origin.substr(0,index);  //将代码左侧字符串赋给left 
        right = origin.substr(index+1);  //将代码右侧字符串赋给right 
    }  
    else //定义语句，右边没有值 
    {  
        left = origin;  
        right = "";  
    }  
}  
  
void getArray(string str,string &name, string &value)  
{  
    int begin = str.find_first_of('[',0);  //找到第一个‘[’ 的位置 
    int end = str.find_last_of(']');  		// find_last_of(']')
    if(begin!=-1)  
    {  
        name = str.substr(0,begin);  //获取数组名 
        value = str.substr(begin+1,end-begin-1);  //获取数组大小 
    }  
    else  				//若只是数字则只返回一个数字 
    {  
        name = "";  
        value = str;  
    }  
}  
  
bool isValue(string value)  
{  
    int index = value.find_first_of('[',0);  
    if(index!=-1)  
        return true;  
    return false;  
}  
  
long long calculateArray(string str)  
{  
    string name,value;  
    getArray(str,name,value);  // 获取下标表达的数组名（如果有的话）和值 
    stack<string> s;  //声明一个栈用来存贮方便计算下标表达式 
    long long ans;  //定义答案 
    while(name!="")  //没有需要继续拆解的表达式 
    {  
        string left,right;   //这里其实应该是name和value 
        getArray(value,left,right);  //表达式
        if (array_table.count(name)==0)  //如果发现该数组不存在则发现bug，返回-1 
        {   
            return -1;  
        }  
        value = right;  //令value获取出的值 
        s.push(name);  //将该数组压入栈中 
        name = left;  // 获取该新的数组名 
  
    }  
    ans = atoi(value.c_str());  //最内侧数组标的值 
    if(ans<0)  //小于0说明出bug 
        return -1;  
    while (!s.empty())  //当栈不为空时 
    {  
        string left = s.top();  //获取最内侧数组名 
        long long num = array_table[left];  //该数组名的大小 
        if(ans>=num)  //如果 最内侧数组标的值 大于 该数组的下标大小则说明下标越界 
            return -1;  
        if(array_value_table[left].count(ans)==0)  //该数组的该下标未赋值， 
            return -1;  
        ans = array_value_table[left][ans];  //ans等于该数组该位置的大小 
        s.pop();  					//pop出栈 
    }  
    return ans;  //返回ans 
}  
  
int main(int argc, char* argv[])  
{  
#ifdef FILE  
    ifstream in("data.txt");  
    ofstream out("output.txt");  
    cin.rdbuf(in.rdbuf());  
    cout.rdbuf(out.rdbuf());  
#endif  
    string str;  //存储一行代码 
    bool mark = false,isfirst = true;  
    int num = 0;  
    while(cin>>str)  //输入一行代码 
    {  
        if(str!=".") 
        {  
            mark = false;  
            num++;  //代码行数加一 
            string left,right;  //存储等号左右两边的内容 
            partition(str,left,right);  //获得该行代码左右两侧内容 
            if(right=="")  					//定义语句 
            {  
                string name,value;  
                getArray(left,name,value);  //获取定义数组的名字和大小 
                array_table[name] = atoi(value.c_str());  //用map映射数组名和数组大小，
														  //atoi函数可以将字符串转换为数字，
														  //无法转换时返回0，遇到第一个非数字字符时停止转换 
            }  
            else 							//赋值语句 
            {  
                string name, value;  
                long long ans,temp;  
                getArray(left,name,value); 		 //获取定义数组的名字和大小 
                temp = calculateArray(value);    //计算赋值语句中数组下标的大小 
                ans = calculateArray(right);  	//计算右侧赋值的大小 
                if(temp>=0&&temp<array_table[name]&&ans!=-1)  //无bug 
                {  
                    array_value_table[name][temp] = ans;  // 进行赋值 
                }  
                else  //有bug 输出 
                {  
                    if(isfirst)  //判断是否是第一次出现bug 
                    {  
                        cout<<num<<endl;   
                        isfirst = false;  
                    }  
                }  
            }  
        }  
        else  //出入结束 
        {  
            array_table.clear(); //初始化 
            array_value_table.clear();  
            if(mark)  //连续输出'.' 结束程序 
                break;  
            else //无bug，初始化 
            {  
                if(isfirst)  
                    cout<<0<<endl;  
                mark = true;  
                isfirst = true;  
                num = 0;  
            }  
        }  
    }  
    return 0;  
}  
