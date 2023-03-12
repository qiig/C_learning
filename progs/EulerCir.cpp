// cpp to solve 7-bridges
// a. IF the number of bridges to one area is odd, count++;
//    IF count > 2, EulerCir can not be found,
//    ELSE IF count = 2, EulerPath can be found,
//    ELSE there is nothing can be found.
// b. we need:
//          count     num. of odd area;
//          sumCol    sum of each columns;
//          a[]       an array to save the map.
// c. Input:
//          a[].
//    Output:
//          c.a.    Existing EulerCircuit!
//          c.b.    Existing EulerPath!
//          c.c.    Do not exist EulerCircuit & Path.
// Date: Mar.2,2023
// Version: 0.0.1
// Author: student
// Language: C++11
//

#include <iostream>

using namespace std;

const int Max_Size = 4;

class Bridges{
    public:
        Bridges(int *a, int n){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    mat[i][j] = *((int *)a + n * i + j);
                }
            }
            vn = n;
        };
        ~Bridges(){};
        void IFEulerCir();
        int oddBridges();
    private:
        int mat[Max_Size][Max_Size];
        int count;
        int vn;
};


int Bridges::oddBridges(){

    int sumCol = 0;
    count = 0;

    for (int i = 0; i < vn; i++){
        sumCol = 0;
        for (int j = 0; j < vn; j++){
            sumCol += mat[i][j];
        }
        if (sumCol % 2 != 0){
            count++;
        }
    }

    return count;
}

void Bridges::IFEulerCir(){
    if (count < 0){
        cout << "Error: count < 0" <<endl;
    }
    else if (count > 2){
        cout << "Do not exist EulerCircuit & Path." <<endl;
    }
    else if (count == 2){
        cout << "Existing EulerPath !" <<endl;
    }
    else{
        cout << "Existing EulerCircuit !" <<endl;
    }
}

int main(){

    int a[Max_Size][Max_Size] = { 0 }, n;

    while (cin >> n)
    {
        if (n <= 0){
            cout << "Error: n <= 0" <<endl;
            break;
        }
        else{
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    cin >> a[i][j];
                }
            }

            Bridges bri(&(a[0][0]),n);

            bri.oddBridges();
            bri.IFEulerCir();

        }
    }

    return 0;
}
