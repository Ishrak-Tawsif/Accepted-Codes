#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;
    char sign[21];
        scanf("%d %s", &n, &sign); //cout << n << "   " << sign << endl;
        int k = strlen(sign),till,nn=n,kk=k;

            if(n%k == 0) till = k;
            else till = n%k;//cout << till << " " << k << endl;

                long long ans = n;
                    for(int i=1; ; i++){
                        //cout << nn << endl;system("pause");
                            if(nn == till) {break;}
                            else{
                                int kk = k * i;//cout << i << endl;
                                nn = n - kk;
                                ans *= nn;
                            }
                    }
                    printf("%lld\n", ans);
return 0;
}