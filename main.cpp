#include "mat.hpp"
using namespace ariel;
using namespace std;
int main()
{
    while(EOF)
    {
        int a;
        int b;
        char c;
        char d;
        cout<< "write two numbers of the size mat (odd numbers)"<< endl;
        cin>> a>>b;
        cout<< "what will be the mat painting?" <<endl;
        cin >> c>>d;
        string my_mat = mat(a,b,c,d);
        cout<< "------------------------------------" <<endl <<"Here is your mat: " <<endl <<  my_mat <<endl <<"------------------------------------"<<endl;

    }
    return 0;
}