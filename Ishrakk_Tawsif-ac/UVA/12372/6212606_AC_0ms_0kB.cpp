#include<iostream>
using namespace std;
int main(){

    int testcase,l,w,h;
        cin>> testcase;
            for(int t=1; t<=testcase; t++){

                cin>> l>> w >>h;
                    if(l<=20 && w<=20 && h<=20)
                        cout << "Case " << t << ": " << "good" << endl;
                    else
                        cout << "Case " << t << ": " << "bad" << endl;
            }
}
