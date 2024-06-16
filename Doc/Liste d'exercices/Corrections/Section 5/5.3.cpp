#include <cmath>
#include <iostream>
using namespace std;

class Point
{
    float x, y;

public:
    Point();
    ~Point();

    float getX();
    float getY();

    void setX(float X);
    void setY(float Y);
};

float Point::getX()
{
    return x;
}

float Point::getY()
{
    return y;
}

void Point::setX(float X)
{
    x = X;
}

void Point::setY(float Y)
{
    y = Y;
}

int main()
{
    Point pt1, pt2;
    pt1.setX(2);
    pt1.setY(3);
    pt2.setX(3);
    pt2.setY(5);

    cout << "La distance entre les points est : " << sqrt( (pt1.getX() - pt2.getX()) * (pt1.getX() - pt2.getX()) + (pt1.getY() - pt2.getY()) * (pt1.getY() - pt2.getY())); 
    
    return 0;
}