#include <iostream>
#include <string>
#include <vector>
using namespace std;

void back_insert(vector<string>& out,string line,int index){
    if(line[index]!='\n'){
        back_insert(out, line,index+1);
        out.push_back({line[index]});
        return;
    }else{
        return;
    }
}

int main(){
    string line;
    getline(cin,line);
    cout << line << endl;
    
    /*size_t pos;
    string del = " ";
    pos = line.find(del);
    
    string t1 = line.substr(0,pos);
    cout << t1 <<endl;
    */
    line+='\n';
    vector <string> out;
    back_insert(out,line,0);
    for(int i=0;i<out.size();i++){
        cout << out[i];
    }
    cout << endl;
    cout << "testing" <<endl;
}
