#include<iostream>
#include<math.h>
using namespace std;
int main (){

    int i,j,c,count;

        while(cin >>i, cin >>j && i || j ){
            count = 0;
            for(int k = i; k<=j; k++){
                c = sqrt(k);

                    if((c*c) == k)
                        count++;
            }
           cout << count << endl;
        }
    return 0;
}
