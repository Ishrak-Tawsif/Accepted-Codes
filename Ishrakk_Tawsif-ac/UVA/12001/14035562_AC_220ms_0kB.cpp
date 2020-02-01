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
#define mx                      303
#define mod                     10056
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

ll ncr[mx][mx];

void genncr()
{
    ncr[0][0] = 1;

    for(int i=1; i<mx; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j == 0) ncr[i][j] = 1;
            else if(j == 1) ncr[i][j] = i;
            else ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]);
        }
    }
}

int main()
{//WRITE("in.txt");
    genncr();

    int n,m,temp;
    ll cnt[53];


    while(scanf("%d %d", &n,&m) == 2)
    {
        if(!n && !m) break;

        mem(cnt,0);
        for(int i=0; i<n; i++) sf(temp),cnt[temp] ++;

        ll res = 0;
        for(int i=1; i<=m; i++)
        {
            res = res + ncr[cnt[i]][3];
            for(int j=i+1; j<=m; j++)
            {
                for(int k=j+1; k<=m; k++)
                {
                    if(i == j || i == k || j == k) continue;//cout<<i<<" "<<j<<" "<<k<<endl;
                    res = res + (cnt[i] * cnt[j] * cnt[k]);
                }
            }
        }

        ll res2 = 0;

        for(int i=1; i<=m; i++)
        {
            res2 = res2 + ncr[cnt[i]][4];
            ll temp = ncr[cnt[i]][3];//out(temp);
            for(int j=1; j<=m; j++)
            {
                if(i != j)
                {
                    res2 += temp * cnt[j];//cout<< temp<<" "<<cnt[j]<<" "<<temp * cnt[j]<<" "<<res2 <<endl;
                }
            }
            //res2 += temp;//out(temp);
        }//out(res2);

        for(int i=1; i<=m; i++)
        {
            //res2 = res2 + ncr[cnt[i]][3];
            for(int j=i+1; j<=m; j++)
            {
                for(int k=j+1; k<=m; k++)
                {
                    if(i == j || i == k || j == k) continue;//cout<<i<<" "<<j<<" "<<k<<endl;
                    res2 = res2 + (ncr[cnt[i]][2] * cnt[j] * cnt[k]);
                    res2 = res2 + (ncr[cnt[j]][2] * cnt[i] * cnt[k]);
                    res2 = res2 + (ncr[cnt[k]][2] * cnt[i] * cnt[j]);//cout<< ncr[cnt[i]][2] <<" "<< ncr[cnt[j]][2] <<" "<< ncr[cnt[k]][2] <<endl;
                    for(int l=k+1; l<=m; l++) res2 = res2 + (cnt[i] * cnt[j] * cnt[k] * cnt[l]);
                }
            }
        }

        cout<<res<<" "<<res2<<endl;
    }

    return 0;
}