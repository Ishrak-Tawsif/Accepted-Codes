#include<bits/stdc++.h>
using namespace std;


int main(){

    int a,b;

        while((scanf("%d %d", &a, &b))){
            int arr[a+1],in=-1;
            if(a==0 && b==0) break;
            else if(a<b) printf("0\n");
            else if(a == b) printf("1\n");
            else{
                int _min = min(b,a-b);
                int max_ = max(b,a-b);

                    for(int i= max_+1; i<=a; i++) arr[++in] = i;
                    int m[_min+1],inn=-1;
                    for(int i=2; i<=_min; i++) m[++inn] = i;

                        for(int i=0; i<=inn; i++){
                            for(int j=0; j<=in; j++){
                                if((!(arr[j]%m[i])) && m[i]!=1){
                                    arr[j] /= m[i];
                                    m[i]=1;
                                    break;
                                }
                            }
                        }
                        long long int ans , s1=1, s2=1;
                        for(int i=0; i<=in; i++){
                            s1 *= (long long int) arr[i];
                        }

                        for(int i=0; i<=inn; i++){
                            s2 *= (long long int) m[i];
                        }
                        printf("%lld\n", s1/s2);
            }
        }
return 0;
}