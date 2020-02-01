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
#define ll                      unsigned long long int
#define mx                      1000005
#define mod                     1000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int isassigned[200005],price[200005],fcl,bcl;

set <int> s[11];

int main()
{
    int n,m,fvcl;
    //s get;

        sf(n);

            loop(i,0,n) sf(price[i]);
            loop(i,0,n) {sf(fcl); s[fcl].insert(price[i]);}
            loop(i,0,n) {sf(bcl); s[bcl].insert(price[i]);}

                sf(m);
                loop(i,0,m)
                {
                    sf(fvcl);

                    if(!s[fvcl].empty())
                    {
                        int temp = *s[fvcl].begin();
                        if(i==0)cout<<temp;
                        else cout<<" "<<temp;


                        s[1].erase(temp);
                        s[2].erase(temp);
                        s[3].erase(temp);
                    }else cout<<" -1";
                }
    cout<<endl;
    return 0;
}