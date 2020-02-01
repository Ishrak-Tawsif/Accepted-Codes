#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<=till; var++)
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


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};


string str;
int arr[107];

int main()
{
    int n,temp,temp2;

    int a=0,g=0;
    string s="";

    sf(n);

    for(int i=0; i<n; i++)
    {
        sf(temp);
        sf(temp2);

        if((abs(g-(a+temp)))<=500)
        {
            a+=temp;
            s += 'A';
        }
        else
        {
            g+=temp2;
            s += 'G';
        }
    }
    cout<<s<<endl;
    return 0;
}