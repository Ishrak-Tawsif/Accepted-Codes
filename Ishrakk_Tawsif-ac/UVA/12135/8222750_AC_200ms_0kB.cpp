#include <bits/stdc++.h>
using namespace std;

vector <int> tog[43];
int lim,n,m,vis[1<<16],dis[1<<16],mask_dis;

int bfs()
{
    queue<int>q;
    q.push(0);
    vis[0]=1;
    dis[0]=0;

        while(!q.empty())
        {//cout<<"bfs"<<endl;
            int mask=q.front(); q.pop();
            int mask_dis=mask;


                for(int i=0; i<m; i++){
                    mask=mask_dis;
                    for(int j=0; j<tog[i].size();j++)
                    {
                        int v=tog[i][j];
                            if(!(mask & (1<<v)))
                                (mask |= (1<<v)); ///if light at position v is 0 make it 1
                            else
                                (mask ^=(1<<v)); ///if light at position v is 1 make 0
                    }
                    if(!vis[mask])
                    {
                        dis[mask]=dis[mask_dis]+1;
                        vis[mask]=1;//cout<<mask<<" "<<dis[mask]<<" "<<u<<" "<<i<<endl;
                        q.push(mask);
                    }
            }
        }
}

int ipow(int base,int pow)
{
    int ans=1;

        while(pow--) ans*=base;

    return ans;
}

int main()
{
    int q,tc;

        scanf("%d",&tc);
            for(int tt=1; tt<=tc; tt++)
            {
                scanf("%d %d", &n,&m);

                for(int i=0; i<43; i++) tog[i].clear();
                memset(vis,0,sizeof(vis));
                memset(dis,0,sizeof(dis));

                    for(int i=0; i<m; i++)
                    {
                        int temp,tm;
                        scanf("%d",&temp);
                            while(temp--){
                                scanf("%d",&tm);
                                tog[i].push_back(tm);
                            }
                    }

                    bfs();

                    printf("Case %d:\n", tt);

                    /*cout<<dis[5]<<"..."<<endl;
                    cout<<dis[2]<<"..."<<endl;
                    cout<<dis[7]<<"..."<<endl;*/

                    string str;
                    scanf("%d",&q);
                    //cin.ignore();

                        while(q--)
                        {
                           cin>> str;

                           int len=str.length(),num=0;

                            for(int i=len-1,j=0; i>=0; i--,j++)
                            {
                                int temp=str[i]-'0';
                                num += (ipow(2,j))*temp;
                            }

                            if(vis[num]==0)cout<<"-1"<<endl;
                            else cout<<dis[num]<<endl;
                        }

                        cout<<endl;
            }
    return 0;
}