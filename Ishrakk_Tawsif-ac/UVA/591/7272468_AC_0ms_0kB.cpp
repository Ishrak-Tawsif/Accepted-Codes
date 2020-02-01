#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long int


int main(){

   int s,testcase=0;

        while(cin>> s && s){
            int b[s+1],tot=0;
                for(int i=0; i<s; i++){cin>> b[i]; tot += b[i];}

                    sort(b,b+s);//for(int i=0; i<s; i++) cout << b[i] << endl;
                    int len= tot/s,mov=0;
                        for(int i=0,j=s-1; i<j;){
                            if(b[i]<len && b[j]>len){//cout << j << endl;
                                int temp = min(b[j]-b[i],min((b[j]-len),(len-b[i])));
                                b[i] += temp;
                                b[j] -= temp;
                                mov+=temp;
                            }//cout << b[i] << " " << i << " " << b[j] << " " << j << endl;
                               //system("pause");
                               if(i<j){
                                if(b[i]==len) i++;
                                if(b[j]==len) j--;
                               }
                               else break;
                            //cout << i << " " << j << endl;
                        }
                        cout << "Set #" << ++testcase << endl << "The minimum number of moves is " << mov <<"." << endl<<endl;
        }
return 0;
}