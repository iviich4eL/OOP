// #include "triangle.h"
#include "Figure.h"
#include "Triangle.h"
#include "Square.h"

#include <iostream>
#include <string>

// void chooseFigure(std::string & f, Figure* ptr);
int main()
{
    // {
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;

    string figure;

    cin >> figure;
    while (!cin.fail())
    {
        Figure *ptr = NULL;
        if (figure == "tr")
        {
            ptr = new Triangle(std::cin);
        }
        else if (figure == "sq")
        {
            cout << "2" << endl;
            ptr = new Square(std::cin);
        }
        else if (figure == "oct")
        {
            cout << "3" << endl;
            // ptr = new Octagon(std::cin);
        }
        else
        {
            cout << "Enter tr, sc or oct " << endl;
        }
        ptr->Print();
        cout << ptr->Square() << endl;
        delete ptr;
        cin >> figure;
    }
    // }
    return 0;
}

// void chooseFigure(std::string & f, Figure & ptr)
// {
//     using namespace std;
//     // Figure *ptr = NULL;
//     if (f == "tr")
//     {
//         cout << "1" << endl;
//         ptr = new Triangle(0, 0, 0);
//     }
//     else if (f == "sq")
//     {
//         cout << "2" << endl;
//         // ptr = new Square(std::cin);
//     }
//     else if (f == "oct")
//     {
//         cout << "3" << endl;
//         // ptr = new Octagon(std::cin);
//     }
//     else {
//         cout << "Enter tr, sc or oct " << endl;
//     }
// }