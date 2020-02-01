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
#define mod                     100000007


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};

int cnt1[31],cnt2[31];

int main()
{
    string a,b,c;
//int tt='Z';cout<<tt-64<<endl;
        cin>> a>> b>> c;

            for(int i=0; i<a.size(); i++)
            {
                int temp = a[i];
                temp-=64;
                cnt1[temp]++;
            }

            for(int i=0; i<b.size(); i++)
            {
                int temp = b[i];
                temp-=64;
                cnt1[temp]++;
            }

            for(int i=0; i<c.size(); i++)
            {
                int temp = c[i];
                temp-=64;
                cnt2[temp]++;
            }

            int fl=1;
            for(int i=1; i<=26; i++)
            {
                if(cnt1[i] != cnt2[i]){fl=0; break;}
            }

            (fl==1)? pf("YES\n") : pf("NO\n");


    return 0;
}