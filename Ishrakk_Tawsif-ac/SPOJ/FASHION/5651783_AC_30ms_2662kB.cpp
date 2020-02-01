#include <iostream>
#include <algorithm>
using namespace std;
int main (){

    int men[1001],women[1001],testcase,totalcouple,sum;
    cin >> testcase;


        while (testcase --){
            sum = 0;
            cin >> totalcouple;

                for (int i = 0; i<totalcouple;i++){
                    cin >> men[i];
                }
                for (int i = 0; i<totalcouple;i++){
                    cin >> women[i];
                }

                sort(men, men + totalcouple);
                sort(women, women + totalcouple);

                for (int i = 0; i<totalcouple;i++){
                  sum = sum + men[i] * women[i];
                }
                cout << sum << endl;
        }
return 0;
}
