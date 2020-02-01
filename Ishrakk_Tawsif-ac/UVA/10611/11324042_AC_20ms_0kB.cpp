#include<bits/stdc++.h>
using namespace std;

vector <int>arr; int type;

int bin_ser(int s_value,int end){

    int found=-1,mid, beg=1;

        while(found == -1 && beg<=end){
            mid=(beg+end)/2;//cout << mid << endl;
            if(arr[mid] == s_value) {found=mid; type=1;}
            else if(arr[mid]>s_value && arr[mid-1]<s_value) {found=mid;type=0;}
            else{
                if(arr[mid]>s_value) end=mid-1;
                else beg=mid+1;
            }
        }
    return found;
}

int main(){

    int n,q,qq,t;
        cin>> n;
            arr.push_back(0);
            for(int i=1; i<=n; i++) {cin>> t;arr.push_back(t);}
            arr.resize(distance(arr.begin(),unique(arr.begin(),arr.end()))); //cout << arr.size() <<endl;
            arr.push_back(0);

              cin>> q;

              for(int i=0; i<q; i++){

                        cin>> qq;
                        type=-1;
                        if(qq>arr[n]) {cout << arr[n] << " " << "X" << endl;continue;}
                        if(qq<arr[1]) {cout << "X" << " " << arr[1] << endl;continue;}
                        int ind = bin_ser(qq,arr.size()-1);//cout << arr[ind]<<" " <<type<< endl;

                        if(type==1){
                                if(arr[ind-1]!=0) cout << arr[ind-1] << " ";
                                else cout << "X" << " ";
                                if(arr[ind+1]!=0) cout << arr[ind+1] << endl;
                                else cout << "X" << endl;
                                //cout << arr[ind-1] << " " << arr[ind+1] <<endl;
                        }
                        else if(type==0){
                                //cout << arr[ind-1] << " " << arr[ind] << endl;
                                if(arr[ind-1]!=0) cout << arr[ind-1] << " ";
                                else cout << "X" << " ";
                                if(arr[ind]!=0) cout << arr[ind] << endl;
                                else cout << "X" << endl;
                        }
              }
    return 0;
}