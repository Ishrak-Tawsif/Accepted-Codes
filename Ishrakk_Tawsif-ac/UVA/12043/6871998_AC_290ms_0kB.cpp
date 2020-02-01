#include<bits/stdc++.h>
using namespace std;

long long int sum,num;

void num_of_div(int n){
    sum=0,num=0;

        for(int i=1; i*i<=n; i++){
            if(n%i == 0){
               if(i != n/i){
                num += 2;
                sum += (i + n/i);
               }
                else {
                    num ++;
                    sum += i;
                }
            }
        }
}

int main(){

    int a,b,k,testcase;
    long long int tot_sum,tot_num;

        scanf("%d", &testcase);

            while(testcase --){
                scanf("%d %d %d", &a, &b, &k);
                tot_sum=0;tot_num=0;

                    int i=1,kk=k;
                    while(kk<a) {kk = i*k; i++;}

                    for(int i=kk,j=2; i<=b; i+=k){

                            num_of_div(i);
                            tot_sum += sum;
                            tot_num += num;

                    }
                    cout << tot_num << " " << tot_sum << endl;
            }
    return 0;
}
