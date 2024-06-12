#ifndef TRUCK_H
#define TRUCK_H
#include "const.h"
#include "vehicle.h"
class Truck : public Vehicle
{
private:
    int m_capacity_kg{};
public:
    Truck(const std::string_view make="", int year=0, double fuelEff=0, int capacity=0);

    std::ostream& print(std::ostream& out) const override;
    std::istream& read(std::istream& in) override;
    
    void signal() const override { std::cout << "HONK\n";}

    int getCapacity() const {return m_capacity_kg;};

    ~Truck() = default;
};
#endif
