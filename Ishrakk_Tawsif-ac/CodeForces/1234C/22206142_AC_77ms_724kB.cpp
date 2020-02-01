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
#define mod                     100000007


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};

string str[2];

bool check(int r,int c)
{
    if(str[r][c] == '1' || str[r][c] == '2') return 1;
    else return 0;
}

int main()
{
    int tc,n;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d", &n);

        for(int i=0; i<=1; i++) cin>> str[i];

        int r = 0,c = 0,fl = 1,cnt = 0,changekorchi = 0;

        while(c<=n-1)
        { //cout<<r<<" "<<c<<endl; system("pause");
           if(!check(r,c))
           {
               if(check(1-r,c))
               {
                   fl = 0;
                   break;
               }
               r = 1-r;
           }//cout<<r<<" "<<c<<endl;
           c++;
        }
//cout<<r<<endl;
        fl &= r;

        fl? printf("YES\n") : printf("NO\n");
    }
    return 0;
}