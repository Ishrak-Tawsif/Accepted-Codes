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

ll ar[2005];

ll lim = (2000*1e10),dis=0;

void call(int i,int j,int chal)
{
    if(i<0 || j<0) return ;
    if(i ==0 && j == 0 && dis==0) {cout << chal << endl; dis=1; return;}

    call(i-1,j,1-chal);
    call(i,j-1,1-chal);
    call(i-1,j-1,1-chal);

}

int main()
{
    int tc,i,j;
//call(5,5,0);
    sf(tc);

    while(tc--)
    {
        scanf("%d %d", &i,&j);//dis=0;call(i,j,0);
        if(i == 0 && j == 0) pf("abdullah\n");
        else if(i == 0) if(j%2 == 0) pf("abdullah\n"); else pf("hasan\n");
        else if(j == 0) if(i%2 == 0) pf("abdullah\n"); else pf("hasan\n");
        else
        {
            if(i%2 == 0 && j%2 == 0) pf("abdullah\n");
            else pf("hasan\n");
        }
    }
    return 0;
}