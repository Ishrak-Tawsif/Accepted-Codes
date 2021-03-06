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

bitset <mx> isprime;
string str;
int res;

void sieve()
{
    isprime[0] = isprime[1] = 1;

    for(int i=4; i<mx; i+=2) isprime[i] = 1;
    for(int i=3; i*i<mx; i+=2)
    {
        if(!isprime[i])
        {
            for(int j=i*i; j<mx; j+=i) isprime[j] = 1;
        }
    }
//    int cnt = 0;
//    for(int i=1; i<100; i++) if(!isprime[i]) cnt++; out(cnt);
}

//void backtrack(int ind,string temp)
//{
//    if(ind == str.length())
//    {
//        if(temp.length() == 0) return;
//        int now = (int) toint(temp);//cout<<temp<<" "<<now<<endl;
//        if(now>100000) return;
//        if(!isprime[now]) res = max(res,now);
//        return;
//    }
//
//    //string cur = temp;
//    backtrack(ind+1,temp + str[ind]);
//    //backtrack(ind+1,temp);
//    backtrack(ind+1,"");
//}

int main()
{
    sieve();
    while(cin>> str)
    {
        if(str.size() == 1 && str[0] == '0') break;
        res = 0;
        //backtrack(0,"");
        string temp;
        int now;
        for(int i=0; i<str.length(); i++)
        {
            temp = "";
            for(int j=i; j<str.length(); j++)
            {
                temp += str[j];
                now = toint(temp);
                if(now>100000) break;
                if(!isprime[now]) res = max(res,now);
            }
        }

        out(res);
    }

    return 0;
    
}