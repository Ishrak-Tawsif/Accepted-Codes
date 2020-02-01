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
#define all(a)                  (a.begin(),a.end())
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000009

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

///hashing

int dxx[] = {0,1,-1};

ll base[mx],ahash[mx];
string str;

void genbase()
{
    base[0] = 1;
    for(int i=1; i<mx; i++) base[i] = ((base[i-1])%mod * 10)%mod;
}

void print(int i,int anslen)
{//cout<<i<<" "<<anslen<<endl; system("pause");
    for(int j=0; j<i; j++) cout<<str[j];
    cout<<"+";
    for(int j=i; j<str.length()-anslen; j++) cout<<str[j];
    cout<<"=";
    for(int j=str.length()-anslen; j<str.length(); j++) cout<<str[j];
    cout<<endl;
}

int main()
{

    genbase();

    //string str;

    cin>> str;

    mem(ahash,0);


    for(int i=0; i<str.length(); i++)
    {
        int cur = (int) (str[i] - '0');
        ahash[i+1] = ((ahash[i]*10)%mod + cur)%mod;
    }

    //for(int i=1; i<=str.length(); i++) cout<<" "<<hash[i]; cout<<endl;
    /*int l,r;

    while(cin>> l>> r)
    {
        int cur = (hash[r] - (hash[l-1] * base[r-l+1])) % mod;
        cur += mod;
        cur %= mod;
        out(cur);
    }*/
//out(str.length());
    int anslen = (str.length()/3);
    int len = str.length();
    int fl = 0;
    int l = len+1;
    int r = str.length();


    ll cur = (ahash[r] - (ahash[l-1] * base[r-l+1])) % mod;
    cur += mod;
    cur %= mod;
    ll res = cur;

    for(int i=1; i<=len-2; i++)
    {

        int templen = max((len-i)/2,i);

        for(int j=0; j<3; j++)
        {//out(anslen);
            anslen = templen + dxx[j];//out(anslen);

            l = (str.length() - anslen)+1;
            r = str.length();

            ll cur = (ahash[r] - (ahash[l-1] * base[r-l+1])) % mod;
            cur += mod;
            cur %= mod;
            ll res = cur;

            l = 1;
            r = i;

            ll cur1 = (ahash[r] - (ahash[l-1] * base[r-l+1])) % mod;
            cur1 += mod;
            cur1 %= mod;


            l = i+1;
            r = len-anslen;
            int _2ndlen = (r-l)+1;

            ll cur2 = (ahash[r] - (ahash[l-1] * base[r-l+1])) % mod;
            cur2 += mod;
            cur2 %= mod;

            if(((cur1 + cur2)%mod) == (res%mod))
            {
                if(str[i] == '0' && _2ndlen != 1) continue;
                fl = 1;print(i,anslen); break;
            }
        }

        if(fl) break;
    }

    return 0;
}

///12345168

///19999999999999999999991000000000000000000000