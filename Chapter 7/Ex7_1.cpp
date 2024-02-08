/*
          Simple calculator

          Revision history:

                    Revised by Bjarne Stroustrup November 2013
                    Revised by Bjarne Stroustrup May 2007
                    Revised by Bjarne Stroustrup August 2006
                    Revised by Bjarne Stroustrup August 2004
                    Originally written by Bjarne Stroustrup
                               (bs@cs.tamu.edu) Spring 2004.

          This program implements a basic expression calculator.
          Input from cin; output to cout.
          The grammar for input is:

          Statement:
                    Declaration
                    Expression
                    Print
                    Quit
          Print:
                    ;

          Quit:
                    q

          Declaration:
                    'let' Name '=' Expression

          Expression:
                    Term
                    Expression + Term
                    Expression – Term
          Term:
                    Primary
                    Term * Primary
                    Term / Primary
                    Term % Primary
          Primary:
                    Number
                    Name
                    ( Expression )
                    – Primary
                    + Primary
          Number:
                    floating-point-literal

          Name:
                    non-existing-variable


          Input comes from cin through the Token_stream called ts.

          Allow underscores in the calculator’s variable names
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
using namespace std;

//------------------------------------------------------------------------------

const char number = '8';        // t.kind==number means that t is a number Token
const char quit = 'q';      // t.kind==quit means that t is a quit Token
const char print = ';';     // t.kind==print means that t is a print Token
const char name = 'a';      // name token
const char let = 'L';       // declaration token

const string declkey = "let";      // declaration keyword
const string prompt = "> ";
const string result = "= ";        // used to indicate that what follows is a result

//------------------------------------------------------------------------------

class Variable {
public:
    string name;
    double value;
};

//------------------------------------------------------------------------------

class Token {
public:
    char kind{};
    double value{};
    string name{};

    Token(char ch) :kind{ ch } { }      // initialize kind with ch
    Token(char ch, double val) :kind{ ch }, value{ val } { }        // initialize kind and value
    Token(char ch, string n) :kind{ ch }, name{ n } { }        // initialize kind and name
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token get();            // get a Token
    void putback(Token t);  // put a Token back
    void ignore(char c);    // discard characters up to and including a c
private:
    bool full{ false };      // is there a Token in the buffer?
    Token buffer = { '0' };           // where we store a 'putback' Token
};

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
// c represents the kind of Token
{
    // first look in buffer:
    if (full && c == buffer.kind)
    {
        full = false;
        return;
    }
    full = false;

    // now search input:
    char ch = 0;
    while (cin >> ch)
        if (ch == c)
            return;
}

void Token_stream::putback(Token t)
{
    if (full)
        throw runtime_error("putback() into a full buffer");
    buffer = t;         // copy t to buffer
    full = true;        // buffer is now full
}

Token Token_stream::get()
// read characters from cin and compose a Token
{
    if (full)
    {     // check if we already have a Token ready
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;     // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case quit:       // for "quit"
    case print:       // for "print"
    case '=':
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        return Token{ ch };   // let each character represent itself
    case '.':       // let each character represent itself
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':       // numeric literal
    {
        cin.putback(ch);       // put digit back into the input stream
        double val;
        cin >> val;        // read a floating-point number
        return Token{ number, val };
    }
    default:
        if (isalpha(ch) || ch == '_') {
            string s;
            s += ch;
            while (cin.get(ch) && (isalnum(ch) || ch == '_'))     // changed isalpha and isdigit to similar isalnum
                s += ch;
            cin.putback(ch);
            if (s == declkey)
                return Token{ let };      // declaration keyword
            return Token{ name, s };
        }
        throw runtime_error("Bad Token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;      // provides get() and putback()

vector<Variable> var_table;

//------------------------------------------------------------------------------

double get_value(string s)
// return the value of the Variable named s
{
    for (const Variable& v : var_table)
        if (v.name == s)
            return v.value;
    throw runtime_error("get: undefined variable");
}

void set_value(string s, double d)
// set the Variable named s to d
{
    for (Variable& v : var_table)
        if (v.name == s)
        {
            v.value = d;
            return;
        }
    throw runtime_error("set: undefined variable");
}

bool is_declared(string var)
// is var already in var_table ?
{
    for (const Variable& v : var_table)
        if (v.name == var)
            return true;
    return false;
}

double define_name(string var, double val)
{
    if (is_declared(var))
        throw runtime_error("declared twice");
    var_table.push_back(Variable{ var, val });
    return val;
}

//------------------------------------------------------------------------------

void clean_up_mess()
{
    ts.ignore(print);
}

//------------------------------------------------------------------------------

double expression(Token_stream&);  // read and evaluate a Expression

double term(Token_stream&);        // read and evaluate a Term

//------------------------------------------------------------------------------

double primary(Token_stream& ts)     // read and evaluate a Primary
{
    Token t = ts.get();

    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression(ts);
        t = ts.get();
        if (t.kind != ')')
            throw runtime_error("')' expected");
        return d;
    }
    case number:
        return t.value;  // return the number’s value
    case name:
        return get_value(t.name);
    case '-':
        return -primary(ts);
    case '+':
        return +primary(ts);
    default:
        throw runtime_error("primary expected");
    }
}

//------------------------------------------------------------------------------

double declaration(Token_stream& ts)
// assume we have seen "let”
// handle: name = expression
// declare a variable called "name” with the initial value "expression”
{
    Token t = ts.get();
    if (t.kind != name)
        throw runtime_error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=')
        throw runtime_error("= missing in declaration");

    double d = expression(ts);
    define_name(var_name, d);
    return d;
}

//------------------------------------------------------------------------------

double statement(Token_stream& ts)
{
    Token t = ts.get();

    switch (t.kind) {
    case let:
        return declaration(ts);
    default:
        ts.putback(t);
        return expression(ts);
    }
}

//------------------------------------------------------------------------------

void calculate()        // expression evaluation loop
{
    while (cin)
        try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print)
            t = ts.get();     // first discard all “prints”
        if (t.kind == quit)
            return;
        ts.putback(t);
        cout << result << statement(ts) << '\n';
    }
    catch (runtime_error& e) {
        cerr << e.what() << endl;     // write error message
        clean_up_mess();
    }
}

//------------------------------------------------------------------------------

int main()
try {
    // predefine names:
    define_name("pi", 3.1415926535);
    define_name("e", 2.7182818284);

    calculate();
}
catch (runtime_error& e) {
    cerr << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "exception" << endl;
    return 2;
}

//------------------------------------------------------------------------------

double expression(Token_stream& ts)
{
    double left = term(ts);      // read and evaluate a Term
    Token t = ts.get();     // get the next token

    while (true) {
        switch (t.kind) {
        case '+':
            left += term(ts);    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term(ts);    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);      // return t to the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double term(Token_stream& ts)
{
    double left = primary(ts);
    Token t = ts.get();     // get the next token

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary(ts);
            t = ts.get();
            break;
        case '/':
        {
            double d = primary(ts);
            if (d == 0)
                throw runtime_error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = primary(ts);
            if (d == 0)
                throw runtime_error("%: division by zero");
            left = fmod(left, d);
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);      // return t to the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------
