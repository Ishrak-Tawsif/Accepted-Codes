#include<bits/stdc++.h>
using namespace std;


int arr[1101];

void pre_gen(){

    int in=-1,temp,arr_temp[7],temp_in;
    for(int i=1; in<=1000; i++){
        temp = i;
        temp_in = -1;
            while(temp!=0){
                arr_temp[++temp_in] = temp%10;
                temp/=10;
            }
            for(int j=temp_in; j>=0; j--) {arr[++in]=arr_temp[j]; /*cout << in << " " << arr[in]<<endl;*/}
    }
}

int main(){
    pre_gen();
    int n;

        while(cin>> n) cout << arr[n-1] << endl;
return 0;
}