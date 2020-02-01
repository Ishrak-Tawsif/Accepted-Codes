#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:\n",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

int dig,sum,dp[500005][10];
string ans[500005][10];


int main()
{   //cout<< (char)(65);
    int tc;
    sf(tc);

    while(tc--)
    {
        scanf("%d %d", &dig,&sum);
        

        int res[dig];

        int i=0,j=dig-1,taken=0,remsum;

        if((dig%2==0 && sum%2==1)|| ((dig*9)<sum)){pf("-1\n");continue;}

        while(i<j)
        {
            if(taken+18<=sum)
            {
                res[i] = 9;
                res[j] = 9;
                taken += 18;
            }
            else
            {
                if(sum-taken)
                {
                    int remsum = sum-taken;
                    remsum/=2;
                    res[i] = res[j] = remsum;
                    taken += (remsum*2);
                }
                else
                {
                    res[i] = res[j] = 0;
                }
            }
            i++;
            j--;
        }//cout<<i<<" "<<j<<endl;
        if(dig%2 == 1)
        {
            res[dig/2] = (sum-taken);
        }
        if(res[0] == 0)pf("-1\n");
        else
        {
            for(int i=0; i<dig; i++)pf("%d",res[i]);
            pf("\n");
        }
    }

    return 0;
}