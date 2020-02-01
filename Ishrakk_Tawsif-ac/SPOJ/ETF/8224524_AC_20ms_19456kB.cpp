#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 1000005
#define ll long long int
#define mp make_pair
#define mod 1000005

bitset <mx> ismark;
int euler_phi[mx];

void sieve()
{
    for(int i=1; i<mx; i++) euler_phi[i]=i;

        ismark[1]=1;

            for(int i=2; i<mx; i++)
            {
                if(!ismark[i]){
                    for(int j=i; j<mx; j+=i)
                    {
                        ismark[j]=1;
                        euler_phi[j]= (euler_phi[j]/i)*(i-1);
                    }
                }
            }
}

int main()
{
    sieve();

        int tc,temp;

            sf(tc);
                for(int tt=1; tt<=tc; tt++)
                {
                    sf(temp);
                    pf("%d\n", euler_phi[temp]);
                }
    return 0;
}