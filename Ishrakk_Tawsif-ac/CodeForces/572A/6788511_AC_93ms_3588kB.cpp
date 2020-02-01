#include<bits/stdc++.h>
using namespace std;

int main(){

     int n1,n2,m,k;
        scanf("%d %d", &n1, &n2);
        scanf("%d %d", &k, &m);

            long long int arr1[n1+5],arr2[n2+5];bool fl=true;

                for(int i=0; i<n1; i++) scanf("%lld", &arr1[i]);
                for(int i=0; i<n2; i++) scanf("%lld", &arr2[i]);

                    /*for(int l=0; l<k; l++){
                            for(int j=0; j<m; j++){
                                if(arr1[l]>=arr2[j]){
                                    fl=false;break;
                                }
                        }
                    }*/
                    sort(arr1, arr1+n1);
                    sort(arr2, arr2+n2);


                    if(arr1[k-1]>=arr2[n2-m]) printf("NO\n"); ///n1-k, m-1
                    else printf("YES\n");
    return 0;
}
