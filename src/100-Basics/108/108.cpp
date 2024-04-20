/*
    Classes - Part IV (Operator overloading)
*/

// https://www.geeksforgeeks.org/operator-overloading-cpp/
// https://en.cppreference.com/w/cpp/language/operators

#include <iostream>

class point
{
public:
    point();
    point( int x, int y );

    ~point() = default;

    point( point&& other ) noexcept;
    point( const point& other );
    point& operator=( point&& other ) noexcept;
    point& operator=( const point& other );

    //
    // Binary Arithmetic
    //

    const point operator+( const point& other ) const;
    const point operator-( const point& other ) const;
    const point operator*( const point& other ) const;
    const point operator/( const point& other ) const;
    const point operator%( const point& other ) const;

    //friend const point operator+( const point& lhs, const point& rhs );
    //friend const point operator-( const point& lhs, const point& rhs );
    //friend const point operator*( const point& lhs, const point& rhs );
    //friend const point operator/( const point& lhs, const point& rhs );
    //friend const point operator%( const point& lhs, const point& rhs );

    //
    // Unary Arithmetic
    //

    point  operator+() const; // convert to positive
    point  operator-() const; // convert to negative
    point& operator++();      // prefix  increment
    point  operator++(int);   // postfix increment
    point& operator--();      // prefix  decrement
    point  operator--(int);   // postfix decrement

    //
    // Compound Assignment (must be member functions since the object gets modified)
    //

    point& operator+=( const point& other );
    point& operator-=( const point& other );
    point& operator*=( const point& other );
    point& operator/=( const point& other );
    point& operator%=( const point& other );
    point& operator&=( const point& other );
    point& operator|=( const point& other );
    point& operator^=( const point& other );

    //
    // Relational / Comparison operators
    //

    bool operator==( const point& other ) const;
    bool operator!=( const point& other ) const;
    bool operator< ( const point& other ) const;
    bool operator> ( const point& other ) const;
    bool operator<=( const point& other ) const;
    bool operator>=( const point& other ) const;

    //friend bool operator==( const point& lhs, const point& rhs )
    //friend bool operator!=( const point& lhs, const point& rhs )
    //friend bool operator< ( const point& lhs, const point& rhs )
    //friend bool operator> ( const point& lhs, const point& rhs )
    //friend bool operator<=( const point& lhs, const point& rhs )
    //friend bool operator>=( const point& lhs, const point& rhs )

    //
    // Bitwise arithmetic operators
    //

    point operator&( const point& other ); // AND
    point operator|( const point& other ); // OR
    point operator^( const point& other ); // XOR
    point operator~();                     // NOT
    point operator<<( int n );             // left shift
    point operator>>( int n );             // right shift
    point operator<<=( int n );            // left shift assignment
    point operator>>=( int n );            // right shift assignment

    //
    // Function call (functor)
    //

    bool operator()() const;

    //
    // Conversion operator
    //

    operator bool() const;

    // some other variants
    // operator string() const;

    //
    // Binary Logical
    //

    point operator&&(const point& other) const;
    point operator||(const point& other) const;

    //
    // Unary Logical
    //

    bool operator!() const;

    //
    // Subscripting
    //

    int operator[](int i);

    // some other variants
    // int& operator[](int i);
    // const int& operator[](int i) const;

    //
    // Set & Get data
    //

    int x() const;
    int y() const;

    void x( int p_x );
    void y( int p_y );

private:
    int m_x;
    int m_y;
};



point::point() : point(0, 0) // delegating ctor
{

}

point::point(int x, int y) : m_x(x), m_y(y)
{

}

point::point(point&& other) noexcept : m_x(0), m_y(0)
{
    m_x = other.m_x;
    m_y = other.m_y;

    other.m_x = 0;
    other.m_y = 0;
}

point::point(const point& other) : m_x(0), m_y(0)
{
    m_x = other.m_x;
    m_y = other.m_y;
}

point& point::operator=(point&& other) noexcept
{
  if (this != &other)
  {
    m_x = other.m_x;
    m_y = other.m_y;

    other.m_x = 0;
    other.m_y = 0;
  }

  return *this;
}

point& point::operator=(const point& other)
{
  if (this != &other)
  {
    m_x = other.m_x;
    m_y = other.m_y;
  }

  return *this;
}

//
// Binary Arithmetic
//

const point point::operator+( const point& other ) const
{
    return point( m_x + other.m_x, m_y + other.m_y );
}

const point point::operator-( const point& other ) const
{
    return point( m_x - other.m_x, m_y - other.m_y);
}

const point point::operator*( const point& other ) const
{
    // ???
    return point();
}

const point point::operator/( const point& other ) const
{
    // ???
    return point();
}

const point point::operator%( const point& other ) const
{
    // ???
    return point();
}

//
// Unary Arithmetic
//

point point::operator+() const
{
  return *this;
}

point point::operator-() const
{
  return point(-m_x, -m_y);
}

