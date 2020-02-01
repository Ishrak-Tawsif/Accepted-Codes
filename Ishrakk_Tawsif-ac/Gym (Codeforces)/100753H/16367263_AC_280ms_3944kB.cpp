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
#define casepf(nn)              printf ("Case %d:\n",nn)
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

unordered_map <string,int> id;
vector <int> graph[160005],list_;
int vis[160005];

pair <string,string> convert(string str)
{
    int len = str.length(),fl = 0;

    string fs = "",sn = "";
    for(int i=0; i<len; i++)
    {
        if(str[i] == ':')
        {
            fl = 1;
            continue;
        }
        if(!fl) fs += str[i];
        else sn += str[i];
    }

    return mp(fs,sn);
}

void dfs(int cur)
{
    vis[cur] = 1;
    for(auto x : graph[cur])
    {
        if(!vis[x]) dfs(x);
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    string str;
    int k,curid = 0;

    for(int i=1; i<=n; i++)
    {
        cin>> str>> k;
//cout<<"hurr "<<id[str]<<endl;
        if(!id[str]) id[str] = ++curid;
        int parent = id[str];//cout<<"parent "<<str<<endl;

        pair <string,string> pii = convert(str);

        if(pii.second == "PROGRAM") list_.pb(id[str]);

        //if(!k) cin>> str;
        for(int i=0; i<k; i++)
        {
            cin>> str;//cout<<" "<<str<<endl;
            if(!id[str]) id[str] = ++curid;
            graph[id[str]].pb(parent);
        }
    }
//out(list_.size());
    for(int i=0; i<list_.size(); i++)
    {
        int now = list_[i];//cout<<"now "<<now<<endl;
        if(!vis[now])dfs(now);
    }
//out(curid);
    int cnt = 0;
    for(int i=1; i<=curid; i++) if(!vis[i]) cnt++;
    printf("%d\n", cnt);

    return 0;
}

//pair <string,string> convert(string str)
//{
//    int len = str.length(),fl = 0;
//
//    string fs = "",sn = "";
//    for(int i=0; i<len; i++)
//    {
//        if(str[i] == ":")
//        {
//            fl = 1;
//            continue;
//        }
//        if(!fl) fs += str[i];
//        else sn += str[i];
//    }
//
//    return mp(fs,sn);
//}

//int main()
//{
//    int n;
//
//    scanf("%d", &n);
//
//    string str;
//    int k;
//
//    for(int i=1; i<=n; i++)
//    {
//        cin>> str;
//        int curexid = 0,curmeid = 0;
//        ///
//        pair <string,string> pii = convert(str);
//        cout << pii.first << " " << pii.second <<endl;
//        if(!id[pii.first]) id[pii.first] = ++curexid;
//        if(!id[pii.second]) id[pii.second] = ++curmeid;
//
//        ///jodi program method thake
//        if(pii.second == "PROGRAM")
//        {
//            run[id[pii.first]] = id[pii.second];
//                                                             [id[pii.second]] = id[pii.first];
//        }
//        methodlist[]
//        int idex = id[pii.first];
//        int idme = id[pii.second];
//
//        methodlist[idex].pb(idme);
//        ///
//
//        scanf("%d", &k);
//
//        string temp;
//        if(!k) cin>> temp;
//
//        for(int i=0; i<k; i++)
//        {
//            cin>> temp;
//            pii = convert(temp);
//            if(!id[pii.first]) id[pii.first] = ++cuexid;
//            if(!id[pii.second]) id[pii.second] = ++curmeid;
//
//            graph[]
//        }
//    }
//
//    return 0;
//}