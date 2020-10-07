#pragma once
class ScrollCenter
{
private:
	double x, y;
public:
	void Translate(double x = 0, double y = 0) {
		this->x += x;
		this->y += y;
	}
	void MoveTo(double x = 0, double y = 0) {
		this->x = x;
		this->y = y;
	}
	double GetX() const { return x; }
	double GetY() const { return y; }
public:
	ScrollCenter():x(0),y(0){}
};

