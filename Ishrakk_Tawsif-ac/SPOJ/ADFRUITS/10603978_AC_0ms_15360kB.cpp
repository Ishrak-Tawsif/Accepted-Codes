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

int dp[103][103],shortlen;
ll dp2[103][103];
string str,str2,ans[103][103];

int call1(int i,int j)
{
    if(i>=str.length() && j>=str2.length()) return 0;
    if(i == str.length()) return str2.length()-j;
    if(j == str2.length()) return str.length()-i;

    if(dp2[i][j] != -1) return dp2[i][j];

    if(str[i] == str2[j]) return dp2[i][j] = (call1(i+1,j+1) + 1);

    int ans=intinf,ans2=intinf;

    ans = call1(i+1,j)+1;
    ans2= call1(i,j+1)+1;

    return dp2[i][j] = min(ans,ans2);
}

void call(int i,int j)
{
    if(i>=str.length() && j>=str2.length()) return;
    if(i>=str.length() && j<str2.length()) {cout<<str2[j];call(i,j+1);return;}
    if(i<str.length() && j>=str2.length()) {cout<<str[i];call(i+1,j);return;}
    if(str[i] == str2[j])
    {
        cout<<str[i];
        call(i+1,j+1);
    }
    else if(call1(i,j+1)<call1(i+1,j))
    {
        cout<<str2[j];
        call(i,j+1);
    }
    else
    {
        cout<<str[i];
        call(i+1,j);
    }
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
	int tc,tt=0,l1,l2,res = -intinf;

        while(cin>>str>> str2)
        {

            mem(dp2,-1);
            call1(0,0);
            call(0,0);
            pf("\n");

        }
	return 0;
}