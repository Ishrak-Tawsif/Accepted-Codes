///uva 10346

#include <iostream>
using namespace std;
int main (){

    int curr_cig,max_cig = 0,k,sum,temp,extra_cigg,cigg;

       while ( cin >> curr_cig >> k ){
        sum = 0;
        cigg = curr_cig;
            while (cigg >= k){
                extra_cigg = cigg % k;
                temp = cigg /k;
                cigg = extra_cigg + temp;
                sum = sum + temp;
            }

                cout << sum + curr_cig << endl;
       }

return 0;
}
