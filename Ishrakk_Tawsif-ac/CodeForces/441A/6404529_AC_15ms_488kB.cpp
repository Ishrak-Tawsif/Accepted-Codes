#include<bits/stdc++.h>
using namespace std;
int main(){

    int seller,item,ans[100010];
    int price,money;

        cin>> seller >>money;
            //cout << seller << " " << money << endl;
                int in=-1,flag;
                for(int i=0; i<seller; i++){
                    scanf("%d", &item);

                        flag=0;
                        for(int j=0; j<item; j++){
                            scanf("%d", &price);
                                if(price<money){
                                    flag=1;
                                }
                        }
                        if(flag == 1) ans[++in]=i+1;
                }
                //cout << ans[in] << endl;
                cout << in+1 << endl;
                if(in !=-1){
                    for(int i=0; i<=in; i++)
                        printf("%d ", ans[i]);
                printf("\n");
                }
return 0;
}
