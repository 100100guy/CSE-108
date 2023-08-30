#include <iostream>
#include<math.h>

using namespace std;

class Point
{
     // x and y coordinate
    int x, y;
    public:
    //Add necessary constructor(s) to initialize x and y
         Point()
         {
            x=0;
            y=0;
         }
         Point(int a, int b)
         {
             x=a;
             y=b;
         }
         //Add your set and get functions for x and y
          int setx(int a)
         {
             x=a;
         }
         int sety(int a)
         {
             y=a;
         }
         int getx()
         {
             return x;
         }
         int gety()
         {
             return y;
         }

         void print()
         {
            cout << "Coordinate: "<< x <<", " <<y <<endl;
         }
};

class Circle
{
     Point p;
     int radius;
     public:
         // Add necessary constructor(s) to initialize p and radius


         Circle(int a,int b, int r)
         {
             p.setx(a);
             p.sety(b);
             radius=r;
         }
         // Overload “upload” functions
         void update(int a,int b)
         {
             int e=p.getx();
             int f=p.gety();
             e+=a;
             f+=b;
             p.setx(e);
             p.sety(f);
         }
          void update(int a)
         {
             radius+=a;
         }
         void update(int a,int b, int c)
         {
             int g=p.getx();
             int h=p.gety();
             g+=a;
             h+=b;
             radius+=c;
             p.setx(g);
             p.sety(h);
         }
         void print()
         {
             cout << "Center ";
             p.print();
             cout << "Radius: " << radius << endl;
         }
};
class Line
{
    Point p1;
    Point p2;
    public:
        Line(int a1,int b1, int a2, int b2)
        {
             p1.setx(a1);
             p1.sety(b1);
             p2.setx(a2);
             p2.sety(b2);

        }
        int length()
        {
            int x1=p1.getx();
            int y1=p1.gety();
            int x2=p2.getx();
            int y2=p2.gety();
            double l=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
            cout<<"Length of line is: "<<l<<endl;
        }
};
int main()
{
     Point p(5,5);
     Circle c(2, 3, 5);
     cout << endl << "Point Display" <<endl;
     p.print();
     cout << endl << "Circle Display" <<endl;
     c.print();
     cout << endl;


    //First update
     cout << "First Update" << endl;
    // call “update” function of Circle class to increase the center’s x
    //coordinate by 5 and y coordinate by 5;
     c.update(5,5);
     c.print();
     cout <<endl;

     //Second update
     cout << "Second Update" << endl;

    // call “update” function of Circle class to increase the radius by 6;
     c.update(6);
     c.print();
     cout << endl;

     //Third update
     cout << "Third Update" << endl;

    // call “update” function of Circle class to increase the center’s x
    //coordinate by 2 and y coordinate by 2 and the radius by 2;
     c.update(2,2,2);
     c.print();
     cout << endl;
     Line l(3,2,0,0);
     l.length();
     cout << endl;
     return 0;
}
