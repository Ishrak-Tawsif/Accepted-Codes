#include<bits/stdc++.h>
using namespace std;

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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

int dx4[] = {-1,0,0,1};
int dy4[] = {0,-1,1,0};

int cnt[101],req[101];

ll mat[27][27];
string str;

void fw()
{
    loop(h,0,26) loop(i,0,26) loop(j,0,26) loop(k,0,26) mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
}

int main()
{
    loop(i,0,26) loop(j,0,26) sfll(mat[i][j]);
    fw();

    cin>> str;
    int i = 0, j =  str.length()-1;
    ll ans=0;
    //loop(i,0,26) {loop(j,0,26) pf(" %d",mat[i][j]);pf("\n");}
    while(i<j)
    {
        ll temp = 1e18;
        for(int k=0; k<26; k++)
        {
            int curi = (int) str[i]-'a';
            int curj = (int) str[j]-'a';

            ll ans1 = mat[curi][k];
            ll ans2 = mat[curj][k];

            if(curi == k) ans1 = 0;
            if(curj == k) ans2 = 0;

            temp = min(temp,ans1+ans2);//cout<<temp<<endl;
        }
        ans += temp;
        i++;
        j--;
    }

    pf("%lld\n", ans);

    return 0;
}