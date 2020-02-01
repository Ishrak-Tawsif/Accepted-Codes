#include<bits/stdc++.h>
using namespace std;
int main(){

    long long int n;

        while(cin>> n){

              if(n%2 != 0) cout << "0" << endl; ///cause it's impossible to form a rectangle with an odd number
              else printf("%.0lf\n",ceil((n/4.0))-1.0); ///1 should be deleted because 1 result here is square.
        }
    return 0;
}
