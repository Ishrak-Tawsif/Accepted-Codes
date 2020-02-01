#include<bits/stdc++.h>
using namespace std;

int sum[103];

int main()
{
    int n,arr[103],fl=0;
    memset(sum,0,sizeof(sum));
        while(scanf("%d", &n) == 1)
        {
            //fl=0;
            for(int i=0; i<n; i++) {
                    scanf("%d", &arr[i]);
                    ///if(arr[i]!=0) fl=1;
                    if(i==0)sum[i]=arr[i];
                    else sum[i] += arr[i]+sum[i-1];//cout<<sum[i] <<endl;
            }
            /*if(fl==1){
                printf("YES\n");
                printf("1\n1 %d\n",n);
            }else{
                printf("NO\n");
            }*/

            //else{
                if(sum[n-1]!=0){
                    printf("YES\n");
                    printf("1\n1 %d\n",n);
                }
                else{
                int fl=0;
                for(int i=0; i<n-1; i++)
                {
                    if(sum[i]!=0 && sum[n-1]-sum[i]!=0)
                    {
                        fl=1;
                        printf("YES\n2\n");
                        printf("1 %d\n",i+1);
                        printf("%d %d\n",i+2,n); break;
                    }
                }
                if(fl==0) printf("NO\n");
            }
        }
    return 0;
}