#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

#include "const.h"
#include "vehicle.h"
#include "car.h"
#include "truck.h"

using Vector = std::vector<std::unique_ptr<Vehicle>>;

void writeToFile(const std::string& fname, const Vector& vector){
    std::ofstream outf{fname};
    if (!outf){
        std::cerr << "file could not be opened\n";
        return;
    }
    for (unsigned int i{0}; i<vector.size(); ++i)
        outf << *(vector[i]) << '\n';
};

void readFromFile(const std::string& fname, Vector& vector){
    std::ifstream inf{fname};
    if (!inf){
        std::cerr << "file could not be opened\n";
        return;
    }

    vector.clear();
    std::string type;
    while(std::getline(inf, type, '(')){
        if (type == "Car"){
            auto carPtr{std::make_unique<Car>()};
            inf >> *carPtr;
            vector.push_back(std::move(carPtr));
        }
        else if (type == "Truck"){
            auto truckPtr{std::make_unique<Truck>()};
            inf >> *truckPtr;
            vector.push_back(std::move(truckPtr));
        }
    }

};


int main()
{
    Vector vector;
    readFromFile("Vh.txt", vector);
    for (unsigned int i{0}; i<vector.size(); ++i)
        vector[i]->signal();
    writeToFile("Vehicles.txt", vector);
    return 0;
};
