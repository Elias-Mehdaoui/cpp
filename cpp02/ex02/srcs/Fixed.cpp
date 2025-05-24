#include "../includes/Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(int value) : _value(value << _frac_bits)
{
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (float)(1 << _frac_bits)))
{
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat() const
{
    return ((float)_value / (1 << _frac_bits));
}


int Fixed::toInt() const
{
    return (_value >> _frac_bits);
}

Fixed& Fixed::operator=(const Fixed& other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _value = other._value;
    return (*this);
}


std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& other) const
{
    return (_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (_value < other._value);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (_value <= other._value);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (_value != other._value);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return (this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() 
{
    this->_value += 1;
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed temp(*this);
    this->_value += 1;
    return temp;
}

Fixed& Fixed::operator--() 
{
    this->_value -= 1;
    return *this;
}

Fixed Fixed::operator--(int) 
{
    Fixed temp(*this);
    this->_value -= 1;
    return temp;
}


Fixed& Fixed::min(Fixed& a, Fixed& b) 
{
    if (a < b)
        return a;
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) 
{
    if (a < b)
        return a;
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) 
{
    if (a > b)
        return a;
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) 
{
    if (a > b)
        return a;
    return (b);
}