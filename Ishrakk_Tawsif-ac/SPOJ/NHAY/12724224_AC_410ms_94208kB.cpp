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
#define mx                      557
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

unsigned long long hash_[10000005];
vector <int> vv;
int main()
{
    int tc;
    string fs,sn;

    //sf(tc);

    while(cin>> tc)
    {
        cin>> fs>> sn;
        int lenfs = fs.length();
        vv.clear();
        unsigned long long fshash = 0;
        for(int i=0; i<lenfs; i++)
        {
            unsigned long long temp = (fs[i]-'a') + 1;
            fshash = (fshash * 10) + temp;//out(fshash);
        }
//out(fshash);
        int st = 0,en = lenfs-1;
        unsigned ll pw = 1;
        for(int i=0; i<lenfs; i++) pw *= 10;
        for(int i=0; i<sn.length(); i++)
        {
            hash_[i] = (hash_[i-1]*10) + ((sn[i]-'a')+1);
            if(i>=lenfs)
            {
                unsigned long long cur = hash_[i] - (hash_[i-lenfs]*pw);//cout<<hash_[i]<<" "<<hash_[i-lenfs]*pw<<" "<<pw<<" "<<cur<<endl;
                if(cur == fshash)
                {//out("ok");
                    vv.pb(i-lenfs+1);
                }
                //pw *= 10;
            }
            //pw *= 10;
        }
        if(vv.size())
        {
            for(int i=0; i<vv.size(); i++) out(vv[i]);
        }
        else pf("\n");
    }

    return 0;
}