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
#define mx                      1123
#define mod                     1000000009
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int dxx[] = {-1,0,0};
int dyy[] = {0,1,-1};
int n,m,vis[9][9],sr,sc;

string str[9];

bool check(int rr,int cc)
{//cout<<rr<<" ..... " << cc <<endl;
    if(str[rr][cc] == 'I' || str[rr][cc] == 'E' || str[rr][cc] == 'H' || str[rr][cc] == 'O'
       || str[rr][cc] == 'V' || str[rr][cc] == 'A' || str[rr][cc] == '#') return true;
    return false;
}

vector <pair <int,int> > path[9][9];
vector <int> direction[9][9],res;

void printpath(int sr,int sc,int r,int c)
{
    //cout<<str[2][3]<<" "<<path[2][3][0].first<<" "<<path[2][3][0].second<<endl;
    int curr = r,curc = c;
    while(curr != -1 && curc != -1)
    {
        res.pb(direction[curr][curc][0]);
        int tr = curr,tc = curc;
        curr = path[tr][tc][0].first;
        curc = path[tr][tc][0].second;//cout<<path[curr][curc][0].first<<" // "<<path[curr][curc][0].second<<endl;
        //cout<<str[curr][curc]<<endl;
    }
    return;
}

void bfs(int sr,int sc)
{
    queue <int> q;
    q.push(sr);
    q.push(sc);
    vis[sr][sc] = 1;
    path[sr][sc].pb(mp(-1,-1));
    direction[sr][sc].pb(-1);

    while(!q.empty())
    {
        int r = q.front(); q.pop();
        int c = q.front(); q.pop();//cout<<r<<" "<<c<<endl;

        if(str[r][c] == '#')
        {
            printpath(sr,sc,r,c);
            return;
        }

        for(int i=0; i<3; i++)
        {
            int tr = r + dxx[i];
            int tc = c + dyy[i];//cout<<r<<" "<<c<<" "<<tr<<" "<<tc<<endl;

            if(tr>=0 && tr<n && tc>=0 && tc<m)
            {//out("ok1");
                if(!vis[tr][tc])
                {//out("ok2");
                    if(check(tr,tc))
                    {//out("ok3");
                        path[tr][tc].pb(mp(r,c));
                        direction[tr][tc].pb(i);
                        q.push(tr);
                        q.push(tc);
                    }
                }
            }//system("pause");
        }

    }
}

void clearall()
{
    mem(vis,0);
    res.clear();
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++) path[i][j].clear(),direction[i][j].clear();
    }
}

int main()
{
    int tc;

    sf(tc);

    while(tc --)
    {
        clearall();
        scanf("%d %d", &n,&m);
        for(int i=0; i<n; i++)
        {
            cin>> str[i];
            for(int j=0; j<m; j++) if(str[i][j] == '@') sr = i,sc = j;
        }
        bfs(sr,sc);//out(res.size());
        for(int i=res.size()-2; i>=0; i--)
        {
            if(i != res.size()-2) pf(" ");

            if(res[i] == 0) pf("forth");
            else if(res[i] == 1) pf("right");
            else if(res[i] == 2)pf("left");
            else break;
        }
        pf("\n");
    }
    
    return 0;
}