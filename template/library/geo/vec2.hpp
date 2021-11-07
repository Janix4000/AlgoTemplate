#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Vec2T {
    T x = 0, y = 0;
    Vec2T<T>(T x, T y) : x(x), y(y) {}
    Vec2T<T>() = default;
    Vec2T<T> &operator+=(const Vec2T<T> &rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    Vec2T<T> operator-() const { return *this * (T)-1; }
    Vec2T<T> operator+(const Vec2T<T> &rhs) const {
        auto res = *this;
        res += rhs;
        return res;
    }
    Vec2T<T> &operator-=(const Vec2T<T> &rhs) { return (*this += -rhs); }
    Vec2T<T> operator-(const Vec2T<T> &rhs) const { return *this + (-rhs); }
    Vec2T<T> &operator*=(int rhs) {
        x *= rhs;
        y *= rhs;
        return *this;
    }
    Vec2T<T> operator*(int rhs) const {
        auto res = *this;
        res *= rhs;
        return res;
    }
    T operator*(const Vec2T<T> &rhs) const { return x * rhs.x + y * rhs.y; }
    T dot(const Vec2T<T> &rhs) const { return x * rhs.x + y * rhs.y; }
    T operator%(const Vec2T<T> &rhs) const { return x * rhs.y - y * rhs.x; }
    T cross(const Vec2T<T> &rhs) const { return x * rhs.y - y * rhs.x; }
    bool is_pendepicular(const Vec2T<T> &rhs) const {
        return *this * rhs == (T)0;
    }
    bool is_coolinear(const Vec2T<T> &rhs) const { return *this % rhs == (T)0; }
    double angle_between(const Vec2T<T> &rhs) {
        auto dot = *this * rhs;
        auto det = *this % rhs;
        return atan2(det, dot);
    }
    T len_sq() const { return *this * *this; }
    double len() const { return sqrt(len_sq()); }
};

using Vec2 = Vec2T<long long>;