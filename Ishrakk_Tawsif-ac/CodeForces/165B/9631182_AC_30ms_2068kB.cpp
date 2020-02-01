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
#define mx                      5005
#define mod                     100000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

ll cake[1003],drink[1003];
string str;
string ans[53];

int n,k;

bool solve(int num)
{
    int kk=1,cnt=0,fl=0;

        while(1)
        {
            cnt = (cnt + (num/kk));
            kk = kk*k;
            if(cnt>=n) {fl=1; break;}
            if(num/kk ==0 ) break;
        }
    if(fl == 0) return 0;

    return 1;
}

int bsearch(int s,int e)
{
    int mid,ans=0;

        while(s<=e)
        {
            mid = (s+e)/2;
                //cout<<mid<<" " <<solve(mid)<<endl;
                if(solve(mid)) {ans=mid;e=mid-1;}
                else s=mid+1;
        }
    return ans;
}

int main()
{
    int tc;


            scanf("%d %d", &n,&k);

                if(k>=n) pf("%d\n",n);
                else pf("%d\n",bsearch(1,n));

    return 0;
}