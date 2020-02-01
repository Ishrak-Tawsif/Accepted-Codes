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

struct st
{
    string s;
    int n;
    bool operator <(const st &x)const
    {
        return n<x.n;
    }
};
vector <st> vv;

int main()
{
    int tc;
    sf(tc);
    st get;

    while(tc--)
    {
        vv.clear();

        sf(get.n);
        get.s = "First";
        vv.pb(get);
        sf(get.n);
        get.s = "Second";
        vv.pb(get);
        sf(get.n);
        get.s = "Third";
        vv.pb(get);

        sort(vv.begin(),vv.end());
        cout<<vv[0].s<<endl;
    }

    return 0;
}