#ifndef __APE_STRUCTURE_H__
#define __APE_STRUCTURE_H__

#include <SDL2/SDL_rect.h> // For SDL_Point

namespace APE {
    /// @brief The Point struct, represent a pair of two-dimensional integer coordinate (x, y). Usually for screen coordinate.
    struct Point {
    public:
        /// @brief The x value (position along the x-axis) of the Point.
        int X = 0;
        /// @brief The y value (position along the y-axis) of the Point.
        int Y = 0;

        /// @brief Create a new Point, and set all value to 0.
        Point();
        /// @brief Create a new Point, with x and y are both set to the given value.
        /// @param XY The value of x and y to set.
        Point(int XY);
        /// @brief Create a new Point.
        /// @param X The x value (position along the x-axis) of the Point.
        /// @param Y The y value (position along the y-axis) of the Point.
        Point(int X, int Y);
        /// @brief Create a new Point from the given SDL_Point.
        /// @param p The SDL_Point to create.
        Point(const SDL_Point& p);

        operator SDL_Point() const; // Cast to SDL_Point.

        Point& operator=(const Point& p);
        Point& operator=(int xy);

        Point& operator+=(const Point& p);
        Point& operator+=(int xy);
        Point operator+(const Point& p) const;
        Point operator+(int xy) const;
        friend Point operator+(int xy, const Point& p);

        Point& operator-=(const Point& p);
        Point& operator-=(int xy);
        Point operator-(const Point& p) const;
        Point operator-(int xy) const;
        friend Point operator-(int xy, const Point& p);

        Point& operator*=(const Point& p);
        Point& operator*=(int xy);
        Point operator*(const Point& p) const;
        Point operator*(int xy) const;
        friend Point operator*(int xy, const Point& p);

        bool operator==(const Point& p) const;
        bool operator==(int xy) const;
        friend bool operator==(int xy, const Point& p);

        bool operator!=(const Point& p) const;
        bool operator!=(int xy) const;
        friend bool operator!=(int xy, const Point& p);

        /// @brief Calculate the distance between the two given Point.
        /// @param a The first Point (the starting Point).
        /// @param b The second Point (the ending Point).
        /// @return The distance between the two given Point.
        static double Distance(const Point& a, const Point& b);

        /// @brief The Zero Point, x and y value are 0 (0, 0)
        static const Point Zero;
        /// @brief The One Point, x and y value are 1 (1, 1)
        static const Point One;
        /// @brief The Up Point, x is 0 and y is 1 (0, 1) 
        static const Point Up;
        /// @brief The Down Point, x is 0 and y is -1 (0, -1) 
        static const Point Down;
        /// @brief The Left Point, x is -1 and y is 0 (-1, 0) 
        static const Point Left;
        /// @brief The Right Point, x is 1 and y is 0 (1, 0) 
        static const Point Right;
    };

    /// @brief The Size struct, represent the size of a two-dimensional integer rectangle. Usually for screen coordinate.
    struct Size {
    public:
        /// @brief The width of the Size (along the x-axis).
        int Width = 0;
        /// @brief The height of the Size (along the y-axis).
        int Height = 0;

        /// @brief Create a new Size, and set all value to 0.
        Size();
        /// @brief Create a new Size, with width and height are both set to the given value.
        /// @param WH The value of width and height to set.
        Size(int WH);
        /// @brief Create a new Size.
        /// @param Width The width of the Size (along the x-axis).
        /// @param Height The height of the Size (along the y-axis).
        Size(int Width, int Height);
        /// @brief Create a new Size, with width and height value are the x and y of the given Point.
        /// @param p The Point to create.
        Size(const Point& p);
        /// @brief Create a new Size, with width and height value are the x and y of the given SDL_Point.
        /// @param p The SDL_Point to create.
        Size(const SDL_Point& p);

        operator Point() const; // Cast to Point.
        operator SDL_Point() const; // Cast to SDL_Point.

        Size& operator=(const Size& s);
        Size& operator=(int wh);

        Size& operator+=(const Size& s);
        Size& operator+=(int wh);
        Size operator+(const Size& s) const;
        Size operator+(int wh) const;
        friend Size operator+(int wh, const Size& s);

        Size& operator-=(const Size& s);
        Size& operator-=(int wh);
        Size operator-(const Size& s) const;
        Size operator-(int wh) const;
        friend Size operator-(int wh, const Size& s);

        Size& operator*=(const Size& s);
        Size& operator*=(int wh);
        Size operator*(const Size& s) const;
        Size operator*(int wh) const;
        friend Size operator*(int wh, const Size& s);

        bool operator==(const Size& s) const;
        bool operator==(int wh) const;
        friend bool operator==(int wh, const Size& s);

        bool operator!=(const Size& s) const;
        bool operator!=(int wh) const;
        friend bool operator!=(int wh, const Size& s);

        /// @brief Create a new Size with the width and height value are the absolute value of this Size width and height.
        /// @return The absolute Size of this Size.
        Size Absolute() const;

        /// @brief Calculate the ratio (width / height) of the Size.
        /// @return The ratio (width / height) of the Size.
        double Ratio() const;
    
        /// @brief Check if the area of the Size represent is 0.
        /// @return true if the Size area is empty, false otherwise.
        bool IsEmptyArea() const;

        /// @brief Calculate the area that the Size represent.
        /// @return The area of the Size.
        long long Area() const;

        /// @brief Create a new Size with the given ratio (width / height).
        /// @param Ratio The ratio of the size (width / height) to create.
        /// @param Height The height of the size (along the y-axis).
        /// @return The newly created Size.
        static Size FromRatio(double Ratio, int Height);
        
        /// @brief Create a new Size with the given ratio (width / height) and width.
        /// @param Ratio The ratio of the size (width / height) to create.
        /// @param Width The width of the size (along the x-axis).
        /// @return The newly created Size.
        static Size FromRatioWithWidth(double Ratio, int Width);

        /// @brief The Zero Size, width and height value are 0 (0, 0)
        static const Size Zero;
        /// @brief The One Size, width and height value are 1 (1, 1)
        static const Size One;
        /// @brief The Up Size, width is 0 and height is 1 (0, 1) 
        static const Size Up;
        /// @brief The Down Size, width is 0 and height is -1 (0, -1) 
        static const Size Down;
        /// @brief The Left Size, width is -1 and height is 0 (-1, 0) 
        static const Size Left;
        /// @brief The Right Size, width is 1 and height is 0 (1, 0) 
        static const Size Right;
    };
}

#endif // __APE_STRUCTURE_H__