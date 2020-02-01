#include<bits/stdc++.h>
using namespace std;

int main(){

    int testcase,paid_char,cn,cents[257];
    char c,ch[200];

        scanf("%d", &testcase);

            while(testcase --){

                memset(cents,0,sizeof(cents));
                scanf("%d", &paid_char);
                double sum=0;

                    getchar();
                    for(int i=1; i<=paid_char; i++){
                        //scanf("%c %d", &c, &cn);
                        cin>>ch[i] >>cents[i];
                        //cents[c-0]=cn;
                        //cout << paid_char;
                    }
                    long int lines;
                    scanf("%ld", &lines);
                        getchar();
                        while(lines--){
                            char str[10005];
                            gets(str);
                               long int len=strlen(str);

                                    //for(int i=0; i<len; i++){ //cout << cents[str[i]] << endl;
                                        //sum += cents[str[i]-0];
                                    //}
                                    ///
                                    for(int i=1;i<=paid_char;i++)
                                        {
                                        for(int c=0;c<len;c++)
                                            {
                                            if(ch[i]==str[c])sum+=cents[i];
                                            }
                                        }

                                    ///
                        }

                        sum /= 100;
                        printf("%0.2lf$\n", sum);
            }
return 0;
}
