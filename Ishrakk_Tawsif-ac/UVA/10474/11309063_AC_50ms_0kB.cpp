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
            mid = (s+e)>>1;
            if(ar[mid] == sv) ans = mid,e = mid-1;
            else if(ar[mid]>sv)
            {
                e = mid-1;
            }
            else s = mid+1;
        }
    return ans;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
//cout<<((3+3)>>1)<<endl;
   int n,q,temp,tt=0;

        while(scanf("%d %d", &n,&q) && n && q)
        {
            loop(i,0,n) sf(ar[i]);
            sort(ar,ar+n);

            pf("CASE# %d:\n", ++tt);
            while(q--)
            {
                sf(temp);
                int ind = bsearch(0,n-1,temp) + 1;
                (ind == 0)? pf("%d not found\n", temp) : pf("%d found at %d\n",temp,ind);
            }
        }
   return 0;
}

/*
4 1
2
3
5
1
5
5 2
1
3
3
3
1
2
3
0 0
*/