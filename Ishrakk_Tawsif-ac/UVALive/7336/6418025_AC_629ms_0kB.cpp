#include<bits/stdc++.h>
using namespace std;
int main(){

        int in[11],c[11];
        int diff,isleaked,n,testcase;
        char ans;

            while(scanf("%d", &testcase) == 1){

                while(testcase --){
                    scanf("%d", &n);

                    memset(in,0,sizeof(in));
                    memset(c,0,sizeof(c));

                        for(int i=0; i<n; i++){
                                scanf("%d %d %c", &diff, &isleaked, &ans);

                                    if(isleaked == 0 && ans == 'i') in[diff]++;
                                    else if(isleaked == 1 && ans == 'c') c[diff]++;
                        }

                            int count=0,sum=0;
                            for(int i=1; i<=10; i++){
                                count=0;
                                if(in[i] != 0){
                                    for(int j=i+1; j<=10; j++){
                                        if(c[j] != 0) count += in[i]*c[j];
                                    }
                                }
                                sum += count;
                            }
                            printf("%d\n", sum);
                }
            }

return 0;
}
