#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#define SYMBOLS " .o+=*BOX@%&#/^"
#define DEBUG_MODE 1 // 0:desable, 1:enable
using namespace std;
//= [UTILS]============================================================================================================================
static string removeChar(string str, char c)
{
    str.erase(remove(str.begin(), str.end(), c), str.end());
    return (str);
}
//= [PLAYER CLASS]=====================================================================================================================
class Player
{
    private:
        char    _s;                             // Player's symbol in the maze
        int     _x;                             // Pos. on x axe (column in maze)
        int     _y;                             // Pos. on y axe (line in maze)
    public:
        // Canonical form
        Player(void);                           // Default constructor
        Player(int x, int y, char c);           // Param. constructor
        Player(Player const &other);            // Copy constructor
        ~Player(void);                          // Param. constructor
        Player &operator=(Player const &other); // Copy Assignement
        // Getters
        char const &getS(void) const ;
        int const &getX(void) const ;
        int const &getY(void) const ;
        // Setters
        bool setS(char const c);
        bool setX(int const x);
        bool setY(int const y);
        bool setCoord(int const x, int const y);

};
//- [CANONICAL FORM]-------------------------------------------------------------------------------------------------------------------
Player::Player(void): _x(0), _y(0), _s('?') { };
Player::Player(int x, int y, char c): _x(x), _y(y), _s(c) { };
Player::Player(Player const &other): _x(other._x), _y(other._y), _s(other._s) { };
Player::~Player(void){ };
Player &Player::operator=(Player const &other)
{
    if (this != &other)
    {
        this->_s = other.getS();
        this->_x = other.getX();
        this->_y = other.getY();
    }
    return (*this);
}
//- [GETTERS AND SETTERS]--------------------------------------------------------------------------------------------------------------
char const &Player::getS(void) const { return (this->_s); }
int const &Player::getX(void) const { return (this->_x); }
int const &Player::getY(void) const { return (this->_y); }
bool Player::setS(char const c)
{
    if (this->_s == c)
        return (false);
    return (this->_s = c, true);
}
bool Player::setX(int const x)
{
    if (this->_x == x)
        return (false);
    return (this->_x = x, true);
}
bool Player::setY(int const y)
{
    if (this->_y == y)
        return (false);
    return (this->_y = y, true);
}
bool Player::setCoord(int const x, int const y) { setX(x);setY(y);return(true);}
//- [OVERLOAD STREAM INSERTION OPERATOR]-----------------------------------------------------------------------------------------------
ostream &operator<<(ostream &out, Player const &play){ out<<"Player:"<<play.getS()<<" at ("<<play.getX()<<", "<<play.getY()<<")";return (out);}
//= [STRING ARRAY]=====================================================================================================================
class StringArray
{
    private:
        int _w;         // width (line's length)
        int _h;         // height (nb of line)
        string *_array; // string array
        string const _symbols = SYMBOLS;
    
