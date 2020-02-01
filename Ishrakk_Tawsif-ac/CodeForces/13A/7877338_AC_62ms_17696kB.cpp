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
   int a,sum;
        while(sf(a) == 1)
        {
            sum=0;
            for(int i=2; i<a; i++)
            {
                int temp=a;
                while(i<=temp){
                    sum += temp%i;
                    temp/=i;//cout<<i<<endl;
                }
                sum+=temp;
            }
            int gcd= __gcd(sum,a-2);//cout<<sum<<" " <<gcd <<endl;
            pf("%d/%d\n", sum/gcd,(a-2)/gcd);
        }
   return 0;
}