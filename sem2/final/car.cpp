#include "car.h"

Car::Car(const std::string_view make, int year, double fuelEff, int numSeats)
    :Vehicle(make, year, fuelEff),m_numSeats{numSeats}{};
std::ostream& Car::print(std::ostream& out) const 
{
    out <<"Car("<<m_make<<", "<<m_year<<", "<<m_fuelEfficiency<<", "<<m_numSeats<<')';
    return out;
};

std::istream& Car::read(std::istream& in)
{
    std::getline(in, m_make, ',');
    in >> m_year;
    in.ignore(g_max_size, ',');
    in >> m_fuelEfficiency;
    in.ignore(g_max_size, ',');
    in >> m_numSeats;
    in.ignore(g_max_size, '\n');
    return in;
};
