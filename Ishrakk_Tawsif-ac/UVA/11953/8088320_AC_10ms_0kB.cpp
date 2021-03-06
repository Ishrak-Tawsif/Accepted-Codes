#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int dir_r[]={0,-1,1,0};
int dir_c[]={-1,0,0,1};
int n,vis[101][101];

string grid[101];
/*
int dfs(int i,int j)
{
    vis[i][j]=1;//cout<< i <<" "<< j <<endl;
    //system("pause");
        for(int k=0; k<4; k++)
        {
            int temp_r=i+dir_r[k];
            int temp_c=j+dir_c[k];
                if(temp_r>=0 && temp_r<n && temp_c>=0 && temp_c<n && !vis[temp_r][temp_c] && grid[temp_r][temp_c]!='.')
                    dfs(temp_r,temp_c);
        }
}
*/
void bfs(int i, int j)
{
    queue <int> q;
    q.push(i);
    q.push(j);
    vis[i][j]=1;

        while(!q.empty())
        {
            int rr=q.front(); q.pop();
            int cc=q.front(); q.pop();//cout<<rr<<" "<<cc<<endl;

            for(int k=0; k<4; k++)
            {
                int t_r=rr+dir_r[k];
                int t_c=cc+dir_c[k];
                if(t_r>=0 && t_r<n && t_c>=0 && t_c<n){
                        if(!vis[t_r][t_c] && grid[t_r][t_c]!='.'){
                            vis[t_r][t_c]=1;
                            q.push(t_r);
                            q.push(t_c);
                        }

                    }
            }
        }
}

int main()
{
    int tc;
        scanf("%d", &tc);
            for(int tt=1; tt<=tc; tt++)
            {
                scanf("%d", &n);
                    for(int i=0; i<n; i++)
                        cin>> grid[i];

                memset(vis,0,sizeof(vis));
                int ans=0;
                for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++)
                        {
                            if(vis[i][j]==0 && grid[i][j]=='x') {
                                    ans++;
                                    //dfs(i,j);
                                    bfs(i,j);
                            }
                        }

                printf("Case %d: %d\n",tt,ans);
            }
    return 0;
}

/*
2
4
x...
..x.
@.@.
....
2
..
x.
*/