#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
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
#define mod                     100000007


bool check(ll s,ll p)
{
    ll i = ((s/50))%475;

    for(int j=0; j<25; j++)
    {
        i = ((i*96)+42)%475;
        ll temp = 26+i;//cout<<temp<<endl;
        if(temp == p) return true;
    }
    return false;
}

int main()
{
    ll p,x,y;
//check(10850,239);
        scanf("%lld %lld %lld", &p,&x,&y);

        ll start,sub,yy;
        yy=x-y;
        (yy%50==0)? start = yy : start = ((yy/50)*50);
        start = x-start;
//cout<<start<<endl;system("pause");
            for(int i=start; ; i++)
            {
                if(check(i,p))
                {
                    sub = x-i;//cout<<i<<endl;
                    if(sub<0)
                    {//cout<<sub<<endl;
                        sub = (sub*-1);
                        (sub%100==0)? sub=sub/100 : sub = (sub/100)+1;
                    }
                    else sub=0;
                    break;
                }
                //else sub=0;
            }
            pf("%lld\n", sub);
}