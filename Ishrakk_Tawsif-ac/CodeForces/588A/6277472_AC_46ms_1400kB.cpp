#include<bits/stdc++.h>
using namespace std;
int main(){


    int days,temp;
    double ans;
        while(scanf("%d", &days) != EOF){

            vector<int>req_meat;
            vector<int>price;
            ans=0;

            for(int i=0; i<days; i++){
                scanf("%d", &temp);
                req_meat.push_back(temp);
                scanf("%d", &temp);
                price.push_back(temp);
            }
                for(int i=0; i<days; ){

                    if(price[i]<price[i+1] && i<days-1){
                        ans += (req_meat[i]*price[i]);
                            temp = i;
                            i++;
                            while(price[temp]<price[i] && i<days){
                                ans += (req_meat[i]*price[temp]);
                                i++;
                            }
                    }
                    else{
                        ans += (req_meat[i]*price[i]);
                        i++;
                    }
                }
                printf("%.0lf\n", ans);
        }
return 0;
}
