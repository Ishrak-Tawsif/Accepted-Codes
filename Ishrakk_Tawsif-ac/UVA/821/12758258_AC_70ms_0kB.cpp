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
#define mx                      200005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int edge[105][105],vis[105];
vector<int> vv;

int warshall(int n)
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            for(int k=0; k<=n; k++)
            {
                //if(vv[j] == 2 && vv[k] == 3 && vv[i] == 4) cout<<edge[vv[j]][vv[i]]<<" "<<edge[vv[i]][vv[k]]<<endl;
                if(edge[vv[j]][vv[i]] != 2e9 && edge[vv[i]][vv[k]] != 2e9)
                {
                    if(edge[vv[j]][vv[k]]>edge[vv[j]][vv[i]]+edge[vv[i]][vv[k]])
                    {
                        edge[vv[j]][vv[k]] /*= edge[vv[k]][vv[j]]*/ = edge[vv[j]][vv[i]]+edge[vv[i]][vv[k]];
                    }
                }
                //else if()
            }
        }
    }
}

int main()
{
    string str;
    int cs = 0;
    //getchar();
    while(getline(cin,str))
    {//out(str);
        stringstream ss (str);

        for(int i=0; i<105; i++) for(int j=0; j<105; j++) if(i == j)edge[i][j]=0; else edge[i][j] = 2e9;

        int u,v,fl=0;
        vv.clear();
        mem(vis,0);
        while(ss>> u>> v)
        {
            if(!u && !v) break;

            fl = 1;

            edge[u][v] = 1;
            if(!vis[u])vv.pb(u);
            if(!vis[v])vv.pb(v);
            vis[u] = vis[v] = 1;
        }
        if(!fl) break;

        //Unique(vv);
        warshall(vv.size()-1);//out("ok");

        double sum=0;
        int cnt = 0;
        for(int i=0; i<vv.size(); i++)
        {
            u = vv[i];
            for(int j=0; j<vv.size(); j++)
            {
                v = vv[j];
                if(u == v) continue;
                sum += (edge[u][v]*1.0);//cout<<vv[i]<<" "<<vv[j]<<" "<<edge[u][v]<<endl;
                cnt++;
            }
        }//out(sum);
        pf("Case %d: average length between pages = %.3f clicks\n",++cs,(sum/(cnt*1.0)));

        //getchar();
    }

    return 0;
}