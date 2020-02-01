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
#define intinf                  7e18
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};


int cnt[29];

int main()
{
    int tc;

    sf(tc);
    string str;

    for(int tt=1; tt<=tc; tt++)
    {
        cin>> str;
        mem(cnt,0);

        for(int i=0; i<str.length(); i++)
        {
            char cur = str[i];//cout<<i<<endl;
            //int j=i+1,cont=1;

            //while(str[j] == cur && j<str.length()) j++,cont++;

            cnt[cur-'a'] ++;//cout<<cur-'a'<<endl;
            //i = j;
        }

        sort(cnt,cnt+26);
        pf("Case %d: %d\n", tt,cnt[0]);
    }

    return 0;
}

//abcdefghijklmnopqrstuvwxy