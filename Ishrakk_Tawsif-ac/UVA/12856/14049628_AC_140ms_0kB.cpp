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

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

ll calc(ll num)
{
    if(num<=0) return 0;

    return ((num * (num + 1))/2);
}

int main()
{//READ("out.txt");
    //WRITE("in.txt");
    string str;

    while(cin>> str)
    {
        ll cnt0 = 0,cnt1 = 0,cnt2 = 0,totsum = 0,res = 0;
        int len = str.length();

        for(int i=0; i<len; i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                int now = str[i] - '0';
                totsum += now;
                totsum = totsum % 3;
//cout<<i<<" "<<cnt0<<" "<<str.length()<<endl;
            
                if(totsum == 0) cnt0++;
                
                else if(totsum == 1) cnt1++;
                
                else cnt2++;
            }
            else
            {//system("pause");
                res += calc(cnt0);
                res += calc(cnt1 - 1);
                res += calc(cnt2 - 1);
                cnt0 = cnt1 = cnt2 = totsum = 0;
            }
        }//out(cnt0);
        res += calc(cnt0);
        res += calc(cnt1 - 1);
        res += calc(cnt2 - 1);
        cnt0 = cnt1 = cnt2 = 0;
        pf("%lld\n", res);//system("pause");
    }

    return 0;
}