#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;

        while(cin>> n){
            int one=1;
            for(int i=1; ; i++){
                if(one == 0) {cout << i << endl;break;}
                one = (one*10)+1;//printf("%.0lf\n", one);
                one %= n;
            }
        }

return 0;
}