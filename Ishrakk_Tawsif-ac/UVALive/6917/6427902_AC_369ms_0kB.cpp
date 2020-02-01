#include<bits/stdc++.h>
using namespace std;
int main(){

        int testcase,n;
        string str;
            scanf("%d", &testcase);

                while(testcase --) {
                    char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",a,b;

                        cin>> str;
                        scanf("%d", &n);
                            while(n --){
                                cin>> a>> b;
                                //cout << a << b << endl;
                                    for(int i=0; i<26; i++){
                                        if(alphabet[i] == b){
                                                alphabet[i]=a;
                                        }
                                    }
                            }
                             //for(int i=0; i<26; i++){
                             //       cout<<alphabet[i]<<endl;
                             //   }
                             int len=str.length();

                                for(int i=0;i<len; i++){
                                    if(str[i] == '_') printf("%c",str[i]);
                                    else printf("%c", alphabet[str[i]-65]);
                                }
                                printf("\n");
                }
return 0;
}
