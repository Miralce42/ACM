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
    int index = origin.find_first_of('=',0);  //�ҵ���һ���Ⱥ� 
    if(index!=-1)  //��ֵ��� 
    {  
        left = origin.substr(0,index);  //����������ַ�������left 
        right = origin.substr(index+1);  //�������Ҳ��ַ�������right 
    }  
    else //������䣬�ұ�û��ֵ 
    {  
        left = origin;  
        right = "";  
    }  
}  
  
void getArray(string str,string &name, string &value)  
{  
    int begin = str.find_first_of('[',0);  //�ҵ���һ����[�� ��λ�� 
    int end = str.find_last_of(']');  		// find_last_of(']')
    if(begin!=-1)  
    {  
        name = str.substr(0,begin);  //��ȡ������ 
        value = str.substr(begin+1,end-begin-1);  //��ȡ�����С 
    }  
    else  				//��ֻ��������ֻ����һ������ 
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
    getArray(str,name,value);  // ��ȡ�±����������������еĻ�����ֵ 
    stack<string> s;  //����һ��ջ����������������±���ʽ 
    long long ans;  //����� 
    while(name!="")  //û����Ҫ�������ı��ʽ 
    {  
        string left,right;   //������ʵӦ����name��value 
        getArray(value,left,right);  //���ʽ
        if (array_table.count(name)==0)  //������ָ����鲻��������bug������-1 
        {   
            return -1;  
        }  
        value = right;  //��value��ȡ����ֵ 
        s.push(name);  //��������ѹ��ջ�� 
        name = left;  // ��ȡ���µ������� 
  
    }  
    ans = atoi(value.c_str());  //���ڲ�������ֵ 
    if(ans<0)  //С��0˵����bug 
        return -1;  
    while (!s.empty())  //��ջ��Ϊ��ʱ 
    {  
        string left = s.top();  //��ȡ���ڲ������� 
        long long num = array_table[left];  //���������Ĵ�С 
        if(ans>=num)  //��� ���ڲ�������ֵ ���� ��������±��С��˵���±�Խ�� 
            return -1;  
        if(array_value_table[left].count(ans)==0)  //������ĸ��±�δ��ֵ�� 
            return -1;  
        ans = array_value_table[left][ans];  //ans���ڸ������λ�õĴ�С 
        s.pop();  					//pop��ջ 
    }  
    return ans;  //����ans 
}  
  
int main(int argc, char* argv[])  
{  
#ifdef FILE  
    ifstream in("data.txt");  
    ofstream out("output.txt");  
    cin.rdbuf(in.rdbuf());  
    cout.rdbuf(out.rdbuf());  
#endif  
    string str;  //�洢һ�д��� 
    bool mark = false,isfirst = true;  
    int num = 0;  
    while(cin>>str)  //����һ�д��� 
    {  
        if(str!=".") 
        {  
            mark = false;  
            num++;  //����������һ 
            string left,right;  //�洢�Ⱥ��������ߵ����� 
            partition(str,left,right);  //��ø��д��������������� 
            if(right=="")  					//������� 
            {  
                string name,value;  
                getArray(left,name,value);  //��ȡ������������ֺʹ�С 
                array_table[name] = atoi(value.c_str());  //��mapӳ���������������С��
														  //atoi�������Խ��ַ���ת��Ϊ���֣�
														  //�޷�ת��ʱ����0��������һ���������ַ�ʱֹͣת�� 
            }  
            else 							//��ֵ��� 
            {  
                string name, value;  
                long long ans,temp;  
                getArray(left,name,value); 		 //��ȡ������������ֺʹ�С 
                temp = calculateArray(value);    //���㸳ֵ����������±�Ĵ�С 
                ans = calculateArray(right);  	//�����Ҳำֵ�Ĵ�С 
                if(temp>=0&&temp<array_table[name]&&ans!=-1)  //��bug 
                {  
                    array_value_table[name][temp] = ans;  // ���и�ֵ 
                }  
                else  //��bug ��� 
                {  
                    if(isfirst)  //�ж��Ƿ��ǵ�һ�γ���bug 
                    {  
                        cout<<num<<endl;   
                        isfirst = false;  
                    }  
                }  
            }  
        }  
        else  //������� 
        {  
            array_table.clear(); //��ʼ�� 
            array_value_table.clear();  
            if(mark)  //�������'.' �������� 
                break;  
            else //��bug����ʼ�� 
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
