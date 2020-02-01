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

int n,q,ar[30005],blocksize=405,tree[180][4*10005],trace[180][10005];
vector <int> vv[75];

void update(int pos,int val)
{
    int posblock = pos/blocksize;
    //int posind = pos%blocksize;
    int original = ar[pos];
    int ind;
    //ar[pos]=val;
    for(int i=0; i<vv[posblock].size(); i++)
    {
        if(vv[posblock][i] == original){ind=i; break;}
    }
    ar[pos]=val;
    vector <int> temp;
    int fl=0;
    for(int i=0; i<vv[posblock].size(); i++)
    {
        if(i == ind) continue;
        if(vv[posblock][i]>=val && !fl)
        {
            fl=1;
            temp.pb(val);
            temp.pb(vv[posblock][i]);
        }
        else temp.pb(vv[posblock][i]);
    }
    if(!fl)temp.pb(val);
    //vv[posblock].clear();
    vv[posblock] = temp;
    //ar[posblock][posind]=val;
}

int query(int u,int v,int val)
{
    int uind = u%blocksize,ublock = u/blocksize,vind=v%blocksize,vblock=v/blocksize,cnt=0,fl=0;
    if(ublock == vblock)
    {
        fl=1;
        for(int i=u; i<=v; i++)
        {//cout<<uind << " " << vind << endl;
            //cout<<" "<<vv[ublock][i]<<endl;
            if(ar[i]>val)cnt++;
        }
        return cnt;
    }
    if(u%blocksize != 0 && !fl)
    {
        for(int i=u; ; i++)
        {
            if(ar[i]>val)cnt++;
            if(i%blocksize == blocksize-1) break;
        }
        ublock++;
    }
    if(v%blocksize!=(blocksize-1) && !fl)
    {
        for(int i=v; ; i--)
        {
            if(ar[i]>val) cnt++;
            if(i%blocksize == 0) break;
        }
        vblock--;
    }

    if(!fl)
    {
        for(int i=ublock; i<=vblock; i++)
        {
            int temp = upper_bound(vv[i].begin(),vv[i].end(),val)-vv[i].begin();//cout<<temp<<"...\n";
            cnt += blocksize-(temp);
        }
    }
   return cnt;
}
int main()
{
    scanf("%d", &n);

        int ind=-1,j;
        for(int i=0; i<n; i++)
        {
            if(i%blocksize == 0)
            {
                ind++; j=0;
            }
            scanf("%d", &ar[i]);
            //trace[ind][ar[ind][j]]++;
            vv[ind].pb(ar[i]);//cout<<ind<<" "<<vv[ind][j-1]<<endl;
        }
        for(int i=0; i<=ind; i++)
        {
            sort(vv[i].begin(),vv[i].end());
        }
        sf(q);
        int type,u,v,val,pos;
        while(q--)
        {
            sf(type);

                if(type == 0)
                {
                    ///update
                    scanf("%d %d", &pos,&val);
                    update(--pos,val);
                }
                else
                {
                    scanf("%d %d %d", &u,&v,&val);
                    pf("%d\n", query(--u,--v,val));
                }
        }

    return 0;
}