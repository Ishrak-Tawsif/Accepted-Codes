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

int ar[100005];

int bsearch(int s,int e,int sv)
{
    int mid = (s+e)/2,ans = -1;

        while(s<=e)
        {
            mid = (s+e)/2;
            if(ar[mid]<=sv)
            {
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
    return ans;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int p,y;

    while(~scanf("%d", &y))
    {
        sf(p);
        loop(i,0,p) sf(ar[i]);

    int last = ar[p-1],ans = -intinf,sy,ey;
    loop(i,0,p)
    {
        int sv = ar[i] + (y-1);
        if(sv>last) sv=last;
        int temp = bsearch(0,p-1,sv);

        if(temp == -1) continue;//cout<<temp<<" ";

        int cur = (temp-i) + 1;
//cout<<temp<<" " << i <<" ......... \n";
        if(cur>ans)
        {
            ans = cur;
            sy = ar[i];
            ey = ar[temp];
        }
    }
        pf("%d %d %d\n", ans,sy,ey);
    }
	return 0;
}

/*

5
20
1
2
3
6
8
12
13
13
15
16
17
18
19
20
20
21
25
26
30
31
*/