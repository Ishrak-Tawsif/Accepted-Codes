#include<bits/stdc++.h>
using namespace std;

int x[1000005];

int binary_search(int s_value,int beg,int end){

        int mid,ans;
        while(beg<=end)
                {
                    mid=(beg+end)/2;
                    if(x[mid]<=s_value)
                    {
                        ans=mid;
                        beg=mid+1;
                    }
                    else
                    {
                        end=mid-1;
                    }
                }
                return ans;
}

int main(){

    int n,q;

        scanf("%d", &n);

            for(int i=0; i<n; i++){ scanf("%d", &x[i]);}
            sort(x, x+n);
        scanf("%d", &q);
        long int m;
            for(int i=0; i<q; i++){
                    scanf("%d", &m);

                        if(m >= x[n-1]) cout << n << endl;
                        else if(m<x[0]) cout << "0" << endl;
                        else{
                             cout << binary_search(m,0,n-1)+1 << endl;
                        }
            }
return 0;
}