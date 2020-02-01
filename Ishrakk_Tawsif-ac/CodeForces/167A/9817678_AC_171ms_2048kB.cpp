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
#define ll                      unsigned long long int
#define mx                      5005
#define mod                     1000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

double d,t,v,a;

double call()
{
    double tt = v/a;
    double ss = tt*tt*a/2;
    double temps = d-ss;
    double tempt;

    if(temps>0) tempt = temps/v;
    else
    {
        tempt=0.0;
        tt = sqrt((2.0 * d)/a);
    }
    return t+tt+tempt;
}

int main()
{
    int n;
    double max_=-1.0;

        scanf("%d%lf%lf",&n,&a,&d);

            loop(i,0,n)
            {
                //cin>> t>> v;
                scanf("%lf%lf",&t,&v);
                    if(max_ == -1.0)
                    {
                        max_ = call();
                        printf("%.10f\n",max_);
                        //cout << setprecision (10) << fixed << max_<<endl;
                    }
                    else
                    {
                        max_ = max(max_,call());
                        //cout << setprecision (10) << fixed << max_<<endl;
                        pf("%.10f\n",max_);
                    }
            }
    return 0;
}