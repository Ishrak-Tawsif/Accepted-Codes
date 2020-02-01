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

//int n,ar[200005],ar2[200005],dp[10005][3];

//int nod,vis[1003],cnt;
//vector <int> graph[1003];

unordered_map <int,unordered_map<int,int> >mpp;
int row,col,islost,ansR,ansC;
char ansPos;
string str;

char turnRight(char pos)
{
    if(pos == 'N') return 'E';
    if(pos == 'E') return 'S';
    if(pos == 'S') return 'W';
    return 'N';
}

char turnLeft(char pos)
{
    if(pos == 'N') return 'W';
    if(pos == 'W') return 'S';
    if(pos == 'S') return 'E';
    return 'N';
}

pair<int,int> Forward(int r,int c,char pos)
{
    if(pos == 'N') return mp(r,c+1);
    if(pos == 'S') return mp(r,c-1);
    if(pos == 'W') return mp(r-1,c);
    return mp(r+1,c);
}

void dfs(int sr,int sc,char pos,int i)
{
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == 'R')
            pos = turnRight(pos);
        else if(str[i] == 'L')
            pos = turnLeft(pos);
        else
        {
            pair<int,int> temp = Forward(sr,sc,pos);
            int tr = temp.first;
            int tc = temp.second;

            if(tr == -1 || tr == row+1 || tc == -1 || tc == col+1)
            {
                if(!mpp[sr][sc])
                {
                    mpp[sr][sc] = 1;
                    islost  = 1;
                    break;
                }
            }
            else
            {
                sr = tr;
                sc = tc;
            }
        }

    }
    (islost==0)?pf("%d %d %c\n", sr,sc,pos) : pf("%d %d %c LOST\n", sr,sc,pos);

}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    scanf("%d %d", &row,&col);

    int sr,sc;
    char pos;
	while(~scanf("%d %d %c", &sr,&sc,&pos))
    {

        //scanf("%d %d %c", &sr,&sc,&pos);

        cin>> str;

        islost = 0;
        dfs(sr,sc,pos,0);
    }
	return 0;
}