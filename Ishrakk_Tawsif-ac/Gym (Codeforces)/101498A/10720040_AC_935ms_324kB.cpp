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

map <int,int> mpp;

int main()
{
    int tc,n;

    string str;

    sf(tc);

    loop(tt,0,tc)
    {
        sf(n);

        mpp.clear();
        int frq,max_=-intinf,ans;

        while(n--)
        {
            cin>> str>> frq;
            mpp[frq] ++;
            if(max_<mpp[frq])max_ = mpp[frq],ans=frq;
            else if(max_ == mpp[frq]) ans=min(ans,frq);
        }cout<<ans<<endl;
    }
    return 0;
}