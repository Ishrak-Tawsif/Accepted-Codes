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

int main()
{
    int n,arr[1003];

        while(sf(arr[0])==1 && arr[0])
        {
            int i=0,GCD;
                while(sf(arr[++i]) && arr[i])
                {
                    int diff=abs(arr[i]-arr[i-1]);
                    if(i>1) GCD=__gcd(GCD,diff);//cout<<GCD<<" "<<diff<<endl;}
                    else GCD=diff;
                }
                pf("%d\n", GCD);
        }
    return 0;
}