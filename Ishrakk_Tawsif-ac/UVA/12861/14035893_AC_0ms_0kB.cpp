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
#define mx                      303
#define mod                     10056
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

int ar[1005],vis[1003];

int main()
{//WRITE("in.txt");
    int n;

    while(~sf(n))
    {
        //multiset <pair<int, pair<int,int> > > st;

        for(int i=0; i<n; i++) sf(ar[i]);

        sort(ar,ar + n);

        int res = 0;
        for(int i=0; i<n; i+=2)
        {
                int j = i + 1;//cout<<i<<" "<<j<<endl;
                int a = ar[i],b = ar[j];
                if(a<b) swap(a,b);

                int d1 = (a - b);
                int d2 = 24 - d1;
                int diff = min(d1,d2);
                //st.insert({diff,{i,j}});if(i%2 == 0 && j == i+1) cout<<i<<" "<<j<<" "<<diff<<endl;
                res += diff;
        }

        int res2 = 24 - (ar[n-1] - ar[0]);
        for(int i=1; i<n-1; i+=2)
        {
                int j = i + 1;
                int a = ar[i],b = ar[j];
                if(a<b) swap(a,b);

                int d1 = (a - b);
                int d2 = 24 - d1;
                int diff = min(d1,d2);
                //st.insert({diff,{i,j}});if(i%2 == 0 && j == i+1) cout<<i<<" "<<j<<" "<<diff<<endl;
                res2 += diff;
        }

//        mem(vis,0);
//        int res = 0;
//        while(!st.empty())
//        {
//            auto now = * st.begin();
//            st.erase(st.begin());
//
//            int u = now.second.first;
//            int v = now.second.second;
//
//            if(!vis[u] && !vis[v])
//            {cout<<u<<" "<<v<<" "<<now.first<<endl;
//                res += now.first;
//                vis[u] = vis[v] = 1;
//            }
//        }

        pf("%d\n", min(res,res2));

    }

    return 0;
}