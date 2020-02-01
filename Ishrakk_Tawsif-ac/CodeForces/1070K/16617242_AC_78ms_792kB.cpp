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
#define eps                     .000000001
template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int ar[100005];

//bool chk(int val)
//{
//    int sum = 0;
//
//    for(int i=1; i<=k; i++)
//    {
//        if(sum+ar[i] == val)
//        {
//            cnt++;
//        }
//        else sum += ar[i];
//    }
//}

int cum[100005];
int n,k,temp;

int bsearch(int val,int st,int block)
{
    int en = n,mid,res = -1;

    while(st <= en)
    {
        mid = (st + en)>> 1;

        if(cum[mid]-val == block) return mid;//cout<<cum[mid]-val<<" "<<val<<" "<<block<<endl;
        if(cum[mid]-val>block) en = mid - 1;
        else st = mid + 1;
    }
    return -1;
}

int main()
{
    while(scanf("%d %d", &n, &k) == 2)
    {
        cum[0] = 0;
        temp = 0;
        for(int i=1; i<=n; i++) scanf("%d", &ar[i]),temp += ar[i],cum[i] = temp;

        int ans=-1;
        for(int i=1; i<=n; i++)
        {
            int now = 0,fl = 0;

            int cnt = 0,cur = 1;
//cout<<i<<" .............................. \n";
            while(1)
            {
                int res = bsearch(now,cur,cum[i]);
                if(res == -1){break;}
                now = cum[res];
                cur = res + 1;
                cnt++;
//cout<<"cur: "<< cur<<" "<<cnt<<endl;
                if(cur == n+1)
                {
                    if(cnt == k) fl = 1,ans=i;
                    break;
                }
            }
        }

        if(ans == -1) {printf("No\n"); return 0;}

        int cursum = 0,cnt = 0,fll = 0,block = cum[ans];
        printf("Yes\n");
        for(int i=1; i<=n; i++)
        {
            cursum += ar[i];
            cnt ++;
            if(cursum == block)
            {
                if(!fll) printf("%d", cnt);
                else printf(" %d", cnt);
                cursum = 0;
                cnt = 0;
                fll = 1;
            }
        }
        printf("\n");
    }

    return 0;
}