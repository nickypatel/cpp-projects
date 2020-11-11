#ifndef COVIDCASEMAP_H
#define COVIDCASEMAP_H

#include "CovidCase.h"
#include <utility>
#include <algorithm>
#include <iterator>
using std::pair;
using std::min_element;

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
    int self_isolation_period;
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
                for (int k = 0; k < cases.size();++k){
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

    double getRadians(const double& degrees){
        double r = degrees * M_PI /180;
        return r;
    } 

    double distanceBetweenTwoCoordinates(const double& lat1, const double& long1,const double& lat2, const double& long2){

        double R(3960);
        
        double dlon =  getRadians(long2 - long1);
           
        double dlat =  getRadians(lat2 - lat1);
        
        double a = pow((sin(dlat/2)), 2) + (cos(getRadians(lat1)) * cos(getRadians(lat2)) * pow((sin(dlon/2)), 2));  
        
        double c = 2 * atan2( sqrt(a), sqrt(1-a) ) ;
        
        double distance = R * c ; 
   
        return distance;
    }

    vector<CovidCase> getActiveCases (const int& time){
        vector<CovidCase> activecases;
        for (int i = 0; i < cases.size(); ++i){
            if (cases[i].getTime() + self_isolation_period > time && cases[i].getTime() < time){
                activecases.emplace_back(cases[i]);
            } 
        }
        return activecases;
    }

    double supportVisitGreedyTSP(const double& latstart, const double& longstart, const int& start_time, const int& self_iso_period){
        self_isolation_period = self_iso_period;
        double distance_travelled_in_miles ;
        vector<pair<double,double> > coordinates;

        coordinates.emplace_back(latstart,longstart);

        vector<CovidCase> actvcases = getActiveCases(start_time);
        for (int i = 0; i < actvcases.size(); ++i){
           coordinates.emplace_back(actvcases[i].getLatitude(), actvcases[i].getLongitude());
            
        }
        int val= 0;
        while (coordinates.size() != 1){
                vector<double> distances;
                
                for (auto k : coordinates){
                distances.emplace_back(distanceBetweenTwoCoordinates(coordinates[0].first, coordinates[0].second,k.first, k.second));
                
                }

                distances.erase(distances.begin());
                val = std::distance(distances.begin(),min_element(distances.begin(),distances.end())+ 1);
                cout << "smallest distance is :" <<*min_element(distances.begin(),distances.end()) << "\n\n";
                distance_travelled_in_miles+= *min_element(distances.begin(),distances.end());
                distances.clear();
                coordinates.emplace(coordinates.begin(), coordinates[val]);
                coordinates.erase(coordinates.begin()+ 1);
                coordinates.erase(coordinates.begin()+ val);
         
        }
        distance_travelled_in_miles+= distanceBetweenTwoCoordinates(coordinates[0].first, coordinates[0].second,latstart,longstart);
  
    return distance_travelled_in_miles;
    }
};



// don't write any code below this line

#endif

