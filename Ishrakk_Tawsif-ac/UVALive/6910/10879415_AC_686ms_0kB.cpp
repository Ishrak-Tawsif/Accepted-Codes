#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d:\n",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define intinf                  7e18
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};


//vector <int> graph[20005];
//unordered_map <int,unordered_map<int,int> > mpp;
int parlist[20005],vis[20005];

/*void dfs(int sr,int col)
{
    vis[sr] = col;///out(sr);
    for(int i=0; i<graph[sr].size(); i++)
    {
        int v = graph[sr][i];//cout<<sr<<" "<<v<<" "<<mpp[sr][v]<<" "<<vis[sr]<<" " <<col<<endl;
        if(mpp[sr][v] && vis[v] != col) dfs(v,col);
    }
}*/

/*void set_clear()
{
    mem(parlist,0);
    mpp.clear();
    for(int i=0; i<20005; i++) graph[i].clear(),vis[i] = 0;
}*/

int find_par(int n)
{
    if(parlist[n]  == n) return n;
    else return  find_par(parlist[n]);
}

int main()
{
    int tc,node,quries,u,v,par;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d %d", &node,&quries);

        //set_clear();

        for(int i=1; i<=node; i++)
        {
            sf(u);
            if(u==0) parlist[i] = i;
            else parlist[i] = u;
        }


        char ch;

        casepf(tt);

        while(quries--)
        {
            cin>> ch;

            if(ch == 'C')
            {
                sf(u);
                parlist[u] = u;
            }
            else
            {
                scanf("%d %d", &u,&v);
                int uu = find_par(u); int vv = find_par(v);
                //cout<<uu<<" " << vv << endl;
                if(uu == vv) pf("YES\n");
                else pf("NO\n");
            }
        }
    }
    
    return 0;
}