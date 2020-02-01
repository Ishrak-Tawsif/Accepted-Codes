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


int n;
int ar[53],dp[53][53];


int main()
{
    int n,st=0,nr=0,temp,track=0,trtrack=0,fl=1;
    string s;

        sf(n);

        for(int i=0; i<n; i++)
        {
            scanf("%d", &temp);cin>>s;
//cout<<s<<endl;
                if(s == "South") nr += temp;
                else if(s == "North") nr -= temp;
                else if(s == "East"){if(nr==0 || nr ==20000)fl=0;}
                else if(s == "West"){if(nr==0 || nr == 20000) fl=0;}
//cout<<nr<<endl;
                if(nr>20000 || nr<0)fl=0;//cout<<nr<<endl;
        }
        if(nr == 0 && fl) pf("YES\n"); else pf("NO\n");
    return 0;
}