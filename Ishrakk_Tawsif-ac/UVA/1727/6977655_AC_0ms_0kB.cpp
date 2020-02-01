#include<bits/stdc++.h>
using namespace std;


int main(){

    string month[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    //int day [] = {31, 28, 31, 30, 31, 30, 31, 31, 30,31, 30, 31};
    string day[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

        int testcase,ans;
        char m[5],d[5];
    //cout << month[1];
            while(cin>> testcase){

                while(testcase --){
                    cin>> m>> d;

                        ans=8;

                        if(m == month[1]) cout << ans << endl;
                        else{
                                if(m==month[0] || m==month[2] || m==month[4] || m==month[6] || m==month[7] || m==month[9] || m==month[11]){
                            //ans = 31/7;
                                if(d == day[3] || d == day[6]) ans += 1;
                                else if(d == day[4] || d == day[5]) ans += 2;
                                }
                                else{
                                    if(d == day[4] || d== day[6]) ans += 1;
                                    else if(d==day[5]) ans += 2;
                                }
                                 cout << ans  << endl;
                        }
                }
            }
   return 0;
}