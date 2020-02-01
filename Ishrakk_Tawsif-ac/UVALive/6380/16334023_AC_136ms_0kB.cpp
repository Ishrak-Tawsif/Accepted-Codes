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
#define casepf(nn)              printf ("Case %d:\n",nn)
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
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int n,k,rw[53],col[53],ran[53],mark[53][53],res;

int calcdis(int r1,int c1,int r2,int c2)
{
    int dis = abs(r1-r2) + abs(c1-c2);

    return dis;
}

void dfs(int pos,int pr,int pc,int curr,int curc)
{//out(".");
    mark[curr][curc] = pos+1;

    for(int i=0; i<8; i++)
    {
        int tr = curr + dx[i];
        int tc = curc + dy[i];

        if(tr>=1 && tr<=n && tc>=1 && tc<=n)
        {
            int dis = calcdis(pr,pc,tr,tc);
            if(dis <= ran[pos])
            {
                if(mark[tr][tc] != (pos+1))dfs(pos,pr,pc,tr,tc);
            }
        }
    }
}

void call(int pos,int mask)
{//out(mask);
    if(pos == k)
    {
        mem(mark,0);
        int cnt = 0;

        for(int i=0; i<k; i++)
        {
            mark[rw[i]][col[i]] = 55;//cout<<mark[1][1]<<" ... "<<rw[k]<<" "<<col[k]<<"///\n";
        }

        for(int i=0; i<k; i++)
        {
            if((mask & (1<<i)))
            {
                dfs(i,rw[i],col[i],rw[i],col[i]);
                cnt ++;
            }
        }

        int fl = 1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(!mark[i][j])
                {//cout<<i<<" "<<j<<" "<<cnt<<endl;
                    fl = 0;
                    break;
                }
            }
        }//cout<<cnt<<" "<<fl<<" "<<mark[1][1]<<endl;
        if(fl) res = min(res,cnt);
        return;
    }

    if(!(mask & (1<<pos)))
    {
        call(pos+1,mask | (1<<pos));
        call(pos+1,mask);
    }
}

int main()
{
    while(sf(n) == 1 && n)
    {
        scanf("%d", &k);

//        if(k == 0)
//        {
//            printf("0\n");
//            continue;
//        }

        for(int i=0; i<k; i++) scanf("%d %d", &rw[i],&col[i]);
        for(int i=0; i<k; i++) scanf("%d", &ran[i]);

        res = 2e9;
        call(0,0);
        res == 2e9? printf("-1\n") : printf("%d\n", res);
    }

    return 0;
}