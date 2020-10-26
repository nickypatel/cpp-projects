#ifndef COUNTDOWN_H
#define COUNTDOWN_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
using std::stack;
using std::vector;
using std::string;
using std::stod;

// this is provided code for the last part of the README

string intToString(const int x) {
    std::ostringstream str;
    str << x;
    return str.str();
}

class CountdownSolution {
  
private:
    std::string solution;
    int value;
    
public:
    
    CountdownSolution() : solution(), value(0) {}
    
    CountdownSolution(const std::string & solutionIn, const int valueIn)
        : solution(solutionIn), value(valueIn) {
    }
    
    const std::string & getSolution() const {
        return solution;
    }
    
    int getValue() const {
        return value;
    }
    
};

// Do not edit above this line

// TODO: write code here:
double evaluateCountdown(const string& expression){
    vector<double> operands;
    stack<double> mystack;
    
    stod(expression)
    if (mystack.top()){

    }
    else mystack.push();
    return mystack.top();
}

CountdownSolution solveCountdownProblem(const vector<int>& input, const int& target){

}

// Do not edit below this line


#endif
