#include <bits/stdc++.h>
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
#define Unique_(a)              sort(all(a));a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000009
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int r,c,vis[103][103],cnt;
vector <int> ans;
string str[103];
queue <int> q;

void dfs(int rr,int cc)
{//cout<<r<<" "<<c<<endl;
    vis[rr][cc] = 1;


    for(int i=0; i<4; i++)
    {
        int tr = rr + dx[i];
        int tc = cc + dy[i];

        if(tr>=0 && tr<r && tc>=0 && tc<c)
        {
            if(!vis[tr][tc] && str[tr][tc] == 'X')q.push(tr),q.push(tc),dfs(tr,tc);
        }
    }
}

int main()
{//WRITE("out.txt");
    int fl = 0,tc = 0;

    while(scanf("%d %d", &c,&r) == 2)
    {
        if(!r && !c) break;


        for(int i=0; i<r; i++) cin>> str[i];//out("ok");

        mem(vis,0);

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {//cout<<i<<" "<<j<<endl;
                if(!vis[i][j] && (str[i][j] == '*' || str[i][j] == 'X'))
                {
                    q.push(i);
                    q.push(j);
                    int totcnt = 0;

                    while(!q.empty())
                    {
                        int curr = q.front(); q.pop();
                        int curc = q.front(); q.pop();

                        for(int k=0; k<4; k++)
                        {
                            int tr = curr + dx[k];
                            int tc = curc + dy[k];

                            if(tr>=0 && tr<r && tc>=0 && tc<c)
                            {
                                //if(str[curr][curc] == 'X' && str[tr][tc] == 'X' && k>=4) continue;
                                if(str[tr][tc] == 'X' && !vis[tr][tc])
                                {
                                    cnt=1,q.push(tr),q.push(tc),dfs(tr,tc),totcnt += cnt;
                                }
                                else if(str[tr][tc] == '*' && !vis[tr][tc])
                                {
                                    vis[tr][tc] = 1,q.push(tr),q.push(tc);
                                }
                            }
                        }
                    }
                    if(totcnt) ans.pb(totcnt);//system("pause");
                }
            }
        }

        sort all(ans);
        pf("Throw %d\n", ++tc);
        for(int i=0; i<ans.size(); i++)
        {
            if(!i) pf("%d", ans[i]);
            else pf(" %d", ans[i]);
        }
        pf("\n\n");

        ans.clear();
    }

    return 0;

}