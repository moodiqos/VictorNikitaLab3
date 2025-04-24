#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib> 

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

int main(int argc, char* argv[]) {
    std::vector<int> arr;

    if (argc > 1) {
        std::stringstream ss(argv[1]);
        std::string number;

        while (std::getline(ss, number, ' ')) {
            try {
                arr.push_back(std::strtol(number.c_str(), nullptr, 10));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Ошибка: Некорректный аргумент: " << number << std::endl;
                return 1; 
            } catch (const std::out_of_range& e) {
                std::cerr << "Ошибка: Число слишком большое: " << number << std::endl;
                return 1; 
            }
        }
    } else {
        return 2;
    }

    std::cout << "Исходный массив: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    bubbleSort(arr);

    std::cout << "Отсортированный массив: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}