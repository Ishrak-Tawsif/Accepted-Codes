#include<bits/stdc++.h>
using namespace std;

int main(){
///odbhsd
    string str[103];
    int testcase,n,temp;
        cin>> testcase;

            while(testcase--){
                cin>> n;
                temp=-1;
                    for(int i=0; i<n; i++){
                        cin>> str[i]; //cout << str[i] << endl;
                        if(str[i][0] != '#') temp = i;
                    }
                    if(temp == -1){
                        cout << str[0];
                        for(int i=1; i<n; i++) cout << " " << str[i];
                        cout << endl;
                    }
                    else{
                        if(temp+1<n)cout << str[temp+1];
                        for(int i=temp+2; i<n; i++) cout << " " << str[i];
                        if(temp!=n-1)cout << " " << str[temp];else cout << str[temp];
                        for(int i=0; i<temp; i++) cout << " " << str[i];
                        cout << endl;
                    }
            }
return 0;
}