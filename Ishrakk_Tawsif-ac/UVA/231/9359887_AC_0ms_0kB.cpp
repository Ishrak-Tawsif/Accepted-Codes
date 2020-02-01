#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 1003
#define ll long long int
#define mp make_pair
#define mod 1000000

int arr[203],n,k,d,in;
ll dp[203][13][203];

ll call()
{
    vector <int> vv;
    int ans=INT_MIN;vv.pb(INT_MIN);
    for(int i=0; i<=in; i++) vv.pb(INT_MAX);

        loop(i,in)
        {
            int ind = lower_bound(vv.begin(),vv.end(),arr[i])-vv.begin();
            vv[ind]= arr[i];
            ans = max(ans,ind);//cout << arr[i] << " " << ind << endl;
        }

    return ans;
}

int main()
{
    int temp,tc=0,fl=0;

        in=-1;

            while(1)
            {
                in=-1;
                while(cin>> temp)
                {
                    if(temp == -1) break;
                    arr[++in]=temp;
                }
                if(in == -1) break;

                if(fl==1) pf("\n");
                if(fl==0) fl=1;

                    ++in;
                    pf("Test #%d:\n",++tc);
                    reverse(arr,arr+in);
                    pf("  maximum possible interceptions: %d\n",call());

            }
     return 0;
}