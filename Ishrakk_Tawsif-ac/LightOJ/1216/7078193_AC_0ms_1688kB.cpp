#include<bits/stdc++.h>
using namespace std;


int main(){

    int testcase;
    double r1,r2,h1,h2;

        scanf("%d", &testcase);
            for(int t=1; t<=testcase; t++){
                scanf("%lf %lf %lf %lf", &r1, &r2, &h1, &h2);
                double temp = r2+(r1-r2)*(h2/h1);
                printf("Case %d: %lf\n", t, ((1/3.0)*acos(-1)*h2*((r2*r2)+(r2*temp)+(temp*temp))));
            }
return 0;
}