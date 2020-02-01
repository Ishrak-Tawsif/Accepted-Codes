#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 5005
#define ll long long int
#define mp make_pair
#define mod 100000007


bitset <mx> isprime;
vector <int> prime;

void sieve()
{
    isprime[0]=isprime[1]=1;
    prime.pb(2);

        for(int i=3; i*i<mx; i+=2)
        {
            if(!isprime[i])
            {
                for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
        }
        for(int i=3; i<mx; i+=2) if(!isprime[i]) prime.pb(i);
}

ll ipow(ll base, ll pow)
{
    ll res=1;

        while(pow--) res *= base;//cout<<base<<" "<<res<<endl;
    return res;
}

vector <pair<int,int > >divofm;

void divi(int m)
{
    int cnt=0;
    for(int i=0; prime[i]*prime[i]<=m && i<prime.size(); i++)
    {
        if(m%prime[i] == 0)
        {
            cnt=0;
            while(m%prime[i] == 0) {m/=prime[i]; cnt++;}
            divofm.pb(mp(prime[i],cnt));
        }
    }
    if(m!=1) divofm.pb(mp(m,1));
}

int main()
{
    sieve();

        int m,n,tc,uttor;

            sf(tc);

                loop1(tt,tc)
                {
                    sf(m); sf(n);


                        bool misprime=false;

                            if(m == 2) misprime=true;
                            else if(isprime[m]==0 and m%2!=0) misprime=true;

                                if(!misprime)
                                {
                                    divofm.clear();
                                    divi(m);
                                    int cnt=INT_MAX,ans;
//cout<<divofm.size()<<endl;
                                        for(int i=0; i<divofm.size(); i++)
                                        {
                                            int p=divofm[i].first,temp=p,in=1;
                                            ans=0;

                                                while(temp<=n)
                                                {
                                                    ans += n/temp;//cout<<temp<<" "<<ans<<endl;
                                                    temp=ipow(p,++in);
                                                }//cout<<ans<<endl;
                                            ans/= divofm[i].second;
                                            cnt = min(cnt,ans);
                                        }
                                    uttor=cnt;
                                }
                                else
                                {
                                    int cnt=0,temp=m,in=1;
                                    while(temp<=n){cnt += n/temp; temp=ipow(m,++in);}
                                    uttor=cnt;
                                }
                      if(uttor!=0) pf("Case %d:\n%d\n",tt,uttor);
                      else pf("Case %d:\nImpossible to divide\n",tt);
                }
    return 0;
}