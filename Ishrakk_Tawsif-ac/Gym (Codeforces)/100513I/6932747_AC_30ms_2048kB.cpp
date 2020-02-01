#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;
        while(cin>> n){
             long int p[n],ans=1;
                for(int i=0; i<n; i++)cin>>p[i];
                sort(p, p+n);

                long long int b=p[n-1],sum=0;

                    for(int i=0; i<n-1; i++){
                        sum += p[i];
                        if(sum<=b) {ans++;}
                        else break;
                    }
                    cout << ans << endl;
        }
return 0;
}
