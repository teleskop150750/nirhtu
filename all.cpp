#include <iostream> // Подключаем библиотеку для работы с вводом-выводом
#include <fstream>  // Подключаем библиотеку для работы с файлами
#include <sstream>  // Подключаем библиотеку для работы с потоками строк
#include <vector>   // Подключаем библиотеку для работы с векторами (динамическими массивами)

std::vector<std::vector<int>> createArray(int size);                                          // Прототип функции для создания двумерного массива заданного размера
void fillArray(std::vector<std::vector<int>> &arr);                                           // Прототип функции для заполнения двумерного массива
void printArray(const std::vector<std::vector<int>> &arr);                                    // Прототип функции для вывода двумерного массива на экран
void writeArrayToFile(const std::vector<std::vector<int>> &arr, const std::string &filename); // Прототип функции для записи двумерного массива в файл
std::vector<std::vector<int>> readArrayFromFile(const std::string &filename);                 // Прототип функции для чтения двумерного массива из файла
std::pair<int, int> countZeroesAndOnes(const std::vector<std::vector<int>> &arr);             // Прототип функции для подсчета количества нулей и единиц в двумерном массиве

int main()
{
    // 1.1 Создание
    auto arr = createArray(5); // Создаем двумерный массив размером 5x5

    // 1.2 Заполнение массива
    fillArray(arr); // Заполняем массив: устанавливаем единицы на диагоналях

    // 1.3 Вывод массива на экран
    printArray(arr); // Выводим массив на экран

    // 1.4 Запись массива в файл
    writeArrayToFile(arr, "array.txt"); // Записываем массив в файл с именем "array.txt"

    // 2.1 Чтение массива из файла
    auto arr_from_file = readArrayFromFile("array.txt"); // Читаем двумерный массив из файла с именем "array.txt"

    // 2.2 Вывод массива на экран
    printArray(arr_from_file); // Выводим прочитанный массив на экран

    // 2.3 Подсчет количества 0 и 1
    auto [countZero, countOne] = countZeroesAndOnes(arr_from_file); // Подсчитываем количество нулей и единиц в массиве
    std::cout << "Number of 0s: " << countZero << '\n';             // Выводим количество нулей на экран
    std::cout << "Number of 1s: " << countOne << '\n';              // Выводим количество единиц на экран

    return 0; // Возвращаем 0, что означает успешное завершение программы
}

/**
 * Функция для создания двумерного массива заданного размера.
 * @param size Размер массива.
 * @return Двумерный массив размера size x size, заполненный нулями.
 */
std::vector<std::vector<int>> createArray(int size)
{
    std::vector<std::vector<int>> arr(size, std::vector<int>(size, 0));
    return arr; // Возвращаем созданный вектор
}

/**
 * Функция для заполнения двумерного массива.
 * Заполняет диагонали массива единицами.
 * @param arr Ссылка на двумерный массив.
 */
void fillArray(std::vector<std::vector<int>> &arr)
{
    const int size = arr.size();       // Получаем размер массива
    const int rowSize = arr[0].size(); // Получаем размер строки arr[i]
    const int middle = size / 2;       // Вычисляем середину массива

    for (int i = 0; i < size; i++) // Проходим по каждой строке массива
    {
        // Если i больше середины массива, то пропускаем итерацию
        if (i > middle)
        {
            continue;
        }

        for (int j = 0; j < rowSize; j++) // Проходим по каждому элементу строки
        {
            // Индекс элемента, симметричного элементу с индексом i
            int endIdx = rowSize - 1 - j;

            // Если текущий индекс равен индексу элемента или индексу симметричного элемента,
            // то устанавливаем значение элемента равным 1
            if (i == j || i == endIdx)
            {
                arr[i][j] = 1;
            }
        }
    }
}

/**
 * Функция для вывода двумерного массива на экран.
 * @param arr Константная ссылка на двумерный массив.
 */
void printArray(const std::vector<std::vector<int>> &arr)
{
    std::cout << "Вывод массива на экран:\n"; // Выводим начальное сообщение

    for (const auto &row : arr) // Проходим по каждой строке массива
    {
        for (int num : row) // В каждой строке проходим по каждому элементу
        {
            std::cout << num << ' '; // Выводим текущий элемент на экран
        }
        std::cout << '\n'; // Переходим на новую строку после вывода всех элементов текущей строки
    }

    std::cout << '\n'; // Выводим пустую строку для отделения вывода разных массивов
}

/**
 * Функция для записи двумерного массива в файл.
 * @param arr Константная ссылка на двумерный массив.
 * @param filename Имя файла для записи.
 */
void writeArrayToFile(const std::vector<std::vector<int>> &arr, const std::string &filename)
{
    std::ofstream file_out(filename); // Создаем объект ofstream для записи в файл с указанным именем

    for (const auto &row : arr) // Проходим по каждой строке массива
    {
        for (int num : row) // В каждой строке проходим по каждому элементу
        {
            file_out << num << ' '; // Записываем текущий элемент в файл
        }

        file_out << '\n'; // Переходим на новую строку в файле после записи всех элементов текущей строки
    }

    file_out.close(); // Закрываем файл после записи
}

/**
 * Функция для чтения двумерного массива из файла.
 * @param filename Имя файла для чтения.
 * @return Двумерный массив, прочитанный из файла.
 */
std::vector<std::vector<int>> readArrayFromFile(const std::string &filename)
{
    std::ifstream file_in(filename); // Создаем объект ifstream для чтения из файла с указанным именем

    if (!file_in) // Если файл не удалось открыть
    {
        std::cerr << "Unable to open file\n"; // Выводим сообщение об ошибке

        return {}; // Возвращаем пустой массив
    }

    std::vector<std::vector<int>> arr; // Создаем двумерный массив для хранения прочитанных данных
    std::string line;                  // Создаем строку для хранения текущей строки файла

    while (std::getline(file_in, line)) // Читаем файл построчно
    {
        std::istringstream iss(line); // Создаем строковый поток из текущей строки
        std::vector<int> row;         // Создаем одномерный массив для хранения текущей строки двумерного массива
        int num;                      // Создаем переменную для хранения текущего числа

        while (iss >> num) // Читаем числа из текущей строки
        {
            row.push_back(num); // Добавляем текущее число в текущую строку
        }

        arr.push_back(row); // Добавляем текущую строку в двумерный массив
    }

    file_in.close(); // Закрываем файл после чтения

    return arr; // Возвращаем прочитанный массив
}

/**
 * Функция для подсчета количества нулей и единиц в двумерном массиве.
 * @param arr Константная ссылка на двумерный массив.
 * @return Пара чисел: количество нулей и количество единиц.
 */
std::pair<int, int> countZeroesAndOnes(const std::vector<std::vector<int>> &arr)
{
    int countZeroes = 0; // Создаем счетчик для нулей
    int countOnes = 0;   // Создаем счетчик для единиц

    for (const auto &row : arr) // Проходим по каждой строке массива
    {
        for (int num : row) // В каждой строке проходим по каждому элементу
        {
            if (num == 0) // Если текущий элемент равен нулю
            {
                countZeroes++; // Увеличиваем счетчик нулей
            }
            else if (num == 1) // Если текущий элемент равен единице
            {
                countOnes++; // Увеличиваем счетчик единиц
            }
        }
    }

    return {countZeroes, countOnes}; // Возвращаем пару: количество нулей и количество единиц
}
