#include <bits/stdc++.h>
using namespace std;


int main(){

    int n;

        while(cin>> n){
            int arr[n+3],temp;

                for(int i=1; i<=n; i++){
                    cin>>temp;
                    arr[temp] = i;
                }
                arr[0] = arr[1];
                long long int sum=0;
                for(int i=2; i<=n; i++){
                    sum += abs(arr[i-1]-arr[i]);
                }cout << sum << endl;
        }
return 0;
}