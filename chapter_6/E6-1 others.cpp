#include <bits/stdc++.h>  
using namespace std;  
const int N = 1005;  
bool lck;  
deque<int> qr;//执行队列  
queue<int> qb;//等待队列  
vector<string> prg[N];  
string s;  
int t[N], p[N], var[26], lim;  
  
void run(int i)  
{  
    int rt = lim, v;  //定义执行时间并赋值 
    string cur;  //定义当前执行语句 
    while(rt > 0)  //执行时间还有的话继续执行 
    {  
        cur = prg[i][p[i]];  // 当前执行语句时prg[i]个程序的第p[i]条语句 
        if(cur[2] == '=')  // 赋值  
        {  
            rt -= t[0];  //剩余时间减去执行时间 
            v = cur[4] - '0';  //获取要赋的值 
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
            if(lck)  //如果已经上锁 
            {  
                qb.push(i);  //则将改锁放入堵塞队列 
                return;  
            }  
            else lck = true;  //没有上锁则继续执行 
        }  
        else if(cur[2] == 'l')  //unlock  
        {  
            lck = false;  
            rt -= t[3];  
            if(!qb.empty())  //如果堵塞队列里有元素而 
            {  
                v = qb.front();  
                qb.pop();  
                qr.push_front(v);  
            }  
        }  
        else return;  //end  
        ++p[i];  //第i个程序下次要执行语句++ 
    }  
    qr.push_back(i);  // 
}  
  
int main()  
{  
    int cas, n;  
    scanf("%d", &cas);  
    while(cas--)  //轮次，给的标准输入中没有轮次 
    {  
        scanf("%d", &n);  //程序数 
        for(int i = 0; i < 5; ++i)  
            scanf("%d", &t[i]);  //每种类型代码执行时间 
        scanf("%d", &lim);  //每个程序的执行的限制时间 
  
        for(int i = 1; i <= n; ++i)  //获取程序 
        {  
            prg[i].clear();  
            while(getline(cin, s))  
            {  
                if(s == "") continue;  
                prg[i].push_back(s);  //获取第i个程序的语句 
                if(prg[i].back() == "end") break;  
            }  
            qr.push_back(i);  //将程序按输入顺序放入双端执行队列 
        }  
  
        memset(p, 0, sizeof(p));   
        memset(var, 0, sizeof(var));  
        while(!qr.empty())  //如果执行队列不为空则继续执行 
        {  
            int cur = qr.front();  //获取当前执行的程序序号 
            qr.pop_front();  //弹出 
            run(cur);  //执行该条语句 
        }  
        if(cas) puts("");  
    }  
    return 0;  
}  
