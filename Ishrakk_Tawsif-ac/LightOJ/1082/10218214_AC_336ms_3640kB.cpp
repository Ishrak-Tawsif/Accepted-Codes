#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:\n",nn)
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
#define mx                      100007
#define mod                     100000007


int arr[mx],tree[4*mx],temp=intinf;

void buildst(int node,int b,int e)
{
    if(b == e) {tree[node] = arr[b];return;}

    int left = 2*node;
    int right = (2*node)+1;
    int mid = (b+e)/2;

    buildst(left,b,mid);
    buildst(right,mid+1,e);

    tree[node] = min(tree[right],tree[left]);
}

void query(int node,int b,int e,int i,int j)
{//cout<<node<<endl;
    if(j<b || i>e) return;
    if(i<=b && j>=e)
    {
        temp = min(temp,tree[node]);
        return;
    }

    int left = 2*node;
    int right = (2*node)+1;
    int mid = (b+e)/2;

    query(left,b,mid,i,j);
    query(right,mid+1,e,i,j);
}

int main()
{
    int n,q,tc;

        sf(tc);

            loop(tt,1,tc)
            {
                scanf("%d %d", &n,&q);

                for(int i=1;i<=n; i++)
                {
                    scanf("%d",&arr[i]);
                }
//out("ffrw");
                buildst(1,1,n);
//out("fr");

                casepf(tt);
                int u,v;
                while(q--)
                {
                    temp = intinf;
                    scanf("%d %d", &u,&v);
                    query(1,1,n,u,v);
                    pf("%d\n",temp);
                }
            }
    return 0;
}