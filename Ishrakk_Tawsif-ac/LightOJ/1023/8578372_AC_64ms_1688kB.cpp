#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 100003
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

int n,k,cnt,vis[31],arr[31];

char alpha[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void backtrack(int nn)
{
    if(cnt == k) return;
    if(nn == n)
    {
        for(int i=0; i<nn; i++) cout<<alpha[arr[i]];
        cout<<endl;
        cnt++;
    }

    for(int i=0; i<n; i++)
    {
        if(vis[i] == 0)
        {
            vis[i]=1;
            arr[nn]=i;
            backtrack(nn+1);
            vis[i]=0;
        }
    }
}

int main()
{
    int tc;
        sf(tc);

            loop1(tt,tc)
            {
                scanf("%d %d", &n,&k);
                cnt=0;
                memset(vis,0,sizeof(vis));

                pf("Case %d:\n",tt);
                backtrack(0);
            }

    return 0;
}