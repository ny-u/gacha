/**
* @file: Vec3.h
* @author: weijie
* @date: 24 feb 2024
* @brief: templated Vec3 
*/


#ifndef PK_VEC3_H
#define PK_VEC3_H

#include <ostream>

template<typename T = float>
struct Vec3
{
	T x{};
	T y{};
	T z{};

	// Constructors
	Vec3() {}
	Vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
	Vec3(T _val) : x(_val), y(_val), z(_val) {}

	Vec3 operator-() const;
	Vec3& operator += (Vec3 const& rhs);
	Vec3& operator -= (const Vec3& rhs);
	Vec3& operator /= (const Vec3& rhs);
	Vec3& operator *= (const Vec3& rhs);

	bool operator == (const Vec3& rhs) const;
	bool operator != (const Vec3& rhs) const;
};

template<typename T>
Vec3<T> operator+ (Vec3<T> const& lhs, Vec3<T> const& rhs);

template<typename T>
Vec3<T> operator- (Vec3<T> const& lhs, Vec3<T> const& rhs);

template<typename T>
Vec3<T> operator * (Vec3<T> const& lhs, Vec3<T> const& rhs);

template<typename T>
Vec3<T> operator / (Vec3<T> const& lhs, Vec3<T> const& rhs);

template<typename T>
T Vec3Magnitude(Vec3<T> const& _vec);

template<typename T>
void Vec3Normalize(Vec3<T> vecResult, Vec3<T> const& _vec);

template<typename T>
T Vec3Length(Vec3<T> const& _vec );

template<typename T>
T Vec3SquaredLength(Vec3<T> const& _vec);

template<typename T>
T Vec3Distance(Vec3<T> const& _vec);

template<typename T>
T Vec3cSquaredDistance(Vec3<T> const& _vec);

template <typename T>
T Vec3DotProduct(Vec3<T> const& lhs, Vec3<T> const& rhs);

template<typename T>
std::ostream& operator<<(std::ostream& lhs, Vec3<T> const& rhs);
// Definition

template <typename T>
Vec3<T> Vec3<T>::operator-() const
{
	x = -x;
	y = -y;
	z = -z;

	return *this;
}

template <typename T>
Vec3<T>& Vec3<T>::operator += (Vec3<T> const& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;

	return *this;
}

template <typename T>
Vec3<T>& Vec3<T>::operator-= (Vec3<T> const& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator*=(Vec3<T> const& rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator/=(Vec3<T> const& rhs)
{
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;
	return *this;
}

template <typename T>
bool Vec3<T>::operator==(Vec3<T> const& rhs) const
{
	if (x == rhs.x &&
		y == rhs.y &&
		z == rhs.z)
		return true;
	return false;
}

template<typename T>
bool Vec3<T>::operator!=(Vec3<T> const& rhs) const
{
	if (*this == rhs) return false;
	return true;
}

// Global Function

template<typename T>
Vec3<T> operator+ (Vec3<T> const& lhs, Vec3<T> const& rhs)
{
	Vec3<T> temp{ lhs };
	temp += rhs;
	return temp;
}

template<typename T>
Vec3<T> operator- (Vec3<T> const& lhs, Vec3<T> const& rhs)
{
	Vec3<T> temp{ lhs };
	temp -= rhs;
	return temp;
}

template<typename T>
Vec3<T> operator * (Vec3<T> const& lhs, Vec3<T> const& rhs)
{
	Vec3<T> temp{ lhs };
	temp *= rhs;
	return temp;
}

template<typename T>
Vec3<T> operator / (Vec3<T> const& lhs, Vec3<T> const& rhs)
{
	Vec3<T> temp{ lhs };
	temp /= rhs;
	return temp;
}

template<typename T>
T Vec3Magnitude(Vec3<T> const& _vec)
{
	return sqrt(pow(_vec.x, 2) + pow(_vec.y, 2) + pow(_vec.z, 2));
}

template<typename T>
void Vec3Normalize(Vec3<T> vecResult, Vec3<T> const& _vec)
{
	float mag = Vec3Magnitude(_vec);
	Vec3<T> magVec{ mag };
	vecResult /= magVec;
}

template<typename T>
T Vec3Length(Vec3<T> const& _vec)
{
	return sqrt(Vec3SquareLength(_vec));
}

template<typename T>
T Vec3SquaredLength(Vec3<T> const& _vec)
{
	return (_vec.x * _vec.x + _vec.y * _vec.y + _vec.z * _vec.z);
}

template<typename T>
T Vec3Distance(Vec3<T> const& lhs, Vec3<T> const& rhs)
{
	return sqrt(Vec3SquareDistance(lhs, rhs));
}

template<typename T>
T Vec3cSquaredDistance(Vec3<T> const& lhs, Vec3<T> const& rhs)
{
	T x = rhs.x - lhs.x;
	T y = rhs.y - lhs.y;
	T z = rhs.z - lhs.z;
	return (x * x + y * y + z * z);
}

template <typename T>
T Vec3DotProduct(Vec3<T> const& lhs, Vec3<T> const& rhs)
{
	T x1 = rhs.x, x0 = lhs.x, y1 = rhs.y, y0 = lhs.y, z1 = rhs.z, z0 = lhs.z;
	return (x1 * x0 + y1 * y0 + z1 * z0);
}

template<typename T>
std::ostream& operator<<(std::ostream& lhs, Vec3<T> const& rhs)
{
	lhs << '[' << rhs.x << ',' << rhs.y << ',' << rhs.z << ']';
	return lhs;
}

#endif // !PK_VEC3_H


