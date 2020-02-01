#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 103
#define ll long long int
#define mp make_pair
#define mod 100000007

double ans,ans2,temp;
int arr[103];

/*int call(int n)
{
    //ans=(abs(arr[1]))*(1/(double)n);
    for(int i=1; i<=n; i++)
    {
        if(arr[i]<0) {ans += (double)1.0/n; ans2 += (1.0/(double)n * (double) abs(arr[i]));}
        else  ans2 += (1.0/(double)n * (double) abs(arr[i]));
    }//cout<<ans<<"..."<<endl;
    ans = 1-ans;
    temp = 1/ans;
}*/

int main()
{
    int tc,n,ccnntt,sum;

        sf(tc);

            loop1(tt,tc)
            {
                sf(n);
                ccnntt=sum=0;

                    loop1(i,n)
                    {
                        sf(arr[i]);
                        if(arr[i]<0) ccnntt++;
                        sum += abs(arr[i]);
                    }

                    if(ccnntt==n) {pf("Case %d: inf\n",tt);/*cout<<"inf"<<endl;*/}
                    else{

                        int gcd = __gcd(sum,(n-ccnntt));//cout<<gcd<<endl;
                        pf("Case %d: %d/%d\n", tt,sum/gcd,(n-ccnntt)/gcd);
                    }
            }
    return 0;
}