#include<bits/stdc++.h>
using namespace std;
int main(){

    int usb_f_drives,file_size,usb_size[101],sum,count;

        while(scanf("%d", &usb_f_drives) != EOF){
            sum=count=0;
            scanf("%d", &file_size);

                for(int i=0; i<usb_f_drives; i++){
                    scanf("%d", &usb_size[i]);
                }
                sort(usb_size, usb_size+usb_f_drives);
                    for(int i=usb_f_drives-1; i>=0; i--){
                        if(sum>=file_size) break;
                        sum += usb_size[i];
                        count++;
                    }
                    printf("%d\n", count);
        }
return 0;
}

