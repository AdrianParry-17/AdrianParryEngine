#include "APE/APE_Structure.h"

#include <math.h>

//* --- APE::Point ---

APE::Point::Point() = default;
APE::Point::Point(int XY) : X(XY), Y(XY) {}
APE::Point::Point(int X, int Y) : X(X), Y(Y) {}
APE::Point::Point(const SDL_Point& p) : X(p.x), Y(p.y) {} // Copy from SDL_Point

APE::Point::operator SDL_Point() const { return SDL_Point{X, Y}; } // Cast to SDL_Point

APE::Point& APE::Point::operator=(const APE::Point& p) { X = p.X; Y = p.Y; return *this; }
APE::Point& APE::Point::operator=(int xy) { X = xy; Y = xy; return *this; }

APE::Point& APE::Point::operator+=(const APE::Point& p) { X += p.X; Y += p.Y; return *this; }
APE::Point& APE::Point::operator+=(int xy) { X += xy; Y += xy; return *this; }
APE::Point APE::Point::operator+(const APE::Point& p) const { return {X + p.X, Y + p.Y}; }
APE::Point APE::Point::operator+(int xy) const { return {X + xy, Y + xy}; }
APE::Point operator+(int xy, const APE::Point& p) { return {xy + p.X, xy + p.Y}; }

APE::Point& APE::Point::operator-=(const APE::Point& p) { X -= p.X; Y -= p.Y; return *this; }
APE::Point& APE::Point::operator-=(int xy) { X -= xy; Y -= xy; return *this; }
APE::Point APE::Point::operator-(const APE::Point& p) const { return {X - p.X, Y - p.Y}; }
APE::Point APE::Point::operator-(int xy) const { return {X - xy, Y - xy}; }
APE::Point operator-(int xy, const APE::Point& p) { return {xy - p.X, xy - p.Y}; }

APE::Point& APE::Point::operator*=(const APE::Point& p) { X *= p.X; Y *= p.Y; return *this; }
APE::Point& APE::Point::operator*=(int xy) { X *= xy; Y *= xy; return *this; }
APE::Point APE::Point::operator*(const APE::Point& p) const { return {X * p.X, Y * p.Y}; }
APE::Point APE::Point::operator*(int xy) const { return {X * xy, Y * xy}; }
APE::Point operator*(int xy, const APE::Point& p) { return {xy * p.X, xy * p.Y}; }

bool APE::Point::operator==(const APE::Point& p) const { return X == p.X && Y == p.Y; }
bool APE::Point::operator==(int xy) const { return X == xy && Y == xy; }
bool operator==(int xy, const APE::Point& p) { return xy == p.X && xy == p.Y; }

bool APE::Point::operator!=(const APE::Point& p) const { return X != p.X || Y != p.Y; }
bool APE::Point::operator!=(int xy) const { return X != xy || Y != xy; }
bool operator!=(int xy, const APE::Point& p) { return xy != p.X || xy != p.Y; }

double APE::Point::Distance(const APE::Point& a, const APE::Point& b) { return hypot(b.X - a.X, b.Y - a.Y); }

const APE::Point APE::Point::Zero = APE::Point(0, 0);
const APE::Point APE::Point::One = APE::Point(1, 1);
const APE::Point APE::Point::Up = APE::Point(0, 1);
const APE::Point APE::Point::Down = APE::Point(0, -1);
const APE::Point APE::Point::Left = APE::Point(-1, 0);
const APE::Point APE::Point::Right = APE::Point(1, 0);

//* --- APE::Size ---

APE::Size::Size() = default;
APE::Size::Size(int WH) : Width(WH), Height(WH) {}
APE::Size::Size(int Width, int Height) : Width(Width), Height(Height) {}
APE::Size::Size(const APE::Point& p) : Width(p.X), Height(p.Y) {}
APE::Size::Size(const SDL_Point& p) : Width(p.x), Height(p.y) {}

APE::Size::operator APE::Point() const { return Point(Width, Height); } // Cast to Point.
APE::Size::operator SDL_Point() const { return SDL_Point{Width, Height}; } // Cast to SDL_Point.


APE::Size& APE::Size::operator=(const Size& s) { Width = s.Width; Height = s.Height; return *this; }
APE::Size& APE::Size::operator=(int wh) { Width = wh; Height = wh; return *this; }

APE::Size& APE::Size::operator+=(const Size& s) { Width += s.Width; Height += s.Height; return *this; }
APE::Size& APE::Size::operator+=(int wh) { Width += wh; Height += wh; return *this; }
APE::Size APE::Size::operator+(const Size& s) const { return {Width + s.Width, Height + s.Height}; }
APE::Size APE::Size::operator+(int wh) const { return {Width + wh, Height + wh}; }
APE::Size operator+(int wh, const APE::Size& s) { return {wh + s.Width, wh + s.Height}; }

APE::Size& APE::Size::operator-=(const Size& s) { Width -= s.Width; Height -= s.Height; return *this; }
APE::Size& APE::Size::operator-=(int wh) { Width -= wh; Height -= wh; return *this; }
APE::Size APE::Size::operator-(const Size& s) const { return {Width - s.Width, Height - s.Height}; }
APE::Size APE::Size::operator-(int wh) const { return {Width - wh, Height - wh}; }
APE::Size operator-(int wh, const APE::Size& s) { return {wh - s.Width, wh - s.Height}; }

APE::Size& APE::Size::operator*=(const Size& s) { Width *= s.Width; Height *= s.Height; return *this; }
APE::Size& APE::Size::operator*=(int wh) { Width *= wh; Height *= wh; return *this; }
APE::Size APE::Size::operator*(const Size& s) const { return {Width * s.Width, Height * s.Height}; }
APE::Size APE::Size::operator*(int wh) const { return {Width * wh, Height * wh}; }
APE::Size operator*(int wh, const APE::Size& s) { return {wh * s.Width, wh * s.Height}; }

bool APE::Size::operator==(const Size& s) const { return Width == s.Width && Height == s.Height; }
bool APE::Size::operator==(int wh) const { return Width == wh && Height == wh; }
bool operator==(int wh, const APE::Size& s) { return wh == s.Width && wh == s.Height; }

bool APE::Size::operator!=(const Size& s) const { return Width != s.Width || Height != s.Height; }
bool APE::Size::operator!=(int wh) const { return Width != wh || Height != wh; }
bool operator!=(int wh, const APE::Size& s) { return wh != s.Width || wh != s.Height; }

APE::Size APE::Size::Absolute() const { return Size(abs(Width), abs(Height)); }
double APE::Size::Ratio() const { return fabs(Width) / fabs(Height); }
bool APE::Size::IsEmptyArea() const { return Width == 0 || Height == 0; }
long long APE::Size::Area() const { return llabs(Width) * llabs(Height); }

APE::Size APE::Size::FromRatio(double Ratio, int Height) { return Size((int)abs(Ratio * Height), abs(Height)); }
APE::Size APE::Size::FromRatioWithWidth(double Ratio, int Width) { return Size(abs(Width), (int)abs((double)Width / Ratio)); }

const APE::Size APE::Size::Zero = APE::Size(0, 0);
const APE::Size APE::Size::One = APE::Size(1, 1);
const APE::Size APE::Size::Up = APE::Size(0, 1);
const APE::Size APE::Size::Down = APE::Size(0, -1);
const APE::Size APE::Size::Left = APE::Size(-1, 0);
const APE::Size APE::Size::Right = APE::Size(1, 0);