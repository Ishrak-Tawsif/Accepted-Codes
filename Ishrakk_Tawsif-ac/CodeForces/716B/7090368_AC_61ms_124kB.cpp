#include <bits/stdc++.h>
using namespace std;


int main(){

    string str;
    bool arr[27];
        cin>> str;
        int len = str.length();

            for(int i=0; i<len; i++){

                int ques=0,alph=0;
                queue <int> q;
                memset(arr,0,sizeof(arr));

                for(int j=i; j<i+26 && j<len; j++){
                    if(str[j] == '?'){ques++; q.push(j);}
                    else if(arr[str[j]-65] == 0) {arr[str[j] - 65] = 1; alph++;}
                    else break;
                }

//cout << alph << " " <<ques << " " << len <<endl;
                    if(alph + ques == 26){//cout << "ok :) " << endl;
                        for(int j=0; j<26; j++){
                            if(arr[j] == 0) {str[q.front()] = (char) j+65; q.pop();}
                        }
                        for(int j=0; j<len; j++){
                            if(str[j] == '?') str[j] = 'A';
                        }
                        cout << str << endl;
                        return 0;
                    }

            }
        cout << "-1" << endl;
return 0;
}