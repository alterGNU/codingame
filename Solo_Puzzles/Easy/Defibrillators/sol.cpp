#include <iostream>
#include <ostream>
#include <string>
#include <cmath>
#include <limits>
#include <vector>
#include <sstream>
#include <algorithm> // min_element
#define DEBUG_MODE 0 // 0:OFF, 1:ON-->print main debug infos, 2:ON-->even print class fun. memb. calls!!
using namespace std;
//- [CLASS: POINT]------------------------------------------------------------------------------------------------
class Point
{
    private:
        string  _name;           // Point's name
        float   _x;              // Longitude
        float   _y;              // Latitude
    public:
        // Canonical form --> not needed, but good practice i guess ^^'
        Point(void);                                // Default constructor
        Point(string const &name);                  // Named constructor
        Point(string const &name, float x, float y);// Param. constructor
        ~Point(void);                               // Destructor
        Point(Point const &other);                  // Copy constructor
        // Getters
        string const &getName(void)const;
        float const &getX(void)const;
        float const &getY(void)const;
        // Setters (no set name cause 'u can change who u are!')
        bool setX(float const x);
        bool setY(float const y);
        // Fun. member that returns the distance between two points
        float   distance(Point const &other);
};
// Overload of the stream insertion operator
ostream    &operator<<(ostream &out, Point const &pt)
{
    out << "[Point:"<< pt.getName() << "]=("<<pt.getX()<<", "<<pt.getY()<<")";
    return (out);
}
// Canonical form
Point::Point(void) : _name("Default"), _x(0), _y(0) {if (DEBUG_MODE > 1) cerr << "[Point:Default] Default constructor called" << endl;}
Point::Point(string const &name) : _name(name), _x(0), _y(0) {if (DEBUG_MODE > 1) cerr << "[Point:"<< name <<"] Named constructor called" << endl;}
Point::Point(string const &name, float x, float y) : _name(name), _x(x), _y(y) {if (DEBUG_MODE > 1) cerr << "[Point:" << name << "] Parameter constructor called" << endl;}
Point::Point(Point const &other) : _name(other._name), _x(other._x), _y(other._y) { if (DEBUG_MODE > 1) cerr << "[Point:" << _name << "] Copy Constructor called" << endl;}
Point::~Point(void) {if (DEBUG_MODE > 1) cerr << "[Point:" << _name << "] Destructor called" << endl;}
// Getters
string const &Point::getName(void)const{return this->_name;}
float const &Point::getX(void)const{return this->_x;}
float const &Point::getY(void)const{return this->_y;}
// Setters
bool Point::setX(float const x)
{
    if (DEBUG_MODE > 1)
        cerr << "[Point:"<< _name << "] setX(" << x << ") called" << endl;
    if (this->_x == x)
        return (false);
    this->_x = x;
    return (true);
}
bool Point::setY(float const y)
{
    if (DEBUG_MODE > 1)
        cerr << "[Point:" << _name << "] setY(" << y << ") called" << endl;
    if (this->_y == y)
        return (false);
    this->_y = y;
    return (true);
}
// Distance between two points
float Point::distance(Point const &other)
{
    if (DEBUG_MODE > 1)
        cerr << "[Point:"<< _name << "] distance from " << other.getName() << endl;
    float bx = other.getX();
    float by = other.getY();
    float x = (bx - _x) * cos((by + _y)/2);
    float y = by - _y;
    return (6371 * sqrtf(pow(x,2) + pow(y, 2)));
}
//- [CLASS: DEFIB]------------------------------------------------------------------------------------------------
class Defib : public Point
{
    private:
        string  _id;
        string  _add;
        string  _phone;
        float   _dist;
    public:
        Defib(void);                // Default constructor.
        Defib(string const &name);  // Named constructor.
        // Named constructor.
        Defib(string const &id, string const &name, string const &add, string const &phonee, float const x, float const y);
        ~Defib(void);               // Destructor
        // Getters
        string const &getId(void)const;
        string const &getAdd(void)const;
        string const &getPhone(void)const;
        float const &getDist(void)const;
        // Set distance
        void setDistance(Point const &other);
};
// Overload of the stream insertion operator
ostream    &operator<<(ostream &out, Defib const &defib)
{
    out << "[Defib:"<< defib.getName() << "]={id:"<<defib.getId()<<", add:"<<defib.getAdd()<<", phone:"<< defib.getPhone()<<", pos("<<defib.getX()<<", "<<defib.getY()<<"), dist="<<defib.getDist()<<"}";
    return (out);
}
// Canonical form
Defib::Defib(void):_id(""), _add(""), _phone(""), _dist(numeric_limits<float>::max()) { if (DEBUG_MODE > 1) cerr << "[Defib:Default] Default constructor called."<<endl;}
Defib::Defib(string const &name): Point(name), _id(""), _add(""), _phone(""), _dist(numeric_limits<float>::max()) { if (DEBUG_MODE > 1) cerr << "[Defib:"<< _id <<"] Named constructor called."<<endl;}
Defib::Defib(string const &id, string const &name, string const &add, string const &phone, float const x, float const y): Point(name, x, y), _id(id), _add(add), _phone(phone), _dist(numeric_limits<float>::max()) { if (DEBUG_MODE > 1) cerr << "[Defibsd:"<< _id <<"] Parameters constructor called."<<endl;}
Defib::~Defib(void){if (DEBUG_MODE > 1) cerr << "[Defig:"<< this->getName() << "] Destuctor called." << endl ; }
// Getters
string const &Defib::getId(void)const{return _id;}
string const &Defib::getAdd(void)const{return _add;}
string const &Defib::getPhone(void)const{return _phone;}
float const &Defib::getDist(void)const{return _dist;}
// Set distance (other setters not really needed...)
void Defib::setDistance(const Point &other) { this->_dist = this->distance(other); }
//- [ UTILS ]-----------------------------------------------------------------------------------------------------
// Convert string number with ',' into float
float toFloat(string s)
{
    replace(s.begin(), s.end(), ',', '.');
    return (stof(s));
}
// Split a string:<str> by separator char:<sep> and return a vector<string>
vector<string> splitBySep(string const &str, char sep)
{
    vector<string>  res;
    stringstream    ss(str);
    string          token;
    while (getline(ss, token, sep))
        res.push_back(token);
    return (res);
}
//- [ MAIN ]------------------------------------------------------------------------------------------------------
int main()
{
    // STEP 1: INIT USER
    string lon; cin >> lon; cin.ignore();
    string lat; cin >> lat; cin.ignore();
    Point user("user", toFloat(lon), toFloat(lat));
    if (DEBUG_MODE > 0)
        cerr << "STEP1: INIT USER:\n> " << user << endl;
    // STEP 2: INIT DEFIB ARRAY
    if (DEBUG_MODE > 0)
        cerr << "STEP 2: INIT ARRAY:(using vector)" << endl;
    int n; cin >> n; cin.ignore();
    Defib array[n];
    vector<string> tmp_vect;
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        replace(str.begin(), str.end(), ',', '.');
        if (DEBUG_MODE > 1)
            cerr << "> ["<<i<<"]   :\"" << str << "\"" << endl;
        tmp_vect = splitBySep(str, ';');
        for (int j=0;j<tmp_vect.size();j++)
        {
            if (DEBUG_MODE > 1)
                cerr << "> [" << i << "]["<<j<<"]:" << tmp_vect[j] << endl;
        }
        array[i] = Defib(tmp_vect[0],tmp_vect[1],tmp_vect[2],tmp_vect[3], toFloat(tmp_vect[4]), toFloat(tmp_vect[5]));
        array[i].setDistance(user);
    }
    if (DEBUG_MODE > 0)
    {
      for (int i = 0; i < n; i++)
        cerr << "[" << i << "]->" << array[i] << endl;
    }
    // STEP 3: SEARCH AND RETURN MIN_ELEMENT BASE ON ITS _dist CLASS MEMBER ATTRIBUTE
    if (DEBUG_MODE > 0)
        cerr << "STEP 3: SEARCH AN RETURN MIN_ELEMENT:(using algorithm::min_element)" << endl;
    auto it = min_element(array, array + n, [](const Defib &a, const Defib &b){ return a.getDist() < b.getDist();});
    cout << it->getName() << endl;
}
