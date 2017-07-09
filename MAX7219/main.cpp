#include "hwlib.hpp"
#include "MAXimus.hpp"
#include "static_address.hpp"
#include "coordinate.hpp"
#include "shapes.hpp"

//  for (int i = 1; i <= 8; i++){
//     s.superKitt(coordinate (1 , i), coordinate( 1, i), 1, 1);
//  }

int main(void){
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
	
    auto cs = hwlib::target::pin_out(hwlib::target::pins::d12);
    auto clk = hwlib::target::pin_out(hwlib::target::pins::d11);
    auto din = hwlib::target::pin_out(hwlib::target::pins::d13);
	
	hwlib::wait_ms(1000);
   MAXimus w( cs, clk, din);
    
   w.init();
	w.clean();
   
   shapes s(w);
   coordinate start  (1,1);
   coordinate end  (1,4);
//     for (int i = 1; i <= 8; i++){
//     s.superKitt(coordinate (1 , i), coordinate( 1, i), 1, 1);
// }

//   s.circle(coordinate(5,5), 3);
//   s.rectangle(coordinate(9,1), coordinate(16,8));
   s.triangle(coordinate(16,1), 8, 8);
   w.update();

  
   
   
}

