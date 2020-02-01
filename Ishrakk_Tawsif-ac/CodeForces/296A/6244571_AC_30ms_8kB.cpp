#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,array[101],count,max,temp;

        while(cin>> n){
            for(int i=0; i<n; i++)
                cin>> array[i];

            sort(array, array+n);
                max=0;
                //for(int i=0; i<n; i++) cout << array[i] << endl;
                for(int i=0; i<n; ){
                    temp=array[i];
                    count=0;
                        while(array[i] == temp && i<n){
                            count ++;
                            //cout << array[i] << " arr " << endl;
                            i++;
                        }
                            if(count>max) max=count;
                            //cout << max << " .." << endl;
                }
                //cout << count << " " << max << endl;
                //max += 1;
                    if(max <= ((n+1)/2)) cout << "YES" << endl;
                    else cout << "NO" << endl;
        }
return 0;
}
