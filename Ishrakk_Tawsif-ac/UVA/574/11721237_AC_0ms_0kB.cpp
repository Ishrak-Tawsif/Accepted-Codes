#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d: ",nn)
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
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int n,t,vis[13],ar[13],cnt,ans[13];
map<vector<int>,bool> isok;
vector <int> vv;

void backtrack(int pos,int in,int jog)
{//out(in);
    if(in == (n+2)) return;
    if(jog>t)  return;
    //if(pos>n) return;
    if(jog == t)
    {
        if(isok[vv]) return;
        isok[vv] = 1;
        cnt++;
            pf("%d", vv[0]);
            for(int i=1; i<in-1; i++)
            {
                pf("+%d", vv[i]);
            }
            pf("\n");

        return;
    }

    //if(in == n+1) return;
    for(int i=pos; i<=n; i++)
    {
        if(!vis[i])
        {
            vv.pb(ar[i]);
            backtrack(i+1,in+1,jog+ar[i]);
            vv.pop_back();
        }
    }
}


int main()
{//READ("in.txt");WRITE("out.txt");
    while(scanf("%d %d", &t,&n) == 2)
    {
        if(!n) break;
        for(int i=1; i<=n; i++) sf(ar[i]);
        pf("Sums of %d:\n", t);
        cnt=0;
        vv.clear();
        isok.clear();
        backtrack(1,1,0);
        if(!cnt) pf("NONE\n");//out(cnt);
    }
    return 0;
}