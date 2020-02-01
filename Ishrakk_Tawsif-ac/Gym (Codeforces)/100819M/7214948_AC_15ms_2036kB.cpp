#include<bits/stdc++.h>
using namespace std;

int main(){

    string s[11];int temp[11],testcase,cnt=0;

        cin>> testcase;

            for(int i=0; i<testcase; i++){
                cin>> s[i]>> temp[i];
            }
            for(int i=1; i<=100; i++){
                int n=i,fl=0;

                    for(int j=0; j<testcase; j++){
                        if(s[j] == "ADD") n += temp[j];
                        else if(s[j] == "SUBTRACT") {n-= temp[j]; if(n<0) {fl=1; break;}}
                        else if(s[j] == "MULTIPLY") n*= temp[j];
                        else{
                            if(n%temp[j]!=0) {fl=1; break;}
                            else n/=temp[j];
                        }//if(fl == 1) cout << temp[i] << " " << i << endl;
                }if(fl==1){cnt++;}
            }cout << cnt << endl;
return 0;
}