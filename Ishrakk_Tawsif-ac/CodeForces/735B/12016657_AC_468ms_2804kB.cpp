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
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      200005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

double ar[100005];

int main()
{
    double n,n1,n2;

    cin>> n>> n1>> n2;

    for(int i=0; i<n; i++) cin>> ar[i];

    int nn=n;
    sort(ar,ar+nn);

    //if(n1<=n2)
    //{
        double sum = 0,sum2=0;
        int i,j;
        for(i=n-1,j=0; j<n1; j++,i--) sum += ar[i];
        sum /= n1;
        for(j=0; j<n2; j++,i--) sum2 += ar[i];
        sum2 /= n2;
        double ans1 = sum + sum2;


        sum = 0,sum2=0;
        //int i,j;
        for(i=n-1,j=0; j<n2; j++,i--) sum += ar[i];
        sum /= n2;//cout<<sum<<endl;
        for(j=0; j<n1; j++,i--) sum2 += ar[i];
        sum2 /= n1;//cout<<sum2<<endl;
        double ans2 = sum + sum2;

        pf("%.6f\n", max(ans1,ans2));
    /*}
    else
    {
        double sum = 0,sum2=0;
        int i,j;
        for(i=n-1,j=0; j<n2; j++,i--) sum += ar[i];
        sum /= n2;//cout<<sum<<endl;
        for(j=0; j<n1; j++,i--) sum2 += ar[i];
        sum2 /= n1;//cout<<sum2<<endl;
        double ans = sum + sum2;
        pf("%.6f\n", ans);
    }*/
    return 0;
}