#include<bits/stdc++.h>
using namespace std;

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
#define mx                      5005
#define mod                     100000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int main()
{
    ll n,f,amount,customer;

        scanf("%lld %lld", &n,&f);

            multiset <pair<ll,pair<ll,ll> > > s;

                for(int i=0; i<n; i++)
                {
                    scanf("%lld %lld", &amount,&customer);
                    ll temp = min(2*amount,customer);
                    s.insert(mp(temp-min(amount,customer),mp(amount,customer)));
                }
                    ll sum=0;//cout<<"size : " << s.size() << endl;
                    while(!s.empty())
                    {//cout<<"fgwrf"<<endl;
                        pair<ll,pair<ll,ll> > tt = *--s.end();//cout<<tt.first<<".."<<endl;
                        s.erase(--s.end());//cout<<tt.first<<endl;
                        if(f>0)
                            {sum += min(tt.second.first*2,tt.second.second); f--;}
                        else sum += min(tt.second.first,tt.second.second);//cout<<s.size()<<endl;
                    }

                    pf("%lld\n", sum);
    return 0;
}