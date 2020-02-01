#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<=till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define mx                      100007
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int arr[mx],tree[4*mx];
/*bitset <mx> isprime;

void sieve()
{
    isprime[0] = isprime[1]=1;
    for(int i=3; i*i<mx; i+=2)
    {
        if(!isprime[i])
        {
            for(int j=i*i; j<mx; j+=(2*i)) isprime[j] = 1;
        }
    }
    //int in=1;
    //for(int i=3; i<1000000; i++)if(!isprime[i] && i%2 != 0) in++;cout<<in<<endl;
}*/

void buildst(int node,int b,int e)
{
    tree[node] = 0;

    if(b == e) {tree[node] = arr[b]; return;}

    int left = 2*node;
    int right = (2*node) + 1;
    int mid = (b+e)/2;

    buildst(left,b,mid);
    buildst(right,mid+1,e);

    tree[node] = tree[right] + tree[left];
}

int query(int node,int b,int e,int l,int r)
{
    if(r<b || e<l) return 0;
    if(b>=l && e<=r) return tree[node];

    int left = node*2;
    int right = (node*2) + 1;
    int mid = (b+e)/2;

    int lef = query(left,b,mid,l,r);
    int rig = query(right,mid+1,e,l,r);

    return lef + rig;
}

void update(int node,int b,int e,int pos,int val)
{
    if(b>pos || e<pos) return ;
    if(b == e) {tree[node] += val; return;}

    int left = 2*node;
    int right = 2*node+1;
    int mid = (b+e)/2;

    update(left,b,mid,pos,val);
    update(right,mid+1,e,pos,val);

    tree[node] = tree[right] + tree[left];
}

int main()
{
    //sieve();
    int tc;
    int n,q;

    sf(tc);

    loop(tt,1,tc){

    sf(n);
    sf(q);

    for(int i=0; i<n; i++)
    {
        sf(arr[i]);
    }

    buildst(1,0,n-1);

    //int q;
    casepf(tt);pf("\n");
    while(q--)
    {
        int t,l,r,in,val;

            sf(t);

                if(t == 1)
                {
                    scanf("%d",&l);
                    //arr[l] = 0;
                    update(1,0,n-1,l,-1*(arr[l]));
                    pf("%d\n",arr[l]);
                    arr[l]=0;
                    //scanf("%d %d",&l,&r);
                    //pf("%d\n", query(1,1,n,l,r));
                }
                else if(t==2)
                {
                    scanf("%d %d",&l,&r);
                    update(1,0,n-1,l,r);
                    arr[l]+=r;
                }
                else
                {
                    scanf("%d %d",&l,&r);

                    /*if((!isprime[arr[in]] && arr[in]%2 != 0) || arr[in] == 2)
                    {
                        if((!isprime[val] && val%2 != 0) || val == 2)
                        {
                            arr[in] = val;
                        }
                        else
                        {
                            arr[in] = val;
                            update(1,1,n,in,-1);
                        }
                    }
                    else
                    {
                        if((!isprime[val] && val%2 != 0) || val == 2)
                        {
                            arr[in] = val;
                            update(1,1,n,in,1);
                        }
                        else arr[in] = val;
                    }*/

                    pf("%d\n",query(1,0,n-1,l,r));
                }
    }
    }
    return 0;
}