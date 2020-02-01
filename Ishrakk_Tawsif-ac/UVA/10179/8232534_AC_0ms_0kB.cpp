#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 32000
#define ll long long int
#define mp make_pair
#define mod 1000005

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

int ipow(int base,int pow)
{
    int ans=1;

        while(pow--) ans*=base;

    return ans;
}

int euler_phi(int n)
{
    int ans=1;
    for(int i=0; prime[i]*prime[i]<=n; i++)
    {
        if(n%prime[i] == 0)
        {
            int cnt=0;
            while(n%prime[i] == 0)
            {
                cnt++;
                n/=prime[i];
            }
            if(cnt==0) ans*=(prime[i]-1);
            else ans*= ((ipow(prime[i],cnt-1))*(prime[i]-1));//cout<<ans<<endl;
        }
    }
    if(n!=1) ans *= (n-1);//cout<<n<<" "<<ans<<endl;
    return ans;
}

int main()
{
    sieve();

    int n;
        while(sf(n) == 1 && n)
        {
            printf("%d\n", euler_phi(n));
        }
    return 0;
}