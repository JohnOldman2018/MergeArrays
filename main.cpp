#include <QCoreApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int a_array [9] = {4, 5, 6, 8, 23, 45, 89, 90, 532};
    int b_array [12] = {0, 1, 3, 4, 6, 7, 11, 20, 56, 66, 76, 467};

    int a_arrayLength = sizeof(a_array)/sizeof(*a_array);   // Определение длины массива a_array
    int b_arrayLength = sizeof(b_array)/sizeof(b_array[0]); // Определение длины массива b_array
    int c_arrayLength = a_arrayLength + b_arrayLength;      // Создается переменная из суммы длин обоих массивов.
    int c_array [c_arrayLength];                            // Создается новый массив c_array.

    cout << "Length of a_array = " << a_arrayLength << endl;// Длина массива a_array
    cout << "Content of a_array \t: ";                      // Показываем содержимое массива a_array
    for (int element : a_array) {
        cout << element << "  ";
    }
    cout << endl << endl;

    cout << "Length of b_array = " << b_arrayLength << endl;// Длина массива b_array
    cout << "Content of b_array \t: ";                      // Показываем содержимое массива b_array
    for (int element : b_array) {
        cout << element << "  ";
    }
    cout << endl << endl;

    cout << "Length of c_array = " << c_arrayLength << endl;// Длина массива c_array

    int temp = 0; //  Эта переменная и нижеследующая рокировка необходимы для определения последней сравниваемой величины в первом массиве.
    if (a_array[a_arrayLength - 1] > b_array[b_arrayLength - 1]){
        temp = a_array[a_arrayLength - 1];
        a_array[a_arrayLength - 1] = b_array[b_arrayLength - 1];
        b_array[b_arrayLength - 1] = temp;
    }

    int i = 0;   // три переменные k, j, i необходимы
    int j = 0;   // для независимой переборки соответствующих
    int k = 0;   // трех массивов a_array, b_array и c_array
    for (i; i < c_arrayLength; i++) {
            if (a_array[k] > b_array[j]){
            c_array[i] = b_array[j];
            j++;
        }
        else {c_array[i] = a_array[k]; k++;}
    }

    cout << "Content of c_array \t: ";    // Показываем содержимое массива c_array
    for (int element : c_array) {
        cout << element << "  ";
    }
    return a.exec();
}
