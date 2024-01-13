#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Функция для создания массива
std::vector<std::vector<int>> createArray(int size)
{
    std::vector<std::vector<int>> arr(size, std::vector<int>(size, 0));
    return arr;
}

// Функция заполнения массива
void fillArray(std::vector<std::vector<int>> &arr)
{
    const int size = arr.size(); // Размер массива
    const int rowSize = arr[0].size(); // Размер строки arr[i]
    const int middle = size / 2; // Середина массива

    for (int i = 0; i < size; i++)
    {
        // Если i больше середины массива, то пропускаем итерацию
        if (i > middle)
        {
            continue;
        }

        for (int j = 0; j < rowSize; j++)
        {
            // Индекс элемента, симметричного элементу с индексом i
            int endIdx = rowSize - 1 - j;
            
            if (i == j || i == endIdx)
            {
                arr[i][j] = 1;
            }
        }
    }
}

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

// Функция записи массива в файл
void writeArrayToFile(const std::vector<std::vector<int>> &arr, const std::string &filename)
{
    std::ofstream file_out(filename);
    for (const auto &row : arr)
    {
        for (int num : row)
        {
            file_out << num << ' ';
        }
        file_out << '\n';
    }
    file_out.close();
}

int main()
{
    // 1. Создание
    auto arr = createArray(5);

    // 2. Заполнение массива
    fillArray(arr);

    // 3. Вывод массива на экран
    printArray(arr);

    // 4. Запись массива в файл
    writeArrayToFile(arr, "array.txt");

    return 0;
}
