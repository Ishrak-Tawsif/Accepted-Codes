#include<bits/stdc++.h>
using namespace std;

int arr[10],ans[10],track[11],n;
bool fn;

void backtrack(int ind){
    //if(fn == 1) return;
    if(ind==5){
        long int temp=0,mul=1;
            for(int j=4; j>=0; j--){temp += ans[j]*mul; mul*=10;}
            //cout<<"\n"<<temp<<endl;
            if(temp*n<=99999){
                memset(track,0,sizeof(track));
                int tt=temp*n;
                    for(int j=0; j<5; j++){
                        track[ans[j]]=1;
                        track[tt%10]=1;
                        tt/=10;
                    }
                int k=0;
                    for(int j=0; j<10; j++){
                        if(track[j]==1) k++;
                    }//cout<<k<<" " <<fn<<endl;
                if(k==10){
                    fn=1;
                    printf("%d / ",temp*n);
                    for(int i=0; i<5; i++)printf("%d", ans[i]);
                    printf(" = %d\n",n);
                }
            }
            return;
    }

    for(int i=0; i<10; i++){
        if(arr[i] == 0){
            arr[i]=1;
            ans[ind]=i;
            backtrack(ind+1);
            arr[i]=0;
        }
    }
}

int main(){
    int N=0;
    while(cin>>n && n){
        fn=0;
        if(N>0) printf("\n");
        N++;
        for(int i=0; i<5; i++){
            arr[i]=1;
            ans[0]=i;
            //cout<<fn<<endl;
            backtrack(1);
            arr[i]=0;
        }
    if(fn==0) printf("There are no solutions for %d.\n",n);
    }
return 0;
}