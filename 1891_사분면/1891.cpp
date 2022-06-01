#include <iostream>
#include <string>
using namespace std;

enum XY {X, Y};

class XYCoordinate
{
private:
    long long   x;
    long long   y;

public:
    XYCoordinate();
    XYCoordinate(long long const & x, long long const & y);
    XYCoordinate(XYCoordinate const & src);
    ~XYCoordinate();

    XYCoordinate &  operator=(XYCoordinate const & rhs);

    long long   getX() const;
    long long   getY() const;
    void        setX(long long const & x);
    void        setY(long long const & y);
};

XYCoordinate::XYCoordinate() : x(0), y(0)
{
    return;
}

XYCoordinate::XYCoordinate(long long const & x, long long const & y) : x(x), y(y)
{
    return;
}

XYCoordinate::XYCoordinate(XYCoordinate const & src) : x(src.getX()), y(src.getY())
{
    return;
}

XYCoordinate::~XYCoordinate()
{
    return;
}

XYCoordinate &  XYCoordinate::operator=(XYCoordinate const & rhs)
{
    this->x = rhs.getX();
    this->y = rhs.getY();
    return *this;
}

long long   XYCoordinate::getX() const
{
    return this->x;
}

long long   XYCoordinate::getY() const
{
    return this->y;
}

void    XYCoordinate::setX(long long const & x)
{
    this->x = x;
    return;
}

void    XYCoordinate::setY(long long const & y)
{
    this->y = y;
    return;
}


class FragmentQuadrant
{
private:
    int             digit;
    string          number;
    XYCoordinate    xy;

    FragmentQuadrant();
    bool            boolXYcoordinate(XY const & axis, int const & quadrant);
    XYCoordinate    findXYCoordinate();
    void    setDigit(int const & digit);
    void    setNumber(string const & number);
    void    setXY(XYCoordinate const & XY);

public:
    FragmentQuadrant(int const & digit, string const & number);
    FragmentQuadrant(FragmentQuadrant const & src);
    ~FragmentQuadrant();

    FragmentQuadrant &  operator=(FragmentQuadrant const & rhs);

    int             getDigit() const;
    string          getNumber() const;
    XYCoordinate    getXY() const;
    void            moveXY(long long const & x, long long const & y);
};

FragmentQuadrant::FragmentQuadrant()
{
    return;
}

FragmentQuadrant::FragmentQuadrant(int const & digit, string const & number) 
: digit(digit), number(number), xy(findXYCoordinate())
{
    return;
}

FragmentQuadrant::FragmentQuadrant(FragmentQuadrant const & src)
: digit(src.getDigit()), number(src.getNumber()), xy(src.getXY())
{
    return;
}

FragmentQuadrant::~FragmentQuadrant()
{
    return;
}

FragmentQuadrant &  FragmentQuadrant::operator=(FragmentQuadrant const & rhs)
{
    this->digit = rhs.getDigit();
    this->number = rhs.getNumber();
    this->xy = rhs.getXY();
    return *this;
}

int FragmentQuadrant::getDigit() const
{
    return this->digit;
}

string  FragmentQuadrant::getNumber() const
{
    return this->number;
}

XYCoordinate    FragmentQuadrant::getXY() const
{
    return this->xy;
}

void    FragmentQuadrant::setDigit(int const & digit)
{
    this->digit = digit;
    return;
}

void    FragmentQuadrant::setNumber(string const & number)
{
    this->number = number;
    return;
}

void    FragmentQuadrant::setXY(XYCoordinate const & xy)
{
    this->xy = xy;
    return;
}

bool    FragmentQuadrant::boolXYcoordinate(XY const & axis, int const & quadrant)
{
    if (axis == X)
    {
        if (quadrant == 1 || quadrant == 4)
        {
            return true;
        }
    }
    else if (axis == Y)
    {
        if (quadrant == 1 || quadrant == 2)
        {
            return true;
        }
    }
    return false;
}

XYCoordinate    FragmentQuadrant::findXYCoordinate()
{
    long long       x = 0;
    long long       y = 0;
    for (int i = 0; i < number.size(); i++)
    {
        int quadrant = number[i] - '0';
        x = (x << 1) + boolXYcoordinate(X, quadrant);
        y = (y << 1) + boolXYcoordinate(Y, quadrant);
    }
    XYCoordinate    xy(x, y);
    return xy;
}

void    FragmentQuadrant::moveXY(long long const & x, long long const & y)
{
    long long   nextX = this->getXY().getX() + x;
    long long   nextY = this->getXY().getY() + y;
    if (nextX < 0 || nextY < 0)
    {
        setNumber("-1");
        return;
    }
    else if ((nextX >> number.size()) > 0 || (nextY >> number.size()) > 0)
    {
        setNumber("-1");
        return;
    }

    string  fixNumber(number);
    for (long long i = 0; i < number.size(); i++)
    {
        long long   idx = number.size() -1 - i;
        if ((nextX >> i & 1) == 1 && (nextY >> i & 1) == 1)
        {
            fixNumber[idx] = '1';
        }
        else if ((nextX >> i & 1) == 0 && (nextY >> i & 1) == 1)
        {
            fixNumber[idx] = '2';
        }
        else if ((nextX >> i & 1) == 0 && (nextY >> i & 1) == 0)
        {
            fixNumber[idx] = '3';
        }
        else if ((nextX >> i & 1) == 1 && (nextY >> i & 1) == 0)
        {
            fixNumber[idx] = '4';
        }
    }
    
    setNumber(fixNumber);
    setXY(XYCoordinate(x,y));
    return;
}

int main()
{
    int     digit;
    string  number;
    cin >> digit >> number;
    FragmentQuadrant    fragmentQuadrant(digit, number);

    long long x, y;
    cin >> x >> y;
    fragmentQuadrant.moveXY(x, y);
    cout << fragmentQuadrant.getNumber() << endl;
}
