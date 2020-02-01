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
#define mod                     998244353
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define bitOff(N,in)            (N&(~(1LL<<(in))))
#define bitOn(N,in)             (N|(1LL<<(in)))
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int n,m,k,ar[503][503],dp[503][503],cst[503][503],classkortehbe,totclass;
vector <int> vv[503];

int call(int ind,int koyta)
{//cout<<"ind :"<<ind<<endl;
    if(ind == n+1)
    {//out(koyta);
        if(koyta<0) return 2e9;
        return 0;
    }

    if(dp[ind][koyta] != -1) return dp[ind][koyta];

    int ans = 2e9,len = vv[ind].size();

    for(int i=0; i<=vv[ind].size(); i++)
    {
        if((koyta - (len-i)) >=0 )
        {
            ans = min(ans,call(ind+1,(koyta - (len-i))) + cst[ind][i]);
        }
    }
    return dp[ind][koyta] = ans;
}

int main()
{
    //READ("out.txt");
    for(int i=0; i<=502; i++) for(int j=0; j<=502; j++) cst[i][j] = 2e9;

    scanf("%d %d %d", &n,&m,&k);

    string str;

    for(int i=1; i<=n; i++)
    {
        cin>> str;//out(str.length());
        for(int j=0; j<m; j++)
        {
            //str[i] == '0'? ar[i][j+1] = 0 : ar[i][j+1] = 1;
            if(str[j] == '1')vv[i].pb(j+1),totclass++;//out(totclass);
        }
    }

    //for(int i=1; i<=n; i++) cout<<" "<<vv[i].size();

    if(totclass<=k)
    {
        out("0");
        return 0;
    }

    int clas;
    for(int i=1; i<=n; i++)
    {
        cst[i][0] = 0;
        cst[i][1] = 1;
        clas = 2;
        while(clas)
        {
            for(int j=0; j<vv[i].size(); j++)
            {
                int ind = j + clas - 1;
                if(ind >= vv[i].size()) break;//cout<<i<<" "<<clas<<" "<<ind<<" "<<vv[i][ind]<<endl;
                else cst[i][clas] = min(cst[i][clas],vv[i][ind] - vv[i][j]+1);
            }
            if(clas>vv[i].size()) break;
            clas ++;
        }
    }

    classkortehbe = totclass-k;//out(totclass);

    mem(dp,-1);
    out(call(1,k));

    return 0;

}