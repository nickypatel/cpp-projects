#ifndef COVIDCASE_H
#define COVIDCASE_H
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>
#include <regex>
#include <vector>
using std::vector;
using std::string;
using std::ostream;


class CovidCase{
    
    private:
    double latitude;
    double longitude;
    string patientname;
    int patientage; 
    int hours_since_test;

    public:
    CovidCase(double lat, double longi, string name, int age, int hours)
    : latitude(lat), longitude(longi), patientname(name), patientage(age), hours_since_test(hours){}

    friend ostream& operator<<(ostream& os, const CovidCase& case1);

    const double& getLatitude() const{return latitude;}
    
    const double& getLongitude() const{return longitude;}
    
    double getRadians(double degrees){
        double r = degrees * M_PI /180;
        return r;
    }

    double distanceTo(const CovidCase& othercase){
        double R(3960);
        
        double dlon =  getRadians(othercase.getLongitude()- longitude);
           
        double dlat =  getRadians(othercase.getLatitude()- latitude);
        
        double a = pow((sin(dlat/2)), 2) + (cos(getRadians(latitude)) * cos(getRadians(othercase.getLatitude())) * pow((sin(dlon/2)), 2));  
        
        double c = 2 * atan2( sqrt(a), sqrt(1-a) ) ;
        
        double distance = R * c ; 
   
        return distance;
    }
 
    bool operator== (const CovidCase& rhs){
        return (latitude == rhs.latitude) && (longitude == rhs.longitude) && (patientname.compare(rhs.patientname)==0) && (patientage == rhs.patientage)
        && (hours_since_test == rhs.hours_since_test);
    }

  
    const string& getName() const{return patientname;}
 
    const int& getAge() const {return patientage;}
  
    const int& getTime() const {return hours_since_test;}
 
    CovidCase (const string& str){
        const std::regex re(R"([{|, |}|\"]+)");
        std::sregex_token_iterator ittr{str.begin(),str.end(),re,-1};
        vector<string> tokens{ittr, {}};

        latitude= std::stod(tokens[0]);
        longitude= std::stod(tokens[1]);
        patientname= tokens[2];
        patientage= std::stoi(tokens[3]);
        hours_since_test= std::stoi(tokens[4]);
        }

    
 };

    ostream& operator<<(ostream& os, const CovidCase& case1){
        os << '{' << case1.latitude << ", " << case1.longitude << ", \"" << case1.patientname << "\", " << case1.patientage<< ", " << case1.hours_since_test << '}';
        return os;
    }

// don't write any code below this line

#endif

