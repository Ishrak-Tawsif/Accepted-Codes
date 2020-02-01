///lca

#include<bits/stdc++.h>
using namespace std;

int dirx[8]={0,0,1,-1,1,1,-1,-1};
int diry[8]={1,-1,0,0,1,-1,1,-1};

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
#define inf                     2e16
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      5000+5
#define mod                     1000000007


int main()
{//WRITE("in.txt");
    int c,s,tc=0,in,cnt=0;
    double ar[2005],sum,avg;

    while(scanf("%d %d", &c,&s) == 2)
    {

        sum = 0.0;
        cnt = 0;
        vector <double> vv;

        pf("Set #%d\n", ++tc);
        in = -1;

        for(int i=0; i<s; i++) scanf("%lf", &ar[i]),sum += ar[i],vv.pb(ar[i]);
        avg = sum/(c*1.0);
        sum = 0.0;

        while(vv.size()<(2*c)) vv.pb(0.0);
        sort(vv.rbegin(),vv.rend());

        int st=0,en=vv.size()-1;
        for(int i=0; i<(vv.size()/2); i++)
        {
            pf("%2d:", ++in);
            if(vv[st] > 0) cout<<" "<<vv[st];
            if(vv[en] > 0) cout<<" "<<vv[en];
            double temp = ((avg-(vv[st]+vv[en])));
            sum += (temp>=0.0)? temp : -temp;
            st++,en--;
            pf("\n");

        }

        pf("IMBALANCE = %.5f\n\n", sum);
    }
    return 0;
}