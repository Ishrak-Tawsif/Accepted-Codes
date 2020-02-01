#include<iostream>
using namespace std;
int main(){

    long int hasmat,opnent;

        while(cin>> hasmat>> opnent){

            if(opnent>hasmat)
                cout << opnent-hasmat << endl;
            else
                cout << hasmat-opnent << endl;
        }
return 0;
}
