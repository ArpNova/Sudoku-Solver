#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<vector<char>>&sudoku, int row,int col,char c){
    for(int i=0;i<9;i++){
        if(sudoku[row][i]==c)return false;
        if(sudoku[i][col]==c)return false;
        if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3]==c)return false;

    }
    return true;
}
bool solve(vector<vector<char>>&sudoku){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j]=='.'){
                for(char c='1';c<='9';c++){
                    if(isvalid(sudoku, i, j, c) ==true){
                        sudoku[i][j]=c;
                        if(solve(sudoku)==true){
                            return true;
                        }
                        else{
                            sudoku[i][j]='.';
                        }
                    }         
                }
                return false;
            }
        }
    }
    return true;
}
void solution(vector<vector<char>>&sudoku,bool &check){
    solve(sudoku);
    if(solve(sudoku)==false){
        cout<<"This is not a valid Sudoku.";
        check=false;
        
    }
}

int main(){
    vector<vector<char>>sudoku(9, vector<char>(9));
    cout<<"enter the table('.' for blank spaces): "<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            
            cin>>sudoku[i][j];
        }
    }
    bool check=true;
    solution(sudoku,check);
    if(check==false){return 0;}
    cout<<"The solved Sudoku is: "<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}