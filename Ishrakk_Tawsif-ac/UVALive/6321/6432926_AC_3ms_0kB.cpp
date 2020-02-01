#include<bits/stdc++.h>
using namespace std;
int main(){

    int testcase,candy,kids_want;

        while(scanf("%d", &testcase) == 1){

            while(testcase --){

                scanf("%d %d", &candy, &kids_want);
                int arr[candy+3];

                    for(int i=0; i<candy; i++) scanf("%d", &arr[i]);

                        int sum=0;
                        for(int i=0; i<candy; i++){
                            sum += arr[i]/kids_want;
                        }

                        printf("%d\n", sum);
            }
        }
return 0;
}
