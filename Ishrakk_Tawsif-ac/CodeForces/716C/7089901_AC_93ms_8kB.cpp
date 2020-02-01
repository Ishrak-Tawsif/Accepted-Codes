#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;

        while(scanf("%d", &n) == 1){

                double ini=2.0;
                for(double level=1; level<=n; level++){
                    double temp = (level * (level+1))*1.0;
                    temp *= temp;

                        printf("%.0lf\n", (temp-ini)/(level*1.0));
                        ini = level * (level+1)*1.0;
                }
        }
return 0;
}