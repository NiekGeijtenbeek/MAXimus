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
	File:		   display.cpp
	
	Copyright Niek Geijtenbeek 2017.
	Distrubyted under the Boost Software License, Version 1.0.
	(See accompanying file "license.txt" or copy at
			http://www.boost.org/LICENSE_1_0.txt)	
*/

#include "display.hpp"

display::display( hwlib::target::pin_out cs, hwlib::target::pin_out clk, hwlib::target::pin_out din):
   cs( cs ),
   clk( clk ),
   din( din )
{}

void display::init(){
    sendAdressData( DISPLAY_TEST, NO_OP );
    sendAdressData( SHUTDOWN, SHUTDOWN_MODE );
    sendAdressData( SCAN_LIMIT, SCAN_LIMIT_MODE );
    sendAdressData( DECODE, DECODE_MODE );
}

void display::setBrightness( uint8_t lvl ){
    sendAdressData( INTENSITY, lvl ); 
    switch( lvl ){
        case 5:
            sendAdressData( INTENSITY, INTENSITY_LVL_1 ); 
            break;
        case 10:
            sendAdressData( INTENSITY, INTENSITY_LVL_2 ); 
            break;
        case 15:
            sendAdressData( INTENSITY, INTENSITY_LVL_3 ); 
            break;
        case 20:
            sendAdressData( INTENSITY, INTENSITY_LVL_4 ); 
            break;
        case 25:
            sendAdressData( INTENSITY, INTENSITY_LVL_5 ); 
            break;
        case 30:
            sendAdressData( INTENSITY, INTENSITY_LVL_6 ); 
            break;
        case 35:
            sendAdressData( INTENSITY, INTENSITY_LVL_7 ); 
            break;
        case 40:
            sendAdressData( INTENSITY, INTENSITY_LVL_8 ); 
            break;
        case 45:
            sendAdressData( INTENSITY, INTENSITY_LVL_9 ); 
            break;
        case 50:
            sendAdressData( INTENSITY, INTENSITY_LVL_10 ); 
            break;
        case 55:
            sendAdressData( INTENSITY, INTENSITY_LVL_11 ); 
            break;
        case 60:
            sendAdressData( INTENSITY, INTENSITY_LVL_12 ); 
            break;
        case 70:
            sendAdressData( INTENSITY, INTENSITY_LVL_13 ); 
            break;
        case 80:
            sendAdressData( INTENSITY, INTENSITY_LVL_14 ); 
            break;
        case 90:
            sendAdressData( INTENSITY, INTENSITY_LVL_15 ); 
            break;
        case 100:
            sendAdressData( INTENSITY, INTENSITY_LVL_16 ); 
            break;
        default:
            sendAdressData( INTENSITY, INTENSITY_LVL_16 ); 
            break;   
    }
}

void display::clockPulse(){
    hwlib::wait_us( 1 );
    clk.set( 0 );
    hwlib::wait_us( 3 );
    clk.set( 1 );
    hwlib::wait_us( 2 );
}

void display::selectAdress( uint8_t adress ){
	cs.set( 0 ); 
	for( int counter = 0; counter < 8 ; ++counter ){
		if( adress & 0x80 ){
			din.set( 1 );
			clockPulse();
		}else{
			din.set( 0 );
			clockPulse();
		}
		adress<<=1;
	}
	cs.set( 1 );
}

void display::sendData( uint8_t data ){
	cs.set( 0 );
	for( int counter = 0; counter < 8 ; ++counter ){
		if( data & 0x80 ){
			din.set( 1 );
			clockPulse();
		}else{
			din.set( 0 );
			clockPulse();
		}
		data<<=1;
	}
	cs.set( 1 );
}

void display::sendAdressData( uint8_t adress, uint8_t data ){ 
	cs.set( 0 );
    for( int counter = 0; counter < 8 ; ++counter ){
		if( adress & 0x80 ){
			din.set( 1 );
			clockPulse();
		}else{
			din.set( 0 );
			clockPulse();
		}
		adress<<=1;
	}

	for( int counter = 0; counter < 8 ; ++counter ){
		if( data & 0x80 ){
			din.set( 1 );
			clockPulse();
		}else{
			din.set( 0 );
			clockPulse();
		}
		data<<=1;
	}
    cs.set( 1 );
}

void display::setAdressData( uint8_t adress, uint8_t data ){ 
	for( int counter = 0; counter < 8 ; ++counter ){
		if( adress & 0x80 ){
			din.set( 1 );
			clockPulse();
		}else{
			din.set( 0 );
			clockPulse();
		}
		adress<<=1;
	}

	for( int counter = 0; counter < 8 ; ++counter ){
		if( data & 0x80 ){
			din.set( 1 );
			clockPulse();
		}else{
			din.set( 0 );
			clockPulse();
		}
		data<<=1;
	}
}

void display::set( const coordinate & pos ){
	uint8_t input = pos.x;
	int counter = 0;
	while( input > 8 ){
        if( input % 8 >= 0 ){++counter; input-=8;} 
    }
	uint8_t data = matrix[pos.y-1][counter];
	matrix[pos.y-1][counter] = ( data | (0x80 >> ( input-1 ) ));
}

void display::draw( const coordinate & pos ){
    set( pos );
    update();
}

void display::update(){
    for ( int y =0; y<8; ++y ){
       cs.set( 0 );
	    for ( int x = 0; x<4; ++x ){
		    setAdressData( y+1, matrix[y][x] );
	    }
       cs.set( 1 );
    }
}

void display::printFrame(){
     for ( int y =0; y<8; ++y ){
	    for ( int x = 0; x<4; ++x ){
		    hwlib::cout << matrix[y][x] << "\t";
	    }
        hwlib::cout << "\n"; 
    }
    hwlib::cout << "\n";
}

void display::clean(){
    for ( int x = 0; x < DISPLAY_WIDTH/DISPLAY_HEIGHT; x++ ) {
        for ( int y=1; y<=8; ++y ){
            sendAdressData( y, 0x00 );   
        } 
    }
}

void display::resetMatrix(){
   for ( int i = 0; i < DISPLAY_HEIGHT; i++ ) {
      for (int j = 0; j < ( DISPLAY_WIDTH/DISPLAY_HEIGHT ); j++ ) {
         matrix[i][j] = 0x00;
      }
   }
}

void display::drawMatrix( const int field[], int size, int displayNr ){
      for ( int i = 0; i < size; ++i ){
         matrix[i][displayNr-1] = field[i];
      }
      update();
}

void clearArray( int array[8] ){
   for( int i=0; i<8; ++i ){
         array[i] = 0;
   }
}

void display::drawAnimation( const int field[ANIMATION_LIMIT][8], int frames, int times, int delay, int displayNr, bool repeat ){
      int temp[8] = {0};
      if( repeat ){
            for(;;){
               for( int i=0; i<frames; ++i ){
                  clearArray( temp );
                  for( int j=0; j<8; ++j ){
                     temp[j] = field[i][j];
                  }
                  drawMatrix( temp, 8, displayNr );
                  hwlib::wait_ms( delay );
               }
               hwlib::wait_ms( delay );
            }
      }else{
         for( int t=0; t<times; ++t ){
               for( int i=0; i<frames; ++i ){
                  clearArray( temp );
                  for( int j=0; j<8; ++j ){
                     temp[j] = field[i][j];
                  }
                  drawMatrix( temp, 8, displayNr );
                  hwlib::wait_ms( delay );
               }
               hwlib::wait_ms( delay );
            }
      }
}

void display::drawText(char text[5]){
    int x = 0;
    for ( int i=4; i>0; --i ){
        switch( text[x] ){
            case 'A':
                drawMatrix( A, 8, i );
                break;
            case 'B':
                drawMatrix( B, 8, i );
                break;
            case 'C':
                drawMatrix( C, 8, i );
                break;
            case 'D':
                drawMatrix( D, 8, i );
                break;
            case 'E':
                drawMatrix( E, 8, i );
                break;
            case 'F':
                drawMatrix( F, 8, i );
                break;
            case 'G':
                drawMatrix( G, 8, i );
                break;
            case 'H':
                drawMatrix( H, 8, i );
                break;
            case 'I':
                drawMatrix( I, 8, i );
                break;
            case 'J':
                drawMatrix( J, 8, i );
                break;
            case 'K':
                drawMatrix( K, 8, i );
                break;
            case 'L':
                drawMatrix( L, 8, i );
                break;
            case 'M':
                drawMatrix( M, 8, i );
                break;
            case 'N':
                drawMatrix( N, 8, i );
                break;
            case 'O':
                drawMatrix( O, 8, i );
                break;
            case 'P':
                drawMatrix( P, 8, i );
                break;
            case 'Q':
                drawMatrix( Q, 8, i );
                break;
            case 'R':
                drawMatrix( R, 8, i );
                break;
            case 'S':
                drawMatrix( S, 8, i );
                break;
            case 'T':
                drawMatrix( T, 8, i );
                break;
            case 'U':
                drawMatrix( U, 8, i );
                break;
            case 'V':
                drawMatrix( V, 8, i );
                break;
            case 'W':
                drawMatrix( W, 8, i );
                break;
            case 'X':
                drawMatrix( X, 8, i );
                break;
            case 'Y':
                drawMatrix( Y, 8, i );
                break;
            case 'Z':
                drawMatrix( Z, 8, i );
                break;
            case ' ':
                drawMatrix( space, 8, i );
                break;
            default:
                drawMatrix( space, 8, i );
                break;
        }
        ++x;
    }
}