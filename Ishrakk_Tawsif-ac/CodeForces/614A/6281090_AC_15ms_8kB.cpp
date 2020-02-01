#include<bits/stdc++.h>
using namespace std;

/*
long long int ipow(int base, int pow){

    long long int ans = 1;

        while(pow != 0){
            ans *= base;
            pow --;
        }
    return ans;
}*/

int main(){

    long long int start,end,k,temp,ans[101];
    int count;
            while(scanf("%lld %lld %lld", &start, &end, &k) == 3){
                count=0;
                temp=k;
                if(start>end) swap(start,end);

                    if(start == 1) {ans[count]=1;count++;}
                    for(int i=0; i<63;i++){
                            if(k>=start && k<=end){
                                    ans[count]=k;
                                    count++;
                            }
                            if(k>end/temp) break;
                            k *= temp;
                    }
                    if(count == 0) printf("-1\n");
                    else {
                        for(int i=0; i<count; i++){
                            printf("%lld ", ans[i]);
                        }
                        printf("\n");
                    }
            }
return 0;
}
