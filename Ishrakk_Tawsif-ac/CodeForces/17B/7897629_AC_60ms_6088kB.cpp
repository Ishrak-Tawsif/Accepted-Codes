#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 1005
#define ll long long int
#define mp make_pair
/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/


vector <int> graph[mx];
vector <pair<int,int> > qualification;
int vis[1001],q[1001],ans,cnt,cost[1001][1001];

/*int dfs(int s)
{
    vis[s]=1;
        for(int i=0; i<graph[s].size();i++){
           if(q[s]>q[graph[s][i]] && !vis[graph[s][i]])
           {
                cnt++;//cout << cost[s][graph[s][i]] << endl;
                ans += cost[s][graph[s][i]];
                dfs(graph[s][i]);
           }
        }
   return ans;
}*/

int main()
{//cout << graph[1][2].second << endl;
   int n,m,u,v,c;
   /*while(sf(n) == 1)
   {
       loop(mx) graph[i].clear();
       qualification.clear();
       memset(q,0,sizeof(q));
       memset(cost,-1,sizeof(cost));//cout<<cost[1][2]<<endl;

            loop(n)
            {
                sf(v);
                qualification.pb(mp(v,i+1));
            }
        sort(qualification.begin(),qualification.end());
        for(int i=0; i<qualification.size(); i++) q[qualification[i].second]=qualification[i].first;
        //for(int i=1; i<=n; i++) cout<< q[i]<<endl;
        sf(m);
            loop(m)
            {
                sf(u); sf(v); sf(c);
                if(cost[u][v]!=-1 && cost[u][v]>c) cost[u][v]=c;
                else if(cost[u][v]==-1){graph[u].pb(v); cost[u][v]=c;}
            }
        int max_ = qualification[n-1].first,min_=INT_MAX;
        for(int i=n-1; i>=0; i--)
        {
            if(max_ == qualification[i].first)
            {
                memset(vis,0,sizeof(vis));
                ans=cnt=0;
                //cout << qualification[i].second << "../" << endl;
                int temp = dfs(qualification[i].second);
                if(cnt == n-1) min_ = min(min_,temp);
                    if(min_ != INT_MAX)pf("%d\n",min_);
                    else pf("-1\n");
            }
        }
   }*/
       while(sf(n) == 1)
       {
           loop(mx) graph[i].clear();
           memset(q,0,sizeof(q));
           memset(cost,-1,sizeof(cost));
           memset(vis,0,sizeof(vis));

           int temp,max_=INT_MIN;
           loop(n) {sf(q[i+1]); if(q[i+1]>max_) {temp=i+1;max_=q[i+1];}}//cout<<temp<<endl;
                sf(m);
                loop(m){
                    scanf("%d %d %d", &u,&v,&c);
                    if(cost[v][u] == -1) {cost[v][u]=c; graph[v].pb(u);}
                    else if(cost[v][u]>c) cost[v][u]=c;
                }
                int min_,ans=0,tt;
                for(int i=1; i<=n; i++){
                    if(i==temp || graph[i].size()==0) continue;
                    //cout<<i<<endl;
                    min_=INT_MAX;
                    for(int j=0; j<graph[i].size(); j++) {
                        //cout<<graph[i][j]<<" "<<cost[i][graph[i][j]]<<endl;
                        if(q[graph[i][j]]>q[i]){
                            if(min_>cost[i][graph[i][j]]) {min_=cost[i][graph[i][j]];tt=i;}
                            vis[i]=1;
                        }
                    }
                    //vis[tt]=1;
                    //cout<<"......"<<endl;
                    //pf("%d\n",min_);
                    //vis[]
                    if(min_!=INT_MAX)ans+=min_;
                }
                int fl=1;
                for(int i=1; i<=n; i++) if(!vis[i] && i!=temp){fl=0; break;}
                if(fl==1)pf("%d\n",ans);
                else pf("-1\n");
       }
   return 0;
}

/*
5
6 10 7 8 5
10
3 1 5
2 4 1
2 3 2
4 5 9
3 5 0
4 1 9
4 5 2
1 5 8
2 3 7
1 5 1

answer : 8
*/