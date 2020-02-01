#include <iostream>
using namespace std;
int main (){
    long int a,b,c,test_case;
    cin >> test_case;

    for (int i = 1; i <= test_case; i++){


        cin >> a >> b >> c;
            if (((a+b)>c) && (b+c)>a && (c+a)>b){

                if (a==b && b==c && c==a){
                    cout << "Case " << i << ": Equilateral" <<endl;
                }
                else if (a==b || b==c || c==a){
                    cout << "Case " << i << ": Isosceles" << endl;
                }
                else {
                    cout << "Case " << i << ": Scalene" << endl;
                }
            }
            else{
                cout << "Case " << i << ": Invalid" << endl;
            }
    }
return 0;
}
