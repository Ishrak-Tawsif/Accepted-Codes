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
#define mod                     1000000007
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

int ans[200005],pos[100005],stackk[100005];

bool check(char ch)
{
    if(ch == '<' || ch == '(' || ch == '{' || ch == '[') return true;
    return false;
}

bool checkoppsite(char ch,char now)
{
    if(ch == '(' && now == ')') return true;
    if(ch == '{' && now == '}') return true;
    if(ch == '<' && now == '>') return true;
    if(ch == '[' && now == ']') return true;
    return false;
}

int main()
{
    int tc,top;
    string str;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        cin>> str;
        top = 0;
        mem(ans,0);
        mem(pos,0);
        int len = str.length();

        for(int i=0; i<len; i++)
        {//out(top);
            if(check(str[i])) pos[++top] = i,stackk[top] = i;
            else
            {
                if(top>0 && checkoppsite(str[stackk[top]],str[i])) ans[pos[top]] = (i-pos[top]) + 1,top--;
                else
                {
                    top = 0;
                }
            }
        }

        for(int i=len-1; i>=0; i--)
        {
            ans[i] = ans[i] + ans[i+ans[i]];
        }
        pf("Case %d:\n", tt);
        for(int i=0; i<len; i++) pf("%d\n", ans[i]);

    }


    return 0;
}