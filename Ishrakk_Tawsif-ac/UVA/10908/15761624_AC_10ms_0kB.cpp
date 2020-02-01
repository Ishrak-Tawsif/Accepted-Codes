#include <bits/stdc++.h>
#include <ext/rope>

using namespace __gnu_cxx;
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
#define mx                      100005
#define mod                     998244353
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define bitOff(N,in)            (N&(~(1LL<<(in))))
#define bitOn(N,in)             (N|(1LL<<(in)))
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int n,m,vis[103][103];
string str[103];

int calc(int r,int c)
{
    queue <int> q;
    mem(vis,0);

    vis[r][c] = 1;

    int fl = 0,cnt = 0,totcnt=0,step=1;

    for(int i=0; i<8; i++)
    {
        int tr = r + dx[i];
        int tc = c + dy[i];

        if(tr>=0 && tr<n && tc>=0 && tc<m)
        {
            if(str[tr][tc] == str[r][c])
            {
                q.push(tr);
                q.push(tc);
                cnt++;
                vis[tr][tc] = 1;
            }
            else return 0;
        }
        else return 0;
    }

    totcnt = 8;
    while(1){
        set <pair<int,int> > tempq;
        while(!q.empty())
        {
            ++ step;
            fl = 1;

            int curr = q.front(); q.pop();
            int curc = q.front(); q.pop();

            for(int i=0; i<8; i++)
            {
                int tr = curr + dx[i];
                int tc = curc + dy[i];

                if(tr<0 || tr>=n || tc<0 || tc>=m)
                {
                   fl = 0;
                   break;
                }
                else
                {
                     if(str[tr][tc] != str[r][c])
                     {
                         fl = 0;
                         break;
                     }
                }
            }
            if(fl)
            {
                for(int i=0; i<8; i++)
                {
                    int tr = curr + dx[i];
                    int tc = curc + dy[i];
                    if(!vis[tr][tc])tempq.insert(mp(tr,tc)),vis[tr][tc]=1;
                }
            }
            else {return totcnt;}
        }

        for(auto x: tempq)
        {
            q.push(x.first);
            q.push(x.second);
        }

        totcnt += tempq.size();
    }
    return totcnt;
}

int main()
{//READ("in.txt");WRITE("out.txt");
    int tc,q;

    sf(tc);
    //cin.ignore();
    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d %d %d", &n,&m,&q);
        cin.ignore();
        for(int i=0; i<n; i++) getline(cin,str[i]);

        int r,c,qq=0;
        pf("%d %d %d\n",n,m,q);
        while(q--)
        {
            scanf("%d %d", &r,&c);//cout<<++qq<<" "<<r<<" "<<c<<endl;
            int res = calc(r,c);
            pf("%d\n", (int) sqrt(res+1));
        }
    }

    return 0;
}