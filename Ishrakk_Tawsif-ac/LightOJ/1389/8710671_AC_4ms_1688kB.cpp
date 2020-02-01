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
    string arr;

        sf(tc);

            loop1(tt,tc)
            {
                sf(n);
                cin>> arr;

                    int ans=0;

                        for(int i=0; i<n; )
                        {
                            while(i<n)
                            {
                                if(arr[i]=='#') i++;
                                else {ans++;break;}
                            }
                            for(int j=0; j<3; j++)
                            {
                                arr[i+j]='#';
                            }
                        }
                        
                        pf("Case %d: %d\n",tt,ans);
            }
    return 0;
}

/*
11
11
.#.#.#.#.#.
*/