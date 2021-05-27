#define USE_MATH_DEFINES 


#include <iostream>
#include <cmath>


using namespace std;


/*
* \brief находит значение a
* \param x Значение x
* \param y Значение z
* \param z Значение y
* \return Значение a
*/
double GetA(const double x, const double y, const double z);

/*
* \brief Находит значение b
* \param x Значение y
* \param y Значение x
* \param z Значение z
* \return Значение b
*/
double GetB(const double x, const double y, const double z);

int main()
{
	const auto x = -0.5;
	const auto y = 1.7;
	const auto z = 0.44;

	const auto a = GetA(x, y, z);
	const auto b = GetB(x, y, z);

	cout << "x = " << x << ", y =  " << y << ", z = " << z << "\n";
	cout << "a = " << a << ", b = " << b << endl;

	return 0;
}


double GetA(const double x, const double y, const double z)

{
	return exp(-y * z) * sin(x - z) - sqrt(abs(y * z + x));
}


double GetB(const double x, const double y, const double z)
{
	return y * sin(exp(-y * z) * sin(x - z) - sqrt(abs(y * z + x)) * pow(z, 2) * cos(2 * z));
}