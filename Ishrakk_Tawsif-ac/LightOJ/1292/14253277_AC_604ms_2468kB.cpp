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
#define mx                      100005
#define mod                     1000000007
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

vector <pair<int,int> > vv;
double ar[100005];

int calc(int ind)
{
    int maxi = 0,cnt=0;

    if(ind == -1) return 0;

    sort(ar,ar + ind+1);//for(int i=0; i<=ind; i++) out(ar[i]);out("\n\n");
    for(int i=0; i<ind; i++)
    {
        if(ar[i] == ar[i+1]) cnt++;
        else maxi = max(maxi,cnt),cnt = 0;
    }

    maxi = max(maxi,cnt);

    return maxi+1;
}

int main()
{//WRITE("out.txt");
    int x,y,res = 0,tc,n;
    //while(cin>>x>>y) vv.pb({x,y});
    sf(tc);

    for(int tt = 1; tt <= tc; tt++)
    {
        res = 0;

        sf(n);

        for(int i=0; i<n; i++) scanf("%d %d", &x,&y),vv.pb({x,y});

        for(int i=0; i<vv.size(); i++)
        {
            //double aa = atan2(vv[i].first,vv[i].second);
            //cout<<vv[i].first<<" "<<vv[i].second<<endl;
            int ind = -1;
            for(int j=0; j<vv.size(); j++)
            {
                if(i == j) continue;
                int aa = (vv[j].second - vv[i].second);
                int bb = (vv[j].first - vv[i].first);
                if(bb == 0)ar[++ind] = 2e9;
                else ar[++ind] = (aa*1.0 / bb*1.0);
            }
            res = max(res,calc(ind));
            //printf("\n\n\n");
        }
        casepf(tt);
        printf("%d\n",res+1);
        vv.clear();
    }
    return 0;
}