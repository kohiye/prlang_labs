#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Laptop {
  std::string brand;
  std::string model;
  double screenSizeInInches;
  int memoryInGB;
  bool hasSSD;
};

using laptopList = std::vector<Laptop>;

void print(laptopList laptops) {
  std::cout << "Laptop List:\n";
  int index{0};
  for (const auto &laptop : laptops) {
    std::cout << "Index: " << index++ << ", Brand: " << laptop.brand
              << ", Model: " << laptop.model
              << ", Screen Size: " << laptop.screenSizeInInches << " inches"
              << ", Memory: " << laptop.memoryInGB << " GB"
              << ", Has SSD: " << (laptop.hasSSD ? "Yes" : "No") << "\n";
  }
}

int showMenu() {
  int choice;
  std::cout << "\nMenu:\n"
            << "1. Print the list\n"
            << "2. Add new laptop\n"
            << "3. Delete a laptop\n"
            << "4. Clear the list\n"
            << "5. Export list to a file\n"
            << "6. Import list from a file\n"
            << "0. Exit\n"
            << "Enter your choice: ";
  std::cin >> choice;
  return choice;
}
void addLaptop(laptopList &laptops) {
  Laptop newLaptop;
  std::cout << "Enter laptop details:\n";
  std::cout << "Brand: ";
  std::cin >> newLaptop.brand;
  std::cout << "Model: ";
  std::cin >> newLaptop.model;
  std::cout << "Screen Size (in inches): ";
  std::cin >> newLaptop.screenSizeInInches;
  std::cout << "Memory (in GB): ";
  std::cin >> newLaptop.memoryInGB;
  std::cout << "Has SSD (1 for Yes, 0 for No): ";
  std::cin >> newLaptop.hasSSD;

  laptops.push_back(newLaptop);
  std::cout << "Laptop added successfully.\n";
}

void deleteLaptop(laptopList &laptops) {
  if (laptops.empty()) {
    std::cout << "The list is empty. Cannot delete.\n";
    return;
  }

  int index;
  std::cout << "Enter the index of the laptop to delete (0 to "
            << laptops.size() - 1 << "): ";
  std::cin >> index;

  if (index >= 0 && index < laptops.size()) {
    laptops.erase(laptops.begin() + index);
    std::cout << "Laptop deleted successfully.\n";
  } else {
    std::cout << "Invalid index. No laptop deleted.\n";
  }
}

void clearList(laptopList &laptops) {
  laptops.clear();
  std::cout << "List cleared successfully.\n";
}

void exportToFile(const laptopList &laptops, const std::string &filename) {
  std::ofstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return;
  }

  for (const auto &laptop : laptops) {
    file << laptop.brand << " " << laptop.model << " "
         << laptop.screenSizeInInches << " " << laptop.memoryInGB << " "
         << laptop.hasSSD << "\n";
  }

  file.close();
  std::cout << "List exported to file successfully.\n";
}

void importFromFile(laptopList &laptops, const std::string &filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return;
  }

  laptops.clear();

  Laptop laptop;
  while (file >> laptop.brand >> laptop.model >> laptop.screenSizeInInches >>
         laptop.memoryInGB >> laptop.hasSSD) {
    laptops.push_back(laptop);
  }

  file.close();
  std::cout << "List imported from file successfully.\n";
}

int main() {
  laptopList laptops;

  int choice;
  do {
    choice = showMenu();

    switch (choice) {
    case 1:
      print(laptops);
      break;
    case 2:
      addLaptop(laptops);
      break;
    case 3:
      deleteLaptop(laptops);
      break;
    case 4:
      clearList(laptops);
      break;
    case 5: {
      std::string filename;
      std::cout << "Enter the filename to export to: ";
      std::cin >> filename;
      exportToFile(laptops, filename);
      break;
    }
    case 6: {
      std::string filename;
      std::cout << "Enter the filename to import(overwrite) from: ";
      std::cin >> filename;
      importFromFile(laptops, filename);
      break;
    }
    case 0:
      std::cout << "Exiting the program.\n";
      break;
    default:
      std::cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 0);

  return 0;
}
