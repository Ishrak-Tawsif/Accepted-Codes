#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >match_box_in_container;

int main(){

    long int max_match_box_can_hold,ans;
    int container,match_box,matches_in_box;
        //while(cin>> max_match_box_can_hold>> container){
            cin>> max_match_box_can_hold>> container;
            ans=0;
                while(container --){
                    cin>> match_box>> matches_in_box;
                    match_box_in_container.push_back(make_pair(matches_in_box,match_box));
                }
                sort(match_box_in_container.begin(),match_box_in_container.end());

                    for(int i=match_box_in_container.size()-1; i>=0; i--){
                        //cout << ans << " " << match_box_in_container[i].second << " " << match_box_in_container[i].first << endl;
                        if(max_match_box_can_hold == 0) break;
                        else{
                            if(match_box_in_container[i].second<=max_match_box_can_hold){
                                ans += match_box_in_container[i].second*match_box_in_container[i].first;
                                max_match_box_can_hold -= match_box_in_container[i].second;
                            }
                            else{
                                //match_box_in_container[i].first -= (match_box_in_container[i].first-max_match_box_can_hold);
                                ans += match_box_in_container[i].first * max_match_box_can_hold;
                                break;
                            }
                        }
                    }
            cout << ans << endl;
        //}
}