    protected:
        // canonical form
        StringArray(void);                                  //Default constructor
        StringArray(int w, int h);                          //Param. constructor
        StringArray(StringArray const &other);              //Copy constructor
        ~StringArray(void);                                 //Destructor
        StringArray &operator=(StringArray const &other);   //Assignment Copy
        // Setters
        bool setElem(int y, int x, char value);
        bool setLine(int l, string const &value);
    public:
        // Getters
        int const &getHeight(void)const;
        int const &getWidth(void)const;
        string const &getSymbols(void)const;
        string const &getLine(int l)const;
        string const *getArray(void) const;
        bool setToNextSymbol(int y, int x);
};
//- [CANONICAL FORM]-------------------------------------------------------------------------------------------------------------------
StringArray::StringArray(void):_w(0), _h(0), _array(NULL){;}
StringArray::StringArray(int w, int h):_w(w), _h(h)
{
    if (h <= 0)
        throw invalid_argument("ERROR: StringArray Param. Constructor Invalid.");
    _array = new string[h];
}
StringArray::StringArray(StringArray const &other):_w(other._w), _h(other._h)
{
    if (other._h > 0)
    {
        _array = new string[other._h];
        for (int i=0;i<other._h;i++)
            _array[i] = other._array[i];
    }
    else
        _array = NULL;
}
StringArray::~StringArray(void){delete[] _array;}
StringArray &StringArray::operator=(StringArray const &other)
{
    if (this != &other)
    {
        delete[] _array;
        this->_w = other._w;
        this->_h = other._h;
        if (other._h > 0)
        {
            _array = new string[_h];
            for (int i=0;i<_h;i++)
                _array[i] = other._array[i];
        }
        else
            _array = NULL;
    }
    return (*this);
}
//- [SETTERS]--------------------------------------------------------------------------------------------------------------------------
bool StringArray::setElem(int y, int x, char value)
{
    if (y < 0 || this->_h <= y || x < 0 || this->_w <= x)
        return (false);
    this->_array[y][x] = value;
    return (true);
}
bool StringArray::setLine(int l, string const &value)
{
    if (l < 0 || this->_h <= l || value.empty())
        return (false);
    this->_array[l] = value;
    return (true);
}
bool StringArray::setToNextSymbol(int c, int l)
{
    if (l < 0 || this->_h < l || c < 0 || this->_w < c)
        return (false);
    char oldValue = this->_array[l][c];
    string symb = this->getSymbols();
    this->_array[l][c] = symb[(symb.find(oldValue) + 1)%symb.length()];
    cerr << "[set] old_arr["<<l<<"]["<<c<<"]="<<oldValue<<"new_arr["<<l<<"]["<<c<<"]="<<symb[(symb.find(oldValue) + 1)%symb.length()]<<endl;
    return (true);
}
//- [GETTERS]--------------------------------------------------------------------------------------------------------------------------
int const &StringArray::getHeight(void)const { return (this->_h); }
int const &StringArray::getWidth(void)const { return (this->_w); }
string const &StringArray::getSymbols(void)const { return (this->_symbols); }
string const &StringArray::getLine(int l)const
{
    if (l < 0 || this->_h < l)
        throw ("[StringArray] getLine() wrong line argument given");
    return (this->_array[l]);
}
string const *StringArray::getArray(void) const { return (this->_array); }

