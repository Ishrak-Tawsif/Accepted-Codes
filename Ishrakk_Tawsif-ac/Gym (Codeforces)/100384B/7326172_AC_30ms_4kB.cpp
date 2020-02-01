#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;

        while(cin>> n){
            /*int max_ = INT_MIN;
            int arr[100001],sum,start=100,end=999;
            for(int i=start; i<=end; i++){
                int temp=i; cout << i << endl;
                sum=0;

                    while(temp!=0)
                    {
                        sum += temp%10;
                        temp/=10;
                    }
                    arr[i] = sum;
            }
            for(int i=start; i<=end; i++){cout << max_ << endl;
                for(int j=i+1; j<=end; j++) if(arr[i] == arr[j]){ max_=max(max_,abs(i-j));}
            }cout << max_ << "//" << endl;
        //}*/

        if(n==1) cout << 0 << endl;
        else if(n == 2) cout << 72 << endl;
        else if(n==3) cout << 801 << endl;
        else if(n==4) cout << 8811 << endl;
        else if(n==5) cout << 89001 << endl;
        else if(n==6) cout << 898101 << endl;
        else if(n==7) cout << 8990001 << endl;
        else if(n==8) cout << 89981001 << endl;
        else if(n==9) cout << 899900001 << endl;
        else if(n==10) cout << 8999810001 << endl;
    }
return 0;
}