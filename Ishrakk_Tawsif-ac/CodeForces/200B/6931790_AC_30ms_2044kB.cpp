#include <bits/stdc++.h>
using namespace std;


int main(){

    int n;
        while(cin>> n){

            int p,sum=0;

                for(int i=0; i<n; i++){
                    cin>>p;
                    sum += p;
                }

                double ans = (double) (sum)/ (n*100.00);
                printf("%.12llf\n", ans*100.00);
        }
return 0;
}
