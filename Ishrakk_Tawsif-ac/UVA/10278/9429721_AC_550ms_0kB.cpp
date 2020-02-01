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
#define intinf                  1e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

int dir_r_4[] = {0, 0, 1, -1};
int dir_c_4[] = {1, -1, 0, 0};

int cost[501][501],fire[501];

int main()
{//WRITE("in.txt");
    int tc,f,inter,ff[501],temp;

        sf(tc);
            loop(tt,1,tc+1)
            {
                scanf("%d %d", &f,&inter);

                    for(int i=0; i<501; i++)
                    {
                        ff[i] = 0;
                        fire[i]=0;
                        for(int j=0; j<501; j++)
                        {
                            if(i == j? cost[i][j]=0 : cost[i][j] = intinf);
                        }
                    }

                    loop(i,0,f)
                    {
                        sf(temp);
                        ff[temp] = 1;
                        fire[i+1] = temp;
                    }

                    string s;
                    //stringstream ss;

                    cin.ignore();

                    while(getline(cin,s))
                    {
                        if(s.empty()) break;
                        //ss.clear();
                        stringstream ss(s);

                        int u,v,cst;

                            ss>>u >>v>> cst;
                            cost[u][v] = min(cost[u][v],cst);
                            cost[v][u] = cost[u][v];
                            //cout<<cost[u][v]<<" " <<cost[v][u]<<endl;
                    }

                    ///floyd warshall

                    for(int i=1; i<=inter; i++)
                        for(int j=1; j<=inter; j++)
                            for(int k=1; k<=inter; k++)
                                   cost[j][k] = min(cost[j][k],cost[j][i]+cost[i][k]);

                    int closeststation[501];
                    for(int i=1; i<=inter; i++)
                    {
                        closeststation[i]=0;
                        if(!ff[i])
                        {
                            int min_ = intinf;
                            for(int j=1; j<=f; j++)
                            {
                                min_ = min(min_,cost[i][fire[j]]);
                            }
                            closeststation[i] = min_;
                        }

                    }


                    int min_ = intinf,ans=1;
                    for(int i=1; i<=inter; i++)
                    {
                        if(!ff[i])
                        {
                            int max_ = -1,cnt=0;

                                for(int j=1; j<=inter; j++)
                                {
                                    //if(i == 5) cout<<cost[j][i]<<" "<<closeststation[j]<<endl;
                                    max_ = max(max_,min(cost[j][i],closeststation[j]));
                                }
                                //cout<<max_<<endl;
                            if(min_>max_)
                            {
                                min_=max_;
                                ans = i;
                            }
                        }
                    }
                if(tt==tc? pf("%d\n", ans) : pf("%d\n\n", ans));
            }
    return 0;
}