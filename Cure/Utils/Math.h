#pragma once
#include <math.h>

struct Vec2 {
	float x, y;

	void ClampMagnitude(float min, float max) {
		float mag = Magnitude();
		float desiredMag = std::max(std::min(mag, max), min);

		if (mag > 0) {
			float s = desiredMag / mag;
			*this *= s;
		}
	}
	float Magnitude() {
		return sqrt(x * x + y * y);
	}
	Vec2& Normalize() {
		float mag = Magnitude();
		x /= mag;
		y /= mag;
		return *this;
	}
	Vec2 operator+(const Vec2& b) {
		Vec2 out = { x + b.x, y + b.y };
		return out;
	}
	Vec2& operator+=(const Vec2& b) {
		*this = *this + b;
		return *this;
	}

	Vec2 operator-(const Vec2& b) {
		Vec2 out = { x - b.x, y - b.y };
		return out;
	}

	Vec2 operator*(const float X) {
		return { x * X, y * X };
	}
	Vec2& operator+=(const float& X) {
		x += X;
		y += X;
		return *this;
	}
	Vec2& operator*=(const float& X) {
		x *= X;
		y *= X;
		return *this;
	}
	Vec2& operator-=(const Vec2& b) {
		*this = *this - b;
		return *this;
	}

	friend std::ostream& operator <<(std::ostream& out, const Vec2& B) {
		return out << B.x << " " << B.y;
	}

};
