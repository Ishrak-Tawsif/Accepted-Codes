#include<bits/stdc++.h>
using namespace std;

#define mx 10000

bitset <mx> isprime;
vector <int> prime;


void sieve()
{
    isprime[0]=isprime[1]=1;
    prime.push_back(2);

        for(int i=3; i*i<mx; i+=2)
            if(!isprime[i])
                for(int j=i*i; j<mx; j+=i) isprime[j]=1;
        for(int i=3; i<mx; i+=2) if(!isprime[i]) prime.push_back(i);//cout<<prime.size();
}

int main()
{
    sieve();
        int n,k,len=prime.size(),cnt;

            while(scanf("%d %d", &n,&k) == 2)
            {
                cnt=0;
                for(int i=1; i<len; i++)
                {
                    int temp = prime[i]+prime[i-1]+1;
                    if(temp>n) break;
                    if(!isprime[temp] && temp%2 != 0) cnt++;
                }//cout<<cnt<<endl;
                if(cnt >= k) printf("YES\n");
                else printf("NO\n");
            }
    return 0;
}