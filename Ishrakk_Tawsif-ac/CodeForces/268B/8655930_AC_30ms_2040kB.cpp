#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 5005
#define ll long long int
#define mp make_pair
#define mod 100000007


bitset <mx> isprime;
vector <int> prime;


int main()
{
    int n;

        while(scanf("%d", &n) == 1)
        {
            int ans=0;
            for(int i=1; i<=n; i++)
            {
                ans += (((n-i)+1)+(i-1)*(n-i)); //cout<<ans<<endl;
            }
            pf("%d\n",ans);
        }
    return 0;
}