#include<bits/stdc++.h>
using namespace std;

vector <int> vv[263];
int arr[263];
string nn;
int n,u,v,vis[263],ans[263],fl;


void backtrack(int ind,int pre){

    if(fl) return;
    if(ind == n && arr[ans[n-1]]==1){

            fl=1;
            //if(fl==1){
                for(int i=0; i<n; i++) printf("%d ", ans[i]);
                printf("%d\n", ans[0]);
            //}
       return;
    }

        for(int j=0; j<vv[pre].size(); j++){
            if(vis[vv[pre][j]] == 0){
                vis[vv[pre][j]]=1;
                ans[ind]=vv[pre][j]; //cout<< pre << " " << ans[ind] <<endl;
                backtrack(ind+1,vv[pre][j]);
                vis[vv[pre][j]]=0;//cout<< "................" <<endl;
            }
        }
}

int main(){



        while(scanf("%d", &n) == 1){
        for(int i=0; i<=n; i++) {vv[i].clear(); arr[i]=0;vis[i]=0;}
                while(1){
                    cin>> nn;
                        if(nn[0]=='%') break;
                            int ii=1;
                            u=0;
                            for(int j=nn.length()-1; j>=0; j--) { u+= (nn[j]-'0')*ii; ii*=10;}
                            scanf("%d", &v);
                            vv[u].push_back(v);
                            vv[v].push_back(u);
                            if(u==1) arr[v]=1;
                            if(v==1) arr[u]=1;
                }

                //for(int i=1; i<=n; i++){for(int j=0; j<vv[i].size(); j++){cout<<vv[i][j]<<" ";}cout<<"\n";}
                fl=0;
                ans[0]=1;
                vis[1]=1;
                backtrack(1,1);

                if(fl==0) printf("N\n");
        }
return 0;
}