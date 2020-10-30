#ifndef COVIDCASEMAP_H
#define COVIDCASEMAP_H

#include "CovidCase.h"

// TODO: your code goes here

class TimeAndCaseData{
    private:
    int current_time;
    int current_number_of_cases;
    public:

    TimeAndCaseData(int time, int numberofcases)
    : current_time(time), current_number_of_cases(numberofcases){}

    const int& getTime() const{
        return current_time;
    }

    const int& getNumberOfCases() const{
        return current_number_of_cases;
    }
};

class CovidCaseMap{
    private:
    vector<CovidCase> cases;

    public:

    void addCase(CovidCase c){
        cases.push_back(c);
    }
    
    vector<TimeAndCaseData> getCasesOverTime(const int& active_time){
        vector<TimeAndCaseData> data;
        data.push_back(TimeAndCaseData(0,0));
        int current_time(0);
        int active_cases(0);

        for (int i = 0; i < cases.size(); ++i){
            
            current_time = cases[i].getTime();
            for (int j = 1; j < data.size(); ++j){
                if (data[j].getTime()+ active_time < current_time){
                    --active_cases;
                    data.push_back(TimeAndCaseData(data[j].getTime()+ active_time, active_cases));
                }
            }
            ++active_cases;
            data.push_back(TimeAndCaseData(cases[i].getTime(), active_cases));

            if (i == cases.size()-1){
                for (int k = 1; k < cases.size();++k){
                    if(cases[k].getTime()+ active_time > current_time){
                        --active_cases;
                        data.push_back(TimeAndCaseData(cases[k].getTime()+ active_time, active_cases));
                    }
                 if (cases[k].getTime() == current_time)
                 {
                    break;
                 }
                                                 
                }
            }           
        }
        return data;
    }

    int supportVisitGreedyTSP(const double& latstart, const double& longstart, const int& start_time, const int& self_isolation_period){

    }
};



// don't write any code below this line

#endif

