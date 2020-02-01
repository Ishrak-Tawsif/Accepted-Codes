#include<bits/stdc++.h>
using namespace std;

vector <long long> divi;
vector <long long> sqr;

void pre_gen(){
    sqr.clear();//int i;
    for(long long i=2; i*i<=1000000000000; i++){
        long long temp = (long long) i*i;
        sqr.push_back(temp);
    }//cout<<i<<endl;
}

void divisor(long long n){
    long long i;
    for(i=1; i*i<n; i++){ //cout<<i<<endl;
        if(n%i == 0){//if(i==16) cout<<n/i<<endl;
            divi.push_back(i);
            divi.push_back(n/i);
        }
    } if(n%i == 0) divi.push_back(i); //cout<<i<<endl;
}

int main(){
    pre_gen();
    long long n;
//cout<<"khbrfg"<<endl;
        while(scanf("%lld", &n) == 1){
            divi.clear();
            //cout<<divi.size()<<endl;
            divisor(n);
            sort(divi.begin(), divi.end());//for(int i=divi.size()/2; i<divi.size(); i++) cout<<divi[i]<<endl;
            for(int i=divi.size()-1; i>=0; i--){
                long long k=divi[i],fl=1;//cout<<k<<endl;
                    for(int j=0; sqr[j]<=k; j++){//cout<<sqr[j]<<endl;
                        if(k%sqr[j] == 0) {fl=0; break;}
                    }//cout<<fl<<endl;
                    if(fl==1){cout<<k<<endl; break;}
            }
        }
return 0;
}