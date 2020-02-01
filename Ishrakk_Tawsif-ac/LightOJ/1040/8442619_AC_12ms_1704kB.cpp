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

int par[103],node,cost[53][53];
double start;

int time_needed()
{
    double end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<cpu_time_used<<endl;
}

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
    if(cnt!=(node-1)) return -1;
    return sum;
}

int mst2()
{
    int cnt=0,sum=0,len=best.size();

    start=clock();

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

                memset(cost,-1,sizeof(cost));

                int temp,sum=0;

                    for(int i=1; i<=node; i++)
                    {
                        for(int j=1; j<=node; j++){
                            sf(temp);
                            sum+=temp;

                            if(temp==0) continue;

                                if(cost[i][j]==-1 && cost[j][i]==-1)
                                {
                                    cost[i][j]=cost[j][i]=temp;
                                }
                                else
                                {
                                    if(cost[i][j]>temp) cost[i][j]=cost[j][i]=temp;
                                }
                        }
                    }

                    for(int i=1; i<=node; i++)
                    {
                        for(int j=1; j<=node; j++)
                        {
                            if(cost[i][j]!=-1)
                            {
                                get.u=i;
                                get.v=j;
                                get.w=cost[i][j];//cout<< i << " " << j << " " << cost[i][j] << endl;
                                best.push_back(get);
                                cost[i][j]=cost[j][i]=-1;
                            }
                        }
                    }

                    sort(best.begin(),best.end());

                    for(int i=0; i<=node; i++) par[i]=i;
                    int ans = mst();

                        if(ans==-1) pf("Case %d: -1\n", tt);
                        else pf("Case %d: %d\n", tt,sum-ans);

                            //time_needed();
            }
    return 0;
}