#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Функция вывода массива на экран
void printArray(const std::vector<std::vector<int>> &arr)
{
    std::cout << "Вывод массива на экран:\n";

    for (const auto &row : arr)
    {
        for (int num : row)
        {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }

    std::cout << '\n';
}

// Функция чтения массива из файла
std::vector<std::vector<int>> readArrayFromFile(const std::string &filename)
{
    std::vector<std::vector<int>> arr;
    std::ifstream file_in(filename);
    std::string line;
    while (getline(file_in, line))
    {
        std::vector<int> row;
        int num;
        std::istringstream iss(line);
        while (iss >> num)
        {
            row.push_back(num);
        }
        arr.push_back(row);
    }
    file_in.close();
    return arr;
}

// Функция для подсчета 0 и 1
std::pair<int, int> countZeroesAndOnes(const std::vector<std::vector<int>> &arr)
{
    int countZero = 0, countOne = 0;
    for (const auto &row : arr)
    {
        for (int num : row)
        {
            if (num == 0)
                ++countZero;
            else if (num == 1)
                ++countOne;
        }
    }
    return {countZero, countOne};
}

int main()
{
    // 1. Чтение файла
    auto arr_from_file = readArrayFromFile("array.txt");

    // 2. Вывод массива на экран
    printArray(arr_from_file);

    // 3. Подсчет количества 0 и 1
    auto [countZero, countOne] = countZeroesAndOnes(arr_from_file);
    std::cout << "Number of 0s: " << countZero << '\n';
    std::cout << "Number of 1s: " << countOne << '\n';

    return 0;
}
