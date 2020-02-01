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
#define mx                      5005
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

int dirR[] = {0,0,-1,1,-1,-1,1,1};
int dirC[] = {-1,1,0,0,-1,1,-1,1};

int main()
{
    string s,t,ans="";
    int fl=0;

        cin>> s>> t;
        int cnt=0;

            for(int i=0; i<s.length(); i++)
            {
                if(s[i] == t[i]) {cnt++; ans += s[i];}
                else
                {
                    if(fl==0){ans+=s[i]; fl=1;}
                    else {ans+=t[i];fl=0;}
                }

            }
            if((s.length()-cnt)%2 == 0) cout<<ans<<endl;
            else cout<<"impossible"<<endl;

        return 0;
}