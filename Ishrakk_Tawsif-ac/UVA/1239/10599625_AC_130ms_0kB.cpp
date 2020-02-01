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

//int n,ar[200005],ar2[200005],dp[10005][3];

int dp[1005][1005],k;
string str;

int call(int i,int j)
{
    if(i>=j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(str[i] == str[j]) return dp[i][j] = call(i+1,j-1);

    int ans1=0,ans2=0;

    ans1 = call(i+1,j-1) + 1;
    //ans2 = call(i+1,j) + 1;

    return dp[i][j] = ans1;
}

int main()
{//WRITE("in.txt");
	int tc,temp,tt=0,l1,l2,res = -intinf;
	sf(tc);
	while(tc--)
    {
        cin>>str>> k;

        mem(dp,-1);
        res = -intinf;

        for(int i=0; i<str.length(); i++)
            for(int j=i; j<str.length(); j++)
            {
                int ans = call(i,j);//if(i==1 && j==8) cout<<ans<<endl;
                if(ans<=k)
                {//cout<< i << " " << j << endl;
                    int temp = (j-i) + 1;
                    res = (res<temp)? temp : res;
                }
            }
        pf("%d\n", res);
    }
	return 0;
}