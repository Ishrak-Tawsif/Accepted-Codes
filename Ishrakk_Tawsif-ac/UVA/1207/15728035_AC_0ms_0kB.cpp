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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000007

int dp[1005][1005],n,m;
string x,y;

int call(int i,int j)
{
    if(i>=m) return (n-(j));
    if(j>=n) return (m-(i));
    if(dp[i][j] != -1) return dp[i][j];

    int ans1=inf,ans2=inf,ans3=inf;

    if(x[i] == y[j]) ans1 = call(i+1,j+1);

    ans2 = call(i+1,j) + 1;
    ans2 = min(ans2,call(i,j+1) + 1);
    ans2 = min(ans2,call(i+1,j+1)+1);

    return dp[i][j] = min(ans1,ans2);
}

int main()
{//WRITE("in.txt");
    while(scanf("%d", &m) == 1)
    {
        cin>> x;
        sf(n);
        cin>> y;
        mem(dp,-1);
        cout<<call(0,0)<<endl;
    }
}