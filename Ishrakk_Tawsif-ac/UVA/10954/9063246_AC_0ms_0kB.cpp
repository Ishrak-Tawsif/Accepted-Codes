#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 1003
#define ll long long int
#define mp make_pair
#define mod 1000000

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

int n,k;

/*int call(int pos)
{
    if(dp[pos] != -1) return dp;

        int ans=0;
        for(int i=1; i<=k; i++)
        {
            for(int i=1; i<=n; i++) ans += call(i);
        }

}*/

ll arr[301][301];

int main()
{
    int n,temp;


         while(sf(n) == 1 && n)
         {

            priority_queue<ll,vector<ll>, greater<ll> > q;

                loop(i,n)
                {
                    sf(temp);
                    q.push(temp);

                }
                        ll sum=0,cost=0;
                        while(!q.empty())
                        {
                            sum = q.top();
                            q.pop();

                            if(q.empty()) break;

                            sum += q.top();
                            q.pop();

                            cost += sum;
                            q.push(sum);
                        }

                pf("%lld\n", cost);
         }


    return 0;
}