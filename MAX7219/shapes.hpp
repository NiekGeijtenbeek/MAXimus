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
	File:		   shapes.hpp
	
	Copyright Niek Geijtenbeek 2017.
	Distrubyted under the Boost Software License, Version 1.0.
	(See accompanying file "license.txt" or copy at
			http://www.boost.org/LICENSE_1_0.txt)	
*/

#ifndef SHAPES_HPP
#define SHAPES_HPP

#include "coordinate.hpp"
#include "hwlib.hpp"
#include "display.hpp"
#include "math.hpp"

/**
 * @class shapes
 * @author Niek Geijtenbeek
 * @date 10/07/2017
 * @file shapes.hpp
 * @brief class used to draw shapes (circles, lines, squares ,triangles) on the display.
 */
class shapes {
private:
   display & w;
public:
	/**
	 * @brief Constructor of the shapes class.
	 * @param w : display
	 */
   shapes( display & w ):
      w( w )
   {}
	
	/**
	 * @brief EXTREMELY fast line algorithm made by a Professor at MIT.
	 * @details This function uses a heavily modified version of the xiaolin wu anti-aliasing algorithm. \n
	 * This modified version removes the contrast correction that comes standard to the original version and enhances some other features like less redundant code. \n
	 * This algortihm also is very optimized for smaller microcontrollers or hardware in general by using bitshifting instead of diferncias in more loops. 
	 * @param start : coordinate
	 * @param end : coordinate
	 */
	void line( coordinate start, coordinate end ){
	   int x = start.x;
	   int y = start.y;
	   int x2 = end.x;
	   int y2 = end.y;
	   
		  bool yLonger=false;
			int shortLen=y2-y;
			int longLen=x2-x;
			if ( abs( shortLen )>abs( longLen )) {
				int swap=shortLen;
				shortLen=longLen;
				longLen=swap;				
				yLonger=true;
			}
			int decInc;
			if ( longLen==0 ) decInc=0;
			else decInc = ( shortLen << 8 ) / longLen;

			if ( yLonger ) {
				if ( longLen>0 ) {
					longLen+=y;
					for ( int j=0x80+(x<<8);y<=longLen;++y ) {
						w.set( coordinate( j >> 8,y ));	
						j+=decInc;
					}
					return;
				}
				longLen+=y;
				for ( int j=0x80+(x<<8);y>=longLen;--y ) {
					w.set( coordinate( j >> 8,y ));	
					j-=decInc;
				}
				return;	
			}

			if ( longLen>0 ) {
				longLen+=x;
				for ( int j=0x80+( y<<8 );x<=longLen;++x ) {
					w.set( coordinate( x,j >> 8 ));
					j+=decInc;
				}
				return;
			}
			longLen+=x;
			for ( int j=0x80+(y<<8);x>=longLen;--x ) {
				w.set(coordinate( x,j >> 8 ));
				j-=decInc;
			}
	}
	
	/**
	 * @brief Special kitt function that moves a vertical line from one side to the other for a certain n amount of times.
	 * @param start : coordinate
	 * @param end : coordinate
	 * @param delay : uint8_t
	 * @param times : uint8_t
	 */
	void superKitt( coordinate start, coordinate end, uint8_t delay, uint8_t times ){
	   
	   coordinate tempStart = start;
	   coordinate tempEnd = end;
	   
	   for( int count = 0; count < times; count++ ) {
	   for ( int i = 0; i < ( DISPLAY_WIDTH-1 ); i++ ){
		  hwlib::wait_ms( delay );
		  w.resetMatrix();
		  hwlib::wait_ms( delay );
		  line( start, end );
		  start.shiftRight( 1 );
		  end.shiftRight( 1 );
		  w.update();
	   }
	   for ( int i = ( DISPLAY_WIDTH-1 ); i > 0; i-- ){
		  hwlib::wait_ms( delay );
		  w.resetMatrix();
		  hwlib::wait_ms( delay );
		  line( start, end );
		  start.shiftLeft( 1 );
		  end.shiftLeft( 1 );
		  w.update();
	   }
	 }
	 
	   w.resetMatrix();
	   line( tempStart, tempEnd );
	   w.update();
	   hwlib::wait_ms( delay );
	   w.resetMatrix();
	   w.update();
	}   

	/**
	 * @brief Function that draw a rectangle by making 4 lines.
	 * @param start : coordinate
	 * @param end : coordinate
	 */
	void rectangle( coordinate start, coordinate end ){
	   coordinate pointOne = start;
	   coordinate pointTwo = coordinate( end.x, start.y );
	   coordinate pointThree = end;
	   coordinate pointFour = coordinate( start.x, end.y );
	   
	   line( pointOne, pointTwo );
	   line( pointTwo, pointThree );
	   line( pointThree, pointFour );
	   line( pointFour, pointOne );
	   
	   w.update();
	}

	/**
	 * @brief Pitteway circle algorithm
	 * @details This funcition can be used to draw a circle on a specific coordinate of a display
	 * @param midpoint : coordinate
	 * @param radius : coordinate
	 * @warning circles can look odd with display with a low resolution.
	 */
	void circle( coordinate midpoint, int radius ){
			int x0 = midpoint.x;
			int y0 = midpoint.y;
			
			int x = radius;
			int y = 0;
			int error = 0;

			while( x >= y ){
				w.set(coordinate( x0 + x, y0 + y ));
				w.set(coordinate( x0 + y, y0 + x ));
				w.set(coordinate( x0 - y, y0 + x ));
				w.set(coordinate( x0 - x, y0 + y ));
				
				w.set(coordinate( x0 - x, y0 - y ));
				w.set(coordinate( x0 - y, y0 - x ));
				w.set(coordinate( x0 + y, y0 - x ));
				w.set(coordinate( x0 + x, y0 - y ));
				
				++y;
				if ( error <= 0 ){
					error+= 2*y + 1;
				}
				if ( error > 0 ){
					--x;
					error -= 2*x + 1;
				}
			}
		  w.update();
		}

	/**
	 * @brief Function that draws a triangle by making 3 lines
	 * @param start : coordinate : start point of the triangle
	 * @param base : int : length of the base of the triangle 
	 * @param height : int : length of the height of the triangle
	 * @warning Triangle will always be facing downwards, because the display has an inverted y axis
	 */
	void triangle( coordinate start, int base, int height ){
   coordinate pointOne = start;
   coordinate pointTwo = coordinate (( start.x + base-1 ), start.y );
   coordinate pointThree = coordinate (( start.x + (( base-1 ) /2 )), ( start.y+ height-1 ));
   
   line( pointOne, pointTwo );
   line( pointOne, pointThree );
   line( pointTwo, pointThree );
   w.update();
}
};
#endif //SHAPES_HPP 