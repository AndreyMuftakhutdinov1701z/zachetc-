﻿/*
Работу выполнил: Муфтахутдинов Андрей Михайлович, студент 1701z
Задача 2.
Запросить у пользователя размеры ящика, имеющего форму прямоугольного
параллелепипеда(длина, ширина, высота).Вычислить и вывести на консоль
минимальное количество предметов кубической формы, которыми можно
заполнить весь объём ящика.*/

#include <iostream>
int cubeCount(int a, int b, int c)
{
	int count = 0;
	int x, y;//доп переменные (коэффициенты, количество блоков по стороне B и C
	int tmpArr[3] = { a,b,c }; // доп массив, нам надо будет упорядочить  abc по возрастанию

	if ((a <= 0) || (b <= 0) || (c <= 0))return 0;//делаем проверку на ноль и отрицательное значение
											

	for (int i = 0; i < 2; i++) //упорядочиваем доп массив массив из  a b c
		for (int j = 0; j < 2; j++)
			if (tmpArr[j] > tmpArr[j + 1])
			{// это свап элементов (без доп переменной) выглядит также как и
				tmpArr[j] = tmpArr[j] + tmpArr[j + 1];// a=a+b
				tmpArr[j + 1] = tmpArr[j] - tmpArr[j + 1];// b=a-b
				tmpArr[j] = tmpArr[j] - tmpArr[j + 1];// a=a-b
			}
	a = tmpArr[0]; //теперь в а кладем наименьшую сторону
	b = tmpArr[1];//в b среднюю
	c = tmpArr[2];//с - наибольшую

	x = trunc(b / a);// в х сколько лежит кубов по стороне b
	y = trunc(c / a);// в y сколько лежит кубов по стороне c
	count = x * y;//количество в count

	if ((b - a * x) > (c - a * y))//если по стороне b  остаток толще то вычислим сколько в слоях 
		count += cubeCount(a, b - a * x, c) + cubeCount(a, a * x, c - a * y);//то вычислим его с огрызком     
	else
		count += cubeCount(a, b, c - a * y) + cubeCount(a, b - a * x, a * y);                                 
		return count;
//я задолбался рисовать эти кубики в тетрадке для проверки плак-плак...оказывается еще со времен Евклида подобное проворачивали

int main()
{
	int totalCount = 0;

	std::cout << "Vvedi dlinu paralelepipeda: ";
	int a = 0;
	std::cin >> a;
	std::cout << "Vvedi shiriny paralelepipeda: ";
	int b = 0;
	std::cin >> b;
	std::cout << "Vvedi vysoty paralelepipeda: ";
	int c = 0;
	std::cin >> c;

	totalCount = cubeCount(a, b, c);

	std::cout << "Minimalnoe kolichestvo predmetov kubicheskoi formy:" << totalCount << std::endl;
	system("pause");
	return 0;

}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
