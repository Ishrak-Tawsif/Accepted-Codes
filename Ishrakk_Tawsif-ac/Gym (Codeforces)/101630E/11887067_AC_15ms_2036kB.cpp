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
#define casepf(nn)              printf ("Case %d:\n",nn)
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
#define mx                      5000005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

int ar[1005];
//vector <int> ansuni;
/*vector <pair<int,int> > negi;
queue <int> uni;*/
map<int,int> mpp;

int main()
{
    int n,temp,fl=1,uni=0;
    queue <int> ansuni;

    sf(n);

    for(int i=0; i<n; i++)
    {
        sf(temp);
        ar[i] = temp;
        if(temp == 0) uni++;
        else if(temp<0)
        {
            int cur = temp * -1;
            if(mpp[cur]) mpp[cur]--;
            else if(uni) uni--,ansuni.push(cur);
            else fl = 0;
        }
        else
        {
            mpp[temp]++;
        }
    }
    if(fl)
    {
        pf("Yes\n");
        int hoise = 0;
        while(!ansuni.empty())
        {
            pf("%d", ansuni.front());
            ansuni.pop();
            if(ansuni.size()) pf(" ");
        }
        for(int i=1; i<=uni; i++)
        {
            if(fl) pf(" ");
            fl = 1;
            pf("1000");
        }
        pf("\n");
    }
    else pf("No\n");
    return 0;
}