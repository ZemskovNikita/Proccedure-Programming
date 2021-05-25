#include<iostream>
#include<cmath>

using namespace std;


/**
 * \brief функци€ дл€ расчета заначений табул€ции.
 * \x начало интервала.
 * \return значение табул€ции.
*/
double Tabulation(const double x);
/**
 * \brief ¬озможность выполнени€ функции.
 * \return в случае успеха, возвращает 1.
*/
bool Luck(const double x);

/**
 * \brief ¬ход в программу.
 * \return в случае успеха, возвращает 0.
*/
int main() {
	double x = 1.0;
	const auto z = 3;
	const auto step = 0.2;

	for (x; x <= z; x += step) {
		if (Luck(x))
			cout << "x: " << x << " y: " << Tabulation(x) << endl;
	}

	system("pause");
	return 0;
}

double Tabulation(double x) {
	return sin(log(x)) - cos(log(x)) + 2 * log(x);
}
	bool Luck(double x) {
	return 1 / (sin(log(x)) - cos(log(x)) + 2 * log(x)) != 0;
}

