#include <iostream>
using namespace std;

int main()
{
   int x, y, temp;
   cout << "Enter the value of x and y:" << endl; cin >> x >> y;
   cout << "Before swapping x=" << x << ", y=" << y << endl;
    
   /*Swapping logic */
   temp = x;
   x = y;
   y = temp;
   cout << "After swapping x=" << x << ", y=" << y << endl;
   return 0; 
}

