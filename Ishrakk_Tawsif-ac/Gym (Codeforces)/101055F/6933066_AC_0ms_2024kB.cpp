#include<bits/stdc++.h>
using namespace std;


int main(){

    int a,testcase,sign;
    string s;
    cin>>testcase;

    for(int t=1; t<=testcase; t++){
        cin>>a>>s;
        sign = s.length();
        //cout <<a << " " << s.length() <<endl;

            long long ans=a;

                for(int i=1,j=sign; ;i++,j=i*sign){
                    //cout << a-j<<endl;;
                    if((a-j)>=1) ans *= a-j;
                    else break;
                }
                printf("%.0lld\n", ans);
    }
}
