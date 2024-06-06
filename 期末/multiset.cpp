#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>

using namespace std;


typedef vector<int> intvec;

int main(){
    cout << "one dimension vector" << endl;
    vector<int> a(3,4);
    for (int i = 0 ; i < a.size(); i++){
        cout << a[i] << " " ;
    }
    cout << endl;
    for (auto const &num: a){
        cout << num << " ";
    }
    cout << endl;

    cout << "multi dimentional vector" << endl;

    vector<vector<int>> multi;
    for (int i = 0 ; i < 5; i++){
        vector<int>numList(5, i);
        multi.push_back(numList);
    }
    for (auto &numList: multi){
        for (auto &num: numList){
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "set" << endl;
    int tempInt[] = {10,20,30,40};
    set<int> Set(tempInt, tempInt+4);
    Set.insert(5);
    Set.insert(7);
    Set.insert(7);
    Set.erase(7);
    for (auto &value: Set){
        cout << value << " ";
    }
    cout << endl;

    cout << "using iterator" << endl;
    set<int>::iterator it;
    for (it = Set.begin(); it != Set.end(); it++){
        cout << *it << " ";
    }
    cout << endl;


    //map
    map<string, int>Map;
    string word[10] = {"a","d","v","q"};
    for (int i = 0; i < 4; i++){
        Map[word[i]] = i*2;
    }

    map<string, int>::iterator mapIt;
    for (mapIt = Map.begin(); mapIt != Map.end(); mapIt++){
        cout << mapIt->first << " " << mapIt->second << endl;
    }
    cout << endl;


}
