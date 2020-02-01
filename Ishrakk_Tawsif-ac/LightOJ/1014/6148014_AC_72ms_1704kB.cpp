#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
int main(){

    long long int total_piaju,left,eaten_piaju;
    int testcase;
    cin>> testcase;


        for(int t=1; t<=testcase; t++){
            cin>>total_piaju  >>left;
            cout << "Case " << t << ":";
            //if(total_piaju == left)cout << " 0";
            //k=-1;
            eaten_piaju=total_piaju-left; ///eaten_piaju > left is given
                if(eaten_piaju<=left)cout <<" impossible"<<endl;

                else{
                    vector<long long int>contestant;
                    long long int sq = sqrt(eaten_piaju);
                    for(int i=1; i<=sq; i++){
                        if(eaten_piaju%i == 0){
                            contestant.push_back(i);
                            contestant.push_back(eaten_piaju/i);
                        }

                    }
                sort(contestant.begin(),contestant.end());
                contestant.resize(distance(contestant.begin(), unique(contestant.begin(),contestant.end())));
                for(int i=0; i<contestant.size(); i++){
                    if(contestant[i]>left)
                        cout << " " << contestant[i];
                }
                    cout<<endl;
                }
                //contestant.empty();
        }
return 0;
}
