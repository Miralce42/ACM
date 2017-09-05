#include <algorithm>  
#include <iostream>  
#include <stdlib.h>  
#include <string.h>  
#include <stdio.h>  
using namespace std;  
#define INF 0x7fffffff  
  
int h[35 * 35], n, m;  
double v, H, k;  
  
int main()  
{  
//    freopen("815.in", "r", stdin);  
  
    int cas = 0;  
    while(scanf("%d%d", &n, &m), n)  
    {  
        n *= m;  
        for(int i = 0; i < n; i++)  
            scanf("%d", h + i);  
        h[n] = INF, n++;  
        sort(h, h + n);  
        scanf("%lf", &v);  
        v /= 100.0;  
        for(i = 1; i <= n; i++)  
        {  
            v += h[i - 1];  
            H = v / i;  
            if(H < h[i])  
            {  
                k = i;  
                break;  
            }  
        }  
        printf("Region %d\n", ++cas);  
        printf("Water level is %.2lf meters.\n", H);  
        printf("%.2lf percent of the region is under water.\n\n", 100.0 * k / (n - 1));  
    }  
    return 0;  
}  