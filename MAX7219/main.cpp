#include "hwlib.hpp"
#include "MAXimus.hpp"


int main(void){
      // kill the watchdog
      WDT->WDT_MR = WDT_MR_WDDIS;
	
      auto cs = hwlib::target::pin_out(hwlib::target::pins::d12);
      auto clk = hwlib::target::pin_out(hwlib::target::pins::d11);
      auto din = hwlib::target::pin_out(hwlib::target::pins::d13);
	
      hwlib::wait_ms(1000);
      display w( cs, clk, din);
      shapes s(w);
      examples e(w);
    
      w.init();
      w.setBrightness(70);
      w.clean();
      
//      e.test1_1(coordinate(5,5)); // single pixel
//      e.test1_2(); // multple pixels
//      e.test1_3(); //error message
//      e.test2_1(); //super kitt
//      e.test2_2(); // superkitt v2.0

//      s.line(coordinate(1,1), coordinate(10,5)); //line
//      w.update();

//      e.test3_2(coordinate(2,2) , coordinate(10,5)); //rectangle
//      e.test3_3(coordinate(5,5), 3); //circle
//      e.test3_4(coordinate(1,1), 30, 5); //triangle
//      e.test4_1(2); //show spaceinvader
//      e.test4_2(); //print text
//      e.test5_1(1); //show looped invader
//      e.test5_3(); //show appearing invaders 10 times each
//      char test[5] = "TEST";
//      e.test6_1(test); // show 'test' on display
//      e.test6_2(1);
      
      
      
   
}

