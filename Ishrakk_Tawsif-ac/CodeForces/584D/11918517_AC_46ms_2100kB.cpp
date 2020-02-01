#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d: ",nn)
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
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int vis[105][105],ran[105];
pair<int,int> ar[5005];

int isprime(ll num)
{
    int fl=1;
    if(num == 0 || num == 1) return 0;
    if(num == 2) return 1;
    for(int i=2; i*i<=num; i++)
    {
        if(num%i == 0) {fl=0; break;}
    }
    return fl;
}

int main()
{
    ll n;
//cout<<isprime(0)<<endl;
    scanf("%lld", &n);
    srand(time(0));
    if(isprime(n)) {pf("1\n%lld\n", n); return 0;}
    while(true)
    {
        ll first = (rand()*rand())%n;
        first += 2;
        if(first > n) first = n;

            if(isprime(first))
            {
                int cnt1=10;

                while(cnt1--)
                {
                    ll second = (rand()*rand())%(n-first);
                    second += 2;
                    if(second>(n-first)) second = (n-first);

                    if(isprime(second))
                    {
                        if(first + second == n) {pf("2\n%lld %lld\n",first,second); return 0;}

                        int cnt2 = 25;
                        //while(cnt2--)
                        //{
                            ll third = (n-(first+second));
                            if(isprime(third))
                            {
                                pf("3\n%lld %lld %lld\n", first,second,third);
                                return 0;
                            }
                        //}
                    }
                }
            }
            else if(isprime(n-first))
            {
                first = n-first;

                int cnt1=10;

                while(cnt1--)
                {
                    ll second = (rand()*rand())%(n-first);
                    second += 2;
                    if(second>(n-first)) second = (n-first);

                    if(isprime(second))
                    {
                        if(first + second == n) {pf("2\n%lld %lld\n",first,second); return 0;}

                        int cnt2 = 25;
                        //while(cnt2--)
                        //{
                            ll third = (n-(first+second));
                            if(isprime(third))
                            {
                                pf("3\n%lld %lld %lld\n", first,second,third);
                                return 0;
                            }
                        //}
                    }
                }
            }
    }

    return 0;
}