#include<bits/stdc++.h>
using namespace std;


int main(){
//cout << (char) 65;
    int n,mod,len;
    char s[10000];
    //getchar();
        while(cin>> n && n){
            getchar();
            gets(s);//cout << s << endl;
//cout << "ljhf";
                //if(n == 0) break;
                if(n<0) {mod = 26+(n%26);}
                else mod = n%26;

                   len=strlen(s);

                        for(int i=0; i<len; i++){

                            if(isalpha(s[i])){
                                if(isupper(s[i])){
                                    int val = (int) s[i];//cout << (mod - (int)((int)'z'-(int)s[i])) << endl;
                                    if(val+mod>90) cout << (char)(('A'+ ((val+mod)-90))-1);
                                    else cout << (char) (s[i]+mod);
                                }
                                else{
                                    int val = (int) s[i];
                                    if(val+mod>122) cout << (char)(('a'+ ((val+mod)-122))-1);
                                    else cout << (char) (s[i]+mod);
                                }
                            }
                            else cout << s[i];
                        }
                        cout << endl;
        }
return 0;
}