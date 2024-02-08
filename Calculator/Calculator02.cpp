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
                    Expression
                    Print
                    Quit
          Print:
                    ;

          Quit:
                    q

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
                    ( Expression )
                    – Primary
                    + Primary
          Number:
                    floating-point-literal


          Input comes from cin through the Token_stream called ts.
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>  

//------------------------------------------------------------------------------

const char number = '8';        // t.kind==number means that t is a number Token
const char quit = 'q';      // t.kind==quit means that t is a quit Token
const char print = ';';     // t.kind==print means that t is a print Token
const char name = 'a';      // name token
const char let = 'L';       // declaration token

const std::string declkey = "let";      // declaration keyword
const std::string prompt = "> ";
const std::string result = "= ";        // used to indicate that what follows is a result

//------------------------------------------------------------------------------

class Variable {
public:
    std::string name;
    double value;
};

//------------------------------------------------------------------------------

class Token {
public:
    char kind{};
    double value{};
    std::string name{};
    Token(char ch) :kind{ ch } { }      // initialize kind with ch
    Token(char ch, double val) :kind{ ch }, value{ val } { }        // initialize kind and value
    Token(char ch, std::string n) :kind{ ch }, name{ n } { }        // initialize kind and name
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
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // now search input:
    char ch = 0;
    while (std::cin >> ch)
        if (ch == c) return;
}

void Token_stream::putback(Token t)
{
    if (full) throw std::runtime_error("putback() into a full buffer");
    buffer = t;         // copy t to buffer
    full = true;        // buffer is now full
}

Token Token_stream::get()
// read characters from cin and compose a Token
{
    if (full) {     // check if we already have a Token ready
        full = false;
        return buffer;
    }
    char ch;
    std::cin >> ch;     // note that >> skips whitespace (space, newline, tab, etc.)

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
        std::cin.putback(ch);       // put digit back into the input stream
        double val;
        std::cin >> val;        // read a floating-point number
        return Token{ number, val };
    }
    default:
        if (isalpha(ch)) {
            std::string s;
            s += ch;
            while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
            std::cin.putback(ch);
            if (s == declkey) return Token{ let };      // declaration keyword
            return Token{ name, s };
        }
        throw std::runtime_error("Bad Token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;      // provides get() and putback()

std::vector<Variable> var_table;

//------------------------------------------------------------------------------

double get_value(std::string s)
// return the value of the Variable named s
{
    for (const Variable& v : var_table)
        if (v.name == s) return v.value;
    throw std::runtime_error("get: undefined variable");
}

void set_value(std::string s, double d)
// set the Variable named s to d
{
    for (Variable& v : var_table)
        if (v.name == s) {
            v.value = d;
            return;
        }
    throw std::runtime_error("set: undefined variable");
}

//------------------------------------------------------------------------------

bool is_declared(std::string var)
// is var already in var_table ?
{
    for (const Variable& v : var_table)
        if (v.name == var) return true;
    return false;
}

double define_name(std::string var, double val)
{
    if (is_declared(var)) throw std::runtime_error("declared twice");
    var_table.push_back(Variable{ var, val });
    return val;
}

//------------------------------------------------------------------------------

void clean_up_mess()
{
    ts.ignore(print);
}

//------------------------------------------------------------------------------

double expression();  // read and evaluate a Expression

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') throw std::runtime_error("')' expected");
        return d;
    }
    case number:
        return t.value;  // return the number’s value
    case '-':
        return -primary();
    case '+':
        return +primary();
    default:
        throw std::runtime_error("primary expected");
    }
}

//------------------------------------------------------------------------------

double declaration()
// assume we have seen "let”
// handle: name = expression
// declare a variable called "name” with the initial value "expression”
{
    Token t = ts.get();
    if (t.kind != name)
        throw std::runtime_error("name expected in declaration");
    std::string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=')
        throw std::runtime_error("= missing in declaration");

    double d = expression();
    define_name(var_name, d);
    return d;
}

//------------------------------------------------------------------------------

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
    }
}

//------------------------------------------------------------------------------

void calculate()        // expression evaluation loop
{
    while (std::cin) 
    try {
        std::cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t = ts.get();     // first discard all “prints”
        if (t.kind == quit) return;
        ts.putback(t);
        std::cout << result << statement() << '\n';
    }
    catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;     // write error message
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

    return 0;
}
catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    //std::cout << "to close the window, enter the '~' symbol" << std::endl;
    //char ch{};
    //for (char ch; std::cin >> ch;)      // read before character input ~
    //    if (ch == '~') return 1;
    return 1;
}
catch (...) {
    std::cerr << "exception" << std::endl;
    return 2;
}

//------------------------------------------------------------------------------

double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();     // get the next token
    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);      // return t to the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = ts.get();     // get the next token
    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) throw std::runtime_error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = primary();
            if (d == 0) throw std::runtime_error("%: division by zero");
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