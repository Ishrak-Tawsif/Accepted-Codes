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

int cnt1[31],cnt2[31];

int main()
{
    string str;
    int cnt=0,ans=0;

        cin>> str;

            for(int i=0; i<str.length(); )
            {//cout<<i<<endl;
                if(str[i] == 'P')
                {
                    cnt=1;
                    while(str[i] == 'P' && cnt<=5 && i<str.length()) {i++;cnt++;/*cout<<i<<" "<<cnt<<endl;*/}
                    ans++;
                    if(i>=str.length()) break;
                }
                else if(str[i] == 'C')
                {
                    cnt=1;
                    while(str[i] == 'C' && cnt<=5 && i<str.length()){i++; cnt++;}
                    ans++;
                    if(i>=str.length()) break;
                }
            }

            pf("%d\n", ans);
    return 0;
}