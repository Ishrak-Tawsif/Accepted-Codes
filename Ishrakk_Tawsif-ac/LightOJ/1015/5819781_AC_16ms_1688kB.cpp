#include<iostream>
#include<cstdio>
using namespace std;
int main(){

    int testcase,dust_amount,student,sum;
        cin >> testcase;
            for(int j = 1; j<=testcase; j++){
                cin >> student;
                sum=0;
                    for(int i = 0; i<student; i++){
                        cin >> dust_amount;
                           if(dust_amount>0){
                                sum += dust_amount;
                           }
                        //cout << dust << " " << sum << endl;
                    }
                    //cout << sum << endl;
                    printf("Case %d: %d\n",j,sum);
            }
return 0;
}
