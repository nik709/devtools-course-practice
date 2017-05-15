// Copyright 2017 Zorina Ekaterina

#include "include/vector3D.h"


Vector3D::Vector3D(double _x, double _y, double _z) {
    x = _x;
    y = _y;
    z = _z;
}

Vector3D::Vector3D(const Vector3D &v) {
    x = v.x;
    y = v.y;
    z = v.z;
}

bool Vector3D::operator==(const Vector3D &v) const {
    if (x == v.x && y == v.y && z == v.z)
        return true;
    else
        return false;
}

bool Vector3D::operator!=(const Vector3D &v) const {
    return !(*this == v);
}

Vector3D& Vector3D::operator=(const Vector3D &v) {
    if (*this != v) {
        x = v.x;
        y = v.y;
        z = v.z;
    }
    return *this;
}

Vector3D Vector3D::operator+(const Vector3D &v) const {
    Vector3D temp;
    temp.x = x + v.x;
    temp.y = y + v.y;
    temp.z = z + v.z;

    return temp;
}

Vector3D Vector3D::operator-(const Vector3D &v) const {
    Vector3D temp;
    temp.x = x - v.x;
    temp.y = y - v.y;
    temp.z = z - v.z;

    return temp;
}

double Vector3D::Norm() {
    return sqrt(x*x + y*y + z*z);
}

Vector3D Vector3D::Normalize() {
    double norm = Norm();
    if (norm != 0.0) {
        x = x / norm;
        y = y / norm;
        z = z / norm;
    }

    return *this;
}

double Vector3D::operator*(const Vector3D & v) const {
    return x*v.x + y*v.y + z*v.z;
}

Vector3D Vector3D::operator^(const Vector3D & v) const {
    Vector3D vt(*this), temp;
    if (vt.x != 0 || vt.y != 0 || vt.z != 0) {
        if (v.x != 0 || v.y != 0 || v.z != 0) {
            temp.x = vt.y*v.z - vt.z*v.y;
            temp.y = vt.z*v.x - vt.x*v.z;
            temp.z = vt.x*v.y - vt.y*v.x;
        }
    }
    return temp;
}
