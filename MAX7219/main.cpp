#include "hwlib.hpp"
#include "MAXimus.hpp"
#include "static_address.hpp"
#include "coordinate.hpp"

int main(void){
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
	
    auto cs = hwlib::target::pin_out(hwlib::target::pins::d12);
    auto clk = hwlib::target::pin_out(hwlib::target::pins::d11);
    auto din = hwlib::target::pin_out(hwlib::target::pins::d13);
	
	hwlib::wait_ms(1000);
   MAXimus test( cs, clk, din);
    
   test.init();
	test.clean();
   
   coordinate arsalan (3,3);
   arsalan = (3,3);

   test.update();
   test.printFrame();
   
   
   test.update();
   
   
}

