#include<iostream>
using namespace std;
        int trailingZeros(int n) {
              int trailingZeros = 0;
              int tmp;
                  while ((tmp = n / 5) >= 1) {
                    trailingZeros+=tmp;
                    n = tmp;
                  }
  return trailingZeros;
}

int main (){

   int num,testcase;

    cin >> testcase;
    while (testcase--){
        cin >> num;
        cout << trailingZeros(num) << endl;
    }

}
