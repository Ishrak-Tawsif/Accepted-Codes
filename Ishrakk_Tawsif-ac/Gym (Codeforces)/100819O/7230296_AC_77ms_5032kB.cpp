#include<bits/stdc++.h>
using namespace std;

int rr[] = {-1,0,1,0};
int cc[] = {0,-1,0,1};

int grid[501][501];
int visited[501][501];
int dis[501][501];
int m,n;

int bfs(){

    queue<int>q;
    q.push(0);
    q.push(0);
    visited[0][0]=1;
    dis[0][0]=0;

        while(!q.empty()){
            int r = q.front();q.pop();
            int c = q.front();q.pop();

                for(int i=0; i<4; i++){
                    int t_r = r + (grid[r][c] * rr[i]);
                    int t_c = c + (grid[r][c] * cc[i]);

                    //cout  << t_r << " " << t_c <<endl;

                        if(t_r>=0 && t_r<=m-1 && t_c>=0 && t_c<=n-1){
                            if(visited[t_r][t_c] == 0){
                                dis[t_r][t_c] = dis[r][c]+1;
                                visited[t_r][t_c] = 1;
                                q.push(t_r);
                                q.push(t_c);
                            }
                        }
                }
        }
   return dis[m-1][n-1];
}

int main(){

    //int n,m;
    string s;

        //while(cin>> m>> n){

            //int grid[m+1][n+1];
                cin >>m >>n;
                for(int i=0; i<m; i++){
                    cin>> s;

                        for(int j=0; j<n; j++) grid[i][j]=s[j]-48;
                }

                int ans = bfs();
                if(ans!=0)cout << ans << endl;
                else cout << "IMPOSSIBLE" << endl;
        //}
return 0;
}