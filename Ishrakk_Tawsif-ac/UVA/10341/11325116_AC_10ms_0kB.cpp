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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000007

double p,q,r,s,t,u;

double f(double x)
{
    return (p*exp(-x)) + (q*sin(x)) + (r*cos(x)) + (s*tan(x)) + (t*x*x) + u;
}

double b_search()
{
    double st = 0.0,en = 1.0,mid,ans=0.0;

    double temp = f(1),temp2 = f(0);
//pf("%.4f %.4f\n", temp,temp2);
    if(temp>(1e-18*1.0) || temp2<(-1e-18*1.0)) return -1.0;

    int cnt = 0;
    while(st<=en)
    {
        cnt++;
        mid = (st+en)/2.0;

        double cur = f(mid);
        //pf("%.4f %.4f\n", mid,cur);
        if(cur>0.0)
        {
            ans = mid;
            st=mid;
        }
        else en = mid;
        if(cnt == 101) break;
    }
    return ans;
}

int main()
{//WRITE("in.txt");

    while(scanf("%lf %lf %lf %lf %lf %lf", &p,&q,&r,&s,&t,&u) == 6)
    {
        double res = b_search();
        (res == -1.0)? pf("No solution\n") : pf("%.4f\n",res);
    }

    return 0;
}