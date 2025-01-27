#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int reverseDigits(int num)
{
    string numStr = to_string(num);
    int i, j;

    for (i = 0, j = numStr.length() - 1; i < j; ++i, --j)
    {
        swap(numStr[i], numStr[j]);
    }

    while (numStr.length() < 3)
    {
        numStr += '0';
    }

    return stoi(numStr);
}

int sumDigits(int num)
{
    int sum = 0;

    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

void customSort(vector<int> &vec)
{
    size_t i, j;

    for (i = 0; i < vec.size(); ++i)
    {
        for (j = i + 1; j < vec.size(); ++j)
        {
            if (vec[j] < vec[i])
            {
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
}

int main()
{
    vector<int> randomNumbers;
    vector<int> reversedNumbers;
    vector<int> digitSums;

    int i;
    int num;

    srand(time(0));

    for (i = 0; i < 20; ++i)
    {
        randomNumbers.push_back(100 + rand() % 900);
    }

    customSort(randomNumbers);

    for (i = 0; i < randomNumbers.size(); ++i)
    {
        num = randomNumbers[i];
        reversedNumbers.push_back(reverseDigits(num));
        digitSums.push_back(sumDigits(num));
    }

    cout << "Random Numbers: ";
    
    for (i = 0; i < randomNumbers.size(); ++i)
    {
        cout << randomNumbers[i] << " ";
    }

    cout << endl;
    cout << "Reversed Numbers: ";

    for (i = 0; i < reversedNumbers.size(); ++i)
    {
        cout << setw(3) << setfill('0') << reversedNumbers[i] << " ";
    }

    cout << endl;
    cout << "Sum of Digits: ";

    for (i = 0; i < randomNumbers.size(); ++i)
    {
        cout << "Sum of digits of " << randomNumbers[i] << " is " << digitSums[i] << endl;
    }

    return 0;
}
