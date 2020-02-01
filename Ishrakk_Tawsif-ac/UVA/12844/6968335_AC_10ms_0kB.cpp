#include<bits/stdc++.h>
using namespace std;


int main(){

    int testcase,arr[11],ans[7];

        while(cin >>testcase){

            for(int t=1; t<=testcase; t++){

                int sum=0;
                for(int i=0; i<10; i++) {cin>> arr[i]; sum += arr[i];}
                sum /= 4;
                ans[3] = sum - (arr[0]+arr[9]);
                ans[1] = arr[1]-ans[3];
                ans[2] = arr[0] - ans[1];
                ans[5] = arr[8] - ans[3];
                ans[4] = sum - (ans[1]+ans[2]+ans[3]+ans[5]);
                    cout << "Case " << t << ": " << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << " " << ans[5] << endl;
            }
        }
return 0;
}
