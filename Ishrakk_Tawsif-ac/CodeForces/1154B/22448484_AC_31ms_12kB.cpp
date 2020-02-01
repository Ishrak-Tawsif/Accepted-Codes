#include <bits/stdc++.h>
using namespace std;

int ar[103],n;

int _abs(int val){
    if(val<0) return (val * -1);
    return val;
}

int check(int val){
    int now, uni = _abs(val-ar[1]);
    for(int i=2; i<=n; i++){
        now = _abs(val-ar[i]);//cout<<val<<" "<<uni<<endl;
        if(now != uni && now!=0) return 0;
    }
    return 1;
}

int main(){

    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &ar[i]);
    }

    sort(ar,ar+n+1);

    int st = 0,en = 203,mid,res = 1005;

    for(int i=0; i<=205; i++){
        mid = i;
        if(check(mid)){
            res = min(res,_abs(ar[1]-mid));//cout<<ar[1]<<" "<<mid<<endl;
            //break;
        }
        //else st = mid + 1;
    }
    if(res != 1005)printf("%d\n", res);
    else printf("-1\n");
    return 0;
}