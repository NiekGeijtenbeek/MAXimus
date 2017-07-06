#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include "settings.hpp"

class coordinate{
public:
    uint8_t x;
    uint8_t y;
    
    coordinate( uint8_t x = 0, uint8_t y = 0 ):
        x(x),y(y)
    {
        if( x > DISPLAY_WIDTH ){hwlib::cout << "ERROR: coordinate x value is out of range. " << x-DISPLAY_WIDTH << " too big.\n";}
        if( y > DISPLAY_HEIGHT ){hwlib::cout << "ERROR: coordinate y value is out of range. " << y-DISPLAY_HEIGHT << " too big.\n";}
    }
    
    coordinate & operator=(const coordinate & rhs){
        x=rhs.x;
        y=rhs.y;
        return *this;
    }
    
    void shiftLeft(const uint8_t & rhs){
        x = x - rhs;
    }
    
    void shiftRight(const uint8_t & rhs){
        x = x + rhs;
    }
    
    void shiftUp(const uint8_t & rhs){
        y = y - rhs;
    }
    
    void shiftDown(const uint8_t & rhs){
        y = y + rhs;
    }
    
    void invert(){
        uint8_t temp = x;
        x=y;
        y=temp;
    }
    
    coordinate & operator+=(const coordinate & rhs){
        x = x + rhs.x;
        y = y + rhs.y;
        return *this;
    }
    
    coordinate & operator*=(const coordinate & rhs){
        x = x * rhs.x;
        y = y * rhs.y;
        return *this;
    }
    
    coordinate & operator-=(const coordinate & rhs){
        x = x - rhs.x;
        y = y - rhs.y;
        return *this;
    }
    
    //Dit is om positieve getallen te onderscheiden van negatieve... bijv: -5 +5  
    coordinate operator+() const{
        return coordinate(x,y);
    }
    
    coordinate operator+(const coordinate & rhs) const{
        return(coordinate(x+rhs.x, y+rhs.y));
        
    }
    
    coordinate operator*(const coordinate & rhs) const{
        return(coordinate(x*rhs.x, y*rhs.y));
        
    }
    
    coordinate operator-(const coordinate & rhs) const{
        return(coordinate(x-rhs.x, y-rhs.y));
        
    }
  
};

#endif //COORDINATE_HPP