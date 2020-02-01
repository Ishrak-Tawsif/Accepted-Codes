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
#define mod                     100000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int main()
{

    int n,m,fl=0,nr,nc;
    string ss[103];

            int lr=intinf,lc=intinf,hr=-1*intinf,hc=-1*intinf;

            scanf("%d %d", &n,&m);

                for(int i=0; i<n; i++)
                {
                    cin>>ss[i];
                        for(int j=0; j<m; j++)
                        {
                            if(ss[i][j] == 'B')
                            {
                                lr = min(lr,i);
                                lc = min(lc,j);
                                hr = max(hr,i);
                                hc = max(hc,j);
                            }
                        }
                }

                if(lr==intinf) {pf("1\n"); return 0;}
                        int diff_r = (hr-lr)+1;
                        int diff_c = (hc-lc)+1;

                        if(diff_r == diff_c) {fl=1;}
                        else if(diff_r>diff_c)
                        {
                            int originaldiff = diff_r-diff_c;
                                if(lc-originaldiff>=0){lc-=originaldiff; fl=1;}
                                else if(hc+originaldiff<m) {hc+=originaldiff;fl=1;}
                                else
                                {
                                    int temp = lc;
                                    if(temp==originaldiff){fl=1;lc=0;}
                                    else if(temp>originaldiff){fl=1;lc-=originaldiff;}
                                    else
                                    {
                                        int rest = originaldiff-temp;
                                        if(hc+rest<m) {fl=1;hc+=rest;lc=0;}
                                    }
                                }
                        }
                        else
                        {
                            int originaldiff = diff_c-diff_r;
                                if(lr-originaldiff>=0){lr-=originaldiff;fl=1;}
                                else if(hr+originaldiff<n) {hr+=originaldiff;fl=1;}
                                else
                                {
                                    int temp = lr;
                                    if(temp == originaldiff){fl=1;lr=0;}
                                    else if(temp>originaldiff){fl=1;lr-=originaldiff;}
                                    else
                                    {
                                        int rest = originaldiff-temp;
                                        if(hr+rest<n){fl=1;hr+=rest;lr=0;}
                                    }
                                }
                        }

                        int cnt=0,acnt=0;
                        if(fl == 1)
                        {
                            for(int i=lr; i<=hr; i++)
                            {
                                for(int j=lc; j<=hc; j++)
                                {
                                    if(ss[i][j] != 'B') cnt++;
                                    //acnt++;
                                }
                            }

                            pf("%d\n", cnt);
                        }
                        else pf("-1\n");
                //}
    return 0;
}