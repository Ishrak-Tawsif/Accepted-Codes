#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,cnt[100005];
        scanf("%d", &n);
            int h[n+1],aw[n+1];
                memset(cnt,0,sizeof(cnt));
                for(int i=0; i<n; i++){
                    scanf("%d %d", &h[i], &aw[i]);
                    cnt[h[i]]++;
                    }

                    for(int i=0; i<n; i++){
                        printf("%d %d\n", (n-1)+cnt[aw[i]], (n-1)-cnt[aw[i]]);
                    }

return 0;
}