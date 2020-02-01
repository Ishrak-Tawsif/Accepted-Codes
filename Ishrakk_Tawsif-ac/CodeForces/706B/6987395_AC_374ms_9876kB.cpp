#include<bits/stdc++.h>
using namespace std;

int x[1000005];
map <long long, int> mm;

int binary_search(int s_value,int left,int right){

    /*int mid=(beg+end)/2;
    //cout << mid << endl;
        if(x[mid] == s_value) return mid;
        else if(beg==end && s_value!=x[mid]) return mid;
        else if(x[mid]<s_value){
            beg=mid+1;
            binary_search(s_value,beg,end);
        }else{
            end=mid;
            binary_search(s_value,beg,end);
        }*/
        int mid,ans;
        while(left<=right)
                {
                    mid=(left+right)/2;
                    if(x[mid]<=s_value)
                    {
                        ans=mid;
                        left=mid+1;
                    }
                    else
                    {
                        right=mid-1;
                    }
                }
                return ans;
}

int main(){

    int n,q;

        scanf("%d", &n);

            for(int i=0; i<n; i++){ scanf("%d", &x[i]); mm[x[i]]++;}//cout << m[x[0]] << endl;
            sort(x, x+n);
        scanf("%d", &q);
        long int m;
            for(int i=0; i<q; i++){
                    scanf("%d", &m);

                        if(m >= x[n-1]) cout << n << endl;
                        else if(m<x[0]) cout << "0" << endl;
                        else{
                             cout << binary_search(m,0,n-1)+1 << endl;
                        }
            }
return 0;
}