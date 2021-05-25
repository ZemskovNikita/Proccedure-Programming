#define USE_MATH_DEFINES

#include <iostream>
#include <cmath>


using namespace std;

/**
 * \brief функция ввода данных
 * \parama x
 * \return Введенное значение
 */
double InputValue();

/**
 * \brief функция расчета суммы двух чисел
 * \param x
 * \param y
 * \return сумма
 */
double sum(const double x, const double y);

/**
 * \brief функция расчета разности двух чисел
 * \param x
 * \param y
 * \return разность
 */
double difference(const double x, const double y);

/**
 * \brief функция расчета произведения двух чисел
 * \param x
 * \param y
 * \return произведение
 */
double product(const double x, const double y);

/**
 * \brief функция расчета частного двух чисел
 * \param x
 * \param y
 * \return частное
 */
double quotient(const double x, const double y);




int main() {

	const auto x = InputValue();
	const auto y = InputValue();

	const auto a = sum(x, y);
	const auto b = difference(x, y);
	const auto с = product(x, y);
	const auto d= quotient(x, y);


	cout << "x = " << x << ", y = " << y << endl;
	cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << endl;

	return 0;
} 

double InputValue() {
	double z;
	cout << "Input value: " << endl;
	cin >> z;

	return z;
}

double sum(const double x, const double y) {
	
	return x + y;
}

double difference(const double x, const double y) {
	
	return x - y;
}

double product(const double x, const double y) {
	
	return x * y;
}

double quotient(const double x, const double y) {
	
	return x / y;
}