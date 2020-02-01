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
#define inf                     1e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int main()
{//WRITE("in.txt");

    string str;

    while(cin>> str)
    {
        int len = str.length(),cnt,last=0;

        for(int i=0; i<len;)
        {
            char cur = str[i];
            cnt=0;
            while(str[i] == cur && i<len)i++,cnt++;
            if(cnt == 1) cout<<cur,last=1;
            else if(cnt>=2 && last <= 1)last=2,cout<<cur<<cur;
            else if(cnt>=2 && last > 1) last=1,cout<<cur;
        }
        pf("\n");
    }

    return 0;
}