//- [OVERLOAD STREAM INSERTION OPERATOR]-----------------------------------------------------------------------------------------------
ostream &operator<<(ostream &out, StringArray const &strArr)
{ 
    for (int l=0;l<strArr.getHeight();l++)
        out<<"|"<<strArr.getLine(l)<<"|"<<endl;
    return (out);
}
//= [BINARY STRING ARRAY]==============================================================================================================
class BinStrArr : public StringArray
{
    public:
        BinStrArr(string const &fp);
};
BinStrArr::BinStrArr(string const &fp) : StringArray(2, 2 * fp.length())
{
    if (fp.empty()) throw ("[BinStrArr] empty fingerprint");

    string const binStr = "0123456789abcdef";
    string const binArr[16] = { "0000","0001","0010","0011","0100","0101","0110","0111",
                                "1000","1001","1010","1011","1100","1101","1110","1111" };
    int line = 0;
    for (size_t i=0; i<fp.length(); i+=2)
    {
        string byteBits = binArr[binStr.find(fp[i])] + binArr[binStr.find(fp[i+1])];
        this->setLine(line++, byteBits.substr(6,2)); 
        this->setLine(line++, byteBits.substr(4,2)); 
        this->setLine(line++, byteBits.substr(2,2)); 
        this->setLine(line++, byteBits.substr(0,2)); 
    }
}
//= [GAME CLASS]=======================================================================================================================
class Game : public StringArray
{
    private:
        Player      _playInit;
        Player      _player;
        BinStrArr   _movArr;
    public:
        Game(BinStrArr const &binArr);
        ~Game(void);
        void    movePlayer(void);
        void    insertPlayer(Player p);
        void    moveUpLeft(void);
        void    moveUpRight(void);
        void    moveDownLeft(void);
        void    moveDownRight(void);
};
void    Game::moveUpLeft(void)
{
    int pX = _player.getX();
    int pY = _player.getY();
    cerr << "Mov Up Left:(" << pX << ", " << pY << ")";
    int newX = (pX > 0)?pX-1:pX;
    int newY = (pY > 0)?pY-1:pY;
    _player.setCoord(newX, newY);
    cerr << "-->(" << newX << ", " << newY << ")" << endl;
    this->setToNextSymbol(newY, newX);
}
void    Game::moveUpRight(void)
{
    int pX = _player.getX();
    int pY = _player.getY();
    cerr << "Mov Up Right:(" << pX << ", " << pY << ")";
    int newX = (pX > 0)?pX - 1:pX;
    int newY = (pY + 1 < this->getWidth())?pY + 1:pY;
    _player.setCoord(newX, newY);
    cerr << "-->(" << newX << ", " << newY << ")" << endl;
    this->setToNextSymbol(newY, newX);
}
void    Game::moveDownRight(void)
{
    int pX = _player.getX();
    int pY = _player.getY();
    cerr << "Mov Down Left:(" << pX << ", " << pY << ")";
    int newX = (pX + 1 < this->getHeight())?pX+1:pX;
    int newY = (pY + 1 < this->getWidth())?pY+1:pY;
    _player.setCoord(newX, newY);
    cerr << "-->(" << newX << ", " << newY << ")" << endl;
    this->setToNextSymbol(newY, newX);
}
void    Game::moveDownLeft(void)
{
    int pX = _player.getX();
    int pY = _player.getY();
    cerr << "Mov Down Right:(" << pX << ", " << pY << ")";
    int newY = (pY > 0)?pY-1:pY;
    int newX = (pX + 1 < this->getHeight())?pX+1:pX;
    _player.setCoord(newX, newY);
    cerr << "-->(" << newX << ", " << newY << ")" << endl;
    this->setToNextSymbol(newY, newX);
}
Game::Game(BinStrArr const &binArr) : StringArray(17,9), _movArr(binArr)
{
    this->_playInit = Player(this->getHeight()/2, this->getWidth()/2, 'S');
    this->_player = Player(this->getHeight()/2, this->getWidth()/2, 'E');
    for (int l=0;l<this->getHeight();l++)
        this->setLine(l,"                 ");
    for (int i=0;i<this->_movArr.getHeight();i++)
    {
        string line = _movArr.getLine(i);
        cerr << line << ":";
        if (line == "00")
            this->moveUpLeft();
        else if (line == "01")
            this->moveUpRight();
        else if (line == "10")
            this->moveDownLeft();
        else
            this->moveDownRight();
    }
    this->insertPlayer(this->_playInit);
    this->insertPlayer(this->_player);
}
Game::~Game(void){;}
void Game::insertPlayer(Player p) { this->setElem(p.getX(), p.getY(), p.getS()); }
ostream &operator<<(ostream &out, Game const &game)
{ 
    out << "+---[CODINGAME]---+" << endl;
    for (int l=0;l<game.getHeight();l++)
        out<<"|"<<game.getLine(l)<<"|"<<endl;
    out << "+-----------------+" << endl;
    return (out);
}
int main()
{
    string rawfingerprint;getline(cin, rawfingerprint);
    string fp = removeChar(rawfingerprint, ':');
    if (DEBUG_MODE)
    {
        cerr << "rawfingerprint:\"" << rawfingerprint << "\"" << endl;
        cerr << "fp:\"" << fp << "\"" << endl;
    }
    Player p;
    BinStrArr ba(fp);
    if (DEBUG_MODE)
        cerr << "START:\n> " << p <<"\n> Binary Array:\n"<<ba<<endl;
    Game game(ba);
    cout << game;
}
