#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 1000000005
#define ll long long int
#define mp make_pair
#define mod 100000007

int arr[1005],n,m;

bool ispossible(int val)
{
    int sum=0,cont=m;


    for(int i=0; i<n; )
    {
        sum=0;
        while(i<n && sum+arr[i]<=val)
        {
            sum+=arr[i];
            i++;
        }
        cont--;
    }

    if(cont >= 0) return true;
    else return false;
}

int binary_search(int start,int end)
{
    int mid=(start+end)/2,res=-1;

        while(start<=end)
        {
            mid=(start+end)/2;

                if(ispossible(mid))
                {
                    end=mid-1;
                    res=mid;
                }
                else start=mid+1;

        }
    return res;
}

int main()
{
    int tc,sum,min_;

        sf(tc);

            loop1(tt,tc)
            {

                scanf("%d %d", &n,&m);
                sum=0;
                min_=INT_MIN;

                    loop(i,n)
                    {
                        sf(arr[i]);
                        sum += arr[i];
                        min_ = max(min_,arr[i]);
                    }

                int ans=binary_search(min_,sum);
                pf("Case %d: %d\n",tt,ans);
            }
    return 0;
}