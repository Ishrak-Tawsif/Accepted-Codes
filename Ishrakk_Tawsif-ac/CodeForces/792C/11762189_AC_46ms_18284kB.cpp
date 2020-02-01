#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

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
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007

string str;
int len,dp[100000+27][5][2],vis[100000+27][5][2];

int call(int i,int j,int nici)
{
    if(i>=len) {if(j == 0) return 0; else return -inf;}
    if(i>=len) return -inf;
    if(dp[i][j][nici] != -1) return dp[i][j][nici];

    int ans = -inf,ans2=-inf;


    if(str[i] == '0' && nici) ans = call(i+1,((j%3)+((str[i]-'0')%3))%3,1)+1;
    else if(str[i] != '0') ans = call(i+1,((j%3)+((str[i]-'0')%3))%3,1)+1;
    ans2 = call(i+1,j,nici);

    vis[i][j][len] = (ans>ans2)? 1 : 0;

    return dp[i][j][nici] = max(ans,ans2);

}

int washere[100005],flag=0;

void call2(int i,int j,int nici)
{
    if(i>=len) return;
    if(dp[i][j][nici] == call(i+1,j,nici)) {call2(i+1,j,nici); return;}
    if((str[i] == '0' && nici) || str[i] != '0')
    {
        if(dp[i][j][nici] == call(i+1,((j%3)+((str[i]-'0')%3))%3,1)+1){
            flag = 1;//out(i);
            cout<<str[i];
            call2(i+1,((j%3)+((str[i]-'0')%3))%3,1);
            return;
        }
    }
    return;
}

void printans()
{
    int taken = 0;
    for(int i=0; i<len; i++)
    {
        if(vis[i][0] && vis[i][1])
        {
            if(!taken && str[i] == '0') continue;
            else taken++,cout<<str[i];
        }
    }
    pf("\n");
}

int main()
{
    cin>> str;
    len = str.length();

    int zero = 0;

    for(int i=0; i<len; i++) if(str[i] == '0') zero = 1;

    mem(dp,-1);
    int res = call(0,0,0);//out(res);
    if(res == 0 && !zero){pf("-1\n"); return 0;}

    call2(0,0,0);
    
    if(flag == 0) pf("0\n");

    return 0;
}