#include<bits/stdc++.h>
using namespace std;

string fibo[5003];

void pre_gen(){

    fibo[0]='0',fibo[1]='1'; fibo[2]='1';

        for(int i=3; i<=5000; i++){
            int len1=fibo[i-1].length(),len2=fibo[i-2].length(),carry=0,tl1,tl2;;
            string str;
                for(int k=len1-1,l=len2-1; k>=0 && l>=0; k--,l--){
                    int t1=fibo[i-1][k]-'0',t2=fibo[i-2][l]-'0';
                    int temp=t1+t2+carry;
                        str +=  temp%10 + '0';//cout<<temp<<endl;
                        temp/=10;carry=0;
                        if(temp!=0) carry=temp;//cout<<str<<endl;
                        tl1=k,tl2=l;
                }//cout<<str<<endl;
                if(len1!=len2){
                    if(len1<len2){
                        //int t_l=len2-len1;
                            for(int k=tl2-1; k>=0; k--){
                                int t1=fibo[i-2][k]-'0';
                                int temp=t1+carry;
                                    str+=temp%10 + '0';
                                    temp/=10;carry=0;
                                    if(temp!=0) carry=temp;
                            }//cout<<str<<endl;
                    }
                    else{
                        int t_l=len1-len2;
                            for(int k=tl1-1; k>=0; k--){
                                int t1=fibo[i-1][k]-'0';//cout<<t1<<endl;
                                int temp=t1+carry;
                                    str+=temp%10 + '0';
                                    temp/=10;carry=0;
                                    if(temp!=0) carry=temp;
                            }//cout<<str<<endl;
                    }
                }//cout<<str<<" "<<carry<<endl;
                if(carry!=0) str+= carry + '0';
                //fibo[i]=str;
                for(int kk=str.length()-1; kk>=0; kk--) fibo[i]+=str[kk];
        }
}

int main(){
    pre_gen();
    int n;
        while(cin>> n)
            cout<<"The Fibonacci number for "<<n<<" is "<<fibo[n]<<endl;
return 0;
}