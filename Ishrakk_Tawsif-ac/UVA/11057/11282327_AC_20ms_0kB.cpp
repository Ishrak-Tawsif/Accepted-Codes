 #include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d\n",nn)
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
#define mx                      2000+5
#define mod                     1000000007

int n,ar[10003];

int bsearch(int st,int en,int sval)
{
    int mid,ans=-1;

        while(st<=en)
        {
            mid = (st+en)>>1;//cout<<mid<<endl;
            if(ar[mid] == sval) {ans=mid;break;}
            else if(ar[mid]<sval) st = mid+1;
            else en = mid-1;
        }
    return ans;
}

int main()
{
    int maxdiff,ansi,ansj,tot;

    while(scanf("%d", &n) == 1)
    {
        maxdiff = 1e9;
        for(int i=0; i<n; i++) sf(ar[i]);
        sort(ar, ar+n);

        sf(tot);

        for(int i=0; i<n-1; i++)
        {
            int cur = bsearch(i+1,n-1,tot-ar[i]);//out(cur);
            if(cur != -1)
            {
                int diff = ar[cur]-ar[i];
                if(diff<maxdiff)
                {
                    maxdiff = diff;
                    ansi=i;
                    ansj=cur;
                }
            }
        }//cout<<ansi<<" "<<ansj<<endl;
        pf("Peter should buy books whose prices are %d and %d.\n\n", ar[ansi],ar[ansj]);
    }

    return 0;
}