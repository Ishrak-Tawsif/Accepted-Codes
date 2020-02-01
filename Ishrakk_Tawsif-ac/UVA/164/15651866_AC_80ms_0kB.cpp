#include <bits/stdc++.h>
#include <ext/rope>

using namespace __gnu_cxx;
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

string a,b;
int dp[23][23];

struct st
{
    int i,j;
    char c;
};
vector <st> vv[23][23];

int call(int i,int j)
{//cout<<i<<" "<<j<<endl;
    if(i >= a.length() || j >= b.length())
    {
        if(i == a.length() && j == b.length()) return 0;
        return 2e9;
    }

    if(dp[i][j] != -1) return dp[i][j];

    int ans,temp;

    ans = 2e9;
    st get;

        temp = call(i+1,j)+1;
        if(temp<ans)
        {
            ans = temp;
            get.i = i+1;
            get.j = j;
            get.c = 'd';
            if(vv[i][j].size() == 0)vv[i][j].pb(get);
            else vv[i][j][0] = get;
        }

        temp = call(i,j+1)+1;
        if(temp<ans)
        {
            ans = temp;
            get.i = i;
            get.j = j+1;
            get.c = 'i';
            vv[i][j].pb(get);
            if(vv[i][j].size() == 0)vv[i][j].pb(get);
            else vv[i][j][0] = get;
        }

        temp =call(i+1,j+1)+1;
        if(temp<ans)
        {
            ans = temp;
            get.i = i+1;
            get.j = j+1;
            get.c = 'c';
            vv[i][j].pb(get);
            if(vv[i][j].size() == 0)vv[i][j].pb(get);
            else vv[i][j][0] = get;
        }

        if(a[i] == b[j])
        {
            temp = call(i+1,j+1);

            if(temp<ans)
            {
                ans = temp;
                get.i = i+1;
                get.j = j+1;
                get.c = '#';
                vv[i][j].pb(get);
                if(vv[i][j].size() == 0)vv[i][j].pb(get);
                else vv[i][j][0] = get;
            }
        }
    //}

    return dp[i][j] = ans;
}

//void printall(int i,int j)
//{//cout<<i<<" .. "<<j<<endl;
//    if(i < 0 || j < 0) return;
//    if(a[i] == b[j]) {printall(i-1,j-1);return;}
//
//    if(dp[i-1][j]<dp[i][j-1] && dp[i-1][j]<dp[i-1][j-1])
//    {
//        //cout<<i<<" "<<j<<endl;
//        out("d");
//        printall(i-1,j);
//    }
//    else if(dp[i][j-1]<dp[i-1][j] && dp[i][j-1]<dp[i-1][j-1])
//    {
//        //cout<<i<<" "<<j<<endl;
//        out("i");
//        printall(i,j-1);
//    }
//    else
//    {
//        //cout<<i<<" "<<j<<endl;
//        out("c");
//        printall(i-1,j-1);
//    }
//}

void printall(int i,int j)
{cout<<i<<" .. "<<j<<endl;
    if(i == a.length() || j == b.length()) return;
    if(a[i] == b[j]) {printall(i+1,j+1);return;}

    if(dp[i+1][j]<dp[i][j+1] && dp[i+1][j]<dp[i+1][j+1])
    {
        //cout<<i<<" "<<j<<endl;
        out("d");
        printall(i+1,j);
    }
    else if(dp[i][j+1]<dp[i+1][j] && dp[i][j+1]<dp[i+1][j+1])
    {
        //cout<<i<<" "<<j<<endl;
        out("i");
        printall(i,j+1);
    }
    else
    {
        //cout<<i<<" "<<j<<endl;
        out("c");
        printall(i+1,j+1);
    }
}

int main()
{
    //WRITE("out.txt");
    while(cin>> a)
    {
        if(a[0] == '#' && a.length() == 1) break;

        cin>> b;
        a += 'A';
        b += 'A';
//cout<<a<<" "<<b<<endl;

        for(int i=0; i<23; i++) for(int j=0; j<23; j++) vv[i][j].clear();

        mem(dp,-1);
        call(0,0);//out("ok");

        int i = 0,j = 0;

        //printall(0,0);

        while(i<a.length() && j<b.length())
        {//cout<<i<<" ... "<<j<<endl;
            char tp = vv[i][j][0].c;
            int tempi = vv[i][j][0].i;
            int tempj = vv[i][j][0].j;//cout<<tempi<<" "<<tempj<<endl;

            if(tp != '#')
            {
                if(tp == 'd') pf("D%c%02d",a[i],j+1);
                if(tp == 'i') pf("I%c%02d",b[j],j+1);
                if(tp == 'c') pf("C%c%02d",b[j],j+1);
            }

            i = tempi;
            j = tempj;
        }
        pf("E\n");
    }

    return 0;


}