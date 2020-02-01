#include <bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

/*#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define loop1(var,start,till)   for(int var=start; var<=till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define all(a)                  (a.begin(),a.end())
#define Unique_(a)              sort(all(a));a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000009
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

pair <int,int> ar[23];
int diss[13][23][23],vis[13][23][23],rr,cc,sr,sc,cost[13][13],n,dp[13][1<<13],lim;
unordered_map <int,unordered_map<int,int> >mpp;

void bfs(int id,int cr,int ccc)
{
    queue <int> q;//cout<<cr<<" startt "<<cc<<endl;
    vis[id][cr][ccc] = 1;
    diss[id][cr][ccc] = 0;
    q.push(cr);
    q.push(ccc);

    while(!q.empty())
    {
        int row = q.front(); q.pop();
        int col = q.front(); q.pop();

        for(int i=0; i<4; i++)
        {
            int tr = row + dx[i];
            int tc = col + dy[i];
//cout<<tr<<" /// "<<tc<<" "<<rr<<" "<<cc<<endl;
            if(tr>=1 && tr<=rr && tc>=1 && tc<=cc)
            {//out("ok");
                //if(tr == 2 && tc == 3) cout<<row<<" "<<col<<" "<<tr<<" "<<tc<<" "<<vis[id][tr][tc]<<endl;
                if(!vis[id][tr][tc])
                {//if(tr == 1 && tc == 1) cout<<row<<" heree "<<col<<endl;
                    q.push(tr);
                    q.push(tc);
                    diss[id][tr][tc] = diss[id][row][col] + 1;
                    vis[id][tr][tc] = 1;
                }
            }
        }
    }
}

int tsp(int pos,int mask)
{//cout<<mask<<" .. "<<lim<<endl;
    if(mask == lim)
    {//cout<<pos<<" "<<cost[pos][n]<<endl;
        return cost[pos][n];
    }
    if(dp[pos][mask] != -1) return dp[pos][mask];

    int res = 2e9;
    for(int i=0; i<n; i++)
    {
        if(!(mask & 1<<i))
        {
            res = min(res,tsp(i,mask | (1<<i)) + cost[pos][i]);
        }
    }
    return dp[pos][mask] = res;
}

void clearall()
{
    mem(vis,0);
    mem(diss,0);
    mpp.clear();
    mem(cost,0);
}

int main()
{//WRITE("out.txt");
    int tc,x,y;

    sf(tc);

    while(tc --)
    {

        clearall();

        scanf("%d %d", &rr,&cc);
        scanf("%d %d", &sr,&sc);
        sf(n);
        mpp[sr][sc] = n;
        ar[n] = mp(sr,sc);
//cout<<rr<<" ... "<<cc<<endl;
        for(int i=0; i<n; i++)
        {
            scanf("%d %d", &x,&y);
            if(!mpp[x][y]) mpp[x][y] = i;
            ar[i] = mp(x,y);
        }

        for(int i=0; i<=n; i++)
        {
            int cr = ar[i].first;
            int ccc = ar[i].second;

            bfs(i,cr,ccc);
            //cout<<cr<<" .. "<<ccc<<endl;
            for(int j=0; j<=n; j++)
            {
                cr = ar[j].first;
                ccc = ar[j].second;

                cost[i][j] = cost[j][i] = diss[i][cr][ccc];
                //cout<<cr<<" "<<ccc<<" "<<cost[i][j]<<endl;
            }//system("pause");
        }
//system("pause");
        lim = (1<<n) - 1;
        mem(dp,-1);
        int mask = 0;
//        mask = mask |= (1<<1);//out(mask);
//        mask = mask |= (1<<0);//out(mask);
        pf("The shortest path has length %d\n",tsp(n,0));

    }
    return 0;
}