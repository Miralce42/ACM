#include <bits/stdc++.h>  
using namespace std;  
const int N = 1005;  
bool lck;  
deque<int> qr;//ִ�ж���  
queue<int> qb;//�ȴ�����  
vector<string> prg[N];  
string s;  
int t[N], p[N], var[26], lim;  
  
void run(int i)  
{  
    int rt = lim, v;  //����ִ��ʱ�䲢��ֵ 
    string cur;  //���嵱ǰִ����� 
    while(rt > 0)  //ִ��ʱ�仹�еĻ�����ִ�� 
    {  
        cur = prg[i][p[i]];  // ��ǰִ�����ʱprg[i]������ĵ�p[i]����� 
        if(cur[2] == '=')  // ��ֵ  
        {  
            rt -= t[0];  //ʣ��ʱ���ȥִ��ʱ�� 
            v = cur[4] - '0';  //��ȡҪ����ֵ 
            if(cur.size() == 6) v = v * 10 + cur[5] - '0';  
            var[cur[0] - 'a'] = v;  
        }  
        else if(cur[2] == 'i')   //print  
        {  
            rt -= t[1];  
            printf("%d: %d\n", i, var[cur[6] - 'a']);  
        }  
        else if(cur[2] == 'c')   //lck  
        {  
            rt -= t[2];  
            if(lck)  //����Ѿ����� 
            {  
                qb.push(i);  //�򽫸�������������� 
                return;  
            }  
            else lck = true;  //û�����������ִ�� 
        }  
        else if(cur[2] == 'l')  //unlock  
        {  
            lck = false;  
            rt -= t[3];  
            if(!qb.empty())  //���������������Ԫ�ض� 
            {  
                v = qb.front();  
                qb.pop();  
                qr.push_front(v);  
            }  
        }  
        else return;  //end  
        ++p[i];  //��i�������´�Ҫִ�����++ 
    }  
    qr.push_back(i);  // 
}  
  
int main()  
{  
    int cas, n;  
    scanf("%d", &cas);  
    while(cas--)  //�ִΣ����ı�׼������û���ִ� 
    {  
        scanf("%d", &n);  //������ 
        for(int i = 0; i < 5; ++i)  
            scanf("%d", &t[i]);  //ÿ�����ʹ���ִ��ʱ�� 
        scanf("%d", &lim);  //ÿ�������ִ�е�����ʱ�� 
  
        for(int i = 1; i <= n; ++i)  //��ȡ���� 
        {  
            prg[i].clear();  
            while(getline(cin, s))  
            {  
                if(s == "") continue;  
                prg[i].push_back(s);  //��ȡ��i���������� 
                if(prg[i].back() == "end") break;  
            }  
            qr.push_back(i);  //����������˳�����˫��ִ�ж��� 
        }  
  
        memset(p, 0, sizeof(p));   
        memset(var, 0, sizeof(var));  
        while(!qr.empty())  //���ִ�ж��в�Ϊ�������ִ�� 
        {  
            int cur = qr.front();  //��ȡ��ǰִ�еĳ������ 
            qr.pop_front();  //���� 
            run(cur);  //ִ�и������ 
        }  
        if(cas) puts("");  
    }  
    return 0;  
}  
