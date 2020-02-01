#include<iostream>
#include<cmath>
using namespace std;
int main(){

    int current_channel,desired_channel;

        while(cin>> current_channel >>desired_channel && current_channel>=0 && desired_channel>=0){

            if(desired_channel<current_channel)
                swap(current_channel,desired_channel);

                if((abs(desired_channel-current_channel)) < ((100-desired_channel)+current_channel))
                    cout << (abs(desired_channel-current_channel)) << endl;
                else
                    cout << ((100-desired_channel)+current_channel) << endl;
        }
return 0;
}