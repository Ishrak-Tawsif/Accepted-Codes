#include<bits/stdc++.h>
using namespace std;

//vector <int> v[21];

int bfs(int s, int d,vector <int> v[21]){
    int visited[21],dis[21];
        for(int i=0; i<21; i++){visited[i]=0; dis[i]=INT_MAX;}

        queue<int>q;
        q.push(s);
        visited[s]=1;
        dis[s]=0;

            while(!q.empty()){
                int u = q.front(); q.pop();

                    if(u == d) return dis[u];

                    for(int i=0; i<v[u].size(); i++){
                        int vv = v[u][i];

                            if(visited[vv] == 0 && dis[vv]>(dis[u]+1)){
                                visited[vv]=1;
                                dis[vv]=dis[u]+1;
                                q.push(vv);
                            }
                    }
            }
}

int main(){
//printf("%2d %d",12,12);
    int u,vv,len,testcase=0,temp;

        while(cin>> temp){
            vector <int> v[21];
            len=temp;

            for(int i=1; i<=19; i++){
                if(i==1) len=temp; else cin>> len;
                for(int j=0; j<len; j++){
                    cin>> u;
                    v[i].push_back(u);
                    v[u].push_back(i);
                }
            }

            cout << "Test Set #" << ++testcase << endl;
            cin>> len;
                while(len--){
                    cin>> u>> vv;
                    //cout << u << " to " << vv << ": " << bfs(u,vv,v) << endl;
                    printf("%2d to %2d: %d\n", u, vv, bfs(u,vv,v));
                }
                cout << endl;
        }
return 0;
}