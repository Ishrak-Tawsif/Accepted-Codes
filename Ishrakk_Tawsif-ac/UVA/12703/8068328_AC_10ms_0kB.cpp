#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 1100
#define ll long long int
#define mp make_pair
#define mod 100000007

///sieve

bitset<mx>isprime;
int prime[301],in;
//vector <ll> ans;

void sieve()
{

    isprime[0]=isprime[1]=1;
    prime[0]=2;
    //for(int i=4; i<mx; i+=2) isprime[i]=1;
            for(int i=3; i*i<mx; i+=2)
            {
                if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
            //cnt[2]=1;
            in=0;
            for(int i=3; i<mx; i+=2){
                    if(!isprime[i] && (i%2)!=0) prime[++in]=i;
                    //else cnt[i]=cnt[i-1];
            }
}

int powers [1100][1100],max_;

void solve(int nn)
{

        int n=nn;

            for(int i=0; prime[i]*prime[i]<=n && i<=in; i++)
            {//cout<<prime[i]<<" ";
                if(n%prime[i] == 0)
                {
                    int cnt=0;
                    while(n%prime[i] == 0) {cnt++; n/=prime[i];}
                    powers [prime[i]][nn] = cnt;
                    max_=max(max_,prime[i]);
                }
            }
        if(n!=1) {powers[n][nn]=1; max_=max(max_,n);}
    //}
}

int main()
{
    sieve();
    //solve();
    ll a,b,n,fibo;
    int tc;
        sf(tc);
            loop1(tt,tc)
            {
                scanf("%lld %lld %lld", &n, &a, &b);

                    max_=INT_MIN;
                    memset(powers,0,sizeof(powers));
                    solve(a);
                    solve(b);//cout<<max_<<endl;

                        for(int j=0; prime[j]<= max_; j++)
                        {//cout<<prime[j]<<endl;system("pause");
                            int cnt=0,temp,bb;
                            temp=powers[prime[j]][a];
                            bb=powers[prime[j]][b];
                            if(temp==0 && bb==0) continue;
                            for(int i=2; i<=n; i++){
                                cnt = temp+bb;
                                temp=bb;
                                bb=cnt;//cout<<cnt<<" "<<i<<endl;
                            }
                            cout<<prime[j]<<" "<<cnt<<endl;
                        }
                    cout<<endl;
            }
    return 0;
}