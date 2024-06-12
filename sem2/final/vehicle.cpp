#include <iostream> 
#include <string>
#include "vehicle.h"

Vehicle::Vehicle(const std::string_view make, int year, double fuelEff)
    :m_make{make}, m_year{year}, m_fuelEfficiency{fuelEff}{++s_count;};

std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle)
{
    return vehicle.print(out);
};

std::istream& operator>>(std::istream& in, Vehicle& vehicle)
{
    vehicle.read(in);
    return in;
};

std::ostream& Vehicle::print(std::ostream& out) const
{
    out <<"Vehicle("<<m_make<<", "<<m_year<<", "<<m_fuelEfficiency<<')';
    return out;
};

std::istream& Vehicle::read(std::istream& in)
{
    std::getline(in, m_make, ',');
    in >> m_year;
    in.ignore(g_max_size, ',');
    in >> m_fuelEfficiency;
    in.ignore(g_max_size, '\n');
    return in;
};

