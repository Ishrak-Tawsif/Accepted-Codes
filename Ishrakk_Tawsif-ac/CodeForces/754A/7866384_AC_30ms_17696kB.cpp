#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 1000005
#define ll long long int

vector <int> graph[mx];
vector <int> topsort;
int vis[mx],n,domino;

int arr[105],sum[105];

int main()
{
    int n;

        while(sf(n) == 1)
        {
            loop(n) {
                sf(arr[i]);
                if(i==0) sum[i]=arr[i];
                else sum[i] = arr[i]+sum[i-1];
            }
            if(sum[n-1]!=0)
            {
                pf("YES\n");
                pf("1\n1 %d\n",n);
            }
            else{
                int fl=0;
                for(int i=0; i<n-1; i++)
                {
                    if(sum[i]!=0 && sum[n-1]-sum[i]!=0){
                        pf("YES\n");
                        pf("2\n1 %d\n",i+1);
                        pf("%d %d\n",i+2,n);
                        fl=1;
                        break;
                    }
                }
                if(fl==0)pf("NO\n");
            }
        }
   return 0;     
}