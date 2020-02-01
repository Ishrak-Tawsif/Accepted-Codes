#include<bits/stdc++.h>
using namespace std;

int main(){

    double first_shop,second_shop,connecting,possibility[5];

        while(scanf("%lf %lf %lf", &first_shop,&second_shop,&connecting) == 3){

            possibility[0] = (2*first_shop)+(2*second_shop);
            possibility[1] = (2*first_shop)+(2*connecting);
            possibility[2] = (2*second_shop)+(2*connecting);
            possibility[3] = first_shop+second_shop+connecting;

                sort(possibility, possibility+4);

                printf("%.0lf\n", possibility[0]);

        }
return 0;
}
