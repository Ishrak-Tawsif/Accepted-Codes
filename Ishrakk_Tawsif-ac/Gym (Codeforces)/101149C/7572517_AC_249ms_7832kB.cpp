#include<bits/stdc++.h>
using namespace std;

int arr[2000005];

int main(){

    int p;
        scanf("%d", &p);

            for(int i=1; i<p; i++){
                long long int temp = (long long int) i*i;
                temp%=p;
                arr[temp]=i;
            }

            printf("0");
            for(int i=1; i<p; i++){
                if(arr[i]!=0) printf(" %d", arr[i]);
                else printf(" -1");
            }
            printf("\n");

return 0;
}