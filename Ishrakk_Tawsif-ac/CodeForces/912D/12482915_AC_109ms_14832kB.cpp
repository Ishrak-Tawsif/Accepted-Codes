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
#define mx                      2000000 + 5
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

vector <ll> vvr,vvc;
multiset <pair<ll,pair<int,int> > > st;
map <int,map<int,int> > vis;
int main()
{
    ll n,m,r,k;

    scanf("%lld %lld %lld %lld", &n,&m,&r,&k);

    ll mid = min(r,(n-r+1));

    int cnt = 0,till=2;

    while(till--) for(ll i=1; i<mid; i++) vvr.pb(i),cnt++;
    for(int i=cnt+1; i<=n; i++) vvr.pb((ll)mid);

    mid = min(r,(m-r+1));

    cnt = 0,till=2;

    while(till--) for(ll i=1; i<mid; i++) vvc.pb(i),cnt++;
    for(int i=cnt+1; i<=m; i++) vvc.pb((ll)mid);

    sort all(vvr);
    sort all(vvc);
    //for(int i=0; i<vvr.size(); i++) cout<<" "<<vvr[i]; cout<<endl;
    //for(int i=0; i<vvc.size(); i++) cout<<" "<<vvc[i]; cout<<endl;
    int rr = vvr.size()-1;
    int cc = vvc.size()-1;

    st.insert(mp(vvr[rr]*vvc[cc],mp(rr,cc)));
    vis[rr][cc] = 1;
    double res = 0.0;
    cnt = 0;

    while(!st.empty())
    {
        pair<ll,pair<int,int> > temp = * -- st.end();
        res += temp.first * 1.0;
        st.erase(--st.end());
//pf("%lld\n",temp.first);
        cnt ++;

        if(cnt == k) break;

        rr = temp.second.first;
        cc = temp.second.second;//cout<<rr<<" // "<<cc<<endl;

        int tr = rr-1;
        int tc = cc-1;

        if(!vis[tr][cc] && tr>=0) st.insert(mp(vvr[tr]*vvc[cc],mp(tr,cc))),vis[tr][cc] = 1;//cout<<vvr[tr]*vvc[cc]<<" // "<<tr<<" "<<cc<<endl;//out(st.size());
        if(!vis[rr][tc] && tc>=0) st.insert(mp(vvr[rr]*vvc[tc],mp(rr,tc))),vis[rr][tc] = 1;//cout<<vvr[rr]*vvc[tc]<<" // "<<rr<<" "<<tc<<endl;//out(st.size());
    }
    double tot = ((n-r+1) * (m-r+1)* 1.0);//pf("%.5f %.5f\n", res,tot);
    pf("%.13f\n",(res/tot));

    return 0;
}