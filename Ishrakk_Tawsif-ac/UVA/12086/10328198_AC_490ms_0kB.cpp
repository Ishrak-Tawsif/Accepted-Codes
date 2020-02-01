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


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};

int n,m,ar[501][501],csum[501][501],blocksize=500,csum2[500];

void update(int pos,int val)
{
    int stblock=pos/blocksize;
    //int enblock=n/blocksize;

    int posind = pos%blocksize;

    csum2[stblock] += val-ar[stblock][posind];
    ar[stblock][posind] = val;
}

int query(int u,int v)
{
    int stblock = u/blocksize;
    int enblock = v/blocksize;
    int ans=0,fl=0;

    if(stblock == enblock) /// u and v at same block
    {
        fl=1;
        int uind = u%blocksize;
        int vind = v%blocksize;

        for(int i=uind; i<=vind; i++)
        {
            ans += ar[stblock][i];
        }
    }

    if(u%blocksize != 0 && !fl)
    {
        int ublock = u/blocksize;
        int uind = u%blocksize;
        stblock = ublock+1;

        for(int i=uind; i<blocksize; i++)
        {
            ans += ar[ublock][i];
        }
    }
    if(v%blocksize != (blocksize-1) && !fl)
    {
        int vblock = v/blocksize;
        int vind = v%blocksize;
        enblock = vblock-1;

        for(int i=0; i<=vind; i++)
        {
            ans += ar[vblock][i];
        }
    }

    if(!fl)
    {
        for(int i=stblock; i<=enblock; i++)
            ans += csum2[i];
    }

    return ans;
}

int main()
{//WRITE("in.txt");
    int tt=0;
    while(sf(n)==1 && n)
    {
        if(tt!=0) pf("\n");

        int ind=-1,j=0;
        for(int i=0; i<n; i++)
        {
            if(i%blocksize == 0)
            {
                ind++;
                j=0;
            }
            sf(ar[ind][j]);

            csum2[ind] += ar[ind][j];
            j++;
        }

        string str;
        int u,v,val;

        casepf(++tt);
        while(1)
        {
            cin>> str;

                if(str == "M")
                {
                    scanf("%d %d", &u,&v);

                    printf("%d\n",query(--u,--v));
                }
                else if(str == "S")
                {
                    scanf("%d %d", &u,&val);

                    update(--u,val);
                }
                else
                {
                    mem(csum2,0);
                    break;
                }
        }
    }
}