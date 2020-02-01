#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){

    int testcase,input;
    double ans;
        cin >> testcase;
            while(testcase --){

                cin >> input;

                input = abs ((((input*63+7492)*5-498)/10)%10);

                cout << input << endl;
            }
return 0;
}
