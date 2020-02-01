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

string str,str2;

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int tc;

    //sf(tc);
    int r,c;

    //loop(tt,0,tc)
    //{
        scanf("%d %d", &r,&c);
        int ar[r+3][c+3],vis[105];

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++) sf(ar[i][j]);
        }

        mem(vis,0);

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(ar[i][j] != -1)
                {
                    int cur = ar[i][j];

                    for(int k=0; k<8; k++)
                    {
                        int tr = i+dx[k];
                        int tc = j+dy[k];

                        if(tr>=0 && tr<r && tc>=0 && tc<c)
                        {
                            if(ar[tr][tc] == cur) vis[cur] = 1;
                        }
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0; i<=100; i++) if(vis[i]) cnt++;
        pf("%d\n", cnt);
    //}

    return 0;
}