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
#define mod                     998244353
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define bitOff(N,in)            (N&(~(1LL<<(in))))
#define bitOn(N,in)             (N|(1LL<<(in)))
#define ull                     unsigned long long
#define eps                     .000000001
#define mx                      1000005

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int penalty[203][17];
map <string,int> id;
vector <pair<string,pair<string,string> > > vv[10005];

struct st
{
    string name;
    int time,id,totpro;
    bool operator <(const st & x) const
    {
        if(totpro == x.totpro)
        {
            if(time == x.time) return id < x.id;
            else return time < x.time;
        }
        else return totpro > x.totpro;
    }
}ar[205],temp[205];



int getid(string now)
{
    char cc = now[0];
    int cur = cc - 'A';
    return ++cur;
}

int main()
{
    int n,m,p,istop,lastac,mn,res;
    string str,my,ver,pro;

    scanf("%d %d %d", &n,&m,&p);

    istop = 1;
    lastac = 0;

    st get;
    int curid = 0;
    for(int i=1; i<=n; i++)
    {
        cin>> str;
        if(i == 1) my = str;
        id[str] = ++curid;
        ar[id[str]].name = str;
        ar[id[str]].time = 0;
        ar[id[str]].totpro = 0;//cout<<id[str]<<" "<<str<<endl;
        ar[id[str]].id = id[str];
    }

    for(int i=1; i<=m; i++)
    {
        cin>> str >> pro>> mn>> ver;
        vv[mn].pb(mp(str,mp(pro,ver)));
    }

    res = 0;
    ar[0].totpro = 100005;
    for(int i=1; i<300; i++)
    {
        //if(!vv[i].size()) continue;
        for(int j=0; j<vv[i].size(); j++)
        {
            str = vv[i][j].first;
            pro = vv[i][j].second.first;
            ver = vv[i][j].second.second;

            int teamid = id[str];
            int proid = getid(pro);

            if(ver == "OK")
            {
                ar[teamid].time += penalty[teamid][proid]+i;
                ar[teamid].totpro ++;
            }
            else penalty[teamid][proid] += 20;
            //cout<<"p : "<<penalty[1][proid]<<endl;
        }

        for(int k=0; k<=n; k++)
        {
            temp[k].name = ar[k].name;//if(i == 1)cout<<temp[k].name<<endl;
            temp[k].totpro = ar[k].totpro;
            temp[k].id = ar[k].id;
            temp[k].time = ar[k].time;
        }

        sort (temp,temp+n+1);

//        if(i == 300)
//        for(int k=0; k<=n; k++)
//        {
//            cout<<k<<" "<<temp[k].name<<" ... "<<temp[k].id<<endl;
//        }

        if(temp[1].name == my)
        {//cout<<i<<endl;//system("pause");
            res ++;
        }//else cout<<i<<endl;
    }
    //if(res != 300)
    pf("%d\n", res+1);
    //else pf("%d\n", res);
    return 0;
}