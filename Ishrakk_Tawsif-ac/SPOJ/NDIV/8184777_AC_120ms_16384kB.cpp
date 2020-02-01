#include<bits/stdc++.h>
using namespace std;


#define mx 32000

bitset <mx> isprime;
vector<int>prime;

void sieve()
{
    isprime[0]=isprime[1]=1;

        for(int i=3; i*i<mx; i+=2)
        {
            if(!isprime[i]){
                for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
        }
        prime.push_back(2);
            for(int i=3; i<mx; i+=2)
                if(!isprime[i]) prime.push_back(i);

}

int num_of_div(int n)
{
    int ans=1;
        for(int i=0; prime[i]*prime[i]<=n; i++)
        {
            if(n%prime[i]==0)
            {
                int cnt=0;

                    while(n%prime[i]==0)
                    {
                        cnt++;
                        n/=prime[i];
                    }
                ans *= (cnt+1);
            }
        }
        if(n!=1) ans*=2;
   return ans;
}

int main()
{
    sieve();
    //cout<<prime.size()<<endl;

        int a,b,k,cnt;

            while(scanf("%d %d %d", &a,&b,&k)==3)
            {
                //cnt=0;cout<<a<<" "<<b<<endl;
                for(int i=a; i<=b; i++)
                {
                    int temp=num_of_div(i);

                        if(temp==k) {/*cout<<temp<<" "<<i<<endl;*/cnt++;}
                }
                printf("%d\n", cnt);
            }

    return 0;
}