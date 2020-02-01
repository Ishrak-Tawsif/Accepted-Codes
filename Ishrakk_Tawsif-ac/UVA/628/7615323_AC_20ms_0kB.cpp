#include<bits/stdc++.h>
using namespace std;

int len,n,arr[11];
string str[101],rule;

void backtrack(int ind, int n, int i){

    if(ind == n){
        int in=-1;
        for(int j=0; j<len; j++){
            if(rule[j] == '0') printf("%d", arr[++in]);
            else cout<<str[i];
        }
        printf("\n");
    return;
    }

    for(int j=0; j<10; j++){
        arr[ind]=j;
        backtrack(ind+1,n,i);
    }
}

int main(){
//-
    int wr,m;
        while(scanf("%d", &wr) == 1){

            for(int i=0; i<wr; i++) cin>> str[i];
                scanf("%d", &m);
                    for(int i=0; i<m; i++){
                        cin>> rule;
                        cout<<"--"<<endl;
                         len=rule.length();
                         n=0;
                            for(int i=0; i<len; i++) if(rule[i]=='0')n++;

                            for(int i=0; i<wr; i++){
                                backtrack(0,n,i);
                            }
                    }
        }
return 0;
}