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

double func()
{
    //t/=5;
    double res = 0.0;
    for(int i=0; i<n; i++) res += (((a[i])*(temp[i]*temp[i])) + (b[i] * temp[i]) + c[i]);
    return res/(1.0*n);
}

int main()
{
    scanf("%d %d", &n,&t);
    cc = 480;

    for(int i=0; i<n; i++)
    {
        cin>> a[i]>> b[i]>> c[i];
    }

    mem(temp,0);
    //t*=9;
    //temp[0] = t;
    int tot=0,koyta=0;
    while(tot<t)
    {
        koyta = koyta%n;
        temp[koyta]++;
        koyta++;
        tot++;
    }

    double ans = func();

//for(int i=0; i<n; i++) cout<<" "<<temp[i]; cout<<endl;
    srand(time(0));
    int cnt = 0;
    while(++cnt<=800)
    {
        //int cnt = 200005;
        //while(cnt--)
        //{
            int fl=0;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(i != j)
                    {
                        if(temp[j] - cc>=0)
                        {
                            temp[i] += cc;
                            temp[j] -= cc;
                            double curres = func();
                            if(ans<curres){
                                ans = curres;
                                fl = 1;
                            }
                            else
                            {
                                temp[i] -= cc;
                                temp[j] += cc;
                            }
                        }
                        /*else if(temp[i]-cc>=0)
                        {
                            temp[j] += cc;
                            temp[i] -= cc;

                            double curres = func();
                            if(ans<curres)
                            {
                                ans = curres;
                                fl = 1;
                            }
                            else
                            {
                                temp[j] -= cc;
                                temp[i] += cc;
                            }
                        }*/
                    }
                }
            }

        if(!fl)cc/=2;
    }

    pf("%.11f\n", ans);

    return 0;
}