#ifndef CAR_H
#define CAR_H
#include "const.h"
#include "vehicle.h"
class Car : public Vehicle
{
private:
    int m_numSeats{};
public:
    Car(const std::string_view make="", int year=0, double fuelEff=0, int numSeats=0);

    std::ostream& print(std::ostream& out) const override;
    std::istream& read(std::istream& in) override;

    void signal() const override { std::cout << "BEEP\n";};

    int getNumSeats() const {return m_numSeats;};

    ~Car() = default;
};
#endif
