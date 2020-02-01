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


string str[1505];
int n,m,vis[1505][1505],ispos=0;
pair<int,int>path[1505][1505];

void dfs(int r,int c)
{
    int tempr = r%n,tempc = c%m;
    tempr = (tempr+n)%n;
    tempc = (tempc+m)%m;
    //if(tempr<=0) tempr += n;
    //if(tempc<=m) tempc += m;
//cout<<tempr<<" " << tempc<<endl;
    if(str[tempr][tempc] == '#') return;
//cout<<str[tempr][tempc]<<endl;
    if(vis[tempr][tempc])
    {
        if(path[tempr][tempc].first != r || path[tempr][tempc].second != c)
            {//cout<<tempr<<" " << tempc<<" "<<r<<" " << c<<endl;
                ispos = 1;
                return;
            }
        return;
    }
    else
    {
        vis[tempr][tempc] = 1;
        path[tempr][tempc] = mp(r,c);
        //path[tempr][tempc].second = c;

            for(int i=0; i<4; i++)
            {
                int tempr = r+dx[i];
                int tempc = c+dy[i];
                dfs(tempr,tempc);
            }
    }
    //return false;
}

int main()
{
    int fl=0,sr,sc;

    scanf("%d %d", &n,&m);

    for(int i=0; i<n; i++)
    {
        cin>> str[i];

        if(!fl){
            for(int j=0; j<m; j++)
            {
                if(str[i][j] == 'S')
                {
                    sr = i;
                    sc = j;
                    fl=1;
                    break;
                }
            }
        }
    }
//out(sr);
//out(sc);
    dfs(sr,sc);
//cout<<ispos<<endl;
    (ispos == true)? pf("Yes\n") : pf("No\n");
    return 0;
}