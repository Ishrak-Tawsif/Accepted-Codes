#include<bits/stdc++.h>
using namespace std;


int lis(int arr[], int n){

    int i,j,lis[n],max=0;

    //memset(lis,1,sizeof(lis));
    for(int i=0; i<n; i++) lis[i]=1;
    //cout<< arr[3] << endl;
        for(int i=0; i<n; i++){

            for(int j=0; j<i; j++){
                if(arr[i]>arr[j] && lis[i]<lis[j]+1) lis[i]=lis[j]+1;
            }
        }
        for(int i=0; i<n; i++)
            if(max<lis[i]) max=lis[i];


    return max;
}


int main(){

        int arr[11],len;
        //int len = sizeof(arr)/sizeof(arr[0]);
        while(scanf("%d", &len) == 1){

            for(int i=0; i<len; i++) scanf("%d", &arr[i]);
                printf("%d\n", lis(arr,len));
        }

return 0;
}
