#include<bits/stdc++.h>
using namespace std;

#define mx 32000

bitset <mx> isprime;
vector <int> prime;

void sieve()
{
    isprime[0]=isprime[1]=1;
    prime.push_back(2);

        for(int i=3; i*i<mx; i+=2)
            if(!isprime[i])
                for(int j=i*i; j<mx; j+=i) isprime[j]=1;
        for(int i=3; i<mx; i+=2) if(!isprime[i]) prime.push_back(i); //cout<<prime.size();
}

long int div_count(long int n)
{
    long int cnt=0,len=prime.size(),ans=1;

        for(int i=0; prime[i]*prime[i]<=n && i<len; i++)
        {
            if(n%prime[i] == 0){
                    cnt=0;
                    while(n%prime[i] == 0){cnt++; n/=prime[i];}
                    ans *= (cnt+1); //cout << prime[i] << " " << cnt << endl;
            }
        }
        if(n!=1) ans *= 2;
    return ans;
}

int main()
{
    sieve();
    long int a,b;
        while(scanf("%ld %ld", &a,&b) == 2 && a && b)
        {
            long int temp = abs(a-b);
            cout << div_count(temp) << endl;
        }

    return 0;
}