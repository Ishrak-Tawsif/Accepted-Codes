#include<bits/stdc++.h>
using namespace std;

#define ll long long int


int main(){

    int testcase,tala,temp;
    string s;
    int sf,br;

        scanf("%d %d", &testcase,&tala);
            sf=1,br=tala;
            while(testcase--){
                cin>> temp>> s;

                    if(s == "SAFE") sf = max(sf,temp);
                    else br = min(br,temp);
            }

             cout << sf+1 << " " << br-1 << endl;
            /*else if(br == INT_MAX) cout << sf+1 << " " << sf << endl;
            else{
                int tt = abs(sf-br)-1;int brr = (tala-br)+1;
                double t1 = (double)(((sf)*1.0)/(tala*1.0));
                double t2 = (double)(((brr)*1.0)/(tala*1.0));

                    if(t1 == t2) cout << sf+tt/2 << "// " << br-tt/2 << endl;
                    else if(t1<t2) cout << sf << ".. " << br-(tt/2) << endl;
                    else cout << sf+(tt/2) << " ,," << br << endl;
            }*/

return 0;
}