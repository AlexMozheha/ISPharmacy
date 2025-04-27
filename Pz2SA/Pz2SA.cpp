#include <iostream>
#include <vector>
#include <locale>;
#include "windows.h";

using namespace std;

struct Subsystem {
    vector<vector<double>> elements;
};

double reliabilityOfSubsystem(const vector<vector<double>>& elements);
double reliabilityOfEntireSystem(const vector<double>& subsystems);

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    Subsystem subsystem1 = {
        {
            {0.79, 0.83},   
            {0.91, 0.56},   
            {0.33}          
        }
    };

    Subsystem subsystem2 = {
        {
            {0.85},         
            {0.75},        
            {0.65},         
            {0.55}          
        }
    };

    Subsystem subsystem3 = {
        {
            {0.63},        
            {0.83}          
        }
    };

    double P1 = reliabilityOfSubsystem(subsystem1.elements);
    double P2 = reliabilityOfSubsystem(subsystem2.elements);
    double P3 = reliabilityOfSubsystem(subsystem3.elements);


    vector<double> entireSystem = { P1, P2, P3 };
    double Pc = reliabilityOfEntireSystem(entireSystem);

    cout << "Надійність усієї системи: " << Pc << endl;

    return 0;
}

double reliabilityOfSubsystem(const vector<vector<double>>& elements) {
    double reliability = 1.0;
    for (const auto& group : elements) {
        double groupReliability = 1.0;
        if (group.size() > 1) { 
            double failureProbability = 1.0;
            for (double p : group) {
                failureProbability *= p;
            }
            groupReliability = 1 - failureProbability;
        }
        else { 
            groupReliability = (1 - group[0]);
        }
        reliability *= groupReliability;
    }
    return 1 - reliability;
}


double reliabilityOfEntireSystem(const vector<double>& subsystems) {
    double reliability = 1.0;
    for (double p : subsystems) {
        reliability *= p;
    }
    return reliability;
}