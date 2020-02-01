#include<bits\stdc++.h>
using namespace std;
int main(){

    int num_of_coin,coins[101],sum,i,sum_coin,count_coin;

        while((scanf("%d", &num_of_coin)) != EOF){

            sum=count_coin=sum_coin=0;
            for(i=0; i<num_of_coin; i++){
                scanf("%d", &coins[i]);
                sum += coins[i];
            }
            sum = (sum/2)+1;
            sort(coins, coins+i);
                for(i=num_of_coin-1; i>=0; i--){
                    if(sum>sum_coin){
                        sum_coin += coins[i];
                        count_coin++;
                    }
                    else break;
                }
                cout << count_coin << endl;
        }

return 0;
}