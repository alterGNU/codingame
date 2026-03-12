#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#define DEBUG_MODE 0
using namespace std;
class   Plane
{
    private:
        bool    _status;
        char    _type;
        int     _x;
        int     _y;
    public:
        Plane(void);
        Plane(bool status, char type, int x, int y);
        ~Plane(void);
        // Getters
        bool    const getStatus(void)const;
        char    const getType(void)const;
        int     const getX(void)const;
        int     const getY(void)const;
        // Setters
        void    setStatus(bool status);
        void    setType(char t);
        void    setX(int x);
        void    setY(int y);
        // Fun. Members
        void    move(void);
};
Plane::Plane(void):_status(false), _type('?'), _x(-1), _y(-1){if (DEBUG_MODE > 1){cerr << "[Plane] Default Constructor called." << endl ;};};
Plane::Plane(bool status, char type, int x, int y):_status(status), _type(type), _x(x), _y(y){if (DEBUG_MODE > 1){cerr << "[Plane] Param. Constructor called." << endl ;};};
Plane::~Plane(void){if (DEBUG_MODE > 1){cerr << "[Plane] Destructor called." << endl ;};};
//GETTERS
bool    const Plane::getStatus(void)const{return (this->_status);}
char    const Plane::getType(void)const{return (this->_type);}
int     const Plane::getX(void)const{return (this->_x);}
int     const Plane::getY(void)const{return (this->_y);}
//SETTERS
void    Plane::setStatus(bool status){this->_status = status;}
void    Plane::setType(char c){this->_type = c;}
void    Plane::setX(int x){this->_x = x;}
void    Plane::setY(int y){this->_y = y;}
//FUNCTIONS MEMBERS
void    Plane::move(void)
{
    if (this->_type == '>')
        this->_x++;
    else if (this->_type == '<')
        this->_x--;
    else
        cerr << this << "ERROR->TYPE UNKNOWN" << endl;
}
//OVERLOADING THE << OPERATOR
ostream &operator<<(ostream &out, Plane const &p)
{
    out<<"p["<<p.getType()<<"]("<<p.getX()<<", "<<p.getY()<<")";
    return (out);
}
int main()
{
    int x,y,sx,sy;
    Plane shooter;
    std::list<Plane> enemyList;
    int n;cin >> n;cin.ignore();
    for (int y=0;y<n;y++)
    {
        string line;cin>>line;cin.ignore();
        for (int x=0;x<line.size();x++)
        {
            if (line[x]=='>' || line[x]=='<')
                enemyList.push_back(Plane(true, line[x], x, y));
            if (line[x]=='^')
            {
                shooter.setType('^');
                shooter.setX(x);
                shooter.setY(y + 1);
            }
        }
    }
    sx = shooter.getX();
    sy = shooter.getY();
    while (enemyList.size())
    {
        for (std::list<Plane>::iterator it = enemyList.begin(); it != enemyList.end();)
        {
            x = it->getX();
            y = it->getY();
            if (abs(sx - x)==(sy - y))
            {
                shooter.setStatus(true);
                it = enemyList.erase(it);
            }
            else
            {
                it->move();
                ++it;
            }
        }
        cout << (shooter.getStatus()?"SHOOT":"WAIT") << endl;
        shooter.setStatus(false);
    }
}
