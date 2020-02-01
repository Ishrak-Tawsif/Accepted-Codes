#include<bits/stdc++.h>
using namespace std;

#define mx 10003

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

/*int ipow(int base, int exp)
{
    int res=1;

        while(exp--) res *= base;
    return res;
}*/

int getMaxPrimesPower(int n,int prime)
{
    int cnt=0,pow=prime,in=1;

        while(pow>=prime) {cnt+=n/pow; pow*=prime;}

    return cnt;
}

void calc(int n)
{
    int len = prime.size(),i,fl=0;
    for(i=0; prime[i]<=n && i<len; i++)
    {
        if(fl==0){
            cout<< prime[i]<<"^"<<getMaxPrimesPower(n,prime[i]);
            fl=1;
        }
        else cout << " * "<< prime[i]<<"^"<<getMaxPrimesPower(n,prime[i]);
    }
    cout << endl;
}

int main()
{
    sieve();
    int n;

        while(scanf("%d", &n)==1)
        {
            calc(n);
        }

    return 0;
}