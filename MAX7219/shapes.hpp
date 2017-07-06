#ifndef SHAPES_HPP
#define SHAPES_HPP

#include "coordinate.hpp"

class line{
private:
   coordinate start;
   coordinate end;
public:
   line( const coordinate & start, const coordinate & end ):
      start (start),
      end (end)
   {}
   void draw();
   void setStart();
   void setEnd();
   void getStart();
   void getEnd();
}

#endif //SHAPES_HPP 