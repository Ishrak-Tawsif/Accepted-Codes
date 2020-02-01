#include<bits/stdc++.h>
using namespace std;


int main(){

    string p;

        while(cin>>p){
            int len=p.length();

                int fl=0;
                for(int i=0; i<len; i++){
                    if(p[i] == 'H' || p[i] == 'Q' || p[i] == '9') {fl=1; break;}
                }
                if(fl == 1) cout<<"YES"<<endl;
                else cout << "NO"<<endl;

        }
return 0;
}