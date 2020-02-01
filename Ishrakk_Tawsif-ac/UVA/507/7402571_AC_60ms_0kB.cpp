#include<bits/stdc++.h>
using namespace std;


int main(){

    int routes,n;
        scanf("%d", &routes);

            for(int rr=1; rr<=routes; rr++){
                scanf("%d", &n);

                    int arr[n+1],sum=0,start=1,end_=1,max_=0,diff,diff2,temp=1;
                    for(int i=1; i<n; i++) scanf("%d", &arr[i]);
                        for(int i=1; i<n; i++){
                            //scanf("%d", &arr[i]);
                            sum+=arr[i];

                               if(sum>max_){
                                    start=temp;
                                    max_=sum;
                                    end_=i+1;
                               }
                               else if(sum==max_){
                                    diff=end_-start;
                                    diff2=(i+1)-temp;
                                    if(diff<diff2){
                                        max_=sum;
                                        start=temp;
                                        end_=i+1;
                                    }
                               }
                               if(sum<0){
                                    sum=0;
                                    temp=i+1;
                                    //end_=i+1;
                               }
                        }//cout<<max_<<endl;
                  if(max_) printf("The nicest part of route %d is between stops %d and %d\n",rr,start,end_);
                  else printf("Route %d has no nice parts\n",rr);
            }
return 0;
}