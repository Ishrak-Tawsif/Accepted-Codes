#include<bits/stdc++.h>
using namespace std;

#define ll long long

/*double ncr(ll a, ll b){

    if(a == b) return 1.0;

    double ans=1;
        ll min_ = min(b,a-b);
        ll max_ = max(b,a-b);

            for(int i=max_+1,j=2; i<=a; i++,j++){

                if(j<=min_){ans *= (i*1.0); ans /= (j*1.0);}
                else ans *= i*1.0;
            }
    return ans;
}*/

int main(){

    ll p,q,r,s;

        while(cin>>p >>q>> r>> s){

            ll min_ = min(q,p-q);
            ll min_1 = min(s,r-s);
            ll max_ = max(q,p-q);
            ll max_1 = max(s,r-s);

                double ans = 1.0;

                    for(int i=max_+1,j=2,k=max_1+1; i<=p || k<=r; i++,j++,k++){
                        if(i<=p){
                                ans *= (double) i;
                                if(j<=min_) ans /= (double) j;
                        }
                        if(k<=r){
                            ans /= (double) k;
                            if(j<=min_1) ans *= (double) j;
                        }
                    } printf("%.5lf\n", ans);
        }
return 0;
}