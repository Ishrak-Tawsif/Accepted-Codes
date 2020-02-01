#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

    string s;
    int len,cnt[131];
//....
        while(cin>> s){
            memset(cnt,0,sizeof(cnt));
            len = s.length();

                for(int i=0; i<len; i++) cnt[(int)s[i]]++;
                sort(cnt, cnt+126);

                int cnnt=0,temp=cnt[124]+cnt[125];

                for(int i=0; i<130; i++) {if(cnt[i] !=0) {/*cout << (char)i << " " << cnt[i] <<endl;*/cnnt+=cnt[i];}}
                if(cnnt<=2) cout << 0 << endl;
                else cout << cnnt-temp << endl;
        }
return 0;
}