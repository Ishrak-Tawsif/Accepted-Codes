#include<bits/stdc++.h>
using namespace std;

int main(){

    string str;
    int cnt[7];

        while(cin>> str){
        int len = str.length();
        memset(cnt,0,sizeof(cnt));

            for(int i=0; i<len; ){
                if(cnt[0]>=1 && cnt[1]>=1 && cnt[2]>=2 && cnt[3]>=1) break;
                if(str[i] == 'h') {cnt[0] ++; i++;}
                else if(str[i] == 'e' && cnt[0]!=0) {cnt[1]++; i++;}
                else if(str[i] == 'l' && cnt[0] != 0 & cnt[1]!=0) {cnt[2]++; i++;}
                else if(str[i] == 'o' && cnt[0] != 0 & cnt[1]!=0 && cnt[2]>=2) {cnt[3]++; i++;}
                else {i++;}
            }
            if(cnt[0]>=1 && cnt[1]>=1 && cnt[2]>=2 && cnt[3]>=1)printf("YES\n");
            else printf("NO\n");
        }
return 0;
}