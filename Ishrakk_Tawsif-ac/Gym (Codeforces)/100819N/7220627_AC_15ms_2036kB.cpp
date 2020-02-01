#include<bits/stdc++.h>
using namespace std;

#define ll long long int


int main(){

    int testcase,tala,temp;
    string s;
    int sf,br;

        scanf("%d %d", &testcase,&tala);
            sf=INT_MIN,br=INT_MAX;
            while(testcase--){
                cin>> temp>> s;

                    if(s == "SAFE") sf = max(sf,temp);
                    else br = min(br,temp);
            }
             br = min(br,tala); sf = max(sf,1);
             cout << sf+1 << " " << br-1 << endl;

return 0;
}