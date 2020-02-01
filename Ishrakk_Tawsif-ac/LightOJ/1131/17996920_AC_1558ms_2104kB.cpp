#include <bits/stdc++.h>
using namespace std;

//int dx[8]={0,0,1,-1,1,1,-1,-1};
//int dy[8]={1,-1,0,0,1,-1,1,-1};

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

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
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define mx                      100005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

ll m;

class matrix
{
    public:
        ll mat[31][31];
        int r,c;

        matrix(int tr,int tc)
        {
            r = tr;
            c = tc;
            mem(mat,0);
        }

        void identity()
        {
            for(int i=0; i<r; i++) mat[i][i] = 1;
        }

        matrix operator * (matrix temp)
        {
            matrix ans(r,temp.c);

            for(int i=0; i<r; i++)
            {
                for(int j=0; j<temp.c; j++)
                {
                    for(int k=0; k<c; k++)
                    {
                        ans.mat[i][j] += (mat[i][k]*temp.mat[k][j])%m;
                        ans.mat[i][j] %= m;
                    }
                }
            }
            return ans;
        }

        matrix operator ^ (ll pow)
        {
            matrix ans(r,c);
            ans.identity();
            matrix a = *this;

            while(pow)
            {
               if(pow & 1) ans = (ans * a);
               a = a * a;
               pow = pow>> 1;
            }
            return ans;
        }
};

matrix a(10,10),mag(10,10);

void initmag(ll a1,ll b1,ll c1,ll a2, ll b2,ll c2)
{
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            if(i == 0 && j == 0) mag.mat[i][j] = a1;
            else if(i == 0 && j == 1) mag.mat[i][j] = b1;
            else if(i == 0 && j == 5) mag.mat[i][j] = c1;
            else if(i == 1 && j == 0) mag.mat[i][j] = 1;
            else if(i == 2 && j == 1) mag.mat[i][j] = 1;
            else if(i == 3 && j == 2) mag.mat[i][j] = c2;
            else if(i == 3 && j == 3) mag.mat[i][j] = a2;
            else if(i == 3 && j == 4) mag.mat[i][j] = b2;
            else if(i == 4 && j == 3) mag.mat[i][j] = 1;
            else if(i == 5 && j == 4) mag.mat[i][j] = 1;
            else mag.mat[i][j] = 0;
        }
    }

    //for(int i=0; i<6; i++) {for(int j=0; j<6; j++) printf(" %d", mag[i][j]); printf("\n");}
}

void inita(ll f0,ll f1,ll f2,ll g0,ll g1,ll g2)
{
    a.mat[0][0] = f2; a.mat[1][0] = f1; a.mat[2][0] = f0;
    a.mat[3][0] = g2; a.mat[4][0] = g1; a.mat[5][0] = g0;
}

matrix BigMod(matrix base,ll pow)
{
    if(pow == 0) return base;
    else if(pow%2 == 0)
    {
        matrix ret = BigMod(base,pow/2);

    }
}

int main()
{
    //fast;
    ll a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2;

    int tc;

    cin>> tc;

    for(int tt=1; tt<=tc; tt++)
    {
        int q,n;

            cin>> a1>> b1>> c1>> a2>> b2>> c2>>f0>>f1>>f2>>g0>>g1>>g2>>m;
            initmag(a1,b1,c1,a2,b2,c2);
            inita(f0,f1,f2,g0,g1,g2);

        cin>> q;
        printf("Case %d:\n",tt);
        while(q--)
        {
            cin>> n;
            if(n<=2)
            {
                if(n == 0) printf("%lld %lld\n",f0%m,g0%m);
                else if(n == 1) printf("%lld %lld\n",f1%m,g1%m);
                else if(n == 2) printf("%lld %lld\n",f2%m,g2%m);
            }
            else
            {
                matrix ans(10,10);
                ans = mag ^ n-2;
                ans = (ans * a);
                printf("%lld %lld\n", ans.mat[0][0]%m,ans.mat[3][0]%m);
            }
        }
    }
    return 0;
}