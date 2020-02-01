#include<bits/stdc++.h>
using namespace std;
int main(){

    int ts,pan,shoc,sho,hat;
        while(scanf("%d %d %d %d %d", &hat,&ts,&pan,&shoc,&sho)==5)
        {
            if(ts==0 && pan==0 && shoc==0 && sho==0 && hat==0) break;
            int temp1=shoc*shoc;
            int temp2=sho*sho;
                printf("%d\n",(ts*pan*hat*temp1*temp2));
        }

return 0;
}