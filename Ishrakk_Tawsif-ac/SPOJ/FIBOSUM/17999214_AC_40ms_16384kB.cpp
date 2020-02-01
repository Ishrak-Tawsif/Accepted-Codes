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

//ll m;

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
                        ans.mat[i][j] += (mat[i][k]*temp.mat[k][j])%mod;
                        ans.mat[i][j] %= mod;
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

matrix m(5,5);
matrix a(5,5);

ll getval(int n)
{
    if(n <= 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;

    matrix ans(6,6);
    ans = m ^ (n-2);
    ans = (ans * a);

    return ans.mat[0][0]%mod;
}

int main()
{
    int n;

    int tc;

    scanf("%d", &tc);

    while(tc --)
    {
        int st,en;

        scanf("%d %d", &st,&en);

        m.mat[0][0] = 1,m.mat[0][1] = 1,m.mat[0][2] = 1;
        m.mat[1][0] = 1,m.mat[1][1] = 0,m.mat[1][2] = 0;
        m.mat[2][0] = 0,m.mat[2][1] = 0,m.mat[2][2] = 1;

        a.mat[0][0] = 2,a.mat[1][0] = 1,a.mat[2][0] = 1;

        printf("%lld\n", ((getval(en) - getval(st-1))+mod)%mod);
    }

    return 0;

}