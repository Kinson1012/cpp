// Leung Ming Hei
// H10006255

#include <iostream>
#include <cmath>
using namespace std;
    
int sum_as(int init_num, int diff, int numofterm){
    if(numofterm==0){
        return 0;
    }else{
        return init_num+(sum_as(init_num,diff,numofterm-1)+(diff*(numofterm-1)));
    }
}

int sum_gs(int init_num, int ratio, int numofterm){
    if(numofterm==1){
        return init_num;
    }else{
        return init_num*pow(ratio,numofterm-1)+sum_gs(init_num, ratio, numofterm-1);
    }
}

int main(){
    int init_num, diff, ratio, numofterm;
    //asking user input
    cout << "\nEnter an initial value, a: ";
    cin >> init_num;
    cout << "Enter difference for arithmetic sequence: ";
    cin >> diff;
    cout << "Enter ratio for geometric sequence: ";
    cin >> ratio;
    cout << "Enter number of term(s): ";
    cin >> numofterm;
    //calling function sum_as and sum_gs
    cout << "sum of as is :" << sum_as(init_num, diff, numofterm) << endl;
    cout << "sum of gs is :" << sum_gs(init_num, ratio, numofterm) << endl;
}



