#include <iostream>
#include <string>
#include <map>
using namespace std;
#define AND(a,b)   (((a) && (b))?'-':'_')
#define OR(a,b)    (((a) || (b))?'-':'_')
#define XOR(a,b)   ((!!(a) != !!(b))?'-':'_')
#define NAND(a,b)  ((!( (a) && (b) ))?'-':'_')
#define NOR(a,b)   ((!( (a) || (b) ))?'-':'_')
#define NXOR(a,b)  ((!!(a) == !!(b)) ?'-':'_')
class OutSig
{
    private:
        string  _name;
        string  _type;
        string  _aName;
        string  _bName;
    public:
        // CONSTRUCTERS
        OutSig(void);
        OutSig(string name, string type, string aName, string bName);
        // DESTRUCTER
        ~OutSig(void);
        // GETTERS
        string  const &getName(void) const;
        string  const &getType(void) const;
        string  const &getA(void) const;
        string  const &getB(void) const;
};
OutSig::OutSig(void):_name("unknown"),_type("unknown"),_aName("unknown"),_bName("unknown"){};
OutSig::OutSig(string name, string type, string aName, string bName):_name(name),_type(type),_aName(aName),_bName(bName){};
OutSig::~OutSig(void){};
string  const &OutSig::getName(void) const{return (this->_name);}
string  const &OutSig::getType(void) const{return (this->_type);}
string  const &OutSig::getA(void) const{return (this->_aName);}
string  const &OutSig::getB(void) const{return (this->_bName);}
// OVERLOADING STREAM INSERTION OPERATOR
ostream &operator<<(ostream &out, OutSig const &o)
{
    out << "{name:" << o.getName() << ", type:" << o.getType() << ", aName:" << o.getA() << ", bName:" << o.getB() << "}";
    return (out);
}
int main()
{
    int n;cin>>n;cin.ignore();
    int m;cin>>m;cin.ignore();
    map<string, string> inSig;
    for (int i=0;i<n;i++)
    {
        string input_name;
        string input_signal;
        cin>>input_name>>input_signal;cin.ignore();
        inSig[input_name] = input_signal;
    }
    OutSig Lst[m];
    for (int i=0;i<m;i++)
    {
        string name;
        string type;
        string s1;
        string s2;
        cin>>name>>type>>s1>>s2;cin.ignore();
        Lst[i] = OutSig(name, type, s1, s2);
    }
    int size = inSig.begin()->second.size();
    string  N,A,B,T;
    int  a,b;
    for (int i=0;i<m;i++)
    {
        N=Lst[i].getName();
        A=inSig[Lst[i].getA()];
        B=inSig[Lst[i].getB()];
        T=Lst[i].getType();
        cout << N << " ";
        for (int e=0;e<size;e++)
        {
            a = (A[e] == '-');
            b = (B[e] == '-');
            if (T == "AND")
                cout << AND(a,b);
            else if (T == "OR")
                cout << OR(a,b);
            else if (T == "XOR")
                cout << XOR(a,b);
            else if (T == "NAND")
                cout << NAND(a,b);
            else if (T == "NOR")
                cout << NOR(a,b);
            else if (T == "NXOR")
                cout << NXOR(a,b);
            else
                cout << "?";
        }
        cout << endl;
    }
}
