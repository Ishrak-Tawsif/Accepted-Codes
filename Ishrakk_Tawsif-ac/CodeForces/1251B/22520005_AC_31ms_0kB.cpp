#include <stdio.h>

char ch[53][53];
int cntone[53],cntzero[53],one,zero;

void calc(int ind){
    for(int i=0; ch[ind][i]!= '\0'; i++){
        if(ch[ind][i] == '0') cntzero[ind] ++;
        else cntone[ind] ++;
    }
    one += cntone[ind];
    zero += cntzero[ind];
}

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

        int res = 0;
        for(int j=1; j<=n; j++){
            scanf(" %s", &ch[j]);
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