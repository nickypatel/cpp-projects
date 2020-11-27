#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"

// TODO: Your Sudoku class goes here:
#include <math.h> 
#include <set>
using std::set;

class Sudoku {
    private:
    vector<vector<set<int>>> board;
    int size;

    public:
    Sudoku(int sizeIn)
    :size(sizeIn) {
        
        if(size == 9){
            set<int> s {1,2,3,4,5,6,7,8,9};
        
        vector <set <int> > inner_v(size, s);

        vector<vector< set <int> > > v (size, inner_v);
        board = v;
        }
        if(size == 16){
            set<int> s {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
        
        vector <set <int> > inner_v(size, s);

        vector<vector< set <int> > > v (size, inner_v);
        board = v;
        }
    }

    const int getSquare(int row, int col) const{
        if(board[row][col].size() == 1){
            auto itr = board[row][col].begin();
            return *itr;
        }
        else{return -1;}
    }

    bool hasEmptySquare (){
        for (size_t r = 0; r <board.size(); ++r){
            for(size_t c = 0; c < board[r].size(); ++c){
                if (board[r][c].empty()){
                    return true;
                }        
            }
        }
        return false;
    }

    bool hasOneValue(int row, int col){
        if (board[row][col].size() == 1){
            return true;
        }
        return false;
    }
    bool hasValue(int row, int col ,int val){
        if  (board[row][col].count(val)){
            return true;
        }
        else {return false;}
    }
    bool isSolved (){
        bool solved = true;
        for (size_t r = 0; r <board.size(); ++r){
            for(size_t c = 0; c < board[r].size(); ++c){
                if (!hasOneValue(r,c)){
                    solved = false;
                }
            }
        }
        return solved;   
    }
    void simpleSolverLoop (){
        for (size_t r = 0; r <board.size(); ++r){
            for(size_t c = 0; c < board[r].size(); ++c){
                if (hasOneValue(r,c)){
                    auto itr = board[r][c].begin();
                    int val = *itr;
                    
                
                    for (size_t c1 =0; c1 < board[r].size(); ++c1){
                        board[r][c1].erase(val);
                    }
                    for (size_t r1 = 0; r1 <board.size(); ++r1){
                        board[r1][c].erase(val);
                    }
                    size_t sq = sqrt(size);
                    int colNumber = (c+1) % sq ;
                    int rowNumber = (r+1) % sq ;
                    switch (colNumber){
                        case 1:
                            switch (rowNumber){
                                case 1:
                                    for(size_t r1 = r; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c; c1 < c1 + sq; ++c1){
                                                if(hasValue(r1,c1,val)){
                                                    board[r1][c1].erase(val);
                                                }
                                        }
                                    }
                                    break;
                                case 2:
                                    for(size_t r1 = r - 1; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c; c1 < c1 + sq; ++c1){
                                            if(hasValue(r1,c1,val)){
                                                board[r1][c1].erase(val);
                                            }
                                        }
                                    }
                                    break;
                                case 3:
                                    for(size_t r1 = r - 2; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c; c1 < c1 + sq; ++c1){
                                            if(hasValue(r1,c1,val)){
                                                board[r1][c1].erase(val);
                                            }
                                        }
                                    }
                                    break;                                                            
                                case 0:
                                    for(size_t r1 = r - sq + 1; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c; c1 < c1 + sq; ++c1){
                                            if(hasValue(r1,c1,val)){
                                                board[r1][c1].erase(val);
                                            }
                                        }
                                    }
                                    break;
                            }
                            break;
                        case 2:
                            switch (rowNumber){
                                case 1:
                                    for(size_t r1 = r; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c-1; c1 < c1 + sq; ++c1){
                                            if(hasValue(r1,c1,val)){
                                                board[r1][c1].erase(val);
                                            }
                                        }
                                    }
                                    break;
                                case 2:
                                    for(size_t r1 = r - 1; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c-1; c1 < c1 + sq; ++c1){
                                            if(hasValue(r1,c1,val)){
                                                board[r1][c1].erase(val);
                                            }
                                        }
                                    }
                                    break;
                                case 3:
                                    for(size_t r1 = r - 2; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c-1; c1 < c1 + sq; ++c1){
                                            if(hasValue(r1,c1,val)){
                                                board[r1][c1].erase(val);
                                            }
                                        }
                                    }
                                    break;                                                            
                                case 0:
                                    for(size_t r1 = r - sq + 1; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c-1; c1 < c1 + sq; ++c1){
                                            if(hasValue(r1,c1,val)){
                                                board[r1][c1].erase(val);
                                            }
                                        }
                                    }
                                    break;
                            }
                            break;                         
                        case 3:
                            switch (rowNumber){
                                case 1:
                                    for(size_t r1 = r; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c-2; c1 < c1 + sq; ++c1){
                                            if(hasValue(r1,c1,val)){
                                                board[r1][c1].erase(val);
                                            }
                                        }
                                    }
                                    break;
                                case 2:
                                    for(size_t r1 = r - 1; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c-2; c1 < c1 + sq; ++c1){
                                            if(hasValue(r1,c1,val)){
                                                board[r1][c1].erase(val);
                                            }
                                        }
                                    }
                                    break;
                                case 3:
                                    for(size_t r1 = r - 2; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c-2; c1 < c1 + sq; ++c1){
                                            if(hasValue(r1,c1,val)){
                                                board[r1][c1].erase(val);
                                            }
                                        }
                                    }
                                    break;                                                            
                                case 0:
                                    for(size_t r1 = r - sq + 1; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c-2; c1 < c1 + sq; ++c1){
                                            if(hasValue(r1,c1,val)){
                                                board[r1][c1].erase(val);
                                            }
                                        }
                                    }
                                    break;
                            }                         
                            break;                                                        
                        case 0:
                            switch (rowNumber){
                                case 1:
                                    for(size_t r1 = r; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c- sq + 1; c1 < c1 + sq; ++c1){
                                            if(hasValue(r1,c1,val)){
                                                board[r1][c1].erase(val);
                                            }
                                        }
                                    }
                                    break;
                                case 2:
                                    for(size_t r1 = r - 1; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c- sq + 1; c1 < c1 + sq; ++c1){
                                            if(hasValue(r1,c1,val)){
                                                board[r1][c1].erase(val);
                                            }
                                        }
                                    }
                                    break;
                                case 3:
                                    for(size_t r1 = r - 2; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c- sq + 1; c1 < c1 + sq; ++c1){
                                            if(hasValue(r1,c1,val)){
                                                board[r1][c1].erase(val);
                                            }
                                        }
                                    }
                                    break;                                                            
                                case 0:
                                    for(size_t r1 = r - sq + 1; r1 < r1 + sq; ++r1){
                                        for (size_t c1 = c- sq + 1; c1 < c1 + sq; ++c1){
                                            if(hasValue(r1,c1,val)){
                                                board[r1][c1].erase(val);
                                            }
                                        }
                                    }
                                    break;
                            }
                            break;                                                   
                    }
                    board[r][c].insert(val);
                }        

            }
        }
        
    }
    bool setSquare(int row, int col, int value){
        set<int> newSet;
        newSet.insert(value);
        board[row][col] = newSet;

        //while(!isSolved() || !hasEmptySquare()){
            simpleSolverLoop();
        //}

        return isSolved();           
        
    }
};


#endif
