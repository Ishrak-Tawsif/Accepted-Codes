#include<bits/stdc++.h>
using namespace std;
int main(){

    long long int p,n;
    string str[101];
    double ans,temp;

        while(cin>>n >>p){

            ans=temp=0;
            for(int i=0; i<n; i++){
                cin>> str[i];
            }
                 for(int i=n-1; i>=0; i--){
                    if(str[i] == "halfplus"){
                        temp = (0.5+temp)*2;
                        ans += temp;
                    }
                    else{
                        temp = temp*2;
                        ans += temp;
                    }
                 }
            printf("%.0lf\n", (ans*p)/2.0);
        }
}
