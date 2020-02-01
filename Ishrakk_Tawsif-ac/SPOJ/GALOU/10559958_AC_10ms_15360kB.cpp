#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
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

int r,c,vis[103][103],curi,block,situ[103][103];
string str[103];
//vector <pair<int,int> > bl,anticl;

void dfs(int row,int col)
{
    vis[row][col] = 1;

    for(int i=0; i<6; i++)
    {
        int rr = dirr[i] + row;
        int cc = dirc[i] + col;

        if(rr>=0 && rr<r && cc>=0 && cc<c){
            if(!vis[rr][cc] && str[rr][cc] != '.')
            {

                if(situ[row][col] == 1 && str[rr][cc] != 'I') situ[rr][cc] = 2;
                else if(situ[row][col] == 2 && str[rr][cc] != 'I') situ[rr][cc] = 1;
                if(str[rr][cc] == 'I')
                {
                    if(situ[row][col] == 1){block=1;return;}
                }
                dfs(rr,cc);
            }
            else if(vis[rr][cc] && str[rr][cc] != '.'){if(situ[row][col] == situ[rr][cc]){block = 1;return;}}
        }
    }
}

void dfs2(int row,int col,int isblock)
{
    situ[row][col] = 3;
    for(int i=0; i<6; i++)
    {
        int tr = dirr[i] + row;
        int tc = dirc[i] + col;

        if(tr>=0 && tr<r && tc>=0 && tc<c){
            if(str[tr][tc] != '.'){
                
                if(situ[tr][tc]!=3)dfs2(tr,tc,isblock);
            }
        }
    }
}

int main()
{
    queue<int> ii;
    while(scanf("%d %d", &r,&c) == 2 && r && c)
    {
            ii.empty();
            mem(vis,0);
            mem(situ,0);
            for(int i=0; i<r; i++)
            {
                cin>> str[i];
                for(int j=0; j<c; j++)
                {
                    if(str[i][j] == 'I') {ii.push(i),ii.push(j); situ[i][j] = 1;}
                }
            }

        while(!ii.empty())
        {
            int R = ii.front(); ii.pop();
            int C = ii.front(); ii.pop();
            
            block = 0;
            if(situ[R][C] == 1)dfs(R,C);
            if(block) {situ[R][C] = 3;dfs2(R,C,block);}
        }
        pf("\n");
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(str[i][j] == '*' || str[i][j] == 'I')
                {
                    if(situ[i][j] == 1)pf("(");
                    else if(situ[i][j] == 2) pf(")");
                    else if(situ[i][j] == 3) pf("B");
                    else pf("F");
                }
                else pf("%c", str[i][j]);
            }
            pf("\n");
        }
    }
    
    return 0;
}


/*
3 3
.*.
.*.
.I.

3 3
.*.
I*I
III

*/