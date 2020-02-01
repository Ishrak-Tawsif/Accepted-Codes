#include<bits/stdc++.h>
using namespace std;

#define mx 10000005

bitset <mx> isprime;
vector<int>prime;

void sieve(){
    isprime[0]=isprime[1]=1;
        for(int i=4; i<mx; i+=2) isprime[i]=1;
            //prime.push_back(2);

                for(int i=3; i*i<mx; i++)
                    if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j]=1;int in=-1;
                for(int i=0; i<mx; i++) if(!isprime[i]) prime.push_back(i);
}

int possible_way(long long int n)
{
    int cnt,ans=1;

        for(int i=0; prime[i]*prime[i]<=n && i<prime.size(); i++)
        {

            if(n%prime[i] == 0){
                cnt=0;
                    while(n%prime[i] == 0)
                    {
                        cnt++;
                        n/=prime[i];
                    }
                    if(prime[i]%2 != 0)
                    {
                        cnt++;
                        ans *= cnt;
                    }
            }
        }
        if(n!=1 && n%2 !=0) ans *= 2;
    return (ans-1);
}
int main(){

    sieve();

        int tc;
        long long int n;
            scanf("%d", &tc);

                for(int tt=1; tt<=tc; tt++){
                    scanf("%lld", &n);
                    printf("Case %d: %d\n", tt,possible_way(n));
                }

return 0;
}