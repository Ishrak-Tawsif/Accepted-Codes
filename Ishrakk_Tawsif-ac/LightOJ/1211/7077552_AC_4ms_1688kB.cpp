#include<bits/stdc++.h>
using namespace std;

int main(){

    int testcase,n,x,x1,y,y1,z,z1,temp_x,temp_x1,temp_y,temp_y1,temp_z,temp_z1;

        scanf("%d", &testcase);

            for(int t=1; t<=testcase; t++){
                scanf("%d", &n);

                x=y=z=INT_MIN;
                x1=y1=z1=INT_MAX;

                while(n--){
                    scanf("%d %d %d %d %d %d", &temp_x, &temp_y, &temp_z, &temp_x1, &temp_y1, &temp_z1);

                        if(x<temp_x) x=temp_x;
                        if(y<temp_y) y=temp_y;
                        if(z<temp_z) z=temp_z;
                        if(x1>temp_x1) x1=temp_x1;
                        if(y1>temp_y1) y1=temp_y1;
                        if(z1>temp_z1) z1=temp_z1;
                }
                printf("Case %d: %d\n", t, (max((x1-x),0)*max((y1-y),0)*max((z1-z),0)));
            }
return 0;
}