#include "MAXimus.hpp"

MAXimus::MAXimus( hwlib::target::pin_out cs, hwlib::target::pin_out clk, hwlib::target::pin_out din):
   cs( cs ),
   clk( clk ),
   din( din )
{}

void MAXimus::init(){
    sendAdressData( DISPLAY_TEST, NO_OP );
    sendAdressData( SHUTDOWN, SHUTDOWN_MODE );
    sendAdressData( SCAN_LIMIT, SCAN_LIMIT_MODE );
    sendAdressData( DECODE, DECODE_MODE );
    sendAdressData( INTENSITY, INTENSITY_LVL); 
}

void MAXimus::clockPulse(){
    hwlib::wait_us( 1 );
    clk.set(0);
    hwlib::wait_us( 3 );
    clk.set(1);
    hwlib::wait_us( 2 );
}

void MAXimus::selectAdress( uint8_t adress ){
	cs.set(0); 
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

void MAXimus::sendData( uint8_t data ){
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

void MAXimus::sendAdressData( uint8_t adress, uint8_t data){ 
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

void MAXimus::setAdressData( uint8_t adress, uint8_t data){ 
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



void MAXimus::set(const coordinate & pos){
	uint8_t input = pos.x;
	int counter = 0;
	while( input > 8 ){
        if( input % 8 >= 0 ){++counter; input-=8;} 
    }
	uint8_t data = matrix[pos.y-1][counter];
	matrix[pos.y-1][counter] = ( data | (0x80 >> ( input-1 ) ) );
}

void MAXimus::update(){
    for ( int y =0; y<8; ++y ){
       cs.set(0);
	    for ( int x = 0; x<4; ++x ){
		    setAdressData( y+1, matrix[y][x] );
	    }
       cs.set( 1 );
    }
}

void MAXimus::printFrame(){
     for ( int y =0; y<8; ++y ){
	    for ( int x = 0; x<4; ++x ){
		    hwlib::cout << matrix[y][x] << "\t";
	    }
        hwlib::cout << "\n"; 
    }
}



void MAXimus::clean(){
    for ( int i = 0; i < 4; i++ ) {
        sendAdressData( 0x01, 0x00 );
        sendAdressData( 0x02, 0x00 );
        sendAdressData( 0x03, 0x00 );
        sendAdressData( 0x04, 0x00 );
        sendAdressData( 0x05, 0x00 );
        sendAdressData( 0x06, 0x00 );
        sendAdressData( 0x07, 0x00 );
        sendAdressData( 0x08, 0x00 );
    }
}

void MAXimus::resetMatrix(){
   for ( int i = 0; i < DISPLAY_HEIGHT; i++) {
      for (int j = 0; j < (DISPLAY_WIDTH/DISPLAY_HEIGHT); j++) {
         matrix[i][j] = 0x00;
      }
   }
}