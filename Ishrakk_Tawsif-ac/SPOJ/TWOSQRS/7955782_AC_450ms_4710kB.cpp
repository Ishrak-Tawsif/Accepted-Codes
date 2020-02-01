 #include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 10000005
#define ll long long int
#define mp make_pair
#define mod 10000007

/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/

/*int knapsack(int i,int w)
{
    if(i<0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

        if(w-wei[i]>=0)dp[i][w] = max(ks(i-1,w),ks(i-1,w-wei[i])+val[i]);
        else dp[i][w]=ks(i-1,w);
        //cout << i << " " << w << " " << dp[i][w]<<endl;
    return dp[i][w];
}*/

//vector <int> graph[mx];
//vector <int> graph2[mx];

bitset<mx>isprime;
vector<int>prime;

/*void sieve()
{

    isprime[0]=isprime[1]=1;
    prime.pb(2);

            for(int i=3; i*i<mx; i+=2)
            {
                if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
            for(int i=3; i<mx; i+=2) if(!isprime[i]) prime.pb(i);
}*/

int main()
{
    //sieve();
    int tc;
    ll n,len;
        //while(sf(tc) == 1)
        //{

        sf(tc);
            loop(tc)
            {
                scanf("%lld", &n);
                //len=sqrt(n);
                int fl=0;
                    if(n==1) pf("Yes\n");
                    else{
                        for(ll j=1; j*j<=n; j++)
                        {
                            ll temp=j*j;
                            ll yo = n-temp;
                            ll yoyo=sqrt(yo);//cout<<i<<" " << " " << j <<endl;;
                                if(((yoyo*yoyo) == yo) || (yo == 1)) {fl=1; break;}
                        }

                        if(fl==1)pf("Yes\n");
                        else pf("No\n");
                    }
            }
        //}
    return 0;
}