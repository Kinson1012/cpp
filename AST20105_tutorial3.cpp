// Leung Ming Hei
// H10006255
//group with H10006098

#include <iostream>
#include <cmath>
using namespace std;

double sub_num(int A, int B, int C, double x)
{
    return (A * pow(x, 2) + B * x + C);
}

bool validation(double fx1, double fx2)
{
    bool check = false;
    if (signbit(fx1) != signbit(fx2))
    {
        check = true;
    }
    return check;
}

double inter_bisection(int A, int B, int C, double x1, double x2, double fx1, double fx2)
{
    double m, fm;
    do
    {
        m = (x1 + x2) / 2;
        fm = sub_num(A, B, C, m);
        fx1 = sub_num(A, B, C, x1);
        fx2 = sub_num(A, B, C, x2);
        if (validation(fx1, fm) != 1)
        {
            x1 = m;
        }
        else if (validation(fx2, fm) != 1)
        {
            x2 = m;
        }
        cout << "x1: " << x1 << " x2: " << x2 << endl;
    } while (fx1 != 0 && fx2 != 0 && (abs(x1 - x2) > 0.01 || abs(fm) > 0.01) && fm != 0);
    if (fx1 == 0)
    {
        return x1;
    }
    else if (fx2 == 0)
    {
        return x2;
    }
    else if (fm == 0)
    {
        return m;
    }
    else if (abs(x1 - x2) < 0.01 || abs(fm) < 0.01)
    {
        return x1;
    }
}

double recur_bisection(int A, int B, int C, double x1, double x2, double fx1, double fx2)
{
    double m, fm;
    fm = sub_num(A, B, C, m);
    if (fx1 == 0)
    {
        return x1;
    }
    else if (fx2 == 0)
    {
        return x2;
    }
    else if (abs(x1 - x2) < 0.01 || abs(fm) < 0.01)
    {
        return x1;
    }
    else
    {
        m = (x1 + x2) / 2;
        fm = sub_num(A, B, C, m);
        if (validation(fx1, fm) != 1)
        {
            x1 = m;
        }
        else if (validation(fx2, fm) != 1)
        {
            x2 = m;
        }
        cout << "x1: " << x1 << " x2: " << x2 << endl;
        fx1 = sub_num(A, B, C, x1);
        fx2 = sub_num(A, B, C, x2);
        return recur_bisection(A, B, C, x1, x2, fx1, fx2);
    }
}

int main()
{
    int A, B, C, d;
    double x1, x2, fx1, fx2;
    cout << "Ax^2 + Bx + C" << endl;
    cout << "Input values  of A, B and C: ";
    cin >> A >> B >> C;
    d = pow(B, 2) - 4 * A * C;
    cout << "Discriminant: " << d << endl;
    if (d > 0)
    {
        cout << "Input x1 and x2: ";
        cin >> x1 >> x2;
        fx1 = sub_num(A, B, C, x1);
        fx2 = sub_num(A, B, C, x2);
        while (validation(fx1, fx2) != 1)
        {
            cout << "Invalid input, Please input again" << endl;
            cout << "Input x1 and x2: ";
            cin >> x1 >> x2;
        }
        cout << "\nBisection (Interative) begin"
             << "\n============================" << endl;
        cout << "Root: " << inter_bisection(A, B, C, x1, x2, fx1, fx2) << endl;
        cout << "\n\nBisection (Recursive) begin"
             << "\n============================" << endl;
        cout << "Root: " << recur_bisection(A, B, C, x1, x2, fx1, fx2) << endl;
    }
    return 0;
}
