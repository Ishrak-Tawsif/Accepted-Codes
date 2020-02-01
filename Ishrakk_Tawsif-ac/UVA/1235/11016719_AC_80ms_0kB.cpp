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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      9999+3
#define mod                     1000000007

struct ST
{
    int u,v,cost;

    bool operator < (const ST & x) const
    {
        return cost<x.cost;
    }
};

int par[503],ar[503],in,edge,n;
map <int,int> id;
vector <ST> graph;

void reset()
{
    graph.clear();
    id.clear();
}

int calccost(int i,int j)
{
    int temp1 = ar[i],temp2 = ar[j],total=0,tt=0;

        while(tt<4)
        {
            int dig1 = temp1%10;
            if(temp1 != 0)temp1 /= 10;
            int dig2 = temp2%10;
            if(temp2 != 0)temp2/=10;

            if(dig1<dig2) swap(dig1,dig2);
            int cost1 = dig1-dig2;
            int cost2 = (10-dig1) + dig2;

            total += min(cost1,cost2);
            tt++;//cout<<temp1<< " ... " << temp2<<" "<<total<<endl;;
        }
    return total;
}

int find_par(int p)
{
    if(par[p] == p)return p;
    return  par[p] = find_par(par[p]);
}

int mst()
{
    int total = 0,cnt=0,fl=0;

        for(int i=0; i<graph.size(); i++)
        {
            int u = graph[i].u;
            int v = graph[i].v;
            int cost = graph[i].cost;

            if(fl && (!u || !v)) continue;
            if(!u || !v) fl=1;

                int paru = find_par(u);
                int parv = find_par(v);

                    if(paru != parv)
                    {
                        par[paru] = parv;
                        cnt++;
                        total += cost;//cout<<u<<" " << v <<endl;
                        if(cnt == (n)) break;
                    }
        }
    if(cnt == (n)) return total;
    return -1;
}

int main()
{

    int tc,temp;
    ST get;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        //int n;
        reset();
        in = 0;

        sf(n);

         id[0000] = 0;
         ar[0] = 0000;

            loop(i,0,n)
            {
                scanf("%d", &temp);
                if(id[temp] == 0) id[temp] = ++in,ar[in] = temp;
            }
//cout<<in<<<<endl;
            for(int i=0; i<=in; i++)
            {
                for(int j=i+1; j<=in; j++)
                {
                    //int cost = calccost(i,j);
                    get.u = i;
                    get.v = j;
                    get.cost = calccost(i,j);
                    graph.pb(get);//cout<< i << " .. " << j << " " << get.cost << endl;
                }
            }

            sort(graph.begin(),graph.end());

            for(int i=0; i<=in; i++) par[i] = i;

            int res = mst();
            pf("%d\n", res);
    }
    return 0;
}