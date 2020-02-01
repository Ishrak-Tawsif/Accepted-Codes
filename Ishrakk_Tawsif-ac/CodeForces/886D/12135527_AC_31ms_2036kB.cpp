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

vector <int> graph[27];
int cycle,fl=1,vis[29],ache[29],deg[29],vis2[27][27];
string curstr;

void dfs(int cur,int kontateachi)
{
    if(cycle) return;
    vis2[kontateachi][cur] = 1;
    for(int i=0; i<graph[cur].size(); i++)
    {
        int vv = graph[cur][0];//cout<<kontateachi<<" "<<vv<<endl;;
        //if(vv == kontateachi) {cycle = 1; return;}
        if(!vis2[kontateachi][vv])dfs(vv,kontateachi);
        else {cycle = 1; return;}
    }
}

void dfs2(int cur)
{
    vis[cur] = 1;//cout<<cur<<endl;
    if(!fl) return;
    for(int i=0; i<graph[cur].size(); i++)
    {
        int vv = graph[cur][i];
        if(vis[vv]) {fl=0;return;}
        /*else*/if(!vis[vv]) curstr += (char)(vv+'a'),dfs2(vv);
    }
}

int main()
{
    int n;
    string str,res;

    sf(n);

    for(int i=0; i<n; i++)
    {
        cin>> str;

        int len = str.length();

        for(int i=0; i<len; i++) ache[str[i]-'a'] = 1;
        for(int i=0; i<len-1; i++)
        {
            int u = str[i] - 'a',v = str[i+1] - 'a';//cout<<u<<" //// "<<v<<" "<<count(graph[u].begin(), graph[u].end(),v)<<endl;
            //ache[u] = ache[v] = 1;
            if((count(graph[u].begin(), graph[u].end(),v)) == 0) graph[u].pb(v);
            deg[v]++;
        }
    }//out("ok");

        ///cycle?
        for(int i=0; i<26; i++)
        {
            if(!ache[i]) continue;//out(i);
            if(graph[i].size()>1) {fl = 0; break;}
            dfs(i,i);
            if(cycle) {fl=0;break;}
        }//out(fl);
        if(fl)
        {
            set <string> ss;
            for(int i=0; i<26; i++)
            {
                if(!vis[i] && ache[i] && !deg[i])
                {//out(i);
                    curstr = (char)(i+'a');
                    dfs2(i);
                    ss.insert(curstr);
                    //out(curstr);
                }
            }//out(fl);

            res = "";
            if(fl)
            {
                set <string> :: iterator  it;
                for(it = ss.begin(); it!=ss.end(); it++) res+= *it;
                out(res);
            }
            else out("NO");
        }
        else out("NO");

    return 0;
}