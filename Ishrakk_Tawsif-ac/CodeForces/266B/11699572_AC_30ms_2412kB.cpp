#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int ar[100005];

int main()
{
    string str;
    int n,t;

    cin>> n>> t>> str;

    for(int i=1; i<=t; i++)
    {
        string temp = str;
        for(int i=0; i<str.length()-1; i++)
        {
            if(str[i] == 'G') continue;
            else
            {
                if(str[i+1] == 'G')
                {
                    temp[i] = 'G';
                    temp[i+1] = 'B';
                }
            }
        }
        str = temp;
    }
    cout<<str<<endl;

    return 0;
}