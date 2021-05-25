#include <iostream>
#include <string>
#include <random>

using namespace std;


int* FillRandomArray(size_t size, int minValue, int maxValue);
	
void ArrayPrint(const int* array, size_t size, const string& message = "");


int IntInput(const string& message);

void ChangeWrongRange(int& min, int& max);
	

int SumOddValues(const int* array, size_t size);
bool IsOdd(int element);
void PrintIndexesAboveConst(size_t size, size_t number);

int* SecondElementChanged(const int* array, const size_t size);


size_t FirstNegativeElement(const int* array, size_t size);
size_t MaxNegativeElement(const int* array, size_t size);

int* ArrayCopy(const int* array, size_t size);
int* FillUserArray(size_t size, const string& message = "");
bool TryParse(size_t& value);

enum class ArrayInputWay
{
	random,
	keyboard
};

int main()
{
    cout << "Input array size = ";
    size_t size;
    // cin >> size;
    if (!TryParse(size))
    {
        cout << "Error!";
        return 3;
    }

    if (size == 0)
    {
        cout << "You entered wrong size!\n";
        return 1;
    }

   cout << "Which way of array filling are you prefer?\n"
        << static_cast<int>(ArrayInputWay::random) << " - random,\n"
        << static_cast<int>(ArrayInputWay::keyboard) << " - keyboard.\n"
        << "Your choice is ";
    int choice;
    cin >> choice;

    try
    {
        const auto chosen = static_cast<ArrayInputWay>(choice);
        int* myArray = nullptr;

        switch (chosen)
        {
        case ArrayInputWay::random:
        {
            auto minValue = IntInput("Input min value of array = ");
            auto maxValue = IntInput("Input max value of array = ");
            if (maxValue <= minValue)
            {
                ChangeWrongRange(minValue, maxValue);
            }
            myArray = FillRandomArray(size, minValue, maxValue);
            break;
        }
        case ArrayInputWay::keyboard:
        {
            myArray = FillUserArray(size, "Input elements of the array");
            break;
        }
        default:
            cout << "You entered wrong choice!\n";
            return 1;
        }

        ArrayPrint(myArray, size, "\nThe array is:\n");

        const auto sum = SumOddValues(myArray, size);
        cout << "Sum of elements odd value = " << sum << "\n";

        cout << "Input number in range [0, " << size - 1 << "] = ";
        size_t number;
        cin >> number;
        PrintIndexesAboveConst(size, number);

        const auto changedArray = SecondElementChanged(myArray, size);
        ArrayPrint(changedArray, size, "\nThe changed array is:\n");

        delete[] myArray;
        delete[] changedArray;

        cout << endl;
        return 0;
    }
    catch (out_of_range&)
    {
        cout << "You entered wrong choice!";
        return 1;
    }

}

size_t FirstNegativeElement(const int* array, const size_t size)
{
    if (array == nullptr)
        return size;

    size_t index = 0;
    while (index < size && array[index] >= 0)
    {
        index++;
    }
    return index;
}

size_t MaxNegativeElement(const int* array, const size_t size)
{
    if (array == nullptr)
        return size;

    auto maxElementIndex = FirstNegativeElement(array, size);
    for (size_t index = maxElementIndex + 1; index < size; index++)
    {
        if (array[index] < 0 && array[index] > array[maxElementIndex])
            maxElementIndex = index;
    }
    return maxElementIndex;
}

int* ArrayCopy(const int* array, const size_t size)
{
    if (array == nullptr)
        return nullptr;

    const auto target = new int[size];
    for (size_t index = 0; index < size; index++)
    {
        target[index] = array[index];
    }
    return target;
}

int* SecondElementChanged(const int* array, const size_t size)
{
    if (array == nullptr)
        return nullptr;

    const auto newArray = ArrayCopy(array, size);
    const auto maxElementIndex = MaxNegativeElement(array, size);

    /* if (maxElementIndex < size)
     {
         cout << "\nMax element is "<< array[maxElementIndex] <<"\n";
     }
     else
     {
         cout << "\nNo max element\n";
     }*/

    const auto secondElementIndex = 1;
    if (size - 1 > secondElementIndex && maxElementIndex < size)
        newArray[secondElementIndex] = newArray[maxElementIndex];
    return newArray;
}

void PrintIndexesAboveConst(const size_t size, const size_t number)
{
    cout << "Indexes above " << number << " are: ";
    for (size_t index = number + 1; index < size; index++)
    {
        cout << index << " ";
    }
}

bool IsOdd(const int element)
{
    return element % 2 != 0;
}

int SumOddValues(const int* array, const size_t size)
{
    if (array == nullptr)
        return 42;

    auto sum = 0;
    for (size_t index = 0; index < size; index++)
    {
        if (IsOdd(array[index]))
            sum += array[index];
    }
    return sum;
}

void ChangeWrongRange(int& min, int& max)
{
    min = -10;
    max = 10;
    cout << "\nYou input wrong range. Right range is ["
        << min << ","
        << max << "]\n";
}

int IntInput(const string& message)
{
    cout << message;
    int temp;
    cin >> temp;
    return temp;
}

void ArrayPrint(const int* array, const size_t size, const string& message)
{
    if (array == nullptr)
    {
        cout << "The array doesn't exist";
        return;
    }

    cout << message;
    for (size_t index = 0; index < size; index++)
    {
        cout << array[index] << " ";
    }
    cout << "\n";
}

int* FillRandomArray(const size_t size, const int minValue, const int maxValue)
{
    //Will be used to obtain a seed for the random number engine
    random_device rd;

    //Standard mersenne_twister_engine seeded with rd()
    mt19937 gen(rd());

    const uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);

    auto* array = new int[size];
    for (size_t index = 0; index < size; index++)
    {
        array[index] = uniformIntDistribution(gen);
    }

    return array;
}

int* FillUserArray(const size_t size, const string& message)
{
    auto* array = new int[size];
    cout << message << "\n";
    for (size_t index = 0; index < size; index++)
    {
        cin >> array[index];
    }
    return array;
}

bool TryParse(size_t& value)
{
    string str;
    getline(cin, str);
    const auto size = str.size();
    size_t index = 0;
    while (index < size && isdigit(str[index]))
    {
        index++;
    }

    value = stoi(str);
    return index >= size;
}













}