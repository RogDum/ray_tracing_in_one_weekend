#pragma once
class Vec3 {
public:
    double e[3] = {0};

    //���캯��
    Vec3() {}
    Vec3(double e0, double e1, double e2) { e[0] = e0; e[1] = e1; e[2] = e2; }

    double* begin() { return e; };
    double* end() { return e+3; };

    //ȡ����
    inline double y() const { return e[0]; }
    inline double x() const { return e[1]; }
    inline double z() const { return e[2]; }
    inline double r() const { return e[0]; }
    inline double g() const { return e[1]; }
    inline double b() const { return e[2]; }

    //������
    inline Vec3& operator+() { return *this;}
    inline Vec3  operator-() const { return Vec3(-e[0], -e[1], -e[2]); }

    //������
    inline Vec3 operator+(const Vec3& v) const {
        return Vec3(e[0] + v.e[0], e[1] + v.e[1], e[2] + v.e[2]);
    }
    inline Vec3& operator+=(const Vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    //������
    inline Vec3 operator-(const Vec3& v) {
        return Vec3(e[0] - v.e[0], e[1] - v.e[1], e[2] - v.e[2]);
    }
    inline Vec3& operator-=(const Vec3& v) {
        *this += -v;
        return *this;
    }

    //��ɫ��
    inline Vec3 operator*(const Vec3& v) {
        return Vec3(e[0] * v.e[0], e[1] * v.e[1], e[2] * v.e[2]);
    }
    inline Vec3& operator*=(const Vec3& v) {
        e[0] *= v.e[0];
        e[1] *= v.e[1];
        e[2] *= v.e[2];
        return *this;
    }

    //������
    inline Vec3 operator*(double v) const {
        return Vec3(e[0] * v, e[1] * v, e[2] * v);
    }
    inline Vec3 operator*=(double v) {
        e[0] *= v;
        e[1] *= v;
        e[2] *= v;
        return *this;
    }

    
     //��ɫ��
    inline Vec3 operator/(const Vec3& v) {
        return Vec3(e[0] / v.e[0], e[1] / v.e[1], e[2] / v.e[2]);
    }
    inline Vec3& operator/=(const Vec3& v) {
        e[0] /= v.e[0];
        e[1] /= v.e[1];
        e[2] /= v.e[2];
        return *this;
    }
    
    //������
    inline Vec3 operator/(double v) {
        return Vec3(e[0] / v, e[1] / v, e[2] / v);
    }
    inline Vec3& operator/=(double v) {
        e[0] /= v;
        e[1] /= v;
        e[2] /= v;
        return *this;
    }

    //�±�
    inline double& operator[](int i) { return e[i]; }
    inline double  operator[](int i) const { return e[i];}

    //���
    inline static double dot(Vec3& v1, Vec3& v2) { return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z() ;};

    //���
    inline static Vec3 cross(Vec3& v1, Vec3& v2) {
        return Vec3(v1[1] * v2[2] - v1[2] * v2[1], v1[2] * v2[0] - v1[0] * v2[2], v1[0] * v2[1] - v1[1] * v2[0]);
    }

    //ģ��
    inline double lenth() {
        return sqrt(x() * x() + y() * y() + z() * z());
    }

    //��λ����
    inline static Vec3 unit(Vec3& v) {
        return v / v.lenth();
    }
};

// ��ӡ����
inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {
    return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
}