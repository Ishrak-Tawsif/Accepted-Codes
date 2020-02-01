#include<bits/stdc++.h>
using namespace std;

#define mx 2500
#define ll long long int

bitset <mx> isprime;
vector <int> prime;
int sum[1000005];

ll ipow(ll base, ll pow)
{
    ll res=1;
        while(pow--) res *= base;
    return res;
}

void sieve()
{
    isprime[0]=isprime[1]=1;
    prime.push_back(2);

        for(int i=3; i*i<mx; i+=2)
            if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j]=1;
        for(int i=3; i<mx; i+=2) if(!isprime[i]) prime.push_back(i);
}

long int sumOfDivisor(int n)
{
    int cnt,len=prime.size();
    long int sum=1;

        for(int i=0; prime[i]*prime[i]<=n && i<len; i++)
        {
            if(n%prime[i] == 0)
            {
                cnt=0;
                while(n%prime[i]==0) {n/=prime[i];cnt++;}

                if(cnt==1) sum *= (prime[i]+1);
                else sum *= ((ipow(prime[i],cnt+1)-1)/(prime[i]-1));
            }
        }
        if(n!=1) sum *= (n+1);//cout<<sum<<endl;
        //if(sum == 0) sum=1;
     return sum;
}

bool prime_check(ll n)
{
    int len=prime.size();
        for(int i=0; prime[i]*prime[i]<=n && i<len; i++)
        {
            if(n%prime[i] == 0) return false;
        }
    return true;
}

int main()
{
    sieve(); //cout << prime.size();
    int a,b,max_=INT_MIN,ii,tc;
//cout<<sumOfDivisor(5041)<<endl;
//cout<<prime_check(5113)<<endl;

        //sum[1]=0;
        //sum[2]=1;
//cout<<sumOfDivisor(9)<<endl;
        vector <int> ans; ans.push_back(2);
        for(int i=2; i*i<=1000000; i++)
        {
            ll mmxx=sumOfDivisor(i*i);//cout<<i<<" "<<mmxx<<endl;;
            if(prime_check(mmxx)) {ans.push_back(i*i);
                //cout<<i*i<<endl;
            }
        }//cout<< ans.size()<<endl;

        scanf("%d", &tc);

        while(tc--)
        {
            scanf("%d %d", &a,&b);
            int start=0,end=0;
                for(int i=0; a>ans[i] && i<ans.size(); i++) start++;
                for(int i=0; b>ans[i] && i<ans.size(); i++) end++;//cout<<start<<" "<<end<<endl;
                    printf("%d\n", end-start);
        }
    return 0;
}