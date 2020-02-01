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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

int track[153],temp[153];


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    //cout<<calc(150)<<".."<<endl; system("pause");
    int n;

    while(~sf(n))
    {
        int sum = 0,cur;
        for(int i=1; ; i++)
        {
            sum += i;
            if(sum>=n)
            {
                cur = i;
                break;
            }
        }
        (cur&1)? pf("TERM %d IS %d/%d\n", n,(1+sum-n),(cur-(sum-n))) : pf("TERM %d IS %d/%d\n", n,(cur-(sum-n)),1+sum-n);
    }

    return 0;
}