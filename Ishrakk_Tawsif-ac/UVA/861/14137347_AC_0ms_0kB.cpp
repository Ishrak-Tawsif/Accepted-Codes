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
#define mod                     1000000007
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

//int n,k,previs[9][9];
//unordered_map <int,unordered_map<int,int> > vis,id;
//vector <pair<int,int> > vv[67];
//ll res[65][65],cnt[67],maxi;
//
//int digr[] = {-1,1,-1,1};
//int digc[] = {-1,1,1,-1};
//
//void call(int cur,set<int>st,int nowid,vector <int> ans)
//{
//    if(cur == k)
//    {
//        cnt[cur]++;
//        return;
//    }
//
//    cnt[cur] ++;
//
//    if(!st.size()) return;
//
//    for(int x : st)
//    {
//        if(x>maxi) break;
//        if(x<=nowid) continue;;
//
//        int r = vv[x][0].first;
//        int c = vv[x][0].second;
//
//        set <int> temp = st;
//
//        vector <int> tempans = ans;
//
//        queue <int> q;
//
//        mem(previs,0);
//        previs[r][c] = 1;
//
//        for(int i=0; i<4; i++)
//        {
//            int tr = r + digr[i];
//            int tc = c + digc[i];
//
//                if(tr>=1 && tr<=n && tc>=1 && tc<=n)
//                {
//                    previs[tr][tc] = 1;
//                    int curid = id[tr][tc];
//                    temp.erase(curid);
//                    q.push(tr);
//                    q.push(tc);
//                    q.push(i);
//                }
//        }
//
//        while(!q.empty())
//        {
//            r = q.front(); q.pop();
//            c = q.front(); q.pop();
//            int tp = q.front(); q.pop();
//
//                int tr = r + digr[tp];
//                int tc = c + digc[tp];
//
//                if(tr>=1 && tr<=n && tc>=1 && tc<=n)
//                {
//                    if (previs[tr][tc]) continue;
//                    previs[tr][tc] = 1;
//                    int curid = id[tr][tc];
//                    temp.erase(curid);
//                    q.push(tr);
//                    q.push(tc);
//                    q.push(tp);
//                }
//        }
//        temp.erase(x);
//        tempans.pb(x);
//        call(cur+1,temp,x,tempans);
//    }
//}


ll res[] =
{///generated from backtrack
    1, 1, 1, 4, 4, 0, 0, 1, 9, 26, 26, 8, 0, 0, 0, 0, 0, 1, 16, 92, 232, 260, 112, 16, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 25, 240, 1124, 2728, 3368, 1960, 440, 32, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 36, 520, 3896, 16428, 39680, 53744, 38368, 12944,
    1600, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    49, 994, 10894, 70792, 282248, 692320, 1022320, 867328, 389312, 81184, 5792, 128, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 64, 1736, 26192, 242856, 1444928, 5599888, 14082528, 22522960, 22057472, 12448832,
    3672448, 489536, 20224, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int id[9][65];

int main()
{
    //READ("in.txt");
    //WRITE("in.txt");
//    int totr = 8,totc = 64;
//
//    for(int i=1; i<=totr; i++)
//    {
//        res[i][0] = 1;
//        int curid = 0;
//        set <int> st;
//        for(int i=0; i<64; i++) vv[i].clear();
//        id.clear();
//        for(int ii=1; ii<=i; ii++)for(int j=1; j<=i; j++) id[ii][j] = ++curid,st.insert(curid),vv[curid].pb({ii,j});
//
//            maxi = i * i;
//            n = i;
//            k = i*i;
//            vector <int> ans;
//
//            call(0,st,0,ans);
//
//            for(int j=0; j<=k; j++) if(!j) pf("1\n"); else pf("%lld\n",cnt[j]);
//            mem(cnt,0);
//    }


    int curid = -1;

    for(int i=1; i<=8; i++)
    {
        for(int j=0; j<= i * i; j++) id[i][j] = ++curid;
    }

    int n,k;

    while(scanf("%d %d", &n,&k))
    {
        if(!n && !k) break;
        int nowid = id[n][k];//out(nowid);

        pf("%lld\n",res[nowid]);
    }

    return 0;
}