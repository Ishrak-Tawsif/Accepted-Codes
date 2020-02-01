#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll ipow(ll base, ll pow){

    ll ans = 1;
    while(pow--) ans *= base;

   return ans;
}

int main(){

    long int x,fl=0,start,till;

        while(cin>> x && x){
                fl=0;

                if(x<0){

                        x=x*-1;
                        for(int b=2; b<=sqrt(x); b++){//cout<<b<<endl;
                            if(fl!=0) break;
                                for(int p=3; ; p+=2){
                                    ll res = ipow(b,p);
                                    if(res == x) {fl=p; break;}
                                    if(res>x) break;
                                }
                        }
                        if(fl == 0) fl=1;
                }

                else{

                    for(int b=2; b<=sqrt(x); b++){
                        if(fl!=0) break;
                        for(int p=1; ; p++){
                            ll res = ipow(b,p);
                            if(res == x) {fl=p; break;}
                            if(res>x) break;
                        }
                    }if(fl == 0) fl=1;
                }
            cout << fl << endl;
        }
return 0;
}