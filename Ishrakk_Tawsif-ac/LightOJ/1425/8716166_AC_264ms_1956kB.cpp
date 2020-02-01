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

//double ans,ans2,temp;
//int arr[103];

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
    int arr[100005];

        sf(tc);

            loop1(tt,tc)
            {
                sf(n);
                int max_=INT_MIN;
                arr[0]=0;

                    loop1(i,n)
                    {
                        sf(arr[i]);
                        if(i!=0)
                        {
                            max_ = max(max_,arr[i]-arr[i-1]);
                        }
                    }

                    int ans=max_;
                    for(int i=1; i<=n; i++)
                    {
                        int temp=arr[i]-arr[i-1];

                            if(temp == max_){/*cout<<" - " << " " << temp << " " <<max_<<endl;*/max_--;}
                            else if(max_<temp) {ans++; break;}//cout<< temp << " " << max_<<endl;
                    }
                    pf("Case %d: %d\n", tt,ans);
            }

    return 0;
}

/*
11
11
.#.#.#.#.#.
*/