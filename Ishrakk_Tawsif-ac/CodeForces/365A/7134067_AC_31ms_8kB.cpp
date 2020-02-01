#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,k,fl,cnt;
    long int temp;

        while(cin>>n >>k){
            fl=0;cnt=0;
            int digit[11];

            while(n--){
                cin>> temp;

                    memset(digit, 0, sizeof(digit));
                    while(temp!=0){
                        digit[temp%10] = 1;
                        temp/=10;
                    }
                    fl=1;
                    for(int i=0; i<=k; i++){
                        if(digit[i] == 0){
                            fl = 0; break;
                        }
                    }
                    if(fl==1) cnt++;
            }
                cout << cnt << endl;
        }
return 0;
}