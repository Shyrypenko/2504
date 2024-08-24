#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>

void sortArray(int* array, int size, int order = 1) {
    if (order == 1) {
        std::sort(array, array + size, std::greater<int>());
    }
    else {
        std::sort(array, array + size);
    }
}

void findAndSortBetweenNegatives(int* array, int size) {
    int left = -1, right = -1;

    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            if (left == -1) left = i;
            right = i;
        }
    }

    if (left != -1 && right != -1 && left < right) {
        std::sort(array + left + 1, array + right);
    }

    std::cout << "Массив после сортировки между крайними отрицательными элементами: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void shuffleArray(int* array, int size) {
    std::random_shuffle(array, array + size);
}

int findRandomNumberPosition(int* array, int size) {
    int randomValue = std::rand() % 21 + 1;
    std::cout << "Случайное число: " << randomValue << std::endl;

    for (int i = 0; i < size; i++) {
        if (array[i] == randomValue) {
            return i;
        }
    }
    return -1;
}

void sortArrayAroundPosition(int* array, int size, int position) {
    if (position == -1) return;

    std::sort(array, array + position, std::greater<int>());
    std::sort(array + position + 1, array + size);
}

int main() {
    std::srand(std::time(0));

    int array1[10] = { 5, 3, 8, 1, 2, 9, 7, 6, 4, 0 };
    std::cout << "Исходный массив для сортировки: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;

    sortArray(array1, 10, 0);
    std::cout << "Отсортированный массив по возрастанию: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;

    sortArray(array1, 10, 1);
    std::cout << "Отсортированный массив по убыванию: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;

 
    int array2[10] = { 3, -4, 7, -1, 2, -8, 5, 9, -3, 6 };
    std::cout << "Исходный массив для поиска крайних отрицательных элементов: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;

    findAndSortBetweenNegatives(array2, 10);

    int array3[20];
    for (int i = 0; i < 20; i++) {
        array3[i] = std::rand() % 21;
    }

    std::cout << "Исходный массив для перемешивания и сортировки: ";
    for (int i = 0; i < 20; ++i) {
        std::cout << array3[i] << " ";
    }
    std::cout << std::endl;

    shuffleArray(array3, 20);
    std::cout << "Перемешанный массив: ";
    for (int i = 0; i < 20; ++i) {
        std::cout << array3[i] << " ";
    }
    std::cout << std::endl;

    int position = findRandomNumberPosition(array3, 20);
    std::cout << "Позиция случайного числа: " << position << std::endl;

    sortArrayAroundPosition(array3, 20, position);
    std::cout << "Массив после сортировки вокруг позиции: ";
    for (int i = 0; i < 20; ++i) {
        std::cout << array3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
