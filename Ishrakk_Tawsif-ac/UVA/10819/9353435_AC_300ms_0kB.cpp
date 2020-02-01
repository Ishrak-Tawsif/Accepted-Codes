#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define mx                      5005
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int cap,n,arr[101],val[101],dp[101][15000];

int call(int i,int tk)
{

   if(tk>cap && cap<1800) return -1000;
   if(tk>cap+200) return -1000;
   if(i == n+1)
   {
       if(tk>cap && tk<=2000)
            return -1000;
       return 0;
   }
   if(dp[i][tk] != -1) return dp[i][tk];

        int ans1=0,ans2=0;
        /*if(tk+arr[i]<=cap)*/ans1=max(call(i+1,tk+arr[i])+val[i],call(i+1,tk));

   return dp[i][tk] = ans1;
}

int main()
{
    while(scanf("%d %d", &cap,&n) == 2)
    {
        //if(cap+200>=2000) cap+=200;

        loop(i,1,n+1)
        {
            sf(arr[i]); sf(val[i]);
        }
        mem(dp,-1);
        cout << call(1,0) << endl;
    }

    return 0;
}

/*
500 4
100 2
100 3
200 3
400 4
*/