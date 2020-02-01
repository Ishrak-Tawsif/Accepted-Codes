#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,min_=INT_MAX;
        cin>> n;
            int arr[n+1];

                for(int i=0; i<n; i++) cin>> arr[i];
                sort(arr,arr+n);int in=n/2;
                    for(int i=0,j=n-1; i<in; i++,j--){
                        min_=min(min_,(arr[i]+arr[j]));//cout << arr[i] << " " << arr[j] <<endl;
                    }cout << min_ << endl;
return 0;
}