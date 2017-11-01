#include <iostream>
#include <string>
#include <vector>
using namespace std;
void out(vector <string> list){
    for(int i=0; i< list.size();i++){
        cout << list[i];
    }
}

int check(string s, vector<string> pl){
    for(int i=0; i<pl.size(); i++){
        if(pl[i]==s){
            return 0;
        }
    }
    return 1;
}

void nest(vector<string> list,string picked, vector <string> pl,int loop){
    if(loop==0){
        pl.push_back(picked);
        out(pl);
        cout << endl;
        return;
    }else{
        pl.push_back(picked);
        for(int i=0;i<list.size();i++){
            if(check(list[i],pl)){
                nest(list,list[i],pl,loop-1);
            }
        }
    }
    return;
}

 int main(){
     string line;
     getline(cin,line);
     
     string tmp;
     string deli=",";
     vector<string> list;
     size_t pos;
     while(pos=line.find(deli)!=string::npos){
         tmp = line.substr(0,pos);
         list.push_back(tmp);
         line.erase(0,pos+deli.length());
     }
     list.push_back(line);
     
    out(list);
    cout << endl;
     vector <string> pl;
     cout << list.size()<<endl;
    for(int i=0;i<list.size();i++){
        nest(list,list[i],pl,list.size()-1);
    }
     cout << "testing" << endl;
 }
