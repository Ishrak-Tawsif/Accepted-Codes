#include<bits/stdc++.h>
using namespace std;


int row,col,arr[9],ans[9],cnt;

void backtrack(int ind){
//cout<<ind<<endl;
    if(ind == 9 && ans[row]==col){//cout<<ind<<endl;
        int fl=0;
        for(int i=1; i<=8; i++){
            int t_r=i;
            int t_c=ans[i];
                for(int j=1; j<=8; j++){
                    if(j!=i){
                        int rr=j;
                        int cc=ans[j];
                            if(t_r==rr || t_c==cc) {fl=1;break;}
                            if((t_r+t_c)==(rr+cc) || (t_r-t_c)==rr-cc){fl=1; break;}
                    }
                }
                if(fl==1) break;
        }
        if(fl==0){
            printf("%2d      %d", ++cnt,ans[1]);
            for(int i=2; i<=8; i++){
                printf(" %d", ans[i]);
            }printf("\n");
        }
    }

    for(int j=1; j<=8; j++){
        if(arr[j] == 0){
            arr[j]=1;
            ans[ind]=j;
            backtrack(ind+1);
            arr[j]=0;
        }
    }
}

int main(){

    int N=0,tc;
    char cc='#';
    cin>>tc;
    while(1){
       scanf("%d %d", &col,&row);
       cnt=0;
       if(N>0) printf("\n");
       N++;
       printf("SOLN       COLUMN\n");
       printf(" %c      1",cc);
       for(int i=2; i<=8; i++) printf(" %d",i);
       printf("\n\n");
       for(int i=1; i<=8; i++){
            ans[1]=i;
            arr[i]=1;
            backtrack(2);
            arr[i]=0;
       }//cout<< tc << " " << N <<endl;
       if(tc==N) break;
    }
return 0;
}