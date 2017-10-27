#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class sort{
    /*
    string name;
    sort *myself;
    sort *manager;
    sort *next;
    */
    public:
    sort(string _name, sort* body, sort* tail): name(_name),myself(body),manager(tail){}
    
    string name;
    sort *myself;
    sort *manager;
    
    /*
    void set_name(string _name) {name=_name;}
    void set_pname(sort * p_name) { myself = p_name;}
    void set_pmanager(sort * p_manager) {manager = p_manager;}
    
    sort * show_name(){ return myself;}
    sort * show_manager(){ return manager;}
    */
};

class lookup{
    public:
    string name;
    sort * address;
    lookup * next;
    lookup(){}
    lookup(string _name): name(_name){}
    void set(string _name, lookup * _next){name = _name, next = _next;}
};

lookup* process(string line){
    lookup * head = NULL;
    lookup * tail = NULL;
    lookup * tmp1 = NULL;
    string deli1=",";
    string deli2="->";
    size_t pos=0;
    size_t inner_pos=0;
    
    string name1,name2;//look up name
    string manager="??",worker=" ??";
    string part;
    
    while((pos=line.find(deli1))!=string::npos){
        
        part=line.substr(0,pos);
        cout << part << endl;
        if((inner_pos=part.find(deli2))!=string::npos){
            manager=part.substr(0,inner_pos);
            part.erase(0,inner_pos+2);
            worker=part;
            if(head == NULL){////////////////work with address, be careful
                head = new lookup(manager);
                tmp1 = new lookup(worker);
                head->next = tmp1;
                tmp1->next = new lookup;
                tail = tmp1->next;
            }else{
                tmp1 = new lookup(worker);
                tail->set(manager,tmp1);
                tmp1->next = new lookup;
                tail = tmp1->next;
            }
        }else{
            name1 = part;
        }
        
        line.erase(0,pos + deli1.length());
        //
    }

    //line.erase(line.size()-1); no change line, no need, be aware
    name2 = line;
    return head;
}

int * ret(){
    int x = 1;
    int *y = &x;
    return y;
}

int main()
{
    int obj=10;
    int * p1=&obj;
    int * p2=&obj;
    if(p1==p2){
        cout << "two points same obj"<<endl;
    }
    *p1+=1;
    cout<<"p1 is changing to"<< *p1<< " so p2 = ?  :"<< *p2<<endl;
    *p2-=10;
    cout<<"p2 is changing to"<< *p2<< " so p1 = ?  :"<< *p1<<endl;
    
    sort mei("mei",&mei,NULL);
    sort bob("bob",&bob,&mei);
    sort jim("jim",&jim,&mei);
    
    if(jim.manager->name == bob.manager->name){
        string boss;
        boss= jim.manager->name;
        cout << boss << endl;
    }
    
    sort * tmp = new sort("luck1",tmp,NULL);
    sort * A = tmp;
    cout<< tmp << " " << A <<endl;
    tmp = new sort("luck2",tmp,A);
    sort * B = tmp;
    cout<< tmp << " " << B <<endl;
    tmp = new sort("luck3",tmp,B);
    sort * C = tmp;
    cout<< tmp << " " << C <<endl;
    
    cout << A->manager <<" " 
         << B->name <<" " 
         << C->name <<endl;
    
    delete A,B,C,tmp;
    
    string line;
    getline(cin,line);
    lookup * head = process(line);
    
    while(head!= NULL){
        cout << head->name << endl;
        head = head->next;
    }
    //}
    int * i = new int;
    
    
   return 0;
}
