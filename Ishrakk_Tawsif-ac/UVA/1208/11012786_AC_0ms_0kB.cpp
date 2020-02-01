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
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

struct ST
{
    int u,v,cost;

        bool operator < (const ST & x) const
        {
            return cost<x.cost;
        }
};

int n,m,par[2005];
//unordered_map <string,int> id;
vector <ST> graph;

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int find_par(int p)
{
    if(par[p] == p) return p;
    else return find_par(par[p]);
}

int mst()
{
    int cnt = 0,totalcost=0;

    for(int i=0; i<graph.size(); i++)
    {
        int uu = graph[i].u;
        int vv = graph[i].v;
        int cst = graph[i].cost;

            int paru = find_par(uu);
            int parv = find_par(vv);

                if(paru != parv)
                {
                    par[parv] = paru;
                    totalcost += cst;
                    cnt ++;//cout<<cnt<<" "<<uu<<" "<<vv<<" "<<cst<<endl;

                    if(uu>vv) cout<<alpha[vv-1]<<"-"<<alpha[uu-1]<<" "<<cst<<endl;
                    else cout<<alpha[uu-1]<<"-"<<alpha[vv-1]<<" "<<cst<<endl;

                    if(cnt == (n-1)) break;
                }
    }
    //if(cnt == (n-1)) return totalcost;
    //return -1;
}

void reset()
{
    graph.clear();
    //id.clear();
}

int main()
{//WRITE("in.txt");
    int tc,cs;
    string str;
    ST get;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d", &n);

        reset();

        int temp,val=0,mul=1,in=0;
        m=0;
        cin.ignore();
        loop(i,0,n)
        {//cout<<i<<endl;
            getline(cin,str);
            in = 0;
            for(int j=0; j<str.length(); j++)
            {
                if(str[j]>='0' && str[j]<='9')
                {
                    temp = (int)str[j]-'0';//cout<<j<<" "<<temp<<endl;
                    val = (val * mul) + temp;//cout<<val<<"....."<<endl;
                    mul *= 10;
                }
                if(str[j] == ',' || j == str.length()-1)
                {
                    get.u = i+1;
                    get.v = ++in;
                    get.cost = val;
                    if(val!=0 && j>i)graph.pb(get),m++;

                    mul = 1;
                    val = 0;
                    //in = 0;
                    //cout<<get.u<<" "<<get.v<<" "<<get.cost<<endl;
                }
            }
        }//cout<<"out\n";

        for(int i=1; i<=n; i++) par[i] = i;

        sort(graph.begin(),graph.end());

        casepf(tt);
        mst();

        //(tt == tc)? pf("%d\n", res) : pf("%d\n\n", res);
    }

    return 0;
}