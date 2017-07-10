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
	File:		   examples.hpp
	
	Copyright Niek Geijtenbeek 2017.
	Distrubyted under the Boost Software License, Version 1.0.
	(See accompanying file "license.txt" or copy at
			http://www.boost.org/LICENSE_1_0.txt)	
*/

#ifndef EXAMPLES_HPP
#define EXAMPLES_HPP

#include "coordinate.hpp"
#include "display.hpp"
#include "math.hpp"
#include "settings.hpp"
#include "shapes.hpp"
#include "static_address.hpp"
#include "fonts.hpp"

/**
 * @class examples
 * @author Niek Geijtenbeek
 * @date 10/07/2017
 * @file examples.hpp
 * @brief class to showcase some examples of the functionality of the MAXimus library.
 
 */
class examples{
private:     
    display w;
    shapes s;
public:
    /**
     * @brief Constructor for the examples class
     * @param w : display
     */
    examples( display & w ):
        w( w ),
        s( w )
    {}
    
    /**
     * @brief Function that tests a userdefined coordinate being printed on the MAX7219s
     * @param pos : coordinate
     */
    void test1_1( const coordinate & pos ){
        w.draw(pos);
    }
    
    /**
     * @brief Function that tests a set of defined coordinates being printed on the MAX7219
     */
    void test1_2(){
        w.set( coordinate( 12,7 ) );
        w.set( coordinate( 20,1 ) );
        w.set( coordinate( 5,2 ) );
        w.set( coordinate( 5,0 ) );
        w.set( coordinate( 7,7 ) );
        w.set( coordinate( 17,4 ) );
        w.update();  
    }
    
    /**
     * @brief Function that tries to set a pixel on a coordinate that falls out of the specified window, resulting in an error being printed
     */
    void test1_3(){
        w.set( coordinate( 255,255 ) );
        w.update();  
    }   
    /**
     * @brief Function that showcases the "superkitt" shape using a predefined line, delay and amount of times
     */
    void test2_1(){
        s.superKitt( coordinate( 1,1 ), coordinate( 1,8 ), 1, 25 );
    }
    /**
     * @brief Function that showcases a modified version of the "superkitt" shape, repeating it all over the display.
     */
    void test2_2(){
        for(int c = 1; c < DISPLAY_HEIGHT; c++ ) {
           s.superKitt(1, c, 5, 1);
        }
    }
    /**
     * @brief Function that tests a line being printed on the display 
     * @param start : coordinate
     * @param end : coordinate
     */
    void test3_1( coordinate start, coordinate end ){
//        s.line(start, end);
//        w.update();
    }
    /**
     * @brief Function that tests a square being printed on the display
     * @param start : coordinate
     * @param end : coordinate
     */
    void test3_2( coordinate start, coordinate end ){
        s.rectangle( start,end );
    }
    /**
     * @brief Function that tests a circle being printed on the display
     * @param midpoint : coordinate
     * @param radius : coordinate
     * @warning Circle can look rather strange on a small display because the low resulotion
     */
    void test3_3( coordinate midpoint, int radius ){
        s.circle( midpoint, radius );
    }
    
    /**
     * @brief Function that test a triangle being printed on the display
     * @param start : coordinate
     * @param base : int
     * @param height : int
     * @warning The triangle function draws the triangle downwards
     */
    void test3_4( coordinate start, int base, int height ){
        s.triangle( start, base, height );
    } 
    /**
     * @brief Function that demonstrates drawing a matrix on the display (in this case a spaceinvader)
     * @param displayNr : int
     */
    void test4_1( int displayNr ){
        int spaceinvader_1[8] = {0x18,0x3c,0x7e,0xdb,0xff,0x24,0x5a,0xa5};
        w.drawMatrix( spaceinvader_1, 8, displayNr );
    }
    /**
     * @brief Function that showcases the drawMatrix function on mutliple displays, using the font declared in the "fonts.hpp"
     */
    void test4_2(){
        w.drawMatrix( N, 8, 4 );
        w.drawMatrix( I, 8, 3 );
        w.drawMatrix( E, 8, 2 );
        w.drawMatrix( K, 8, 1 );
    }
   /**
    * @brief Function that tests the animation function, using two frames of a spaceinvader (looped)
    * @param displayNr : int
    */
    void test5_1( int displayNr ){
        int animation[ANIMATION_LIMIT][8] = {
            {0x18,0x3c,0x7e,0xdb,0xff,0x24,0x5a,0xa5},
            {0x18,0x3c,0x7e,0xdb,0xff,0x24,0x42,0x81}
        };
        
        w.drawAnimation( animation, 2, 0, 500, displayNr, true );
        
    }
    /**
     * @brief Function that tests the animation function, using two frames of a spaceinvader (not looped)
     * @param displayNr : int
     */
    void test5_2( int displayNr ){
        int animation[ANIMATION_LIMIT][8] = {
            {0x18,0x3c,0x7e,0xdb,0xff,0x24,0x5a,0xa5},
            {0x18,0x3c,0x7e,0xdb,0xff,0x24,0x42,0x81}
        };
        
        w.drawAnimation( animation, 2, 10, 500, displayNr, false );
        
    }
    /**
     * @brief Function that tests mutliple animations being drawn on all "matrices"
     */
    void test5_3(  ){
        for( int i = 1; i<=4; ++i ){
            test5_2(i);
        }    
    } 
      /**
      * @brief Function that tests the drawText with a user defined 4 letter string
      * @param text : char array
      */
    void test6_1( char text[4] ){
        w.drawText( text );
    }
    /**
     * @brief Function that shows the entire defined font in "fonts.hpp" in the first display
     * @param displayNr : int
     */
    void test6_2( int displayNr ){
        int animation[ANIMATION_LIMIT][8] = {
            {0x66, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x3c, 0x00}, //uppercaseA
            {0x3e, 0x66, 0x66, 0x3e, 0x66, 0x66, 0x3e, 0x00}, //uppercaseB
            {0x3c, 0x66, 0x06, 0x06, 0x06, 0x66, 0x3c, 0x00}, //uppercaseC
            {0x3e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3e, 0x00}, //uppercaseD
            {0x7e, 0x06, 0x06, 0x3e, 0x06, 0x06, 0x7e, 0x00}, //uppercaseE
            {0x06, 0x06, 0x06, 0x3e, 0x06, 0x06, 0x7e, 0x00}, //uppercaseF
            {0x3c, 0x66, 0x76, 0x06, 0x06, 0x66, 0x3c, 0x00}, //uppercaseG
            {0x66, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x66, 0x00}, //uppercaseH
            {0x3c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00}, //uppercaseI
            {0x1c, 0x36, 0x36, 0x30, 0x30, 0x30 ,0x78, 0x00}, //uppercaseJ
            {0x66, 0x36, 0x1e, 0x0e, 0x1e, 0x36, 0x66, 0x00}, //uppercaseK
            {0x7e, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00}, //uppercaseL
            {0xc6, 0xc6, 0xc6, 0xd6, 0xfe, 0xee, 0xc6, 0x00}, //uppercaseM
            {0Xc6, 0Xc6, 0Xe6, 0Xf6, 0Xde, 0Xce, 0Xc6, 0X00}, //uppercaseN
            {0x3c, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x00}, //uppercaseO
            {0x06, 0X06, 0X3e, 0X66, 0X66, 0X66, 0X3e, 0X00}, //uppercaseP
            {0x60, 0x3c, 0x76, 0x66, 0x66, 0x66, 0x3c, 0x00}, //uppercaseQ
            {0x66, 0x36, 0x1e, 0x3e, 0x66, 0x66, 0x3e, 0x00}, //uppercaseR
            {0x3c, 0x66, 0x60, 0x3c, 0x06, 0x66, 0x3c, 0x00}, //uppercaseS
            {0x18, 0x18, 0x18, 0x18, 0x18, 0x5a, 0x7e, 0x00}, //uppercaseT
            {0x7c, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00}, //uppercaseU
            {0x18, 0x3c, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00}, //uppercaseV
            {0xc6, 0xee, 0xfe, 0xd6, 0xc6, 0xc6, 0xc6, 0x00}, //uppercaseW
            {0xc6, 0xc6, 0x6c, 0x38, 0x6c, 0xc6, 0xc6, 0x00}, //uppercaseX
            {0x18, 0x18, 0x18, 0x3c, 0x66, 0x66, 0x66, 0x00}, //uppercaseY
            {0X7e, 0x06, 0x0c, 0x18, 0x30, 0x60, 0x7e, 0x00}, //uppercaseZ
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 ,0x00}
        };
        
        w.drawAnimation( animation, 27, 0, 500, displayNr, true );
        
    }
       
};

#endif //EXAMPLES_HPP