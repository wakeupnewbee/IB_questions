#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void comp(vector<string> list, int i, int i2, vector<string>& out){
    int a,b;
    for(int tmp=0;tmp<list[i].size();tmp++){
        a = list[i][tmp];
        b = list[i2][tmp];
        if(a!=b&&(a-b)!=32&&(a-b)!=-32){
            return;
        }
    }
    out[i]="empty";
}

void compare(vector<string> list,int i,int i2, vector<string>& out){
    if(i2 >= 0){
        comp(list, i , i2, out);
        compare(list,i,i2-1,out);
        return;
    }
    if(i > 1){
        compare(list,i-1,i-2,out);
        return;
    }
    //for the last one compare
    for(int tmp=1; tmp<list.size();tmp++){
        comp(list,0,tmp,out);
    }
    return;
}

int main(){
    string c1="'";
    cout << c1 << endl;
    
    int ia= 'a';
    int iz= 'z';
    cout << ia <<":"<<iz<<endl;
    
    int iA='A';
    int iZ='Z';
    cout << iA << ":" <<iZ <<endl;
    
    int il='|';
    cout << il <<endl;
    
    string s1="aAbB|";
    int is=s1[0];
    cout << is << endl;
    
    int ispace=' ';
    cout << ispace <<endl;
    
    string s2="012345";
    cout<< s2<<endl;
    s2.erase(0,1);
    cout << s2<<endl;
    
    string line;
    getline(cin,line);
    string line_copy=line;
    cout << line << endl;
    
    
    int cv;
    for(int tmp =0; tmp<line.size();tmp++){
        cv = line[tmp];
        if(cv==124|| cv==32|| (cv>=97&&cv<=122) || (cv>=65&&cv<=90) ){
            cout << line[tmp];
        }else{
            line.erase(tmp,1);
            tmp = tmp -1;
        }
        
    }
    
    istringstream ss(line);
    istringstream ssc(line_copy);
    string pdline;
    vector<string> list;
    vector<string> out_list;
    while(getline(ss,pdline,'|')){
        list.push_back(pdline);
        getline(ssc,pdline,'|');
        out_list.push_back(pdline);
    }
    
    cout << endl;
    cout << "getting into process"<<endl;
    compare(list,list.size()-1,list.size()-2,out_list);
    
    cout << "checking the list" <<endl;
    for(int tmp=0;tmp<list.size();tmp++){
        cout << list[tmp]<<endl;
        cout << out_list[tmp]<<endl;
    }
    if(list[0][1]==list[2][1]||list[0][1]+32==list[2][1]){
        cout << "storage clear" <<endl;
        char temp = list[0][1]+32;
        cout << list [0][1]<<":"<<temp<<endl;
    }
    
    
    
    cout << endl;
    cout<< line.size()<<endl;
    cout << line.length()<<endl;
    
    
    cout << "test resuting:" <<endl;
    string oupt = "222";
    string oupt2="1111";
    string com="";
    for(int tmp=0; tmp<out_list.size();tmp++){
        if(out_list[tmp]!="empty"){
            com=com+out_list[tmp]+"|";
        }
    }
    com.erase(com.length()-1);
    ostringstream oo(com);
    cout << com <<endl;
    return 0;
}
