#ifndef VEHICLE_H
#define VEHICLE_H
#include "const.h"
class Vehicle
{
private:
    static inline int s_count{0};
protected:
    std::string m_make;
    int m_year{};
    double m_fuelEfficiency{};
public:
    Vehicle(const std::string_view make="", int year=0, double fuelEff=0);

    friend std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle);
    friend std::istream& operator>>(std::istream& in, Vehicle& vehicle);

    virtual std::ostream& print(std::ostream& out) const;
    virtual std::istream& read(std::istream& in);

    virtual void signal() const = 0;

    const std::string& getMake() const {return m_make;};
    int getYear() const {return m_year;};
    double getFuelEfficiency() const {return m_fuelEfficiency;};
    int getCount() const {return s_count;};

    virtual ~Vehicle() = default;
};
#endif
