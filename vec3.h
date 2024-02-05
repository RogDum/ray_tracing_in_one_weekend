#pragma once
class Vec3 {
public:
    double e[3] = {0};

    //构造函数
    Vec3() {}
    Vec3(double e0, double e1, double e2) { e[0] = e0; e[1] = e1; e[2] = e2; }

    double* begin() { return e; };
    double* end() { return e+3; };

    //取坐标
    inline double y() const { return e[0]; }
    inline double x() const { return e[1]; }
    inline double z() const { return e[2]; }
    inline double r() const { return e[0]; }
    inline double g() const { return e[1]; }
    inline double b() const { return e[2]; }

    //正负号
    inline Vec3& operator+() { return *this;}
    inline Vec3  operator-() const { return Vec3(-e[0], -e[1], -e[2]); }

    //向量和
    inline Vec3 operator+(const Vec3& v) const {
        return Vec3(e[0] + v.e[0], e[1] + v.e[1], e[2] + v.e[2]);
    }
    inline Vec3& operator+=(const Vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    //向量差
    inline Vec3 operator-(const Vec3& v) {
        return Vec3(e[0] - v.e[0], e[1] - v.e[1], e[2] - v.e[2]);
    }
    inline Vec3& operator-=(const Vec3& v) {
        *this += -v;
        return *this;
    }

    //颜色积
    inline Vec3 operator*(const Vec3& v) {
        return Vec3(e[0] * v.e[0], e[1] * v.e[1], e[2] * v.e[2]);
    }
    inline Vec3& operator*=(const Vec3& v) {
        e[0] *= v.e[0];
        e[1] *= v.e[1];
        e[2] *= v.e[2];
        return *this;
    }

    //标量积
    inline Vec3 operator*(double v) const {
        return Vec3(e[0] * v, e[1] * v, e[2] * v);
    }
    inline Vec3 operator*=(double v) {
        e[0] *= v;
        e[1] *= v;
        e[2] *= v;
        return *this;
    }

    
     //颜色商
    inline Vec3 operator/(const Vec3& v) {
        return Vec3(e[0] / v.e[0], e[1] / v.e[1], e[2] / v.e[2]);
    }
    inline Vec3& operator/=(const Vec3& v) {
        e[0] /= v.e[0];
        e[1] /= v.e[1];
        e[2] /= v.e[2];
        return *this;
    }
    
    //标量商
    inline Vec3 operator/(double v) {
        return Vec3(e[0] / v, e[1] / v, e[2] / v);
    }
    inline Vec3& operator/=(double v) {
        e[0] /= v;
        e[1] /= v;
        e[2] /= v;
        return *this;
    }

    //下标
    inline double& operator[](int i) { return e[i]; }
    inline double  operator[](int i) const { return e[i];}

    //点乘
    inline static double dot(Vec3& v1, Vec3& v2) { return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z() ;};

    //叉乘
    inline static Vec3 cross(Vec3& v1, Vec3& v2) {
        return Vec3(v1[1] * v2[2] - v1[2] * v2[1], v1[2] * v2[0] - v1[0] * v2[2], v1[0] * v2[1] - v1[1] * v2[0]);
    }

    //模长
    inline double lenth() {
        return sqrt(x() * x() + y() * y() + z() * z());
    }

    //单位向量
    inline static Vec3 unit(Vec3& v) {
        return v / v.lenth();
    }
};

// 打印向量
inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {
    return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
}