#pragma once
#include "vec3.h"

typedef Vec3 pt;
typedef Vec3 vec;

class Ray {
public:
	Vec3 A, B;

	Ray() {};
	Ray(const Vec3& a, const Vec3& b) { A = a, B = b; }

	pt origin() const { return A; }
	vec direction() const { return B; }
	pt point_at_parameter(double t) const { return A + (B * t); }
};