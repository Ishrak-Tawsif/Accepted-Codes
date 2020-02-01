#include <iostream>
using namespace std;
int main (){
    int a,b,c,d;
    while(( cin >>a >>b >>c) && (a || b || c )){

        if (a >= b){
            if(a>c){
                d = a;
                a = c;
                c = d;
            }
        }
        else if (b > c){
            d = b;
            b = c;
            c = d;
        }

            if ((a*a)+(b*b) == (c*c)){
                cout << "right" << endl;
            }
            else{
                cout << "wrong" << endl;
            }
    }
return 0;
}
