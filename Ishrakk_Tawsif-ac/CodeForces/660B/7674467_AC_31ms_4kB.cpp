#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,m,fl=0;

        while(scanf("%d %d", &n,&m) == 2){

            fl=0;
            for(int i=1; i<=2*n; i++){
                if((2*n)+i<=m) {
                    if(fl==0) cout<<(2*n)+i;
                    else cout<<" " << (2*n)+i;
                    fl++;
                }
                if(i<=m) {
                        if(fl == 0) cout<<i;
                        else cout<<" " << i;
                        fl++;
                    }
            }
            cout<<endl;
        }
return 0;
}