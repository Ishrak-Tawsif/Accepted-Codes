#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 2503
#define ll long long int
//#define mp make_pair
#define mod 100000007

int par[103],node,cost[53][53],in,arr[301];
double start;
map <string,int> mp;

int time_needed()
{
    double end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<cpu_time_used<<endl;
}

int find_(int p)
{
    if(par[p] == p) return p;
    return par[p]=find_(par[p]);
}

struct order_increasing
{
    int u,v,w;

        bool operator <(const order_increasing &x)const
        {
            return w<x.w;
        }
};

vector <order_increasing> best;

int mst()
{
    int cnt=0,sum=0,len=best.size();

        for(int i=0; i<len; i++)
        {
            int u=best[i].u;
            int v=best[i].v;

                int a=find_(u);
                int b=find_(v);

                    if(a!=b){
                        par[a]=b; arr[u]=arr[v]=1;
                        sum+=best[i].w;
                        cnt++;
                            if(cnt==(in-1)) break;
                    }
        }//cout<<cnt<<"..."<<sum<<endl;
    if(cnt==(in-1)) return sum;
    return -1;
}

/*int mst2()
{
    int cnt=0,sum=0,len=best.size();

    start=clock();

        for(int i=len-1; i>=0; i--)
        {
            int u=best[i].u;
            int v=best[i].v;

                int a=find_(u);
                int b=find_(v);

                    if(a!=b){
                        par[a]=b;
                        sum+=best[i].w;
                        cnt++;
                            if(cnt==node) break;
                    }
        }
    return sum;
}*/

int main()
{
    int tc,u,v,w;
        sf(tc);

            loop1(tt,tc)
            {
                sf(node);
                order_increasing get;
                best.clear();

                memset(cost,-1,sizeof(cost));
                mp.clear();

                string str,str1;
                int temp;
                in=0;

                    for(int i=0; i<node; i++)
                    {
                        cin>> str>> str1>> temp;

                        if(mp[str] == 0) mp[str]=++in;//cout<<str<<" "<<mp[str]<<endl;}
                        if(mp[str1] == 0) mp[str1]=++in;//cout<<str1<<" "<<mp[str1]<<endl;}

                            if(cost[mp[str]][mp[str1]] == -1)
                                cost[mp[str]][mp[str1]]=cost[mp[str1]][mp[str]]=temp;
                            else if(temp<cost[mp[str]][mp[str1]])
                                cost[mp[str]][mp[str1]]=cost[mp[str1]][mp[str]]=temp;
                    }


                     for(int i=1; i<=in; i++)
                    {
                        for(int j=1; j<=in; j++)
                        {
                            if(cost[i][j]!=-1)
                            {
                                get.u=i;
                                get.v=j;
                                get.w=cost[i][j];//cout<< i << " " << j << " " << cost[i][j] << endl;
                                best.push_back(get);
                                cost[i][j]=cost[j][i]=-1;
                            }
                        }
                    }

                    sort(best.begin(),best.end());
                    //cout<<in<<endl;
                    for(int i=0; i<=in; i++) par[i]=i;
                    int ans = mst();
                    /*int cnt=0;
                    for(int i=1; i<=in; i++) {if(arr[i]!=1) cout<< i << " ";else cnt++;}
                    cout<<endl<<cnt<<endl;
                    //cout<<ans<<endl;
                    for(int i=1; i<=in; i++)
                    {
                        if(par[i] == i) cout << "par : " << i << endl;
                    }*/

                        if(ans==-1) pf("Case %d: Impossible\n", tt);
                        else pf("Case %d: %d\n", tt,ans);
                            //time_needed();
            }
    return 0;
}


/*
47
Oklahoma NewYork 458
Nevada Illinois 328
Kansas Mississippi 426
Montana Mississippi 425
Tennessee Illinois 378
WestVirginia Pennsylvania 271
Michigan Maryland 146
Beijing Montana 825
Oregon Delaware 507
Changde Florida 814
NewJersey Changchun 440
Massachusetts Wyoming 559
Virginia Changsha 792
WestVirginia Arkansas 439
Connecticut Virginia 142
Vermont NewYork 500
Texas Texas 781
Indiana NewYork 599
Changsha Missouri 914
Delaware NewMexico 959
California NorthCarolina 652
NorthCarolina RhodeIsland 905
Hawaii NewJersey 717
Indiana Arkansas 576
Colorado Indiana 582
Kansas NorthCarolina 798
Oklahoma Alaska 108
Indiana Washington 765
Kentucky Alabama 349
WestVirginia Arizona 388
Nebraska Arkansas 469
Vermont Illinois 696
Maryland Texas 399
Alaska Texas 708
Iowa Ohio 345
Montana NorthDakota 39
Connecticut NorthDakota 414
Changde Utah 968
NewYork Minnesota 880
Illinois Minnesota 303
Wisconsin Texas 757
Connecticut Virginia 329
Nevada WestVirginia 635
Wisconsin RhodeIsland 115
NewHampshire Minnesota 208
Tennessee NorthCarolina 760
Massachusetts Oregon 921
*/