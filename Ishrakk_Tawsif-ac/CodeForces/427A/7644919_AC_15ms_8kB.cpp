#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,p,c,temp,ans;
        scanf("%d", &n);
        ans=0;p=0;
        for(int i=0; i<n; i++){
            scanf("%d", &temp);

                if(temp != -1) p+=temp;
                else if(temp==-1){
                    if(p==0)ans++;
                    else p--;//cout<<p<<endl;
                }
        }
        cout<<ans <<endl;
return 0;
}