#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,temp;

        while(scanf("%d", &n) == 1){
            int cnt1=0,cnt2=0,max_=-1;
            for(int i=0; i<n; i++){

            cin>> temp;

                if(temp==1){
                    cnt1++;
                        if(cnt2>0) cnt2--;
                }
                else{
                    cnt2++;
                    max_=max(cnt2,max_);
                }
            }
            cout<< cnt1+max_<<endl;
        }
return 0;
}