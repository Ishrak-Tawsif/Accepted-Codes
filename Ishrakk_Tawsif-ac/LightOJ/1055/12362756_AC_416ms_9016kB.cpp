#include<bits/stdc++.h>
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
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define all(a)                  (a.begin(),a.end())
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      11
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int n,vis[3][13][13],tr[3],tc[3],visited[11][11][11][11][11][11];
string str[13];
vector <pair<int,int> > start,ok,endd;
//map <vector <pair<int,int> >,int> visisted;

int check()
{
    int fl = 1;//if(ok.size()<3) system("pasuse");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i != j)
            {
                if(ok[i].first == ok[j].first && ok[i].second == ok[j].second) fl = 0;
            }
        }
    }
    return fl;
}

int isend(int rr[3],int cc[3])
{//out("here");
    int endarr[100][100],fl = 1;
    mem(endarr,0);
    for(int i=0; i<3; i++)
    {//out(i);//system("pause");
        endarr[rr[i]][cc[i]] = 1;
        //cout<<" "<<rr[i]<<" "<< cc[i];
    }//cout<<endl;

    for(int i=0; i<3; i++)
    {
        if(!endarr[endd[i].first][endd[i].second]) fl = 0;
    }

    /*for(int i=0; i<3; i++)
    {
        if(str[rr[i]][cc[i]] != 'X') fl = 0;
    }*/
    return fl;
}

void fixedit(int rr[3],int ccc[3])
{
    pair <int,int> aa;
    pair <int,int> bb;
    pair <int,int> cc;


    aa = ok[0];
    bb = ok[1];
    cc = ok[2];
    if(aa == bb)
    {
        if(bb == cc)
        {
            cc.first = rr[2];
            cc.second = ccc[2];
        }
        aa.first = rr[0];
        aa.second = ccc[0];
        bb.first = rr[1];
        bb.second = ccc[1];
    }
    if(aa == cc)
    {
        aa.first = rr[0];
        aa.second = ccc[0];
        cc.first = rr[2];
        cc.second = ccc[2];
    }
    if(bb == cc)
    {
        bb.first = rr[1];
        bb.second = ccc[1];
        cc.first = rr[2];
        cc.second = ccc[2];

        if(aa == bb)
        {
            aa.first = rr[0];
            aa.second = ccc[0];
        }
    }
    ok[0] = aa;
    ok[1] = bb;
    ok[2] = cc;
}

int isvalid(int rr,int cc)
{
    if(rr>=0 && rr<n && cc>=0 && cc<n) return 1;
    return 0;
}

int bfs()
{
    queue <pair<int,pair<int,int> > > q; ///row,col,cost

    for(int i=0; i<3; i++)
    {
        int r = start[i].first;
        int c = start[i].second;
        q.push(mp(r,mp(c,0)));
        vis[i][r][c] = 1;
        ok.pb(mp(r,c));
    }

    visited[ok[0].first][ok[0].second][ok[1].first][ok[1].second][ok[2].first][ok[2].second] = 1;
    ok.clear();
    int rr[3],cc[3],cost[3];
    while(!q.empty())
    {//out("ok");
        int tin = 3,koto=0;

//out(q.size());system("pause");
            for(koto = 0; koto<3; koto++)
            {
                pair<int,pair<int,int> > temp = q.front();
                q.pop();
                rr[koto] = temp.first;
                cc[koto] = temp.second.first;
                cost[koto] = temp.second.second;
            }
//cout<<cost[0]<<endl;
            if(isend(rr,cc))
            {//out("ok");
                //for(int i=0; i<3; i++) cout<<" ... "<<cost[i];cout<<endl;
                return cost[0];
            }

            for(int i=0; i<4; i++)
            {
                int visache = 0;//out("...");
                for(int j=0; j<3; j++)
                {
                    tr[j] = rr[j] + dx[i];//out(",,");
                    tc[j] = cc[j] + dy[i];

                    if(isvalid(tr[j],tc[j]))
                    {
                        if(str[tr[j]][tc[j]] == '#') {ok.pb(mp(rr[j],cc[j]));if(vis[j][rr[j]][cc[j]]) visache++;}
                        else /*if(!vis[j][tr[j]][tc[j]])*/
                        {
                            if(vis[j][tr[j]][tc[j]]) visache ++;
                            ok.pb(mp(tr[j],tc[j]));
                        }
                    }
                    else {ok.pb(mp(rr[j],cc[j]));if(vis[j][rr[j]][cc[j]]) visache++;}
                }
                if(check())
                {
                    if(!visited[ok[0].first][ok[0].second][ok[1].first][ok[1].second][ok[2].first][ok[2].second])
                    {
                        visited[ok[0].first][ok[0].second][ok[1].first][ok[1].second][ok[2].first][ok[2].second] = 1;
                        for(int j=0; j<3; j++)
                        {
                            //if(visache == 3) break;
                            //if(visisted[ok]) break;
                            //visisted[ok] = 1;//out(j);
                            int curr = ok[j].first;
                            int curc = ok[j].second;
                            vis[j][curr][curc] = 1;
                            q.push(mp(curr,mp(curc,cost[j]+1)));
                        }
                    }
                }
                else
                {
                    fixedit(rr,cc);

                    if(!visited[ok[0].first][ok[0].second][ok[1].first][ok[1].second][ok[2].first][ok[2].second])
                    {
                        visited[ok[0].first][ok[0].second][ok[1].first][ok[1].second][ok[2].first][ok[2].second] = 1;
                        for(int j=0; j<3; j++)
                        {
                            //if(visache == 3) break;
                            //if(visisted[ok]) break;
                            //visisted[ok] = 1;//out(j);
                            int curr = ok[j].first;
                            int curc = ok[j].second;
                            vis[j][curr][curc] = 1;
                            q.push(mp(curr,mp(curc,cost[j]+1)));
                        }
                    }
                }
                ok.clear();
            }
        }
    return -1;
}

void clearall()
{
    start.clear();
    endd.clear();
    ok.clear();
    mem(vis,0);
    mem(visited,0);
}

int main()
{//WRITE("out.txt");
    int tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        clearall();
        sf(n);
        for(int i=0; i<n; i++)
        {
            cin>> str[i];
            for(int j=0; j<n; j++)
            {
                if(str[i][j]>= 'A' && str[i][j]<= 'C') start.pb(mp(i,j));
                if(str[i][j] == 'X') endd.pb(mp(i,j));
            }
        }

        casepf(tt);
        int res = bfs();
        res==-1? pf("trapped\n") : pf("%d\n",res);
    }

    return 0;
}

/*
7
7
...#...
#...#..
#..##.C
.#.#...
.BX#...
#.#X.#A
#.####X
*/