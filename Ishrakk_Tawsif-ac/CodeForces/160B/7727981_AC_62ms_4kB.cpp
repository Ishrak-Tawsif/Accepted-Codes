#include<bits/stdc++.h>
using namespace std;


int main(){

    string s;
    int cnt1=0, cnt2=0,len,n;

            while(cin>> n){

                cin>> s;
                cnt1=0; cnt2=0; len=s.length();
                int fir[101],sec[101],in=-1;

                    for(int i=0,j=len-1; i<len/2; i++,j--){
                        fir[++in]=s[i]-'0';
                        sec[in]=s[j]-'0';
                    }
                    sort(fir, fir+n);
                    sort(sec, sec+n);
                    for(int i=0; i<n; i++){
                        if(fir[i]<sec[i]) cnt1++;
                        if(fir[i]>sec[i]) cnt2++;
                    }
                    if(cnt1 == n || cnt2 == n) cout<< "YES" << endl;
                    else cout << "NO" << endl;
            }

return 0;
}