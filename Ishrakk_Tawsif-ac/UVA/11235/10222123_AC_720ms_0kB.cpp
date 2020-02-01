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
#define mx                      100007
#define mod                     100000007

unordered_map <int,int> id,startindex;
int temp,in;
int cnt[mx],tree[4*mx],arr[mx];


void buildst(int node,int b,int e)
{
    if(b == e)
    {//cout<<cnt[b]<<endl;
        tree[node] = cnt[id[arr[b]]];
        return;
    }

    int l = 2*node;
    int r = (2*node)+1;
    int mid = (b+e)/2;

    buildst(l,b,mid);
    buildst(r,mid+1,e);

    tree[node] = max(tree[l],tree[r]);//cout<<b<<" " <<e << " "<<tree[node]<<endl;
}

int query(int node,int b,int e,int i,int j)
{
    if(j<b || i>e) return (-1*intinf);
    if(b>=i && e<=j) return tree[node];

    int l = 2*node;
    int r = (2*node)+1;
    int mid = (b+e)/2;

    int lef = query(l,b,mid,i,j);
    int rig = query(r,mid+1,e,i,j);

    return max(lef,rig);
}

int main()
{
    int n,q;
        while(scanf("%d",&n)==1 && n)
        {
            sf(q);
            in = 0;
            id.clear();
            startindex.clear();
            mem(cnt,0);

            loop(i,1,n+1)
            {
                sf(arr[i]);
                if(id[arr[i]] == 0){id[arr[i]]=++in;startindex[id[arr[i]]]=i;}
                cnt[id[arr[i]]]++;//cout<<cnt[id[temp]]<<endl;
            }
            buildst(1,1,n);

            while(q--)
            {
                int s,e,sb,eb;

                scanf("%d %d",&s,&e);

                if(id[arr[s]] == id[arr[e]])
                {
                    pf("%d\n",e-s+1);
                    continue;
                }

                int ans = startindex[id[arr[s]]]+cnt[id[arr[s]]]-s;
                ans = max(ans,((e-startindex[id[arr[e]]])+1));

                sb = startindex[id[arr[s]]]+cnt[id[arr[s]]];
                eb = startindex[id[arr[e]]]-1;

                pf("%d\n",max(ans,query(1,1,n,sb,eb)));
            }
        }
    return 0;
}