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

class examples{
private:     
    display w;
    shapes s;
public:
    examples( display & w ):
        w( w ),
        s( w )
    {}
    
    void test1_1( const coordinate & pos ){
        w.draw(pos);
    }
    
    void test1_2(){
        w.set( coordinate( 12,7 ) );
        w.set( coordinate( 20,1 ) );
        w.set( coordinate( 5,2 ) );
        w.set( coordinate( 5,0 ) );
        w.set( coordinate( 7,7 ) );
        w.set( coordinate( 17,4 ) );
        w.update();  
    }
    
    void test1_3(){
        w.set( coordinate( 255,255 ) );
        w.update();  
    }   
    
    void test2_1(){
        s.superKitt( coordinate( 1,1 ), coordinate( 1,8 ), 1, 25 );
    }
    
    void test2_2(){
        //TODO
    }
    
    void test3_1( coordinate start, coordinate end ){
//        s.line(start, end);
//        w.update();
    }
    
    void test3_2( coordinate start, coordinate end ){
        s.rectangle( start,end );
    }
    
    void test3_3( coordinate midpoint, int radius ){
        s.circle( midpoint, radius );
    }
    
    void test3_4( coordinate start, int base, int height ){
        s.triangle( start, base, height );
    } 
    
    void test4_1( int displayNr ){
        int spaceinvader_1[8] = {0x18,0x3c,0x7e,0xdb,0xff,0x24,0x5a,0xa5};
        w.drawMatrix( spaceinvader_1, 8, displayNr );
    }
    
    void test4_2(){
        w.drawMatrix( N, 8, 4 );
        w.drawMatrix( I, 8, 3 );
        w.drawMatrix( E, 8, 2 );
        w.drawMatrix( K, 8, 1 );
    }
        
    void test5_1( int displayNr ){
        int animation[ANIMATION_LIMIT][8] = {
            {0x18,0x3c,0x7e,0xdb,0xff,0x24,0x5a,0xa5},
            {0x18,0x3c,0x7e,0xdb,0xff,0x24,0x42,0x81}
        };
        
        w.drawAnimation( animation, 2, 0, 500, displayNr, true );
        
    }
    
    void test5_2( int displayNr ){
        int animation[ANIMATION_LIMIT][8] = {
            {0x18,0x3c,0x7e,0xdb,0xff,0x24,0x5a,0xa5},
            {0x18,0x3c,0x7e,0xdb,0xff,0x24,0x42,0x81}
        };
        
        w.drawAnimation( animation, 2, 10, 500, displayNr, false );
        
    }
    
    void test5_3(  ){
        for( int i = 1; i<=4; ++i ){
            test5_2(i);
        }    
    } 
        
    void test6_1( char text[4] ){
        w.drawText( text );
    }
    
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