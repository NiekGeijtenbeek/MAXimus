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

/**
 * @class coordinate
 * @author Niek Geijtenbeek
 * @date 10/07/2017
 * @file coordinate.hpp
 * @brief This ADT class is used to define a (x,y) pixel coordinate on the display
 * @warning The y-axis of the display is inverted, which means that a higher y coordinates point downwards!
 */
class coordinate{
public:
    uint8_t x;
    uint8_t y;
    
	/**
	 * @brief This is the constructor of the ADT. 
	 * @details The default values for the (x,y) are 0. 
	 * @param x : uint8_t
	 * @param y : uint8_t
	 * @warning If the giving x or y coordinate exceeds the resolution of the display, a error messeage will pop up. \n
	 * Beware that this can cause undefined behaviour if used incorrectly! 
	 */
    coordinate( uint8_t x = 0, uint8_t y = 0 ):
        x( x ),y( y )
    {
        if( x > DISPLAY_WIDTH ){hwlib::cout << "ERROR: coordinate x value is out of range. " << x-DISPLAY_WIDTH << " too big.\n";}
        if( y > DISPLAY_HEIGHT ){hwlib::cout << "ERROR: coordinate y value is out of range. " << y-DISPLAY_HEIGHT << " too big.\n";}
    }
   
   /**
    * @brief Operator that changes the orginial coordinate with the value of the rhs (right hand side) 
    * @param rhs : coordinate
	* @warning This operator will change the orginal value!
    */
    coordinate & operator=( const coordinate & rhs ){
        x=rhs.x;
        y=rhs.y;
        return *this;
    }
    
	/**
	 * @brief Function that shifts the x coordinate left by a specific number
	 * @param rhs : uint8_t
	 * @warning This operator will change the orginal value!
	 */
    void shiftLeft( const uint8_t & rhs ){
        x = x - rhs;
    }
    
	/**
	 * @brief Function that shifts the x coordinate right by a specific number
	 * @param rhs : uint8_t
	 * @warning This operator will change the orginal value!
	 */
    void shiftRight( const uint8_t & rhs ){
        x = x + rhs;
    }
    
	/**
	 * @brief Function that shifts the y coordinate down by a specific number
	 * @param rhs : uint8_t
	 * @warning This operator will change the orginal value! To move up, you need to decrease the y value because the display is inverted.
	 */
    void shiftUp( const uint8_t & rhs ){
        y = y - rhs;
    }
    
	/**
	 * @brief Function that shifts the y coordinate up by a specific number
	 * @param rhs : uint8_t
	 * @warning This operator will change the orginal value! To move up, you need to increase the y value because the display is inverted.
	 */
    void shiftDown( const uint8_t & rhs ){
        y = y + rhs;
    }
    
	/**
	 * @brief Function that swaps the x and y values. 
	 * @detals (x,y) -> (y,x)
	 */
    void invert(){
        uint8_t temp = x;
        x=y;
        y=temp;
    }
    
	/**
	 * @brief Operator that increments a coordinate by the coordinate of the rhs (right hand side)
	 * @details (x,y) += (1,2) = (x+1, y+2) 
	 * @param rhs : coordinate
	 */
    coordinate & operator+=( const coordinate & rhs ){
        x = x + rhs.x;
        y = y + rhs.y;
        return *this;
    }
    
	/**
	 * @brief Operator that increments (by multiplication)  a coordinate by the coordinate of the rhs (right hand side)
	 * @details (x,y) *= (1,2) = (x*1, y*2) 
	 * @param rhs : coordinate
	 */
    coordinate & operator*=( const coordinate & rhs ){
        x = x * rhs.x;
        y = y * rhs.y;
        return *this;
    }
    
	/**
	 * @brief Operator that decrements a coordinate by the coordinate of the rhs (right hand side)
	 * @details (x,y) -= (1,2) = (x-1, y-2) 
	 * @param rhs : coordinate
	 */
    coordinate & operator-=( const coordinate & rhs ){
        x = x - rhs.x;
        y = y - rhs.y;
        return *this;
    }

	/**
	 * @brief Operator that is used to differentiate positive with negative coordinates
	 * @details (5, 5) is the same as +(5, 5)
	 * @return original coordinate
	 */
    coordinate operator+() const{
        return coordinate( x,y );
    }
    
	/**
	 * @brief Operator that is used to sum two coordinates
	 * @param rhs : coordinate
	 * @return new coordinate
	 * @warning This operator will NOT change the original value. Use += instead if you want to change the value.
	 */
    coordinate operator+( const coordinate & rhs ) const{
        return( coordinate( x+rhs.x, y+rhs.y ));
        
    }
    
	/**
	 * @brief Operator that is used to multiply two coordinates
	 * @param rhs : coordinate
	 * @return new coordinate
	 * @warning This operator will NOT change the original value. Use *= instead if you want to change the value.
	 */
    coordinate operator*( const coordinate & rhs ) const{
        return(coordinate( x*rhs.x, y*rhs.y ));
        
    }
    
	/**
	 * @brief Operator that is used to substract two coordinates
	 * @param rhs : coordinate
	 * @return new coordinate
	 * @warning This operator will NOT change the original value. Use -= instead if you want to change the value.
	 */
    coordinate operator-( const coordinate & rhs ) const{
        return(coordinate( x-rhs.x, y-rhs.y ));
        
    }
};

#endif //COORDINATE_HPP