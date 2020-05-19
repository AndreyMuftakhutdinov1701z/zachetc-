/*
Работу выполнил: Муфтахутдинов Андрей Михайлович, студент 1701z
Задача 2.
Запросить у пользователя размеры ящика, имеющего форму прямоугольного
параллелепипеда(длина, ширина, высота).Вычислить и вывести на консоль
минимальное количество предметов кубической формы, которыми можно
заполнить весь объём ящика.*/

#include <iostream>

int main()
{
    std::cout << "Vvedi dlinu paralelepipeda: ";
    double a = 0;
    std::cin >> a;

    std::cout << "Vvedi shiriny paralelepipeda: ";
    double b = 0;
    std::cin >> b;

    std::cout << "Vvedi vysoty paralelepipeda: ";
    double c = 0;
    std::cin >> c;
   
    double x = 0;
    int s = 0;
    int k1 = 0;
    int k2 = 0;
    int k3 = 0;
    //Пусть 1 куб берет на себя меньшую из сторон параллелепипеда
    if (a < b && a < c) x = a;
    else if (b < a && b < c) x = b;
    else if (c < a && c < b) x = c;
    else if (c == a && a < b) x = a;
    else if (a == b && a < c) x = a;
    else if (b == c && b < c) x = b;
    else if (a == b && b == c) x = a;
  
    while (x <= a) {
    a = a - x;
    ++k1;
    }//считаем сколько кубов вмещает в себя параллелепипед по длине
    while (x <= b) {
    b = b - x;
    ++k2;
    }//считаем сколько кубов вмещает в себя параллелепипед по ширине
    while (x <= c) {
    c = c - x;
    ++k3;
    }//считаем сколько кубов вмещает в себя параллелепипед по высоте
    
    s = k1 * k2 * k3;//высчитываем количество кубов
    std::cout << "Minimalnoe kolichestvo predmetov kubicheskoi formy:" << s << std::endl;
    return 0;
 
}
