#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

    int arr1[3],arr[3];

        //while(cin>> arr1[0]>> arr1[1]>> arr1[2]>>arr[0]>> arr[1]>> arr[2]){

        cin>> arr1[0]>> arr1[1]>> arr1[2]>>arr[0]>> arr[1]>> arr[2];
            sort(arr1, arr1+3);
            sort(arr, arr+3);
            int fl=1;
            int area1 = (arr1[0]*arr1[0])+(arr1[1]*arr1[1]);
            int area = (arr[0]*arr[0])+(arr[1]*arr[1]);

                if(arr[0] != arr1[0] || arr[1] != arr1[1]) fl=0;
                if(area1 != (arr1[2]*arr1[2]) || area != (arr[2]*arr[2])) fl=0;
                if(arr[2]!=arr[2] || area1!=area) fl=0;

                    if(fl==1) cout << "YES" << endl;
                    else cout << "NO" << endl;
        //}
return 0;
}