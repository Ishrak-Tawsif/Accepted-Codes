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

int n;
double ansx,ansy,arx[1005],ary[1005],eibarx,eibary;

double func(double xx,double yy)
{
    double tot = 0.0,maxi = 0.0;
    for(int i=0; i<n; i++)
    {
        double diss = sqrt(((xx-arx[i])*(xx-arx[i]))+((yy-ary[i])*(yy-ary[i])));

        if(maxi<diss)
        {
            maxi = diss;
            //eibarx = arx[i];
            //eibary = ary[i];
        }
    }//system("pause");
    return maxi;
}

int main()
{
    double x,y;
    srand(time(0));
    while(cin>> x>> y>> n)
    {
        for(int i=0; i<n; i++) cin>> arx[i]>> ary[i];

        double cst = 1005,curx = 0.0,cury = 0.0,ans = func(curx,cury);
//cout<<" ... "<<ans<<endl;
        int fl = 1,cnt=6665;
        while(cnt--)
        {
            fl = 1;
            while(fl){

                fl = 0;

                for(int i=0; i<8; i++)
                {
                    double valx = ((rand()%100)+1)/50.0;
                    double valy = ((rand()%100)+1)/50.0;

                    double tempx = curx + (valx*dx[i]);
                    double tempy = cury + (valy*dy[i]);

                    if(tempx<=x && tempy<=y && tempx>=0 && tempy>=0) {
//out("ok");
                        double curans = func(tempx,tempy);
                        if(ans>curans)
                        {//out("ok");
                            ans = curans;
                            curx = tempx;
                            cury = tempy;
                            fl = 1;
                        }
                    }
                }
            }
        }
        pf("(%.1f,%.1f).\n", curx,cury);
        pf("%.1f\n", ans);
        //cout<<ansx<<" "<<ansy<<endl;
    }
    return 0;
}