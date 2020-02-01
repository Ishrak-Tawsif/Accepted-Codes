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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

//int n,ar[200005],ar2[200005],dp[10005][3];


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
	int n,q,tt=0,temp,min_,ans1,ans2;

	while(sf(n) == 1 && n)
    {
        int ar[n+3],ttmm;

        for(int i=0; i<n; i++) sf(ar[i]);

        /*int ar2[n+3][n+3];
        for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(i!=j)
                    {
                        ar[i][j] = ar[i] + ar[j];//cout<<ttmm-temp<<endl;
                    }
                }
        }*/

        sf(q);

        casepf(++tt);
        while(q--)
        {
            min_ = intinf;
            sf(temp);//cout<<temp<<endl;
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(i!=j){ttmm = ar[i] + ar[j];//cout<<ttmm-temp<<endl;
                    if((abs(ttmm-temp))<min_)
                    {
                        min_ = abs(ttmm-temp);//cout<<min_<<" " <<ttmm<<" " <<ar[i]<<" " <<ar[j]<<endl;
                        ans1 = ttmm;
                        //ans2 = ar[j];
                    }}
                }
            }
            pf("Closest sum to %d is %d.\n", temp,ans1);//system("pause");
        }
    }

	return 0;
}