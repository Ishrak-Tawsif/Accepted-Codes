#include<bits/stdc++.h>
using namespace std;


int main(){

    int x,y,tc;
        scanf("%d", &tc);
            while(tc--){
                scanf("%d %d", &x,&y);
                    int temp=max(x,y);
                        cout<<temp*temp<<endl;
            }
return 0;
}