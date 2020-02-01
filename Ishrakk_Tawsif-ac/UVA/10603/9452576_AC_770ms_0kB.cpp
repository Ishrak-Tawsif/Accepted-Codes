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

int dp[203][203][203],total[203],A,B,C,D;

queue <pair<int,pair<int,int> > > q;
queue <int> qtot;

int bfs(int a,int b,int c,int tot)
{
    q.push(mp(a,mp(b,c)));
    qtot.push(tot);

        while(!q.empty())
        {
            a = q.front().first;
            b = q.front().second.first;
            c = q.front().second.second;
            q.pop();
            tot = qtot.front();
            qtot.pop();

                if(tot<dp[a][b][c] && tot<total[D])
                {
                    dp[a][b][c] = tot;
                    total[a] = min(total[a],tot);
                    total[b] = min(total[b],tot);
                    total[c] = min(total[c],tot);//cout<<tot<<"..."<<endl;

                        int cura = A-a,curb = B-b,curc = C-c;

                            if(cura>b) /// A te khali jayga B te je pani ache tar soman ba boro
                            {
                                q.push(mp(a+b,mp(0,c))); ///B er purota pani a te niye nibo
                                qtot.push(tot+b);
                            }
                            else
                            {
                                q.push(mp(A,mp(b-cura,c))); ///B er jototuku a te niye nea jay
                                qtot.push(tot+(cura));
                            }

                            if(cura>c)
                            {
                                q.push(mp(a+c,mp(b,0)));
                                qtot.push(tot+c);
                            }
                            else
                            {
                                q.push(mp(A,mp(b,c-cura)));
                                qtot.push(tot+(cura));
                            }

                            if(curb>a)
                            {
                                q.push(mp(0,mp(b+a,c)));
                                qtot.push(tot+a);
                            }
                            else
                            {
                                q.push(mp(a-curb,mp(B,c)));
                                qtot.push(tot+(curb));
                            }

                            if(curb>c)
                            {
                                q.push(mp(a,mp(b+c,0)));
                                qtot.push(tot+c);
                            }
                            else
                            {
                                q.push(mp(a,mp(B,c-curb)));
                                qtot.push(tot+(curb));
                            }

                            if(curc>a)
                            {
                                q.push(mp(0,mp(b,c+a)));
                                qtot.push(tot+a);
                            }
                            else
                            {
                                q.push(mp(a-curc,mp(b,C)));
                                qtot.push(tot+(curc));
                            }

                            if(curc>b)
                            {
                                q.push(mp(a,mp(0,c+b)));
                                qtot.push(tot+b);
                            }
                            else
                            {
                                q.push(mp(a,mp(b-curc,C)));
                                qtot.push(tot+(curc));
                            }
                }
        }
}

int main()
{//WRITE("in.txt");
    int tc;

        sf(tc);

            loop(tt,1,tc+1)
            {
                scanf("%d %d %d %d",&A,&B,&C,&D);

                    for(int i=0; i<=A; i++)
                        for(int j=0; j<=B; j++)
                            for(int k=0; k<=C; k++) dp[i][j][k] = intinf;

                    for(int i=0; i<=D; i++) total[i] = intinf;

                    bfs(0,0,C,0);

                    while(total[D] == intinf) D--;
                    pf("%d %d\n", total[D],D);

            }
    return 0;
}