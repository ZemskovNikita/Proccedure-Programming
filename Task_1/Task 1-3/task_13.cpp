#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>

using namespace std;

double ConvertGramsToKgs(const double mass);
double DeltaTemperature(const double mass, const double Energy);

int main() {

	double massInGrams, Energy;
	cout << "Enter mass in grams and Energy in (m^2*Kgs)/sec^2\n";
	cin >> massInGrams >> Energy;
	
	const auto massInKgs = ConvertGramsToKgs(massInGrams);
	const auto Temperature = DeltaTemperature(massInKgs, Energy);
	cout << "Delta Temperature is " << Temperature;
	return 0;


}

double ConvertGramsToKgs(const double mass)
{
	const auto kiloFactor = 1000;
	return mass / kiloFactor;
}
/**
 *   \brief ����� ������� ������ �����������
 *
 *   \param mass ����� � ����������� (��).
 *   \param Energy ������ (�^2*��/�^2).
 *   \return �������� ���������� ����������� � ��������� (��).
 */

double GetKineticEnergy(const double mass, const double Energy)
{
	return (Energy / (460 * mass))-273;
}