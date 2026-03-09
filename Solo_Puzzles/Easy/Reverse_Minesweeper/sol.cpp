#include <iostream>
#include <string>
#define DEBUG_MODE 1 // 0:desable, 1:enable (print lvl 1 debug infos), 2:enable (all debug infos level)
using namespace std;
// Use of class and its canonical form just for training purpose...
class Mat2d
{
    private:
        int _x;
        int _y;
        int **_grid;
    public:
        // Canonical form
        Mat2d(void);                            // Default Constructor
        Mat2d(int x, int y);                    // Param. Constructor
        Mat2d(int x, int y, int **mat);         // Param. Constructor
        Mat2d(Mat2d const &other);              // Copy Constructor
        Mat2d &operator=(Mat2d const &other);   // Assign. Constructor
        ~Mat2d(void);                           // Destructor
        // Getters
        int getX(void)const;
        int getY(void)const;
        int const   &getV(int x, int y)const;
        // Setters
        bool        setV(int x, int y, int v);
        // Memb. fun()
        int         countBombAround(int x, int y);
        void        setAllV(void);
};
Mat2d::Mat2d(void):_x(0), _y(0), _grid(nullptr){if (DEBUG_MODE > 1){cerr << "[Mat2d] Default Constructor called" << endl;};}
Mat2d::Mat2d(int x, int y):_x(x), _y(y)
{
    if (DEBUG_MODE > 1){cerr << "[Mat2d] 2 Param Constructor called" << endl;}
    this->_grid = new int*[this->_x];
    for (int i=0;i<this->_x;i++)
    {
        this->_grid[i] = new int[this->_y];
        for (int j=0;j<this->_y;j++)
            this->_grid[i][j] = 0;
    }
}
Mat2d::Mat2d(int x, int y, int **grid):_x(0), _y(0), _grid(grid){if (DEBUG_MODE > 1){cerr << "[Mat2d] 3 Param Constructor called" << endl;};}
Mat2d::~Mat2d()
{
    if (DEBUG_MODE > 1)
        cerr << "[Mat2d] Destructor called" << endl;
    for (int i=0;i<this->_x;i++)
        delete[] this->_grid[i];
    delete[] this->_grid;
}
Mat2d::Mat2d(Mat2d const &other)
{
    if (DEBUG_MODE > 1){cerr << "[Mat2d] 3 Param Constructor called" << endl;}
    if (this != &other)
    {
        this->_x = other.getX();
        this->_y = other.getY();
        this->_grid = new int*[this->_x];
        for (int i=0;i<this->_x;i++)
        {
            this->_grid[i] = new int[this->_y];
            for (int j=0;j<this->_y;j++)
                this->_grid[i][j] = other.getV(i, j);
        }
    }
}
Mat2d   &Mat2d::operator=(Mat2d const &other)
{
    if (DEBUG_MODE > 1){cerr << "[Mat2d] Assign. Operator called" << endl;}
    if (this != &other)
    {
        // Destruct old grid
        for (int i=0;i<this->_x;i++)
            delete[] this->_grid[i];
        delete[] this->_grid;
        // Copy from other
        this->_x = other.getX();
        this->_y = other.getY();
        this->_grid = new int*[this->_x];
        for (int i=0;i<this->_x;i++)
        {
            this->_grid[i] = new int[this->_y];
            for (int j=0;j<this->_y;j++)
                this->_grid[i][j] = other.getV(i, j);
        }
    }
    return (*this);
}
// GETTERS
int Mat2d::getX(void) const{return (this->_x);}
int Mat2d::getY(void) const{return (this->_y);}
int const &Mat2d::getV(int x, int y) const
{
    if (x < 0 || this->_x <= x || y < 0 || this->_y <= y)
        throw out_of_range("[Mat2d] getV() index out of range");
    return (this->_grid[x][y]);
}
// SETTERS
bool    Mat2d::setV(int x, int y, int v)
{
    if (DEBUG_MODE > 1){cerr << "[Mat2d] setV("<< x <<","<< y << ") called" << endl;}
    if (x < 0 || this->_x <= x || y < 0 || this->_y <= y)
        return (false);
    this->_grid[x][y] = v;
    return (true);
}
// Fun. Memb.
int     Mat2d::countBombAround(int x, int y)
{
    int tot = -1;
    if (0 <= x && x < this->_x && 0 <= y && y < this->_y)
    {
        tot++;
        if (x > 0)
        {
            if (y > 0)
                tot += this->getV(x - 1, y - 1)<0;    // NORTH-WEST
            tot += this->getV(x - 1, y)<0;            // NORTH
            if (y + 1 < this->_y)
                tot += this->getV(x - 1, y + 1)<0;    // NORTH-EAST
        }
        if (y + 1 < this->_y)
            tot += this->getV(x, y + 1)<0;            // EAST
        if (x + 1 < this->_x)
        {
            if (y + 1 < this->_y)
                tot += this->getV(x + 1, y + 1)<0;    // SOUTH-EAST
            tot += this->getV(x + 1, y)<0;            // SOUTH
            if (y > 0)
                tot += this->getV(x + 1, y - 1)<0;    // SOUTH-WEST
        }
        if (y > 0)
            tot += this->getV(x, y - 1)<0;            // WEST
    }
    return (tot);
}
void    Mat2d::setAllV(void)
{
    for (int i=0;i<this->getX();i++)
    {
        for (int j=0;j<this->getY();j++)
        {
            if (this->getV(i, j) >= 0)
                this->setV(i, j, this->countBombAround(i, j));
        }
    }
}
// Stream insertion operator Overload
ostream &operator<<(ostream &out, Mat2d const &m)
{
    int v;
    int x = m.getX();
    int y = m.getY();
    if (DEBUG_MODE > 0)
        cerr << "Mat[" << x << "][" << y << "]:" << endl;
    for (int i=0;i<x;i++)
    {
        for (int j=0;j<y;j++)
        {
            v = m.getV(i, j);
            out << ((v > 0) ? to_string(v) : ".");
        }
        out << endl;
    }
    return (out);
}
int main()
{
    int w;
    cin >> w; cin.ignore();
    int h;
    cin >> h; cin.ignore();
    Mat2d m(h,w);
    for (int i=0;i<h;i++)
    {
        string line;
        getline(cin, line);
        for (int j=0;j<line.size();j++)
            m.setV(i, j, (line[j] == 'x')? -1 : 0);
    }
    m.setAllV();
    cout << m;
}
