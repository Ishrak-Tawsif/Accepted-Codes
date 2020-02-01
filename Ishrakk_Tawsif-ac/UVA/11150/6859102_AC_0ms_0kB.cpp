#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;

        while(scanf("%d", &n) == 1){
            int temp=0,temp2=n;
                while(temp2>=3){
                    temp +=  temp2/3 ;
                    temp2 =  temp2%3+temp2/3;
                }
                if(temp2 == 2) n++;
                printf("%d\n", n+temp);
        }
    return 0;
}
