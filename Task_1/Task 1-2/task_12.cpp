#define USE_MATH_DEFINES

#include <iostream>
#include <cmath>


using namespace std;

/**
 * \brief ������� ����� ������
 * \parama x
 * \return ��������� ��������
 */
double InputValue();

/**
 * \brief ������� ������� ����� ���� �����
 * \param x
 * \param y
 * \return �����
 */
double sum(const double x, const double y);

/**
 * \brief ������� ������� �������� ���� �����
 * \param x
 * \param y
 * \return ��������
 */
double difference(const double x, const double y);

/**
 * \brief ������� ������� ������������ ���� �����
 * \param x
 * \param y
 * \return ������������
 */
double product(const double x, const double y);

/**
 * \brief ������� ������� �������� ���� �����
 * \param x
 * \param y
 * \return �������
 */
double quotient(const double x, const double y);




int main() {

	const auto x = InputValue();
	const auto y = InputValue();

	const auto a = sum(x, y);
	const auto b = difference(x, y);
	const auto � = product(x, y);
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