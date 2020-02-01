#include<bits/stdc++.h>
using namespace std;

int dir_r[]={-1,1,1,-1,0,0,1,-1};
int dir_c[]={-1,1,-1,1,-1,1,0,0};

int main(){

    int tc,n;
        scanf("%d", &tc);
            while(tc--){
                string str[101];
                scanf("%d", &n);
                    int arr[n+1],max_=INT_MIN,in=-1;
                    for(int i=0; i<3; i++) {
                        cin>> str[i];
                        if(i==1){
                            int len=str[i].length();
                            for(int j=0; j<len; j++){if(str[i][j]=='X') arr[++in]=j;}
                        }

                    }//cout<<in<<endl;
                    for(int i=0; i<=in; i++){
                        int r=1,c=arr[i],temp=0;//cout<<r<<" .. "<<c<<endl;
                            for(int i=0; i<8; i++){
                                int tr=r+dir_r[i];
                                int tc=c+dir_c[i];//cout<<tr<<" "<<tc<<endl;
                                   if(tr>=0 &&tr<3 && tc>=0 && tc<str[1].length()){
                                    if(str[tr][tc]=='*') {temp++;}
                                    }
                            }
                        if(temp>max_) max_=temp;
                    }
                    cout<<max_*4<<endl;
            }
return 0;
}