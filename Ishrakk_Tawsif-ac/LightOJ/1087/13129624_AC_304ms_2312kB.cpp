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
#define mx                      150005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int ar[1505][105], sum[1505];

struct squareroot
{
    void update(int pos,int val)
    {
        int bnum = pos/100;
        int posinbl = pos%100;
        ar[bnum][posinbl] = val;
        sum[bnum] ++;
    }

    int query(int k,int ind)
    {
        int totbl = ind/100 /*+ ((ind%100)>0)*/;

        int cnt = 0,mybl=-1;
        for(int i=0; i<=totbl; i++)
        {
            if(cnt + sum[i]>=k) {mybl = i; break;}
            cnt += sum[i];
        }
        if(mybl == -1) return -1;

        int stofmybl = mybl * 100,res=-1;

        for(int i=0; i<100; i++)
        {
            if(ar[mybl][i] != -1) cnt++;
            if(cnt == k)
            {
                res = ar[mybl][i];
                ar[mybl][i] = -1;
                sum[mybl] --;
                break;
            }
        }
        return res;
    }
};

int main()
{//WRITE("loj1.txt");
    int tc,n,q,bnum,pos,k,temp;
    char c;

    squareroot get;

    scanf("%d", &tc);
    for(int tt=1; tt<=tc; tt++)
    {
        mem(ar,-1);
        mem(sum,0);
        scanf("%d %d", &n,&q);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &temp);
            bnum = i/100;
            pos = i%100;
            ar[bnum][pos] = temp;
            sum[bnum] ++;
        }

        casepf(tt);
        int ind = n-1;
        for(int qq = 1; qq <= q; qq ++)
        {
            scanf(" %c %d",&c,&k);
            if(c == 'a') get.update(++ind,k);
            else
            {
                int now = get.query(k,ind);
                if(now == -1) pf("none\n");
                else pf("%d\n", now);
            }
        }
    }
    return 0;
}