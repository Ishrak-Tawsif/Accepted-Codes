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
#define mx                      1990005
#define mod                     1000000007
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

int n;
ll cnt[400005],ans[400005];
unordered_map <ll,int> id;
set <ll> st;
vector <pair<ll,ll> > vv;

int main()
{
    sf(n);
    pair <ll,ll> temp;

    for(int i=1; i<=n; i++)
    {
        scanf("%lld %lld", &temp.first,&temp.second);
        temp.second++;
        vv.pb(temp);
        st.insert(temp.first);
        st.insert(temp.second);
        //vv.insert(temp.second+1);
    }
    //unique(vv);
    //sort all(vv);
    int ind = 0;
    for(auto x : st) id[x] = ++ind;

    for(int i=0; i<vv.size(); i++)
    {
        ll st = vv[i].first;
        ll en = vv[i].second;

        //int pos = st.lower_bound(st);
        //int pos = st.lower_bound(en);

        cnt[id[st]] ++;
        cnt[id[en]] --;
    }

    for(int i=1; i<=ind; i++) cnt[i] += cnt[i-1];

    //for(int i=1; i<=ind; i++) cout<<" "<<cnt[i];pf("\n");

    ll first = (ll) *st.begin(); st.erase(st.begin());
    ll snd = (ll) *st.begin(); st.erase(st.begin());
//out(ind);
    for(int i=1; i<ind; i++)
    {//cout<<first<<" "<<snd<<" "<<cnt[i]<<endl;
        ans[cnt[i]] += snd - first;
        first = snd;//out(st.size());
        if(!st.empty()) {snd = *st.begin(); st.erase(st.begin());}//out("..");
    }//out("ok");

    for(int i=1; i<=n; i++) {if(i == 1) pf("%lld", ans[i]); else pf(" %lld",ans[i]);}

    pf("\n");

    return 0;
}