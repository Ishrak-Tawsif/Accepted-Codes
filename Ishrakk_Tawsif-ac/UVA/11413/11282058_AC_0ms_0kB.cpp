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

int n,m,ar[1005];

bool solve(int val)
{
    int temp = val,cnt=0;

       for(int i=0; i<n; )
       {
           temp = val;
           cnt++;
           while(temp-ar[i]>=0)
           {
               temp -= ar[i];
               i++;//if(val == 4)cout<<i<<" "<<temp<<" "<<val<<" "<<cnt<<endl;
               if(i == (n)) break;
           }
           if(i == (n)) break;
       }//cout<<val<<" "<<cnt<<endl;
    return(cnt <= m);
}

int bsearch(int st,int en)
{
    int mid,ans=-1;

        while(st<=en)
        {
            mid = (st + en)>>1;
//cout<<mid<<" ... "<<endl;
            if(solve(mid)) ans=mid,en = mid-1;
            else st = mid+1;
        }
    return ans;
}

int main()
{
    int sum,mm;

    while(scanf("%d %d", &n,&m) == 2)
    {
        sum=0;
        mm = -1;
        for(int i=0; i<n; i++) scanf("%d", &ar[i]),sum += ar[i],mm=max(mm,ar[i]);

        int res = bsearch(mm,sum);
        pf("%d\n", res);
    }

    return 0;
}