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
#define mx                      5005
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

int dirR[] = {0,0,-1,1,-1,-1,1,1};
int dirC[] = {-1,1,0,0,-1,1,-1,1};

string move_[]={"D","U","L","R","LD","LU","RD","RU"};
pair<int,int>source[11][11];
int vis[11][11],path[11][11],diss[11][11];
//string path[11];

int convert(string s)
{
        int n=(int)s[0];
        n-=96;
    return n;
}

void path_print(int srr,int scc,int dr,int dc)
{
    int sr=source[dr][dc].first;
    int sc=source[dr][dc].second;
//cout<<sr<<" "<<sc<<endl;system("pause");
        if(sr==srr && sc==scc) return;
        path_print(srr,scc,sr,sc);
        cout<<move_[path[sr][sc]]<<endl;

        /*cout<<dr<<" ... "<<dc<<endl;

        while(dr!=-1)
        {
            cout<<source[dr][dc].first << " " << source[dr][dc].second<<endl;
            dr=source[dr][dc].first;
            dc=source[dr][dc].second;
        }*/
}

void bfs(int sr,int sc,int dr,int dc)
{//cout<<sr<<" "<<sc<<" " <<dr<<" " << dc << endl;
    for(int i=0; i<11; i++)for(int j=0; j<11; j++) diss[i][j]=intinf;
    vis[sr][sc]=1;
    queue<pair<int,int> >q;
    q.push(mp(sr,sc));
    source[sr][sc]=mp(-1,-1);
    diss[sr][sc]=0;

        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

                if(r==dr && c==dc){
                        cout<<diss[dr][dc]<<endl;
                        if(diss[dr][dc]==0) return;
                        path_print(sr,sc,dr,dc);
                        cout<<move_[path[dr][dc]]<<endl;
                        return;
                    }

                for(int i=0; i<8; i++)
                {
                    int tr=r+dirR[i];
                    int tc=c+dirC[i];
//if(i==6) cout<<r << " " << c << " " << tr << " " << tc << " " << dirR[i]<<" " << dirC[i]<< endl;
                        if(tr>=1 && tr<=8 && tc>=1 && tc<=8)
                        {
                            if(!vis[tr][tc]/*diss[r][c]+1<diss[tr][tc]*/)
                            {
                                vis[tr][tc] = 1;
                                source[tr][tc]=mp(r,c);
                                path[tr][tc] = i;
                                diss[tr][tc]=diss[r][c]+1;
                                q.push(mp(tr,tc));
                            }
                        }
                }
        }
}


int main()
{
    string s,s2;
//int i=2,j=2;for(int ii=0; ii<8; ii++) cout<<i+dirR[ii]<<" "<<j+dirC[ii]<<endl;
        cin>> s>> s2;

        int r1=convert(s);
        int r2=convert(s2);
        int c1=(int)s[1]-'0';
        int c2=(int)s2[1]-'0';

            bfs(r1,c1,r2,c2);
    return 0;
}