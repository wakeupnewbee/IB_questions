#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int process_line(string line, vector<vector<int>>& grid){
    int index=0;
    vector <int> col;
    
    istringstream ss(line);
    string s_number;
    int number;
    while(getline(ss,s_number,'#')){
        number = stoi(s_number);
        col.push_back(number);
        index ++;
    }
    grid.push_back(col);
    col.clear();
    return index;
}

int lowest(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8){
    int temp=99;
    if(n1!=-1&& n1<temp) temp = n1;
    if(n2!=-1&& n2<temp) temp = n2;
    if(n3!=-1&& n3<temp) temp = n3;
    if(n4!=-1&& n4<temp) temp = n4;
    if(n5!=-1&& n5<temp) temp = n5;
    if(n6!=-1&& n6<temp) temp = n6;
    if(n7!=-1&& n7<temp) temp = n7;
    if(n8!=-1&& n8<temp) temp = n8;
    
    return temp;
}

int fib(int i){
    if(i==0){
        return 0;
    }else if(i==1){
        return 1;
    }else{
        return (fib(i-1)+fib(i-2));
    }
}



int main () {
    
    string line;
    int col_size = 0;
    int row_size = 0;
    vector<vector<int>> grid;
    while(getline(cin,line)){
        cout << line <<endl;
        istringstream check(line);
        string help_check;
        if(check >> help_check){
            col_size = process_line(help_check, grid);
        }
        row_size++;
    }
    
    cout << col_size<< endl;
    cout << row_size<< endl;
    
    int work_grid[row_size+2][col_size+2];
    
    for(int y = 0; y<row_size; y++){
        for(int x = 0; x<col_size; x++){
            cout<< grid[y][x]<<" ";
            work_grid[y+1][x+1]=grid[y][x];
        }
        cout << endl;
    }
    
    for(int y = 0; y<row_size+2; y++){
        for(int x = 0; x<col_size+2; x++){
            if (x==0 or y==0 or x==(col_size+1) or y ==(row_size+1)){
                work_grid[y][x]=-1;
            }
            cout<< work_grid[y][x]<< "#";
        }
        cout << endl;
    }
    int x = col_size+2;
    int y = row_size+2;
    
    int process[y][x];
    int bigest=0;
    for(int y = 1; y<row_size+1; y++){
        for(int x = 1; x<col_size+1; x++){
            process[y][x]=lowest(work_grid[y-1][x-1],work_grid[y-1][x],work_grid[y-1][x+1],
                                 work_grid[y][x-1],work_grid[y][x+1],
                                 work_grid[y+1][x-1],work_grid[y+1][x],work_grid[y+1][x+1]);
            if(process[y][x]>bigest) bigest=process[y][x];
            cout<< process[y][x]<< "#";
        }
        cout << endl;
    }
    cout << bigest<< endl;
    vector<string> output;
    for(int y = 1; y<row_size+1; y++){
        for(int x = 1; x<col_size+1; x++){
            if(process[y][x]==bigest){
                cout << y << "#" << x << endl;
            }
        }
    }
    
    //recursion fib
    for(int x=0; x<10;x++){
        cout << fib(x)<<" ";
    }
    cout << endl;
    
    vector<int> fibe;
    for(int x=0;x<10;x++){
        if(x==0){
            fibe.push_back(0);
            cout << fibe[0]<<" ";
        }else if(x==1){
            fibe.push_back(1);
            cout << fibe[1]<< " ";
        }else{
            fibe.push_back(fibe[x-1]+fibe[x-2]);
            cout << fibe[x]<<" ";
        }
        
    }
    cout << endl;
    //check prime or not
    int check= 44;
    for(int x=check; x>0; x--){
        if(check%x==0){
            cout <<"not prime"<<endl;
            break;
        }
    }

    
    return 0;
}
