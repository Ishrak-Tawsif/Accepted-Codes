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

vector <pair<int,int > > vv,temp;
vector <int> listt[(1<<15) + 15];
int en[32769];

int main()
{
    int tc,n,k;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d %d", &n,&k);
        for(int i=1; i<=(1<<n); i++)
        {
            sf(en[i]);
            vv.pb(mp(en[i],i));
        }

        while(vv.size()>1)
        {
            for(int i=0; i<vv.size(); i+=2)
            {
                int fs = vv[i].first;
                int sn = vv[i+1].first;
//cout<<fs<<" "<<sn<<endl;
                if(fs>=sn)
                {
                    fs = fs - sn;
                    fs = min(fs+k,en[vv[i].second]);
                    temp.pb(mp(fs,vv[i].second));
                    listt[vv[i].second].pb(vv[i+1].second);
                }
                else
                {
                    sn = sn - fs;
                    sn = min(sn+k,en[vv[i+1].second]);
                    temp.pb(mp(sn,vv[i+1].second));
                    listt[vv[i+1].second].pb(vv[i].second);
                }
            }
            vv = temp;
            temp.clear();//cout<<"end \n";
        }

        int now = vv[0].second;
        printf("%d\n", now);
        for(int i=0; i<listt[now].size(); i++)
        {
            if(i) printf(" %d", listt[now][i]);
            else printf("%d", listt[now][i]);
        }
        printf("\n");
        vv.clear();
        for(int i=0; i<(1<<15)+10; i++) listt[i].clear();
    }

    return 0;
}