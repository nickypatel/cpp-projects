#ifndef COUNTDOWN_H
#define COUNTDOWN_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>
using std::next_permutation;
using std::stack;
using std::vector;
using std::string;
using std::cout;

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
    vector<string> tokens;
    stack<double> mystack;
    std::stringstream ss(expression);     
    string intermediate; 
      
    // Tokenizing w.r.t. space ' ' 
    while(getline(ss, intermediate, ' ')) 
    { 
        tokens.push_back(intermediate); 
    } 
      
    // evaluate expression
    for(int i = 0; i < tokens.size();){ 
        string plus = "+";
        string minus = "-";
        string times = "*";
        string divide = "/";
        if(tokens[i].compare(plus)== 0){
            double result;
            result = mystack.top();
            mystack.pop();
            result+= mystack.top();
            mystack.pop();
            mystack.push(result);
            ++i;
        }

        else if(tokens[i].compare(minus)== 0){
            double result1,result2;
            result1 = mystack.top();
            mystack.pop();
            result2= mystack.top();
            mystack.pop();
            mystack.push(result2-result1);
            ++i;
        }

        else if(tokens[i].compare(times)== 0){
            double result;
            result = mystack.top();
            mystack.pop();
            result*=mystack.top();
            mystack.pop();
            mystack.push(result);
            ++i;
        }   

        else if(tokens[i].compare(divide)== 0){
            double result1,result2;
            result1 = mystack.top();
            mystack.pop();
            result2 = mystack.top();
            mystack.pop();
            mystack.push(result2/result1);
            ++i;
        } 

        else {
            double a = std::stod(tokens[i]);
            mystack.push(a);
            ++i;
            
        }   
           
    }   

    return mystack.top();
}

bool isValid(const double& other, const int& target){
    return (other == target);
}


CountdownSolution solveCountdownProblem(const vector<int>& input, const int& target){
    CountdownSolution bestsolution("h",21);
    bool solved = false;
    vector<string> numbers;
    int answer= target;
    for (int i = 0; i < input.size();++i){
        numbers.push_back(intToString(input[i]));
    }
    std::sort(numbers.begin(),numbers.end());
    do { 

        vector<string> expressions; 
        double evaluationofrpn;
        expressions[i].append(+,-,* /);
        evaluationofrpn = evaluateCountdown(expressions[i]);
        if (evaluationofrpn == answer){break;}
        cout << numbers[0] << " " << numbers[1] << " " << numbers[2] << numbers[3]
         << " " << numbers[4] << " " << numbers[5] <<"\n"; 
    } while (next_permutation(numbers.begin(), numbers.end()));
    
       
    return bestsolution;
    }



// Do not edit below this line


#endif
