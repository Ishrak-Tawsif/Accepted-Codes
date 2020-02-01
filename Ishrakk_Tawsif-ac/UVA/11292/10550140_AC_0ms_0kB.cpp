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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

ll dra[200005],kni[200005];

int main()
{//WRITE("in.txt");
    int n,m;
//cout<<((2+4)>>1)<<endl;
    while(scanf("%d %d", &n,&m) == 2 &&n && m)
    {
        for(int i=0; i<n; i++) scanf("%lld", &dra[i]);
        for(int i=0; i<m; i++) scanf("%lld", &kni[i]);

        sort(dra,dra+n);
        sort(kni,kni+m);

        ll ans=0,fl=0,cnt=0,ind=0;

        for(int i=0; i<m; i++)
        {
            if(dra[ind]<=kni[i])
            {//cout<<dra[ind]<<" "<<kni[i]<<endl;
                cnt++;
                ans += kni[i];
                ind++;
                if(ind>=n){fl=1;break;}
            }
        }

        /*for(int i=0; i<n; i++)
        {
            int temp = bsearch(0,m-1,dra[i]);cout<<temp<<" ... "<<endl;
            if(temp == -1){fl=0;break;}
            else ans += kni[temp];
        }*/
        (fl==0)? pf("Loowater is doomed!\n") : pf("%lld\n", ans);
    }

    return 0;
}