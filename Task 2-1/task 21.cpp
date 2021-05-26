#include <iostream>
#include <string>
#include <clocale>

using namespace std;


/**
* \brief ������������� ��� ����������, ��� ������� ������� �����, ��������, ������������, �������.
*/
enum class Result {


	/**
	* \brief ����������� �����.
	*/
	none,


	/**
	 * \brief ������ --- ����� �����.
	 */
	sum,


	 /**
	  * \brief ������ --- �������� �����.
	  */
	 difference,


	  /**
	   * \brief ������ --- ������������ �����.
	   */
	 product,


	   /**
		* \brief ������ --- �������� �����.
		*/
	 quotient,
};

/**
 * \brief ������� ������� ����� �����.
 * \param ����� "a".
 * \return �����.
 */
double GetSumOfNumbers(const double a);

/**
 * \brief ������� ������� �������� �����.
 * \param ����� "a".
 * \return ��������.
 */
double GetDifferenceOfNumbers(const double a);

/**
 * \brief ������� ������� ������������ �����.
 * \param ����� "a".
 * \return ������������.
 */
double GetProductOfNumbers(const double a);

/**
 * \brief ������� ������� �������� �����.
 * \param ����� "a".
 * \return �������
 */
double GetQuotientOfNumbers(const double a);

/**
 * \brief ���� ������ �����.
 * \param message ������������ �������.
 * \param out ������������ ����� ������.
 * \param in ������������ ����� �����.
 * \return ��������� ��������.
 */
double WriteaANumber(const string& message = "", ostream& out = cout, istream& in = cin);

/**
 * \brief
 * \param message ��������� ��� ������������.
 * \param out ������������ ����� ������.
 * \param in ������������ ����� �����.
 * \return �� ��� ������ ������������.
 */
Result ReadUserChoice(const string& message = "", ostream& out = cout, istream& in = cin);


int main() {
	setlocale(0, "");

	const auto message = "�������� ��� ���������: "
		+ to_string(static_cast<int>(Result::sum)) + " - �����,"
		+ to_string(static_cast<int>(Result::difference)) + " - ��������,"
		+ to_string(static_cast<int>(Result::product)) + " - �������������,"
		+ to_string(static_cast<int>(Result::quotient)) + " - �������\n";

	const auto result = ReadUserChoice(message);

	switch (result) {
		case Result::sum: {
			const auto number = WriteaANumber("������� ����� = ");

			const auto Sum = GetSumOfNumbers(number);
			cout << "\n����� " << Sum << endl;
			break;
		}
		case Result::difference: {
		const auto number = WriteaANumber("������� ����� = ");

		const auto difference = GetDifferenceOfNumbers(number);
		cout << "\n��������� " << difference << endl;
		break;
		}
		case Result::product: {
			const auto number = WriteaANumber("������� ����� = ");

			const auto product = GetProductOfNumbers(number);
			cout << "\n������������ " << product << endl;
			break;
		}
		case Result::quotient: {
			const auto number = WriteaANumber("������� ����� = ");

			const auto quotient = GetQuotientOfNumbers(number);
			cout << "\n������� " << quotient << endl;
			break;
		}
	default:
		cout << "������!";
	}
	system("pause");
	return 0;
}

double GetSumOfNumbers(const double a) {
	return a + a;
}

double GetDifferenceOfNumbers(const double a) {
	return a - a;
}

double GetProductOfNumbers(const double a) {
	return a * a;
}
double GetQuotientOfNumbers(const double a) {
	return a / a;
}

double WriteaANumber(const string& message, ostream& out, istream& in) {
	out << message;
	double number;
	in >> number;
	return number;
}

Result ReadUserChoice(const string& message, ostream& out, istream& in) {
	out << message;
	int userInput;
	in >> userInput;
	return static_cast<Result>(userInput);
}