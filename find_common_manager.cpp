#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class sort{
    public:
    sort(string _name):name(_name){}
    //sort(string _name, sort* _manager): name(_name),manager(_manager){}
    
    void set_tail(sort * tail){ manager = tail;}
    string name;
    sort *manager;
    sort *self;
};

class lookup{
    public:
    string name;
    sort * address;
    lookup * next;
    lookup(){}
    lookup(string _name): name(_name){}
    void set(string _name, lookup * _next){name = _name, next = _next;}
    void set_addr(sort * _address){address= _address;}
};

sort * find_name(lookup * head,string name){
    lookup * test = head;
    while(test != NULL){
        if(test->name != name){
            test = test->next;
        }else{
            return test->address;
        }
    }
    return NULL;
}

lookup* process(string line, string & n1, string & n2){
    lookup * head = NULL;
    lookup * tail = NULL;
    lookup * tmp1 = NULL;
    string deli1=",";
    string deli2="->";
    size_t pos=0;
    size_t inner_pos=0;
    
    string manager="??",worker=" ??";
    string part;
    
    sort *sworker;
    sort *smanager;
    sort *tmpw;
    sort *tmpm;
    
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
                tail = tmp1;
                tail->next = NULL;
                sworker=new sort(worker);
                smanager=new sort(manager);
                sworker->set_tail(smanager);
                head->set_addr(smanager);
                tmp1->set_addr(sworker);
            }else{
                //sworker=new sort(worker);
                //smanager=new sort(manager);
                //sworker->set_tail(smanager);
                if((tmpm=find_name(head,manager))==NULL){// new manager comes
                    tmp1 = new lookup(manager);
                    tail->next = tmp1;
                    tmp1->next = NULL;
                    tail = tmp1;
                    tmp1->set_addr(smanager);
                    smanager=new sort(manager);
                }
                if((tmpw=find_name(head,worker))==NULL){//new works comes :D who case who is his manager
                    tmp1 = new lookup(worker);
                    tail->next = tmp1;
                    tmp1->next =NULL;
                    tail = tmp1;
                    tmp1->set_addr(sworker);
                    sworker=new sort(worker);
                }
                if(tmpm!=NULL){
                    sworker->set_tail(tmpm);
                }else if(tmpw != NULL){
                    smanager->set_tail(tmpw);
                }else{
                    sworker->set_tail(smanager);
                }
            }
        }else{
            n1 = part;
        }
        
        line.erase(0,pos + deli1.length());
        //
    }

    //line.erase(line.size()-1); no change line, no need, be aware
    n2 = line;
    return head;
}

void finding(sort * head1, sort * head2){
    head1 = head1->manager;
    head2 = head2->manager;
    sort * tmp = head1;
    
    while(head2 != NULL){
        
        while(tmp !=NULL){
            cout << "checking "<<endl;
            cout << tmp->name << endl;
            cout << head2->name <<endl;
            if(tmp->name != head2->name){
                tmp=tmp->manager;
            }else{
                cout <<"almost"<<endl;
                cout << head1->name<<endl;;
                return;
            }
            //cout << tmp->name <<endl;
        }
        cout << "finish on loop" <<endl;
        tmp = head1;
        head2 = head2->manager;
    }
}

int main()
{
    string line;
    string n1,n2;
    getline(cin,line);
    
    lookup * head = process(line,n1,n2);
    cout <<"This is the names i need to work on: "<< n1 << " "<< n2<< endl;
    
    cout << "the lookup list: "<<endl;
    
    lookup * find = head; 
    while(find!= NULL){
        cout << find->name << endl;
        find = find->next;
    }
    
    find = head;
    sort *find1;
    sort *find2;
    while(find != NULL){
        if(find->name == n1){
            find1 = find->address;
        }
        if(find->name == n2){
            find2 = find->address;
        }
        find = find->next;
    }
    cout <<"out of whiling"<<endl;
    /*while(find2!=NULL){
        cout << find2->name <<endl;
        find2 = find2->manager;
    }*/
    finding(find1,find2);
    
    
   return 0;
}


//Frank->Mary,Mary->Sam,Mary->Bob,Sam->Katie,Sam->Pete,Bob->John,Bob,Katie
