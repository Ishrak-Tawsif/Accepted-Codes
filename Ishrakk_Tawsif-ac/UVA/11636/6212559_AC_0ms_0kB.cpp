#include<iostream>
using namespace std;

/*
long int ipow(int base,int pow){

    long int result=1;

        while(pow>0){

            result *= base;
            pow--;
        }
    return result;
}
*/
int main(){
    int number,cas=0;
        while(cin>> number && number>=0){
            cas++;
            for(int i=1,j=1; ; i*=2,j++){

                if(i>=number){
                    cout << "Case " << cas << ": " << --j << endl;
                    break;
                }
            }
        }
}
