#include <stdio.h>
#define ll long long int

#define mx 1000000005

int getStartPortion(int n){
    int ss = 0,en = 0,nxt = 2;
    while(1){
        //if(ss == 1) en = (ss + nxt);
        //else {
            ss = en+1;
            en = (en + nxt);
        //}
        if(n>=ss && n<=en) break;
        nxt += 2;
    }
    //printf("....%d... %d ... %d .... %d \n",n,en,nxt,((en-(nxt/2))));
    if(n<=(en-(nxt/2))) return 1;
    return 0;
}

void init(int n){
    int range = 0,val = 1,ans = 0;
    while(range<n){
        range += (val*2);
        val++;
        ans += 2;
    }
    if(!getStartPortion(n)) ans++;
    printf("%d\n", ans);
}

int main(){
    int n;

    while(scanf("%d", &n) == 1) init(n);

    return 0;
}