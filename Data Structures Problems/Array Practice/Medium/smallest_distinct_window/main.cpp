#include <iostream>
#include <unordered_map>

using namespace std;

bool are_equal(unordered_map<char,int> unique_characters, unordered_map<char,int> current_characters){
    for(auto it1=unique_characters.begin(); it1 != unique_characters.end();it1++){
        if(current_characters[it1->first] <= 0)
            return false;
    }
    return true;
}

void printMap(unordered_map<char,int> hashmap){
    for(auto p:hashmap)
        cout<<p.first<<" ";
    cout<<endl;
    for(auto p:hashmap)
        cout<<p.second<<" ";
    cout<<endl;
}

int smallest_distinct_window(string str){

    unordered_map<char,int> current_characters;
    for(char c:str){
        if(current_characters.find(c) == current_characters.end())
            current_characters[c] = 0;
    }

    int unique_characters = current_characters.size();

    int smallest_window_size=str.size();
    int character_counter=0;

    for(int left=0,right=0; right < str.size();right++){
        if(current_characters[str[right]] == 0)
            character_counter++;
        current_characters[str[right]] += 1;

        if(character_counter == unique_characters){
            while(character_counter == unique_characters){
                current_characters[str[left]] -= 1;
                if(current_characters[str[left]] == 0)
                    character_counter--;
                left++;
            }
            smallest_window_size = min(smallest_window_size, right - left + 2);
        }

    }

    return smallest_window_size;
}

int main()
{
    int tc;cin>>tc;
    for(int i = 0 ; i < tc ; i++){
        string str;cin>>str;
        cout<<smallest_distinct_window(str)<<endl;
    }
}
