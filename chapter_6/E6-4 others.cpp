#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn =1e5 + 5;
int last, cur, Next[maxn];
char s[maxn];

int main()
{
    while(~scanf("%s", s + 1))
    {
        int n = strlen(s + 1);
        last = cur = 0;
        Next[0] = 0;
        for(int i = 1; i <= n; i ++)
        {
            char ch = s[i];
            if(ch =='[')
                cur = 0;
            else if(ch ==']')
                cur = last;
            else
            {
                Next[i] = Next[cur];
                Next[cur] = i;
                if(cur == last)
                    last = i;
                cur = i;
            }
            printf("i = %d £¨s[%d] = %c£©: \n", i, i, s[i]);
            printf("cur = %d , last = %d\n", cur, last);
            for(int i = 0; i <= n; i ++)
                printf("Next[%d] = %d\n", i, Next[i]);
            cout << endl;
        }
        for(i = Next[0]; i != 0; i = Next[i])
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}