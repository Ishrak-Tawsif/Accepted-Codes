#include<bits/stdc++.h>
using namespace std;


int main(){

    int testcase;

        while(cin>> testcase){

            for(int tt=1; tt<=testcase; tt++){

                double r,t;

                    cin>> r >>t;

                        double result1 = t/(r-1);
                        double result2 = r*result1;
                        printf("Case %d: %0.3lf %0.3lf\n", tt, result1 + 1e-7, result2 + 1e-7);
            }
        }
return 0;
}
