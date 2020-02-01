#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int n,t;
double a[11],b[11],c[11],cc,temp[11];
//int temp [11];

double func(double x,double y)
{
    //t/=5;
    return (6 * pow(x,7)) + (8 * pow(x,6)) + (7 * pow(x,3)) + (5 * pow(x,2)) - (y*x);
}

double rand_real()
{
    return (double) rand()/RAND_MAX;
}

int main()
{
    double x,y;
    double ans = (double)2e18;


    int tc;
    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        cin>> y;
        double cst = 100.0,curval,temperature = 66666677,val;
        x = 0.0;
        ans = func(x,y);

        for(int lim = 1; lim<=10005; lim++)
        {

            int fl=1,fl1,fl2;

            while(fl)
            {
                fl=0;
                fl1=1,fl2=1;


                while(fl1){
                    fl1=0;
                    double curx = x+cst;
                    if(curx>=0 && curx<=100.00)
                    {
                        curval = func(curx,y);
                        if(curval<ans) ans = curval,fl1=1,x=curx;
                    }
                }

                while(fl2)
                {
                    fl2=0;
                    double curx = x-cst;
                    if(curx>=0 && curx<=100.00)
                    {
                        curval = func(curx,y);
                        if(curval<ans) ans = curval,fl2=1,x=curx;
                    }
                }
                fl = fl1 | fl2;if(fl)cout<<"ok\n";
            }
            cst/=2.0;//pf("%.6f\n", cst);//system("pause");
        }
        pf("%.4f\n", ans);
    }
    return 0;
}