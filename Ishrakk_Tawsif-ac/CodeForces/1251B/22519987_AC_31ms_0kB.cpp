#include <stdio.h>

char ch[53][53];
int cntone[53],cntzero[53],one,zero;

void calc(int ind){
    //int one = 0,zero = 0;
    //printf("....%s\n",ch[ind]);
    for(int i=0; ch[ind][i]!= '\0'; i++){
        if(ch[ind][i] == '0') cntzero[ind] ++;
        else cntone[ind] ++;
    }//printf("%d %d %d\n", ind,cntone[ind],cntzero[ind]);
    one += cntone[ind];
    zero += cntzero[ind];
}

//int checkDiff(int a,int b){
//    int now = (a - b);
//    if(now<0) now = (now * -1);
//    return (now<=1);
//}

void clearcnt(){
    one = zero = 0;
    for(int i=0; i<53; i++){
        cntone[i] = cntzero[i] = 0;
    }
}

int main(){
//freopen("out_.txt","w",stdout);
    int q,n;

    scanf("%d", &q);

    for(int qq=1; qq<=q; qq++){
        scanf("%d", &n);

        clearcnt();

        int res = 0;//printf("ok\n");
        for(int j=1; j<=n; j++){
            scanf(" %s", &ch[j]);//printf("vitore: %s\n", ch[j]);
            calc(j);
        }

        for(int i=1; i<=n; i++){
            if((cntone[i]+cntzero[i])%2){
                if(cntone[i]) cntone[i] --;
                else cntzero[i] --;
            }

            if((cntone[i] + cntzero[i])<=one) one -= (cntone[i] + cntzero[i]),res++;
            else if((cntone[i] + cntzero[i]<=zero)) zero -= (cntone[i] + cntzero[i]),res++;
            else{
                if((cntone[i]+cntzero[i])<=(one+zero)){
                    int sz = 0,fl = 1;
                    for(int j=0; ch[i][j]!='\0'; j++) sz ++;
                    
                    if(sz%2)  sz --;
                        for(int j=0; j<sz; j++) {
                            if((j%2)) continue;
                            if(one>=2) one -= 2;
                            else if(zero>=2) zero -= 2;
                            else fl = 0;
                        }
                        if(fl) res++;
                }
            }
        }
        printf("%d\n", res);
    }

    return 0;
}