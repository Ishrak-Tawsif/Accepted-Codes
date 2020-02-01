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
#define inf                     1e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int rr,cc,mark[5005][5005],dp[5005][5005];

int call(int i,int j)
{
    if(i>=rr || j>=cc) return 0;
    if(mark[i][j] == 1) return 0;
    if(i == rr-1 && j == cc-1) {/*out("ok");*/return 1;}
    if(dp[i][j] != -1) return dp[i][j];

    int ans1=0,ans2=0,ans3=0;

        ans1 = call(i,j+1);
        ans2 = call(i+1,j);

    return dp[i][j] = ans1 + ans2 + ans3;
}

int main()
{
    stringstream ss;
    string str;
    int tc,temp,curr,fl=0;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d %d", &rr,&cc);

            mem(mark,0);
            cin.ignore();

            for(int i=0; i<rr; i++)
            {//out(i);
                getline(cin,str);
                ss.clear();
                ss.str(str);
                fl = 0;

                while(ss>> temp)
                {
                    if(fl) mark[curr-1][temp-1] = 1;
                    else fl=1,curr = temp;
                }
            }

            mem(dp,-1);
            cout<<call(0,0)<<endl;

            if(tt!=tc)pf("\n");
    }
    return 0;
}