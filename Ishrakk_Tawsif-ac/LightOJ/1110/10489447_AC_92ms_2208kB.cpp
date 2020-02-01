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

string a,b, ans[103][103];
int dp[103][103];

string lcs(int i,int j)
{//cout<<i<<" " << j << endl;
    if(i>=a.length() || j>=b.length()) return "";

    if(dp[i][j]) return ans[i][j];

    dp[i][j]=1;

    if(a[i] == b[j]) return ans[i][j] += (a[i]+lcs(i+1,j+1));

    string aa="",bb="";

    aa = lcs(i+1,j);
    bb = lcs(i,j+1);
//cout<<aa<<" " << bb << endl;
    if(aa.length()>bb.length()) ans[i][j] = aa;
    else if(bb.length()>aa.length()) ans[i][j] = bb;
    else ans[i][j] = min(aa,bb);

    return ans[i][j];
}

int main()
{//WRITE("in.txt");
    int tc,tt=0;
    sf(tc);

    while(tc--)
    {
        for(int i=0; i<103; i++) for(int j=0; j<103; j++) {dp[i][j] = 0; ans[i][j]="";}
        cin>> a>> b;//cout<<a<<" " << b << endl;
        //string ans = lcs(a.length()-1,b.length()-1,"");
        casepf(++tt);
        string ans = lcs(0,0);

        if(ans.size() == 0)pf(":(\n") ; else cout<<ans<<endl;
    }
    return 0;
}

/*

3
zxcvbn
hjgasbznxbzmx

*/