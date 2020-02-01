#include<bits/stdc++.h>
using namespace std;
int main(){

    int line;

        while(scanf("%d", &line) == 1){

            int people[line+3];

                for(int i=0; i<line; i++) scanf("%d", &people[i]);

                int min=INT_MAX,time,temp;

                    for(int i=0; i<line; i++){
                        time=0;
                        for(int j=0; j<people[i]; j++){
                            scanf("%d", &temp);
                            time += temp*5+15;
                        }
                        if(time<min) min=time;
                    }

                    cout << min << endl;
        }
return 0;
}
