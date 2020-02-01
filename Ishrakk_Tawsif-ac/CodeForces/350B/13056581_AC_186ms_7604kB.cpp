#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

/*#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define loop1(var,start,till)   for(int var=start; var<=till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define all(a)                  (a.begin(),a.end())
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

vector <int> hotel,ans,res,vv[100005];
int cnt[100005];

void bfs(int temp)
{//out(vv[temp].size());
    if(cnt[temp]>1) return;
    ans.clear();
    ans.pb(temp);
    queue <int> q;
    q.push(temp);

    while(!q.empty())
    {
        int now = q.front(); q.pop();
        if(vv[now].size() == 1)
        {
            int cur = vv[now][0];
            if(cnt[cur]<=1)ans.pb(cur);
            if(cnt[cur]<=1)q.push(cur);
        }
        else break;
    }
    if(ans.size()>res.size()) res = ans;
}

int main()
{
    int n,temp;

    sf(n);

    for(int i=1; i<=n; i++)
    {
        sf(temp);
        if(temp == 1) hotel.pb(i);
    }
    for(int i=1; i<=n; i++)
    {
        sf(temp);
        if(temp)vv[i].pb(temp),cnt[temp] ++;
    }

    for(int i=0; i<hotel.size(); i++)
    {
        temp = hotel[i];
        bfs(temp);
    }
    out(res.size());
    for(int i=res.size()-1; i>=0; i--)
    {
        if(i == res.size()-1) pf("%d", res[i]);
        else pf(" %d",res[i]);
    }pf("\n");
    return 0;
}