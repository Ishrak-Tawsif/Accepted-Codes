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
    int n,i,arr[1001],in,m,l,r,u,d,t1,t2,min_,max_;
    string str[53];
    int a[101],b[101],sum;

        while(sf(n) == 1)
        {
            sf(m);
            sum=0;
            t1=INT_MIN;
            t2=INT_MAX;
                loop(n){
                    sf(a[i]); sf(b[i]);
                     min_=min(a[i],b[i]);
                     max_=max(a[i],b[i]);//cout<<min_<<" "<<max_<<endl;

                             t1=max(t1,min_);
                             t2=min(t2,max_);
                }//cout<<t1<<" "<<t2<<endl;
                if(t2>=t1){
                    if(m<t1) pf("%d\n",t1-m);
                    else if(m>t2) pf("%d\n",m-t2);
                    else pf("0\n");
                }else pf("-1\n");

                //pf("%d\n",sum);
        }
   return 0;
}