point& point::operator++()
{
  ++m_x;
  ++m_y;
  return *this; // return new value by reference
}

point point::operator++(int)
{
    point old = *this; // copy old value
    operator++();      // prefix increment
    return old;        // return old value
}

point& point::operator--()
{
  --m_x;
  --m_y;
  return *this;
}

point point::operator--(int)
{
    point old = *this; // copy old value
    operator--();      // prefix decrement
    return old;        // return old value
}

//
// Assignment
//

point& point::operator+=(const point& other)
{
  m_x += other.m_x;
  m_y += other.m_y;

  return *this;
}

point& point::operator-=(const point& other)
{
  m_x -= other.m_x;
  m_y -= other.m_y;

  return *this;
}

point& point::operator*=( const point& other )
{
  // ???
  return *this;
}

point& point::operator/=( const point& other )
{
  // ???
  return *this;
}

point& point::operator%=( const point& other )
{
  // ???
  return *this;
}

point& point::operator^=( const point& other )
{
  // ???
  return *this;
}

point& point::operator&=( const point& other )
{
  // ???
  return *this;
}

point& point::operator|=( const point& other )
{
  // ???
  return *this;
}

//
// Relational / Comparison operators
//

bool point::operator==(const point& other) const
{
  if(m_x == other.m_x && m_y == other.m_y)
  {
    return true;
  }

  return false;
}

bool point::operator!=(const point& other) const
{
  return !(*this == other);
}

bool point::operator< (const point& other) const
{
  return true;
}

bool point::operator> (const point& other) const
{
  if(m_x > other.m_x && m_y > other.m_y)
  {
    return true;
  }

  return false;
}

bool point::operator<=(const point& other) const
{
  return true;
}

bool point::operator>=(const point& other) const
{
  return true;
}

//
// Bitwise arithmetic operators
//

point point::operator&( const point& other )
{
  return point();
}

point point::operator|( const point& other )
{
  return point();
}

point point::operator^( const point& other )
{
  return point();
}

point point::operator~()
{
  return point();
}

point point::operator<<( int n )
{
  return point();
}

point point::operator>>( int n )
{
  return point();
}

point point::operator<<=( int n )
{
  return point();
}

point point::operator>>=( int n )
{
  return point();
}

//
// Function call (functor)
//

bool point::operator()() const
{
  if (m_x != 0 && m_y != 0)
  {
    return true;
  }

  return false;
}

//
// Conversion operator
//

point::operator bool() const
{
  if (m_x != 0 && m_y != 0)
  {
    return true;
  }

  return false;
}

//
// Binary Logical
//

point point::operator&&(const point& other) const
{
  return point(m_x && other.m_x, m_y && other.m_y);
}

point point::operator||(const point& other) const
{
  return point(m_x || other.m_x, m_y || other.m_y);
}

//
// Unary Logical
//

bool point::operator!() const
{
  if (m_x == 0 && m_y == 0)
  {
    return true;
  }

  return false;
}

//
// Subscripting
//

int point::operator[](int i)
{
  int ret = 0;

  switch (i)
  {
  case 1:
    ret = m_x;
    break;
  case 2:
    ret = m_y;
    break;
  default:
    break;
  }

  return ret;
}


//
// Set & Get data
//

int point::x() const
{
  return m_x;
}

int point::y() const
{
  return m_y;
}

void point::x(int p_x)
{
  m_x = p_x;
}

void point::y(int p_y)
{
  m_y = p_y;
}

//const point operator+( const point& lhs, const point& rhs ) // operator+ as normal function
//{
//    return point( lhs.x() + rhs.x(), lhs.y() + rhs.y() );
//}

//const point operator-( const point& lhs, const point& rhs ) // operator- as friend function with access to members
//{
//    return point( lhs.m_x - rhs.m_x, lhs.m_y - rhs.m_y );
//}

//
// Stream
//

std::ostream& operator<< ( std::ostream& os, const point& p ) // Stream insertion, must be implemented as non-members
{
    os << "[" << p.x() << "," << p.y() << "]";

    return os; // return std::ostream to chain calls to operator<<
}

std::istream& operator>>(std::istream& is, point& p) // Stream extraction, must be implemented as non-members
{
    // read obj from stream
    //if (/* T could not be constructed */)
    //    is.setstate(std::ios::failbit);
    return is;
}


int main()
{
    point p1( 1, 2 );
    point p2( 3, 4 );
    point p3 = p1 + p2;

    std::cout << p3 << std::endl;

    p3 += p1;

    std::cout << p3 << std::endl;

    if( p1 )
    {
        std::cout << "P1 is valid" << std::endl;
    }

    if( p1() )
    {
        std::cout << "P1 is valid" << std::endl;
    }

    if( !p1 )
    {
        std::cout << "P1 is not valid" << std::endl;
    }

    point p4 = -p3;

    std::cout << p4 << std::endl;

    point p5 = p1++;

    std::cout << p1 << p5 << std::endl;
}
