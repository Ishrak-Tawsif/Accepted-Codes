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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int ar[501][501],rr,cc;
int n,m,k,q,fl2;

void do_sum()
{
    for(int i=1; i<=rr; i++)
    {
        for(int j=1; j<=cc; j++)
        {
            ar[i][j] += ar[i-1][j];
            ar[i][j] += ar[i][j-1];
            ar[i][j] -= ar[i-1][j-1];
        }
    }

    /*for(int i=1; i<rr; i++)
    {
        for(int j=1; j<=cc; j++)
        {
            cout<<" "<<ar[i][j];
        }cout<<endl;
    }*/
}

int call()
{
    int ans = -inf,fl=0;

    /*for(int i=1; i<=rr; i++)
    {
        for(int j=1; j<=cc; j++)
        {
            for(int tempi = i; tempi<=rr; tempi ++)
            {
                for(int tempj=j; tempj<=cc; tempj++)
                {
                    int val = ar[tempi][tempj];//11cout<<val<<" ...... ";
                    val -= ar[tempi][j-1];
                    val -= ar[i-1][tempj];
                    val += ar[i-1][j-1];//cout<<val<<endl;
                    int area = ((abs(tempi-i))+1) * (abs(tempj-j)+1);
if((((abs(tempi-i))+1) == k) && ((abs(tempj-j)+1) == k) && area == k*k && val == k*k)
{
    //pf("%d %d %d %d..\n", ((abs(tempi-i))+1),((abs(tempj-j)+1)),area,val);
    fl2 = 1;//out(fl2);
}

                    if(val == 0)ans = max(ans,area); ///we will only update answer when all element in
                                                       ///in the are are 0.
                }
            }
        }
    }*/

    for(int i=k;i<=rr;i++){
        for(int j=k;j<=cc;j++){
            int area=ar[i][j]-ar[i-k][j]-ar[i][j-k]+ar[i-k][j-k];
            //out(area);
            if(area==k*k){fl2 = 1;break;}
        }
    }

    //return ans;
}

struct ST
{
    int u,v,t;
};
vector <ST> vv;

int check(int tm)
{
    mem(ar,0);

    for(int i=0; i<vv.size(); i++)
    {
        int tr = vv[i].u;
        int tc = vv[i].v;
        int ttm = vv[i].t;
//cout<<ttm << " " << tm << endl;
            if(ttm<=tm) ar[tr][tc] = 1;
    }

    /*for(int i=1; i<=rr; i++)
    {
        for(int j=1; j<=cc; j++)cout<<" "<<ar[i][j];
        pf("\n");
    }*/

    do_sum();
    fl2=0;
    call();//out(fl);
    if(fl2) return 1;
    return 0;
}

int main()
{//WRITE("in.txt");
    ST get;

    scanf("%d %d %d %d", &rr,&cc,&k,&q);

    for(int i=0; i<q; i++)
    {
        scanf("%d %d %d", &get.u, &get.v,&get.t);
        vv.pb(get);
    }
//out(check(8));
        int st = 0,en = 1e9+5,mid,ans=-1;
        while(st<=en)
        {//out(mid);
            mid = (st+en)>>1;

            if(check(mid)) ans = mid,en = mid-1;
            else st = mid+1;
        }
        pf("%d\n", ans);
        
    return 0;
}