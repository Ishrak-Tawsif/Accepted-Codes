#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 50005
#define ll long long int
#define mp make_pair
#define mod 1000005

bitset <mx> ismark;
ll euler_phi[mx];

void sieve()
{
    for(ll i=1; i<mx; i++) euler_phi[i]=i;

        ismark[1]=1;

            for(ll i=2; i<mx; i++)
            {
                if(!ismark[i]){
                    for(ll j=i; j<mx; j+=i)
                    {
                        ismark[j]=1;
                        euler_phi[j]= (euler_phi[j]/i)*(i-1);
                    }
                }
            }
}

void pre_gen()
{
    for(int i=2; i<=50000; i++){
        euler_phi[i]+=(euler_phi[i-1]);
    }
}

int main()
{
    sieve();
    pre_gen();

        int tc,up,lo;

                //sf(tc);

                //for(int tt=1; tt<=tc; tt++)
                //{

                while(scanf("%d",&lo) ==1 && lo)
                {
                    //cout<<euler_phi[up]<<" "<<euler_phi[lo-1]<<endl;
                    pf("%lld\n",2*euler_phi[lo]-1);
                }
    return 0;
}