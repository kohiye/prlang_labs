#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Перечисление для пунктов назначения
enum class Location { NewYork, London, Paris, Tokyo, Sydney };

// Перечисление для моделей самолетов
enum class AircraftModel {
  Boeing737,
  AirbusA320,
  Boeing777,
  AirbusA380,
  Boeing787
};

// Структура для представления информации о рейсе
struct Flight {
  AircraftModel model;
  int flightNumber;
  Location departure;
  Location destination;
  std::string departureTime;
  std::string departureDate;
  double ticketPrice;
  int availableSeats;
};

// Функция для вывода данных о рейсе
void printFlight(const Flight &flight) {
  std::cout << "Flight Number: " << flight.flightNumber << "\n"
            << "Aircraft Model: " << static_cast<int>(flight.model) << "\n"
            << "Departure: " << static_cast<int>(flight.departure) << "\n"
            << "Location: " << static_cast<int>(flight.destination) << "\n"
            << "Departure Time: " << flight.departureTime << "\n"
            << "Departure Date: " << flight.departureDate << "\n"
            << "Ticket Price: " << flight.ticketPrice << "\n"
            << "Available Seats: " << flight.availableSeats << "\n\n";
}

// Функция для чтения данных из файла и инициализации массива структур
std::vector<Flight> readFlightsFromFile(const std::string &filename) {
  std::ifstream file(filename);
  std::vector<Flight> flights;

  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return flights;
  }

  Flight flight;
  while (file >> flight.flightNumber >> reinterpret_cast<int &>(flight.model) >>
         reinterpret_cast<int &>(flight.departure) >>
         reinterpret_cast<int &>(flight.destination) >> flight.departureTime >>
         flight.departureDate >> flight.ticketPrice >> flight.availableSeats) {
    flights.push_back(flight);
  }

  file.close();
  return flights;
}

// Функция для вывода меню и выбора опции
int showMenu() {
  int choice;
  std::cout << "1. Вывести все рейсы\n"
            << "2. Выбрать рейсы по пункту назначения\n"
            << "3. Выбрать рейсы по дате вылета\n"
            << "0. Выход\n"
            << "Выберите опцию: ";
  std::cin >> choice;
  return choice;
}

// Функция для вывода рейсов по пункту назначения
void showFlightsByLocation(const std::vector<Flight> &flights,
                           Location destination) {
  std::cout << "Рейсы по пункту назначения " << static_cast<int>(destination)
            << ":\n";
  for (const auto &flight : flights) {
    if (flight.destination == destination) {
      printFlight(flight);
    }
  }
}

// Функция для вывода рейсов по дате вылета
void showFlightsByDate(const std::vector<Flight> &flights,
                       const std::string &date) {
  std::cout << "Рейсы по дате вылета " << date << ":\n";
  for (const auto &flight : flights) {
    if (flight.departureDate == date) {
      printFlight(flight);
    }
  }
}

int main() {
  // Чтение данных из файла и инициализация массива структур
  std::vector<Flight> flights = readFlightsFromFile("flights.txt");

  if (flights.empty()) {
    std::cerr << "No flights data available. Exiting.\n";
    return 1;
  }

  // Вывод всех рейсов

  // Меню выбора опций
  int choice;
  do {
    choice = showMenu();

    switch (choice) {
    case 1:
      for (const auto &flight : flights) {
        printFlight(flight);
      } // Вывести все рейсы (уже выведены выше)
      break;
    case 2: {
      // Выбрать рейсы по пункту назначения
      int destinationChoice;
      std::cout << "Выберите пункт назначения (1-5): ";
      std::cin >> destinationChoice;

      if (destinationChoice >= 1 && destinationChoice <= 5) {
        Location selectedLocation = static_cast<Location>(destinationChoice);
        showFlightsByLocation(flights, selectedLocation);
      } else {
        std::cout << "Некорректный выбор пункта назначения.\n";
      }
      break;
    }
    case 3: {
      // Выбрать рейсы по дате вылета
      std::string selectedDate;
      std::cout << "Введите дату вылета (в формате YYYY-MM-DD): ";
      std::cin >> selectedDate;

      showFlightsByDate(flights, selectedDate);
      break;
    }
    case 0:
      std::cout << "Выход.\n";
      break;
    default:
      std::cout << "Некорректный выбор. Повторите ввод.\n";
    }
  } while (choice != 0);

  return 0;
}
