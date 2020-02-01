#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

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
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      5000005
#define mod                     1000000007

int n,m,s,t,p;
ll diss[2][10005],maxi[10005];
vector <pair<int,ll> > vv[2][10005];

int dikjstra(int sr,int tp)
{
    set <pair<ll,int> >st;
    st.insert(mp(0,sr));
    diss[tp][sr] = 0;

    while(!st.empty())
    {
        pair <ll,int> temp = *st.begin();
        st.erase(st.begin());

        int u = temp.second;
        ll udis = temp.first;
//out(u);
            for(int i=0; i<vv[tp][u].size(); i++)
            {
                int v = vv[tp][u][i].first;//if(u == 5) cout<<" .... " << v << " " << diss[tp][v]<<endl;
                ll vcost = vv[tp][u][i].second;

                if(udis + vcost<diss[tp][v])
                {//if(v == 2) cout<<udis<<" ......222........ " << vcost <<endl;
                    diss[tp][v] = udis + vcost;
                    st.insert(mp(diss[tp][v],v));
                }
            }
    }
    //return ans;
}

void doclear()
{
    for(int i=0; i<10005; i++)
    {
        vv[0][i].clear();
        vv[1][i].clear();
        diss[0][i] = inf;
        diss[1][i] = inf;
    }
}

int main()
{//WRITE("in.txt");
    int tc,u,v,c;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        doclear();
        scanf("%d %d %d %d %d", &n,&m,&s,&t,&p);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d", &u,&v,&c);
            vv[0][u].pb(mp(v,c));
            vv[1][v].pb(mp(u,c));
        }//out("ok");
        dikjstra(s,0);
        dikjstra(t,1);

        ll ans = -inf;

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<vv[0][i].size(); j++)
            {
                int curnd = vv[0][i][j].first;
                ll curcost = diss[0][i] + diss[1][curnd] + vv[0][i][j].second;//cout<<curcost<<" "<<vv[0][i][j].second<<endl;
                //cout<<curnd<<" "<<diss[0][i] << " " << diss[1][curnd]<<" "<<vv[0][i][j].second<<" "<<curcost<<endl;
                if(curcost<=(ll)p) ans = max(ans,(ll)vv[0][i][j].second);
            }
        }

        (ans == -inf)? pf("-1\n") : pf("%lld\n", ans);//if(tt == 6)system("pause");
    }

    return 0;
}