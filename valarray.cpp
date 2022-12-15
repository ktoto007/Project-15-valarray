//Підключення бібліотек
#include <iostream>
#include "Matrixs.h"
#include <Windows.h>

//Головна функція
int main()
{
    //підключення української мови до консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //Екземпляр класу Matrixs
    Matrixs M;

    //змінна num
    int num=0;
    do {
        //Меню програми
        cout << "Виберіть пункт меню" << endl;
        cout << "1. Заповнення масиву вручну за допомогою виділення памяті вказівником" << endl;
        cout << "2. Заповнення масиву з файлу за допомогою виділення памяті вказівником" << endl;
        cout << "3. Заповнення масиву вручну за допомогою визначення типів, використовуючи valarray" << endl;
        cout << "4. Заповнення масиву з файлу за допомогою визначення типів, використовуючи valarray" << endl;
        cout << "5. Заповнення масиву вручну за допомогою контейнеру vector" << endl;
        cout << "6. Заповнення масиву з файлу за допомогою контейнеру vector" << endl;
        cout << "7. Виведення масиву на консоль за допомогою виділення памяті вказівником" << endl;
        cout << "8. Виведення масиву на консоль за допомогою визначення типів, використовуючи valarray" << endl;
        cout << "9. Виведення масиву на консоль за допомогою контейнеру vector" << endl;
        cout << "10. Конволюція масиву за допомогою виділення памяті вказівником" << endl;
        cout << "11. Конволюція масиву за допомогою визначення типів, використовуючи valarray" << endl;
        cout << "12. Конволюція масиву за допомогою контейнеру vector" << endl;
        cout << "0. Вихід" << endl;
        cin >> num; //вибір пункта меню
        
        switch (num)
        {
        case 1: {
            clock_t start = clock();
            M.UkazAdd();
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "Затрачений час: " << seconds << " секунд" << endl;
            break;
        }
        case 2: {
            clock_t start = clock();
            M.UkazFile();
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "Затрачений час: " << seconds << " секунд" << endl;
            break;
        }
        case 3: {
            clock_t start = clock();
            M.ValarrayAdd();
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "Затрачений час: " << seconds << " секунд" << endl;
            break;
        }
        case 4: {
            clock_t start = clock();
            M.ValarrayFile();
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "Затрачений час: " << seconds << " секунд" << endl;
            break;
        }
        case 5: {
            clock_t start = clock();
            M.VectorAdd();
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "Затрачений час: " << seconds << " секунд" << endl;
            break;
        }
        case 6: {
            clock_t start = clock();
            M.VectorFile();
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "Затрачений час: " << seconds << " секунд" << endl;
            break;
        }
        case 7: {
            clock_t start = clock();
            M.UkazPrint();
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "Затрачений час: " << seconds << " секунд" << endl;
            break;
        }
        case 8: {
            clock_t start = clock();
            M.ValarrayPrint();
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "Затрачений час: " << seconds << " секунд" << endl;
            break;
        }
        case 9: {
            clock_t start = clock();
            M.VectorPrint();
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "Затрачений час: " << seconds << " секунд" << endl;
            break;
        }
        case 10: {
            clock_t start = clock();
            M.ConvolutionM1();
            M.UkazPrint();
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "Затрачений час: " << seconds << " секунд" << endl;
            break;
        }
        case 11: {
            clock_t start = clock();
            M.ConvolutionM2();
            M.ValarrayPrint();
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "Затрачений час: " << seconds << " секунд" << endl;
            break;
        }
        case 12: {
            clock_t start = clock();
            M.ConvolutionM3();
            M.VectorPrint();
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "Затрачений час: " << seconds << " секунд" << endl;
            break;
        }
        default:
            break;
        }

    } while (num != 0);

    return 0;
}

