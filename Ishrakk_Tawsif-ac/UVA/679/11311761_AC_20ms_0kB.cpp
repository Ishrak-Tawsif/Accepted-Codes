 #include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000007

int main()
{
    int n,d,tc,ans;

    while(sf(tc) == 1)
    {
        if(tc == -1) break;
        while(tc--)
        {
            scanf("%d %d", &d,&n);

            ans=1;
            for(int i=0; i<(d-1); i++)
            {
                if(n&1)
                {
                    ans *= 2;
                    n = (n+1)/2;
                }
                else
                {
                    ans *= 2;
                    ans++;
                    n/=2;
                }//cout<<n<<" "<<d<<" "<<ans<<endl;
            }
            pf("%d\n", ans);
        }
    }
    return 0;
}