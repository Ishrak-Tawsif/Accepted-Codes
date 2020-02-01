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
#define casepf(nn)              printf ("Case %d:\n",nn)
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
#define mx                      47000+5
#define mod                     1000000007
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

bitset <mx> isprime;
vector <ll> prime,divn,divd;
ll cont[mx],cntt[mx];

void sieve()
{
    prime.pb(2);

    for(int i=3; i*i<mx; i+=2)
    {
        if(!isprime[i])
        {
            for(int j=i*i; j<mx; j+=i) isprime[j] = 1;
        }
    }
    for(int i=3; i<mx; i+=2) if(!isprime[i]) prime.pb(i);
}

void primediv(ll n,int tp)
{
    int cnt=0;
    for(int i=0; (ll)prime[i]*(ll)prime[i]<=n; i++)
    {
        if(n%prime[i] == 0)
        {
            cnt = 0;
            if(tp == 1) divn.pb(prime[i]);
            else divd.pb(prime[i]);
            while(n%prime[i] == 0) n/=prime[i],cnt ++,cntt[prime[i]] ++;
            //cont[tp][prime[i]] = cnt;
        }
    }
    if(n!=1)
    {
        if(tp == 1) divn.pb(n);
        else {divd.pb(n);if(n<mx) cntt[n] = 1;}
        //cont[tp][n] = 1;
    }
}

ll calc(ll n,ll num)
{
    ll cnt = 0,temp = num;
    while(temp<=n)
    {
        cnt += (n/temp);
        temp *= num;
    }//cout<<num<<" "<<cnt<<endl;
    return cnt;
}

int main()
{//WRITE("in.txt");
    sieve();//out(prime.size());
    int n,d;

    while(scanf("%d %d", &n,&d))
    {
        if(!n && !d) break;

        if(d<0) d *= -1;

        //if(n<d) {pf("0\n"); continue;}
        mem(cont,0);
        mem(cntt,0);
        divn.clear();
        divd.clear();
       // primediv(n,1);
        primediv(d,2);

        ll res = 1;
        for(int i=0; prime[i]<=n; i++) divn.pb(prime[i]);
        
        for(int i=0; i<divn.size(); i++)
        {
            ll cur = divn[i];
            cont[cur] = calc(n,cur);
            ll temp = cntt[cur];
            if(temp>cont[cur])
            {
                res = 0;
            }
        }
        for(int i=0; i<divd.size(); i++)
        {
            if(divd[i]<=n)
            {//cout<<divd[i]<<"......... "<<endl;
                if(cont[divd[i]])
                {//cout<<divd[i]<<" "<<cont[divd[i]]<<"......... "<<cntt[divd[i]]<<endl;
                    res *= (cont[divd[i]]-cntt[divd[i]])+1;//cntt[divd[i]]);
                    cont[divd[i]] = 0;
                }
            }
            else res = 0;
        }//out(res);
        for(int i=0; i<divn.size(); i++)
        {
            ll cur = divn[i];
            if(cont[cur])
            {
                cont[cur] ++; //out(cont[cur]);
                res *= cont[cur];
            }
        }
        out(res);
    }//system("pause");
    
    return 0;
}