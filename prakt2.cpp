

#include <iostream>

#include <string>
#include <deque>
using namespace std;

int main()
{
	deque<double> Dec1;// первая очередь тип 3 = double
	int N = 0; // кол-во эл. в очереди
	//a.d1 прочитать из стандартного ввода, d1 содержит n элементов, n задаётся пользователем.
	setlocale(LC_ALL, "Russian");
	cout << "*****************a**********" << endl;
	cout << "Введите кол-во элементов очереди" << endl;
	cin >> N;
	cout << "Поочередно вводите элементы очереди" << endl;	
	for (int i = 0; i < N; i++)
	{
		double temp = 0.0;
		cin >> temp;
		Dec1.push_back(temp);
	}
	//b.Проитерировать по контейнеру d1 и создать deque<тип 3> d2 такой, что d2[i] = d1[i - 1]<операция типа 2>d1[i]
	cout << "*****************b**********" << endl;
	cout << "Создана очередь Dec2 такая что Dec2[i] = Dec1[i - 1] - Dec1[i], при чем Dec2[0] = -Dec1[0]" << endl; // операция типа 2 = -
	deque<double>::const_iterator itDec1;
	itDec1 = Dec1.begin();
	deque<double> Dec2; // вторая очередь
	Dec2.push_back(-(*itDec1));
	itDec1++;
	while (itDec1 != Dec1.end())
	{
		Dec2.push_back(*(itDec1 - 1) - *itDec1);
		itDec1++;
	}

	//c.Вывести d2 на экран.Для вывода проитерировать по элементам от 0 - го до n - 1 - го с помощью итератора(deque<тип 3>::const_iterator)
	cout << "*****************c**********" << endl;
	deque<double>::const_iterator itDec2;
	itDec2 = Dec2.begin();
	cout << "Вывод Dec2 на экран" << endl;
	while (itDec2 != Dec2.end())
	{
		cout << *itDec2 << " ";
		itDec2++;
	}
	cout << endl;
	// d.Создать и вывести на экран deque<тип 3> d3 такой, что d3 получается :
	//iv.поочерёдной вставкой : d2[0] - в конец, d2[n - 1] - в начало, d2[1] - в конец, d2[n - 2] - в начало и т.д.
	//Для вывода проитерировать по элементам d3 с помощью итератора deque<тип 3>::const_iterator
	cout << "*****************d**********" << endl;
	cout << "Создана очередь Dec2 поочерёдной вставкой : d2[0] - в конец, d2[n - 1] - в начало, d2[1] - в конец, d2[n - 2] - в начало и т.д." << endl;
	deque<double> Dec3;
	deque<double>::const_iterator itDec2Beg;
	itDec2Beg = Dec2.begin();
	deque<double>::const_iterator itDec2End;
	itDec2End = Dec2.end() - 1;
	while(itDec2End - itDec2Beg > 0)
	{
		Dec3.push_back(*itDec2Beg);
		Dec3.push_front(*itDec2End);
		itDec2Beg++;
		itDec2End--;
	}

	cout << "Вывод Dec3 на экран" << endl;
	deque<double>::const_iterator itDec3;
	itDec3 = Dec3.begin();
	
	while (itDec3 != Dec3.end())
	{
		cout << *itDec3 << " ";
		itDec3++;
	}
	cout << endl;
	
	//e.Стереть
	//i.элемент d1[i1](i1 - задаётся пользователем)
	cout << "*****************e**********" << endl;
	int i1;
	cout << "Введите номер элемента который надо удалить из Dec1" << endl;
	cin >> i1;
	Dec1.erase(Dec1.begin() + i1 - 1);
	cout << "Вывод нового Dec1" << endl;
	itDec1 = Dec1.begin();
	while (itDec1 != Dec1.end())
	{
		cout << *itDec1 << " ";
		itDec1++;
	}
	cout << endl;
	//	f.Вставить в заданную пользователем позицию i2 листа d1 и вывести d1 на экран в обратном порядке
	//	iii.лист d3
	cout << "*****************f**********" << endl;
	int i2;
	cout << "Введите номер позиции в которую нужно добавить Dec3" << endl;
	cin >> i2;
	itDec3 = Dec3.begin();
	while (itDec3 != Dec3.end())
	{
		Dec1.insert((Dec1.begin() + i2), *itDec3);
		itDec3++;
		i2++;
	}
	cout << "Вывод Dec1 в который добавлен Dec3 " << endl;
	itDec1 = Dec1.begin();
	while (itDec1 != Dec1.end())
	{
		cout << *itDec1 << " ";
		itDec1++;
	}
	cout << endl;
	cout << "Вывод перевернутого Dec1 " << endl;
	deque<double>::const_reverse_iterator ritDec1;
	ritDec1 = Dec1.rbegin();
	while (ritDec1 != Dec1.rend())
	{
		cout << *ritDec1 << " ";
		ritDec1++;
	}
	cout << endl;
	return 0;

}

//В условии :
//
//<тип N> -это любой стандартный тип int, char, double, string…
//
//<операция типа N> -любая стандартная операция : +, -, * …
//
//<тип 1> и <тип 2> -разные типы, то же с операциями : разные номера – > разные типы

//3. Создать элемент типа deque<тип 3> d1
//a.d1 прочитать из стандартного ввода, d1 содержит n элементов, n задаётся пользователем.
//
//b.Проитерировать по контейнеру d1 и создать deque<тип 3> d2 такой, что d2[i] = d1[i - 1]<операция типа 2>d1[i]
//
//c.Вывести d2 на экран.Для вывода проитерировать по элементам от 0 - го до n - 1 - го с помощью итератора(deque<тип 3>::const_iterator)
//d.Создать и вывести на экран deque<тип 3> d3 такой, что d3 получается :

//iv.поочерёдной вставкой : d2[0] - в конец, d2[n - 1] - в начало, d2[1] - в конец, d2[n - 2] - в начало и т.д.

//Для вывода проитерировать по элементам d3 с помощью итератора deque<тип 3>::const_iterator
//
//e.Стереть
//
//i.элемент d1[i1](i1 - задаётся пользователем)
//

//	f.Вставить в заданную пользователем позицию i2 листа d1 и вывести d1 на экран в обратном порядке

//	iii.лист d3

