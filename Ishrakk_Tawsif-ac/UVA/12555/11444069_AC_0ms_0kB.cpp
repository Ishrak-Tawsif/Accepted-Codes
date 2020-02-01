#define ONLINE_JUDGE 1
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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000+5
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};


string str;

int main()
{//WRITE("in.txt");
    int tc;

    sf(tc);
    getchar();
    for(int tt=1; tt<=tc; tt++)
    {
        //stringstream ss (str);
        int a=-1,b=-1,in=-1;
        string cur[4];

        cin>> a;

        getline(cin,str);
        //cout<<str.size()<<endl;
        if(str.size()>3) b = (int) str[3]-'0';

        double ans = (0*1.0);

        if(a != -1) ans += (a*1.0) * 0.5;
        if(b != -1) ans += (b*1.0) * 0.05;

        pf("Case %d: %g\n", tt,ans);

        //cout<< "Case " << tt << ": " << ans << endl;
    }
    return 0;
}