#include<bits/stdc++.h>
using namespace std;

int dirx[8]={0,0,1,-1,1,1,-1,-1};
int diry[8]={1,-1,0,0,1,-1,1,-1};
#define ll             long long
#define sc1(a)         scanf("%d",&a)
#define llsc1(a)       scanf("%lld",&a)
#define sc2(a,b)       scanf("%d %d",&a,&b)
#define llsc2(a,b)     scanf("%lld %lld",&a,&b)
#define sc3(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define llsc3(a,b,c)   scanf("%lld %lld %lld",&a,&b,&c)
#define pf             printf
#define cpfl(s)        cout<<s<<endl
#define cpf(s)         cout<<s
#define FOR(a)         for(ll i=0;i<a;i++)
#define inf            2e9
#define pr             pair<ll,ll>
#define newline        printf("\n")
#define mem(a,b)       memset(a,b,sizeof(a))
#define srt(a,n)       sort(a,a+n)
#define mx             1200
#define mm             1420
#define mod            1000000007
#define frd            freopen("input.txt","r",stdin)
#define fpf            freopen("output.txt","w",stdout)
int n;
ll ar[mx],dp[mx][mx];
ll solve(int i,int j)
    {
        if(i==j)return ar[i];
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        ll ans=0,ans2=0;

        if(ar[i+1]>=ar[j])ans= solve(i+2,j)+ar[i];
        else ans= solve(i+1,j-1)+ar[i];

        if(ar[i]>=ar[j-1])ans2 = solve(i+1,j-1)+ar[j];
        else ans2=solve(i,j-2)+ar[j];
        return dp[i][j]=max(ans,ans2);
    }
/*void init()
    {
        for(int i=0;i<mx;i++){
            for(int j=0;j<mx;j++)dp[i][j]=-1;
        }
    }*/
int main()
    {
        int c=0;
        ll tot;
        while(cin>>n && n){
            c++;
            tot=0;
            mem(ar,0);
            for(int i=0;i<n;i++){
                cin>>ar[i];
                tot+=ar[i];
            }
            mem(dp,-1);
            //init();
            //cpfl(dp[0][0]);
            ll t=solve(0,n-1);
            //cpfl(t);
            //(t<0)?t=0:t;
            t-=tot-t;
            cpfl("In game "<<c<<", the greedy strategy might lose by as many as "<<t<<" points.");
        }
        return 0;
        
    }