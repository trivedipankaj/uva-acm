#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct card{
    char suit;
    char rank;
};
card  new_card(char suit, char rank){
    card c ;
    c.suit=suit;
    c.rank = rank;
    return c;
}
bool is_match(card A, card B){
    return A.suit == B.suit || A.rank == B.rank;
}
int main(){
    string word;
    while(cin>>word){
        if(word =="#") break;
        vector< vector<card> > v;
        v.push_back(vector<card>(1,new_card(word[1],word[0])));
        int n=0;
        
        for(int j=1; j<52;j++ ){
            cin>>word;
            n++;
            v.push_back(vector<card>(1,new_card(word[1],word[0])));
            bool move;
            do{
                move =false;
                for(int i=0; i<=n; i++){
                   if(i>=3 && is_match(v[i-3].back(),v[i].back())){
                        v[i-3].push_back(v[i].back());
                   }else if(i>=1 && is_match(v[i-1].back(),v[i].back())){
                        v[i-1].push_back(v[i].back());
                   }else continue;
                   v[i].pop_back();
                   if(v[i].size() == 0){
                        v.erase(v.begin()+i);
                        n--;
                   }
                   move =true;
                   break;
                }
            }while(move);
    }
    printf("%d pile", n+1); if (n+1!=1) printf("s");
    printf(" remaining:");
            for(int i=0; i<=n;i++)
                cout<<" "<<v[i].size();
            printf("\n");

    }
}
