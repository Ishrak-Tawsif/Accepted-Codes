#include<bits/stdc++.h>
using namespace std;

long int arr[517];

void pre_gen()
{
    for(int i=1; i<515; i++)
    {
        string ch;
            int in=1,temp=i;
            while(temp!=0){
                ch += (temp%2)+'0';//cout<<temp%2;
                temp/=2;
            }//cout<<ch<<endl;
            for(int j=ch.size()-1; j>=0; j--) {
                if(ch[j]!='0')arr[i] = (arr[i]*10) + (ch[j]-'0');
                else arr[i]*=10;
                in*=10;
            }
            //for(int i=1; i<=1000000000;i++)
    }
}

int main()
{
    pre_gen();
    int n;

        while(scanf("%d", &n) == 1)
        {
            int cnt=0,in=0;
                while(arr[++in]<=n) cnt++;
                cout<<cnt <<endl;
        }
    return 0;
}