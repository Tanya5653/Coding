#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    //creation
    unordered_map<string,int> m;

    //insertion
    //1
    pair<string,int> p = make_pair("babbar",3);
    m.insert(p);
    //2
    pair<string,int> p2("love",2);
    m.insert(p2);
    //3
    m["mera"]=1;

    //searching
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;
    //cout<<m.at("tanya")<<endl;
    cout<<m["tanya"]<<endl;
    cout<<m.at("tanya")<<endl;

    //check presence
    cout<<m.count("tanya")<<endl;
    cout<<m.count("palak")<<endl;

    //size
    cout<<m.size()<<endl;

    //erase function
    m.erase("love");
    cout<<m.size()<<endl;

    //access map
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
    //accessing using iterator
    unordered_map<string,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;
} 
