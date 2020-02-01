#include<bits/stdc++.h>
using namespace std;

int main(){
  int testcase,n,d,min_,max_,temp,ans;
//set <int> ss; ss.insert(9);ss.insert(6); ss.insert(5); ss.erase(1);int o = ss.size();cout << o<< endl;
    scanf("%d", &testcase);

        for(int tt=1; tt<=testcase; tt++){
            scanf("%d %d", &n, &d);
            ans = INT_MIN;
                set <int> ss;int temp[n+1];
                for(int i=0; i<n; i++){
                    scanf("%d", &temp[i]);
                    ss.insert(temp[i]);
                        if(i >= (d-1)){
                             min_ = *ss.begin();
                             max_ = *ss.rbegin();
                                if(max_-min_>ans) ans = max_-min_;
                                ss.erase(temp[i-(d-1)]);
                        }
                }printf("Case %d: %d\n", tt,ans);
        }
return 0;
}