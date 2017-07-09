#ifndef MAXIMUS_HPP
#define MAXIMUS_HPP

#include "hwlib.hpp"
#include "static_address.hpp"
#include "coordinate.hpp"
#include "settings.hpp"

class MAXimus{
private:
    hwlib::target::pin_out cs;
    hwlib::target::pin_out clk;
    hwlib::target::pin_out din;
public:
    MAXimus( hwlib::target::pin_out cs, hwlib::target::pin_out clk, hwlib::target::pin_out din);
   
	int matrix[DISPLAY_HEIGHT][DISPLAY_WIDTH/DISPLAY_HEIGHT] = {{0x00}};
	void init(); 
	void clockPulse();
	void selectAdress( uint8_t adress );
	void sendData( uint8_t data );
	void sendAdressData( uint8_t adress, uint8_t data );
    void setAdressData( uint8_t adress, uint8_t data );
	void set(const coordinate & pos);
	void update();
   void printFrame();
	void clean();
   void resetMatrix();       
}; 

#endif //MAXIMUS_HPP 