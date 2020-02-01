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
#define mx                      5005
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

int dirR[] = {0,0,-1,1,-1,-1,1,1};
int dirC[] = {-1,1,0,0,-1,1,-1,1};

int main()
{
    int n,swa=0,swb=0,cnta=0,cntb=0,fl1=0,fl2=0;
    string s;

        sf(n);
        cin>> s;
            for(int i=0; i<n; i++)
            {
                if(fl1 == 0)
                {
                    if(s[i] != 'r') cnta++;
                    fl1=1;
                }
                else
                {
                    if(s[i] != 'b') cntb++;
                    fl1=0;
                }

                if(fl2 == 0)
                {
                    if(s[i] != 'b') swa++;
                    fl2=1;
                }
                else
                {
                    if(s[i] != 'r') swb++;
                    fl2=0;
                }

            }//cout<<cnta<<" " << cntb << " " << swa << " " << swb << endl;
     cout<< min(min(cnta,cntb) + (max(cnta,cntb)-min(cnta,cntb)),min(swa,swb) + (max(swa,swb)-min(swa,swb))) << endl;
    return 0;
}