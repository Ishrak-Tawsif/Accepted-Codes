#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
int main(){

    char str [111];
    int asc,sum;
    while(cin.getline(str,110)){
        int len = strlen(str);
        sum = 0;

            for(int i = 0;i<len;i++){
                if(str[i]>= 'A' && str[i] <= 'Z'){
                    asc = toascii(str[i])-38;
                }
                else{
                    asc = toascii(str[i])-96;
                }
               sum+= asc;
            }

        int tru = 1;
        for(int j=2; j<=sqrt(sum); j++)
        {
            if(sum%j==0)
            {
                tru=0;
                break;
            }
        }
        if(tru==1 || sum==1)
            cout << "It is a prime word." << endl;

        else if(tru==0)
            cout << "It is not a prime word." << endl;
        }
}
