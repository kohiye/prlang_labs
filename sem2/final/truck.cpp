#include "truck.h"

Truck::Truck(const std::string_view make, int year, double fuelEff, int capacity)
    :Vehicle(make, year, fuelEff),m_capacity_kg{capacity}{};
std::ostream& Truck::print(std::ostream& out) const 
{
    out <<"Truck("<<m_make<<", "<<m_year<<", "<<m_fuelEfficiency<<", "<<m_capacity_kg<<')';
    return out;
};

std::istream& Truck::read(std::istream& in)
{
    std::getline(in, m_make, ',');
    in >> m_year;
    in.ignore(g_max_size, ',');
    in >> m_fuelEfficiency;
    in.ignore(g_max_size, ',');
    in >> m_capacity_kg;
    in.ignore(g_max_size, '\n');
    return in;
};
