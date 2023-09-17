// Leung Ming Hei
// H10006255

#include <iostream>
using namespace std;

int sum_vector(vector <int>v, int n){
    if(n == 0){
        return v[n];
    }else{
        return v[n]+sum_vector(v,n-1);
    }
}

int main(){
    vector <int>v;
    int n;
    srand((unsigned) time(NULL));
    cout << "Please enter a positive non-zero integer: ";
    do{
        cin >> n;
        if(n<=0){//validating n
            cout << "invalid input, please input again!"<<endl;
            cout << "Please enter a positive non-zero integer: ";
        }
    }while(n<=0);
    for(int i=0; i<n; i++){//creating vector with required size and fill in with random number(1-2n)
        int random = 1+(rand() % (2*n));
        v.push_back(random);
    }
    cout << "The random vector is : < ";
    for(int j=0; j<v.size(); j++){//showing the whole vector
        cout << v[j] << " ";
    }
    cout << ">" << endl;
    //calling the sum_vector()
    cout << "Sum of vector is: " << sum_vector(v,n) << endl;
}