#include<bits/stdc++.h>
using namespace std;


int main(){

    long int s,f,d,fl;

        while(cin>> s>> f>> d){

            if(s==f) fl=1;
            else if(d == 0) fl=0;
            else if(f<s && d>=0) fl=0;
            else {
                long int sub = f-s;
                long int div = (sub)/d;
                long int ques = (sub)%d; //cout << sub << " " << div << " " << ques << endl;
                    if(ques == 0 && div>0) fl=1;
                    else fl=0;
            }
            if(fl == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
return 0;
}