/*

          _____                    _____                                            _____                    _____                    _____                    _____          
         /\    \                  /\    \                 ______                   /\    \                  /\    \                  /\    \                  /\    \         
        /::\____\                /::\    \               |::|   |                 /::\    \                /::\____\                /::\____\                /::\    \        
       /::::|   |               /::::\    \              |::|   |                 \:::\    \              /::::|   |               /:::/    /               /::::\    \       
      /:::::|   |              /::::::\    \             |::|   |                  \:::\    \            /:::::|   |              /:::/    /               /::::::\    \      
     /::::::|   |             /:::/\:::\    \            |::|   |                   \:::\    \          /::::::|   |             /:::/    /               /:::/\:::\    \     
    /:::/|::|   |            /:::/__\:::\    \           |::|   |                    \:::\    \        /:::/|::|   |            /:::/    /               /:::/__\:::\    \    
   /:::/ |::|   |           /::::\   \:::\    \          |::|   |                    /::::\    \      /:::/ |::|   |           /:::/    /                \:::\   \:::\    \   
  /:::/  |::|___|______    /::::::\   \:::\    \         |::|   |           ____    /::::::\    \    /:::/  |::|___|______    /:::/    /      _____    ___\:::\   \:::\    \  
 /:::/   |::::::::\    \  /:::/\:::\   \:::\    \  ______|::|___|___ ____  /\   \  /:::/\:::\    \  /:::/   |::::::::\    \  /:::/____/      /\    \  /\   \:::\   \:::\    \ 
/:::/    |:::::::::\____\/:::/  \:::\   \:::\____\|:::::::::::::::::|    |/::\   \/:::/  \:::\____\/:::/    |:::::::::\____\|:::|    /      /::\____\/::\   \:::\   \:::\____\
\::/    / ~~~~~/:::/    /\::/    \:::\  /:::/    /|:::::::::::::::::|____|\:::\  /:::/    \::/    /\::/    / ~~~~~/:::/    /|:::|____\     /:::/    /\:::\   \:::\   \::/    /
 \/____/      /:::/    /  \/____/ \:::\/:::/    /  ~~~~~~|::|~~~|~~~       \:::\/:::/    / \/____/  \/____/      /:::/    /  \:::\    \   /:::/    /  \:::\   \:::\   \/____/ 
             /:::/    /            \::::::/    /         |::|   |           \::::::/    /                       /:::/    /    \:::\    \ /:::/    /    \:::\   \:::\    \     
            /:::/    /              \::::/    /          |::|   |            \::::/____/                       /:::/    /      \:::\    /:::/    /      \:::\   \:::\____\    
           /:::/    /               /:::/    /           |::|   |             \:::\    \                      /:::/    /        \:::\__/:::/    /        \:::\  /:::/    /    
          /:::/    /               /:::/    /            |::|   |              \:::\    \                    /:::/    /          \::::::::/    /          \:::\/:::/    /     
         /:::/    /               /:::/    /             |::|   |               \:::\    \                  /:::/    /            \::::::/    /            \::::::/    /      
        /:::/    /               /:::/    /              |::|   |                \:::\____\                /:::/    /              \::::/    /              \::::/    /       
        \::/    /                \::/    /               |::|___|                 \::/    /                \::/    /                \::/____/                \::/    /        
         \/____/                  \/____/                 ~~                       \/____/                  \/____/                  ~~                       \/____/         
                                                                                                                                                                              

	Author:		Niek Franciscus Geijtenbeek			
	Libary:		MAXimus V1.O
	File:		   coordinate.hpp
	
	Copyright Niek Geijtenbeek 2017.
	Distrubyted under the Boost Software License, Version 1.0.
	(See accompanying file "license.txt" or copy at
			http://www.boost.org/LICENSE_1_0.txt)	
*/

#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include "settings.hpp"

class coordinate{
public:
    uint8_t x;
    uint8_t y;
    
    coordinate( uint8_t x = 0, uint8_t y = 0 ):
        x( x ),y( y )
    {
        if( x > DISPLAY_WIDTH ){hwlib::cout << "ERROR: coordinate x value is out of range. " << x-DISPLAY_WIDTH << " too big.\n";}
        if( y > DISPLAY_HEIGHT ){hwlib::cout << "ERROR: coordinate y value is out of range. " << y-DISPLAY_HEIGHT << " too big.\n";}
    }
   
    coordinate & operator=( const coordinate & rhs ){
        x=rhs.x;
        y=rhs.y;
        return *this;
    }
    
    void shiftLeft( const uint8_t & rhs ){
        x = x - rhs;
    }
    
    void shiftRight( const uint8_t & rhs ){
        x = x + rhs;
    }
    
    void shiftUp( const uint8_t & rhs ){
        y = y - rhs;
    }
    
    void shiftDown( const uint8_t & rhs ){
        y = y + rhs;
    }
    
    void invert(){
        uint8_t temp = x;
        x=y;
        y=temp;
    }
    
    coordinate & operator+=( const coordinate & rhs ){
        x = x + rhs.x;
        y = y + rhs.y;
        return *this;
    }
    
    coordinate & operator*=( const coordinate & rhs ){
        x = x * rhs.x;
        y = y * rhs.y;
        return *this;
    }
    
    coordinate & operator-=( const coordinate & rhs ){
        x = x - rhs.x;
        y = y - rhs.y;
        return *this;
    }
    
    //Dit is om positieve getallen te onderscheiden van negatieve... bijv: -5 +5  
    coordinate operator+() const{
        return coordinate( x,y );
    }
    
    coordinate operator+( const coordinate & rhs ) const{
        return( coordinate( x+rhs.x, y+rhs.y ));
        
    }
    
    coordinate operator*( const coordinate & rhs ) const{
        return(coordinate( x*rhs.x, y*rhs.y ));
        
    }
    
    coordinate operator-( const coordinate & rhs ) const{
        return(coordinate( x-rhs.x, y-rhs.y ));
        
    }
};

#endif //COORDINATE_HPP