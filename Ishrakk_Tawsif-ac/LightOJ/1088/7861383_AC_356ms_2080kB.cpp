#include<bits/stdc++.h>
using namespace std;

#define sf scanf
#define pf printf
#define loop(n) for(int i=0; i<n; i++)

int arr[100005];

int bs(int l,int h,int n)
{
    int mid,foundl=-1,foundh=-1,s=0,e=n;

        while(s<=e)
        {
            mid=(s+e)/2;
            if(arr[mid] == l) {foundl=mid; break;}
            if(mid == 0 && arr[mid]>l) {foundl=0; break;}
            else if(arr[mid]<l&&arr[mid+1]>l) {foundl=mid+1;break;}
            else if(arr[mid]>l) e=mid-1;
            else s=mid+1;
        }

        s=0,e=n;
        while(s<=e)
        {
            mid=(s+e)/2; //cout << mid <<endl;
            if(arr[mid] == h) {foundh=mid; break;}
            if(mid == n && arr[mid]<h) {foundh=n; break;}
            else if(arr[mid]>h&&arr[mid-1]<h) {foundh=mid-1;break;}
            else if(arr[mid]>h) e=mid-1;
            else s=mid+1;
        }//cout<< foundh << " " << foundl << endl;
    return (foundh-foundl)+1;
}

int main()
{
    int tc,n,q,l,h;

        while(sf("%d", &tc) == 1)
        {
            for(int tt=1; tt<=tc; tt++){
                sf("%d %d",&n,&q);
                    loop(n) {sf("%d", &arr[i]); }
                    pf("Case %d:\n",tt);
                    loop(q)
                    {
                        sf("%d %d", &l,&h);
                        pf("%d\n", bs(l,h,n-1));
                    }
            }
        }
    return 0;
}