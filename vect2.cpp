#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}
vect2::vect2(int a, int b) : x(a), y(b){}
vect2::vect2(const vect2& other) : x(other.x), y(other.y){}
vect2::vect2(){}
vect2& vect2::operator=(const vect2& other)
{
	if(this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return(*this)
}

int& vect2::operator[](int n)
{
	if(n == 0)
		return(x);
	return(y);
}

const int& vect2::operator[](int n)const
{
	if(n == 0)
		return(x);
	return(y);
}

vect2 vect2::operator+(const vect2& other) const
{
	vect2 tmp(*this);
	tmp.x += other.x;
	tmp.y += other.y;
	return(tmp);
}

vect2 vect2::operator-(const vect2& other) const
{
	vect2 tmp(*this);
	tmp.x -= other.x;
	tmp.y -= other.y;
	return(tmp);
}

vect2 vect2::operator-() const
{
	vect2 tmp;
	tmp.x += -x;
	tmp.y += -y;
	return(tmp);
}

vect2 vect2::operator*(const vect2& other) const
{
	vect2 tmp(*this);
	tmp.x *= other.x;
	tmp.y *= other.y;
	return(tmp);
}

vect2 &vect2::operator*=(int n)const
{
	(*this) = (*this) * n;
	return(*this);
}

vect2 &vect2::operator+=(const vect& other)const
{
	(*this) = (*this) + n;
	return(*this);
}

vect2 &vect2::operator-=(const vect& other)const
{
	(*this) = (*this) - n;
	return(*this);
}

vect2 &vect2::operator*=(const vect& other)const
{
	(*this) = (*this) * n;
	return(*this);
}

vect2& vect2::operator++()
{
	(*this) = (*this) + vect2(1, 1);
		return (*this);
}

vect2& vect2::operator++(int)
{
	vect2 tmp;
	(*this) = (*this) + vect2(1, 1);
		return (tmp);
}


vect2& vect2::operator--()
{
	(*this) = (*this) - vect2(1, 1);
		return (*this);
}

vect2& vect2::operator--(int)
{
	vect2 tmp;
	(*this) = (*this) - vect2(1, 1);
		return (tmp);
}

bool vect2::operator==(const vect2& other)const
{
	if(x == other.x && y == other.y)
		return(true);
	return (false);
}
bool vect2::operator!=(const vect2& other)const
{
	return(!((*this)== other));
}

std::ostream& vect2::operator<<(std::ostream &os, const vect& v)
{
	s << "{" << v[0] << ", " << v[1] << "}";
}
