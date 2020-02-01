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

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

unordered_map <int,int> mpp;

int ar[400005];

int main()
{
    double x1,x2,y1,y2,r1,r2;

    cin>>x1 >> y1>> r1>> x2>> y2>> r2;

    double dis = sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));//cout<<dis<<endl;

    double ans = 0.0;
    if(dis>(r1+r2)) ans = dis-(r1+r2);
    else
    {
        if(dis<(fabs(r1-r2))) ans=(fabs(r1-r2))-dis;
    }

    ans /= 2.0;

    pf("%.6f\n",ans);

    //pf("%lld\n", cnt);
}