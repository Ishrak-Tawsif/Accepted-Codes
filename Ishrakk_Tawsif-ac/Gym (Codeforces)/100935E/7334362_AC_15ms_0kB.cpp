#include<bits/stdc++.h>
using namespace std;


int main()
{

    int testcase,input[23];
        scanf("%d",&testcase);
        for(int tt=1; tt<=testcase; tt++){

            int sum=0;
            for(int i=1;i<=10;i++){
                scanf("%d",&input[i]);
                sum+=input[i];
            }

            sort(input+1,input+1+10);

                int ans[7];
                    ans[3]=(sum/4) - (input[1]+input[10]);
                    ans[1]=input[2] - ans[3];
                    ans[2]=input[1] - ans[1];
                    ans[5]=input[9] - ans[3];
                    ans[4]=input[10] - ans[5];
                        printf("Case %d: %d %d %d %d %d\n",tt,ans[1], ans[2], ans[3], ans[4], ans[5]);
        }
   return 0;
}