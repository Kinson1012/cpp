// Leung Ming Hei
// H10006255

#include <iostream>
#include <cmath>
using namespace std;


double sub_num(int A, int B, int C, double x){
    return (A*pow(x,2)+B*x+C);
}


bool validation(double fx1, double fx2){
    if((fx1>0 && fx2<0) || (fx1<0 && fx2 >0)){
        return true;
    }else{
        return false;
    }
}

double inter_bisection(int A, int B, int C, double x1, double x2 , double fx1, double fx2){
    double m, fm;
    m = (x1+x2)/2;
    fm = sub_num(A,B,C,m);
    cout << fx1 << " " << fx2 << " " << m << " " << fm << endl;
    while(fx1!=0.00 || fx2!=0.00 || fm!=0.00 || fm>=0.01 || abs(fx1)-abs(fx2)>=0.01){
    m = (x1+x2)/2;
    fm = sub_num(A,B,C,m);
    fx1 = sub_num(A,B,C,x1);
    fx2 = sub_num(A,B,C,x2);
    cout << fm << endl;
    cout << fx1 << endl;
    cout << fx2 << endl;
    if(validation(fx1,fm)==1){
        x1 = m;
    }else if(validation(fx2,fm)==1){
        x2 = m;
    }
    cout << "x1: " << x1 << " x2:" << x2 << endl;
    }
    if(sub_num(A,B,C,x1)==0){
        return x1;
    }else if(sub_num(A,B,C,x2)==0){
        return x2;
    }
}


int main(){
    int A, B, C, d;
    double x1, x2, fx1, fx2;
    cout << "Ax^2 + Bx + C" << endl;
    cout << "Input values  of A, B and C: ";
    cin >> A >> B >> C;
    d = pow(B,2) - 4*A*C;
    cout << "Discriminant: " << d << endl;
    if(d>0){
        cout << "Input x1 and x2: ";
        cin >> x1 >> x2;
        fx1 = sub_num(A,B,C,x1);
        fx2 = sub_num(A,B,C,x2);
        while(validation(fx1,fx2)!=1){
            cout << "Invalid input, Please input again"<< endl;
            cout << "Input x1 and x2: ";
            cin >> x1 >> x2;
        }
        cout << inter_bisection(A, B, C, x1, x2, fx1, fx2) << endl;
    }
}

