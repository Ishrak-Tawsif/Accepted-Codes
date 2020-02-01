#include<bits/stdc++.h>
using namespace std;
map <long long,int>m;

int main(){

    string str;
    int testcase;

            cin>> testcase;

                while(testcase --){
                    cin>> str;//cout << str << endl;
                    int len = str.length(),in=1;
                    double ans = 0.0;

                            for(int i=0; i<len; ){
                                char c = str[i];i++;
                                in = 1;

                                    if(str[i]-'0'>=0 && str[i]-'0'<=9){
                                        in = str[i] - '0'; i++;

                                        while(str[i]-'0'>=0 && str[i]-'0'<=9){
                                            in *= 10;
                                            in += str[i] - '0';
                                            i++;
                                        }
                                    }
                                if(c == 'C') ans += in * 12.01;
                                else if(c == 'H') ans += in * 1.008;
                                else if(c == 'O') ans += in * 16.00;
                                else ans += in * 14.01;
                            }
                        printf("%.3lf\n", ans);
                }

return 0;
}