#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:\n",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

int dx4[] = {-1,0,0,1};
int dy4[] = {0,-1,1,0};

//char com,colr,ar[253][253];
//int row,col,x,y;
//string name;

ll ar[105][105],temp[105];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    //cout<<calc(150)<<".."<<endl; system("pause");

    int c,v,tc;

    sf(tc);

    loop(tt,0,tc)
    {
        scanf("%d %d", &c,&v);
        int cnt[c+3],pre[v+3][c+3];
        mem(cnt,0);

        for(int i=1; i<=v; i++)
        {
            for(int j=0; j<c; j++) sf(pre[i][j]);
        }

        int ans = -1,fiftyper = ((v/2));//cout<<fiftyper<<endl;
        int max1=-intinf,max2=-intinf,c1,c2;
        //vector <int> vv;
        for(int i=1; i<=v; i++)
        {
            cnt[pre[i][0]] ++;
            if(cnt[pre[i][0]] > fiftyper)ans = pre[i][0];
//cout<<pre[i][0]<<" " << cnt[pre[i][0]]<<endl;
            if(cnt[pre[i][0]]>max1)
            {
                max1 = cnt[pre[i][0]];
                c1 = pre[i][0];
                //max2 = max1;
                //c2 = c1;
            }
            //else if(cnt[pre[i][0]]>max2)
            //{
            //    max2 = cnt[pre[i][0]];
            //    c2 = pre[i][0];
            //}
        }

        if(ans != -1)pf("%d 1\n", ans);

        else
        {

            for(int i=1; i<=c; i++)
            {
                if(cnt[i]>max2 && i != c1)max2 = cnt[i],c2=i;
            }
            mem(cnt,0);
            max1 = -intinf;
            for(int i=1; i<=v; i++)
            {
                for(int j=0; j<c; j++)
                {
                    if(pre[i][j]==c1 || pre[i][j] == c2)
                    {//cout<<pre[i][j]<<endl;
                        cnt[pre[i][j]]++;
                        if(max1<cnt[pre[i][j]])
                        {
                            max1 = cnt[pre[i][j]];
                            ans = pre[i][j];
                        }
                        break;
                    }
                }
            }
            pf("%d 2\n", ans);
        }
    }

    return 0;
}