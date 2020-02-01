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

int n,ar[200005],ar2[200005],dp[10005][3];

int lis()
{
    vector <int> vec;

    for(int i=0; i<n; i++)
    {//cout<<" "<<ar2[i] << " " ;
        int pos = lower_bound(vec.begin(),vec.end(),ar2[i]) - vec.begin();
        if(pos == vec.size()) vec.pb(ar2[i]);
        vec[pos] = ar2[i];
    }//cout<<endl;
    return vec.size();
}

int main()
{
	int tc,temp,tt=0;
	sf(tc);

	while(tc--)
    {
        sf(n);
        for(int i=0; i<n; i++) {sf(temp); ar[temp]=i;}
        for(int i=0; i<n; i++) {sf(temp); ar2[i] = ar[temp];}
        casepf(++tt);
        pf("%d\n", (n-lis())*2);
    }

	return 0;
}