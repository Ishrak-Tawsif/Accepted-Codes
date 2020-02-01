#include<bits/stdc++.h>
using namespace std;


int main(){

    int k,n,testcase;

        cin>> testcase;

            for(int tt=1; tt<=testcase; tt++){
                cin>> n>> k;
                long int sam[n+1],kad[n+1],loss[n+1];

                    for(int i=0; i<n; i++) cin>> kad[i];
                    for(int i=0; i<n; i++) cin>> sam[i];

                        long int p_sum=0,los_sum=0,in=-1;
                        for(int i=0; i<n; i++){
                            if(sam[i]>=kad[i]){
                                p_sum += sam[i]-kad[i];
                            }
                            else{
                                loss[++in] = kad[i]-sam[i];
                                los_sum += loss[in];
                            }
                        }//cout << ":)" << endl;
                        sort(loss, loss+(in+1));//cout << in << " " << p_sum << " " << los_sum << endl;
                        for(int i=in; i>=0 && k>0; i--,k--) los_sum -= loss[i];

                        if((p_sum - los_sum)>0)cout << "Case " << tt << ": " << p_sum - los_sum << endl;
                        else cout << "Case " << tt << ": " << "No Profit" << endl;
            }
return 0;
}