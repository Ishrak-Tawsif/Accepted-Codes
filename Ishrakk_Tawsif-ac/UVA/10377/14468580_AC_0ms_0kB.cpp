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

string str[63],orientation = "NESW";
vector <string> vv;
int n,m;

int dxx[] = {-1,0,1,0};
int dyy[] = {0,1,0,-1};

int turnright(int type)
{
    if(type == 0) return 1;
    if(type == 1) return 2;
    if(type == 2) return 3;
    return 0;
}

int turnleft(int type)
{
    if(type == 0) return 3;
    if(type == 3) return 2;
    if(type == 2) return 1;
    return 0;
}

void bfs(int sr,int sc)
{
    queue <int> q;
    q.push(sr);
    q.push(sc);
    q.push(0);

    for(int i=0; i<vv.size(); i++)
    {
        string temp = vv[i];

        for(int j=0; j<temp.length(); j++)
        {
            int r = q.front(); q.pop();
            int c = q.front(); q.pop();
            int tp = q.front(); q.pop();

            if(temp[j] == 'R')
            {
                int curtp = turnright(tp);
                q.push(r);
                q.push(c);
                q.push(curtp);
            }
            else if(temp[j] == 'L')
            {
                int curtp = turnleft(tp);
                q.push(r);
                q.push(c);
                q.push(curtp);
            }
            else if(temp[j] == 'F')
            {
                //while(1)
                //{
                    int tr = r + dxx[tp];
                    int tc = c + dyy[tp];

                    if(tr>=0 && tr<n && tc>=0 && tc<m)
                    {
                        if(str[tr][tc] == '.') r = tr,c = tc;
                        //else break;
                    }
                    //else break;
                //}
                q.push(r);
                q.push(c);
                q.push(tp);
            }
            else
            {
                q.push(r);
                q.push(c);
                q.push(tp);
                break;
            }
        }
    }
    int r = q.front(); q.pop();
    int c = q.front(); q.pop();
    int tp = q.front(); q.pop();
    cout<<r+1<<" "<<c+1<<" "<<orientation[tp]<<endl;
}

int main()
{//WRITE("out.txt");
    int tc,sr,sc;

    sf(tc);

    while(tc --)
    {
        scanf("%d %d", &n,&m);

        getchar();
        for(int i=0; i<n; i++)
        {
            getline(cin,str[i]);//out(str[i]);
            for(int j=0; j<m; j++) if(str[i][j] == ' ') str[i][j] = '.';
        }
        //for(int i=0; i<n; i++) out(str[i]);
        scanf("%d %d", &sr,&sc);

        string ins,temp;
        vv.clear();
        getchar();
        while(getline(cin,ins))
        {
            if(ins.length() == 0) break;
            stringstream strem (ins);

            while(strem>> temp) vv.pb(temp);
        }


        bfs(sr,sc);

        if(tc) pf("\n");
    }

    return 0;
}