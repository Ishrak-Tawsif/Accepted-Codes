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
#define mx                      1000005
#define mod                     1000000009
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

int t,n,ar[23],inp[23];
//unordered_map <int,int> ids;

//int call(int pos,int tot)
//{
//    if(pos>=n) return 0;
//    if(dp[pos][tot] != -1) return dp[pos][tot];
//
//    int ans = 0,ans2 = 0;
//
//    if(tot - ar[pos]>=0) ans = call(pos+1,tot-ar[pos]) + ar[pos];
//    ans2 = call(pos+1,tot);
//
//    if(ans || ans2) mark[pos][tot] = (ans>ans2);
//
//    return dp[pos][tot] = max(ans,ans2);
//}
int maxi = -2e9,maxicnt = -2e9,mark[23],curmark[23];

void backtrack(int pos)
{
    if(pos == n)
    {
        int cnt = 0,nowtot = 0;
            mem(curmark,0);

            for(int i=0; i<n; i++)
            {
                if(ar[i]) nowtot += inp[i],cnt++;
            }//out(n);
            if(nowtot<=t && nowtot>maxi)
            {
                maxi = nowtot;
                maxicnt = cnt;
                for(int i=0; i<n; i++) {if(ar[i])mark[i] = 1; else mark[i] = 0;}
            }
            else if(cnt>maxicnt && nowtot == maxi)
            {
                maxi = nowtot;
                maxicnt = cnt;
                for(int i=0; i<n; i++) {if(ar[i])mark[i] = 1; else mark[i] = 0;}
            }
            return;
    }

    ar[pos] = 1;
    backtrack(pos+1);
    ar[pos] = 0;
    backtrack(pos+1);
}

int main()
{
    int res;
    while(~scanf("%d", &t))
    {
        sf(n);//out(n);
        //ids.clear();
        for(int i=0; i<n; i++) sf(inp[i]),ar[i] = i;
        mem(mark,0);
        maxi = -2e9,maxicnt = -2e9;

//        do
//        {//for(int i=0; i<n; i++) out(ar[i]);
//            int cnt = 0,nowtot = 0;
//            mem(curmark,0);
//
//            for(int i=0; i<n; i++)
//            {
//                if(nowtot + inp[ar[i]]<=t) nowtot += inp[ar[i]],cnt++,curmark[ar[i]] = 1;
//                else break;
//            }//out(n);
//            if(nowtot>maxi)
//            {
//                maxi = nowtot;
//                maxicnt = cnt;
//                for(int i=0; i<n; i++) mark[i] = curmark[i];
//            }
//            else if(cnt>maxicnt)
//            {
//                maxi = nowtot;
//                maxicnt = cnt;
//                for(int i=0; i<n; i++) mark[i] = curmark[i];
//            }
//        }while(next_permutation(ar,ar+n));

        backtrack(0);

        int fl = 0;
        for(int i=0; i<n; i++)
        {//cout<<inp[i]<<" "<<ids[inp[i]]<<" "<<mark[ids[inp[i]]]<<endl;
            if(mark[i])
            {
                if(fl) pf(" ");
                pf("%d", inp[i]),fl = 1;
            }
        }

        pf(" sum:%d\n", maxi);
    }

    return 0;
}