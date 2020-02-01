#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 2503
#define ll long long int
#define mp make_pair
#define mod 100000007

int par[103],node;

int find_(int p)
{
    if(par[p] == p) return p;
    return par[p]=find_(par[p]);
}

struct order_increasing
{
    int u,v,w;

        bool operator <(const order_increasing &x)const
        {
            return w<x.w;
        }
};

vector <order_increasing> best;

int mst()
{
    int cnt=0,sum=0,len=best.size();

        for(int i=0; i<len; i++)
        {
            int u=best[i].u;
            int v=best[i].v;

                int a=find_(u);
                int b=find_(v);

                    if(a!=b){
                        par[a]=b;
                        sum+=best[i].w;
                        cnt++;
                            if(cnt==node) break;
                    }
        }
    return sum;
}

int mst2()
{
    int cnt=0,sum=0,len=best.size();

        for(int i=len-1; i>=0; i--)
        {
            int u=best[i].u;
            int v=best[i].v;

                int a=find_(u);
                int b=find_(v);

                    if(a!=b){
                        par[a]=b;
                        sum+=best[i].w;
                        cnt++;
                            if(cnt==node) break;
                    }
        }
    return sum;
}

int main()
{
    int tc,u,v,w;
        sf(tc);

            loop1(tt,tc)
            {
                sf(node);
                order_increasing get;
                best.clear();

                    while(scanf("%d %d %d", &get.u,&get.v,&get.w) == 3)
                    {
                        if(get.u==0 && get.v==0 && get.w==0) break;//cout<<"..."<<endl;

                            best.push_back(get);
                    }
                    sort(best.begin(),best.end());

                    for(int i=0; i<=node; i++) par[i]=i;
                    int ans = mst();
                    for(int i=0; i<=node; i++) par[i]=i;
                    int ans2 = mst2();
                    ans += ans2;

                        if(ans%2 == 0) pf("Case %d: %d\n",tt,ans/2);
                        else pf("Case %d: %d/2\n", tt,ans);

                            //if(tt!=tc) pf("\n");
            }
    return 0;
}