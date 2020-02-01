#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 5005
#define ll long long int
#define mp make_pair
#define mod 100000007

unordered_map <int,unordered_map<int,int> > cost;
int par[1000005],n,m,k;

int find_(int i)
{
    if(par[i] == i) return par[i];
    return par[i]=find_(par[i]);
}

struct st
{

    int u,v,c;

        bool operator <(const st &x) const
        {
            return c<x.c;
        }
};

vector <st> graph,graph2[1000005];

int mst()
{
    int sum=0,cnt=0;

        for(int i=0; i<graph.size(); i++)
        {
            int u=graph[i].u;
            int v=graph[i].v;

                int a=find_(u);
                int b=find_(v);

                    if(a!=b)
                    {
                        par[a]=b;
                        sum += graph[i].c; //cout<<u << " " << v << " ... " << graph[i].c << endl;
                        cnt++;

                            if(cnt == (n-1)) break;
                    }
        }//cout<<sum<<"  ... " << cnt<<endl;
        if(cnt==(n-1)) return sum;
        return -1;
}


int main()
{
    int u,v,c,ans,ans2,tc=0;

       while(scanf("%d",&n) == 1)
       {

        graph.clear();

        if(tc!=0) pf("\n");

           ans=0;
               loop(i,n-1)
               {
                    //ans=0;
                    scanf("%d %d %d",&u,&v,&c);
                    ans += c;
               }

           sf(k);
           st get;

               loop(i,k)
                {
                   scanf("%d %d %d", &get.u,&get.v,&get.c);
                   cost[u][v]=c; //cout<< "cost :" << cost[u][v]<<endl;
                   graph.pb(get);
                }

           sf(m);


               loop(i,m)
               {
                   scanf("%d %d %d", &get.u,&get.v,&get.c);
                   /*if(cost[u][v]!=0)
                   {
                        get.c = min(cost[u][v],get.c);
                        graph.pb(get);
                   }*/
                   //else
                    graph.pb(get);
               }

           sort(graph.begin(),graph.end());

           for(int i=1; i<=n; i++) par[i]=i;
           cout<<ans<<endl;
           cout<<mst()<<endl;
           tc++;
       }

    return 0;
}


/*
5
1 2 5
1 3 5
1 4 5
1 5 5
1
2 3 2
6
1 2 5
1 3 5
1 4 5
1 5 5
3 4 8
4 5 8
*/