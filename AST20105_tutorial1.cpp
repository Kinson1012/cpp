// Leung Ming Hei
// H10006255

#include <iostream>
using namespace std;

void calculation(int init_num, int diff, int ratio, int numofterm)
{
    //diff declaring variables
    int geo = 0, arith = 0;
    int i = 0, j = 0;
    while (i <= (numofterm - 1))//calculation sum of as
    {
        arith += (init_num + i * diff);
        i++;
    }

    while (j <= (numofterm - 1))//calculation sum of gs
    {
        geo += init_num * pow(ratio, j);
        j++;
    }
    cout << "Arithmetic Sum: " << arith << endl;
    cout << "Geometric Sum: " << geo << endl;
}

bool validation(int init_num, int diff, int ratio, int numofterm)
{
    int geo, arith;
    if (init_num == 0 || diff == 0 || ratio == 0 || numofterm == 0)//validation of is/are zero value in 4 variables
    {
        cout << "At least one of your inputs is/are zero value.  Programme terminates." << endl;
        return false;
    }
    else if (init_num < 0 || diff < 0 || ratio < 0 || numofterm < 0)//validation of is/are invalid value in 4 variables
    {
        cout << "At least one of the inputs is invalid!  All inputs must be positive non-zero integers!" << endl;
        return true;
    }
    else//validation suceed and running calculation part
    {
        cout << endl;
        calculation(init_num, diff, ratio, numofterm);
        return true;
    }
}

int main()
{
    //declaring variables
    int init_num, diff, ratio, numofterm;
    bool valid = true;
    do
    {
        //asking user input
        cout << "\nEnter an initial value, a: ";
        cin >> init_num;
        cout << "Enter difference for arithmetic sequence: ";
        cin >> diff;
        cout << "Enter ratio for geometric sequence: ";
        cin >> ratio;
        cout << "Enter number of term(s): ";
        cin >> numofterm;
        cout << endl;
        valid = validation(init_num, diff, ratio, numofterm);//pass by value to validation()
    } while (valid);
}
