#include<iostream>
using namespace std;
int main(){

    long long int n,k,temp,temporary;
    while(cin >>n >>k && k>1){
        temporary = n;
        temp = 0;
       while(temporary>=k){
        temp =temp + (temporary/k);
        temporary = (temporary%k) + (temporary/k);
        //temporary = temp + temporary;
       }
        cout << temp+n << endl;
    }

}
