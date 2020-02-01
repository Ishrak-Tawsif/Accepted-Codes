#include<bits/stdc++.h>
using namespace std;
int main(){

    int i, j, len1, len2;
    char Str1[1000001],Str2[1000001];

    cin>> Str1>>Str2;
    len1 = strlen(Str1);
    len2 = strlen(Str2);

        for(i = 0; Str1[i] == '0'; ++i);
        for(j = 0; Str2[j] == '0'; ++j);

        //cout <<i << " "<<len1<<endl;
        //cout <<j << " " << len2<<endl;

        if(len1 - i < len2 - j) {
            puts("<");
            return 0;
        }
        if(len1 - i > len2 - j) {
            puts(">");
            return 0;
        }

            for(; Str1[i] != '\0'; ++i, ++j) {
                if(Str1[i] < Str2[j]) {
                    puts("<");
                    return 0;
                }
                    if(Str1[i] > Str2[j]) {
                        puts(">");
                        return 0;
                    }
            }
        puts("=");

    return 0;

}
