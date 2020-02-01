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

int dp[10005][10005];
string s1,s2;

int call(int i,int j)
{
    if(i>=s1.length() || j>=s2.length())
    {
        if(i>=s1.length() && j<s2.length()) return s2.length()-j;
        else if(i<s1.length() || j>=s2.length()) return s1.length()-i;
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) return dp[i][j] = call(i+1,j+1);

    int ans=intinf,ans2=intinf,ans3=intinf;

    ans = call(i+1,j) + 1;
    ans2 = call(i,j+1) + 1;
    ans3 = call(i+1,j+1) + 1;

    return dp[i][j] = min(ans,min(ans2,ans3));
}

int main()
{//WRITE("in.txt");
	int tc,temp,tt=0,l1,l2;
	//sf(tc);

	while(cin>>l1>> s1)
    {
        cin>> l2>> s2;
        mem(dp,-1);
        cout<<call(0,0)<<endl;
    }

	return 0;
}