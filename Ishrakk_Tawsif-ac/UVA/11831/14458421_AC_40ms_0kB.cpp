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

int n,m,len;
string str[105],ins;

int dxx[] = {-1,0,1,0};
int dyy[] = {0,1,0,-1};

int turnright(int tp)
{
    if(tp == 0) return 1;
    else if(tp == 1) return 2;
    else if(tp == 2) return 3;
    return 0;
}

int turnleft(int tp)
{
    if(tp == 0) return 3;
    else if(tp == 3) return 2;
    else if(tp == 2) return 1;
    return 0;
}

int bfs(int sr,int sc,int type)
{//cout<<sr<<" .... "<<sc<<"  ... "<<type<<endl;
    queue <int> q;
    q.push(sr);
    q.push(sc);
    q.push(type);
    q.push(0);
    //vis[sr][sc] = 1;

    for(int i=0; i<len; i++)
    {
        int r = q.front(); q.pop();
        int c = q.front(); q.pop();
        int tp = q.front(); q.pop();
        int cost = q.front(); q.pop();
        //if(i) cout<<ins[i-1];
        //cout<<i<<" "<<r<<" "<<c<<" "<<tp<<endl;

        if(ins[i] == 'F')
        {
            int tr = r + dxx[tp];
            int tc = c + dyy[tp];

            if(tr>=0 && tr<n && tc>=0 && tc<m && (str[tr][tc] != '#'))
            {
                int curcost = cost;
                if(str[tr][tc] == '*') curcost++;
                str[tr][tc] = '.';
                q.push(tr);
                q.push(tc);
                q.push(tp);
                q.push(curcost);
            }
            else
            {
                q.push(r);
                q.push(c);
                q.push(tp);
                q.push(cost);
            }
        }
        else if(ins[i] == 'D')
        {
            int curtype = turnright(tp);
            q.push(r);
            q.push(c);
            q.push(curtype);
            q.push(cost);
        }
        else
        {
            int curtype = turnleft(tp);
            q.push(r);
            q.push(c);
            q.push(curtype);
            q.push(cost);
        }
    }

    int r = q.front(); q.pop();
    int c = q.front(); q.pop();
    int tp = q.front(); q.pop();
    int cost = q.front(); q.pop();


    return cost;
}

int check(char ch)
{
    if(ch == 'N') return 0;
    if(ch == 'L') return 1;
    if(ch == 'S') return 2;
    if(ch == 'O') return 3;
    return -1;
}

int main()
{//WRITE("out.txt");
    int sr,sc,type;
    while(scanf("%d %d %d", &n,&m,&len) == 3)
    {
        if(!n && !m && !len) break;

        for(int i=0; i<n; i++)
        {
            cin>> str[i];//out(i);
            for(int j=0; j<str[i].length(); j++)
            {
                int now = check(str[i][j]);
                if(now != -1)
                {//cout<<str[i][j]<<" here "<<i<<" "<<j<<endl;
                    sr = i;
                    sc = j;
                    type = now;
                }
            }
            //getchar();
        }

        cin>> ins;

        int res = bfs(sr,sc,type);
        pf("%d\n", res);
    }
    return 0;
}