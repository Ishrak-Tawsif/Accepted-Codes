#include <bits/stdc++.h>
using namespace std;

int a,b,dp[13][13];

int call(int i,int j)
{
    if(i == a && j == b) return 1;
    if(i>a) return 0;
    if(j>b) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = call(i+1,j) + call(i,j+1);

    return dp[i][j] = ans;
}

int main()
{
    //long long a,b;

    while(scanf("%d %d", &a,&b))
    {
        if(a == -1 && b == -1) break;

        for(int i=0; i<13; i++) for(int j=0; j<13; j++) dp[i][j] = -1;

        int sum = call(0,0);

        if(sum == (a+b)) printf("%d+%d=%d\n",a,b,(a+b));
        else printf("%d+%d!=%d\n",a,b,(a+b));
    }
    return 0;
}