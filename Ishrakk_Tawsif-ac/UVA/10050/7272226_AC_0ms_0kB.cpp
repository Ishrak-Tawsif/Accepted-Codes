#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,testcase,days;
    cin>> testcase;

        while(testcase--){
            cin>> days;
            int arr[days+1];
            memset(arr,0,sizeof(arr));

                cin>> n;
                int nn[n+1];

                    for(int i=0; i<n; i++) cin>> nn[i];

                        for(int i=0; i<n; i++){
                            for(int j=1; j*nn[i]<=days; j++){
                                int temp=j*nn[i];//cout << temp << endl;
                                if(temp%7!=6 && temp%7!=0){ arr[temp]=1;/*cout << temp << endl;*/}
                            }
                        }
                        int cnt=0;
                        for(int i=1; i<=days; i++) {if(arr[i] == 1) cnt++;}
                        cout << cnt << endl;
        }
return 0;
}