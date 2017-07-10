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
	File:		   display.hpp
	
	Copyright Niek Geijtenbeek 2017.
	Distrubyted under the Boost Software License, Version 1.0.
	(See accompanying file "license.txt" or copy at
			http://www.boost.org/LICENSE_1_0.txt)	
*/

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "hwlib.hpp"
#include "static_address.hpp"
#include "coordinate.hpp"
#include "settings.hpp"
#include "fonts.hpp"

/**
 * @class display
 * @author Niek Geijtenbeek
 * @date 10/07/2017
 * @file display.hpp
 * @bief A simple display driver that uses a axessystem with an inverted y-axis 
 * @details This class controls all the operations used to write and delete items on the led display. \n
 * A custom 2d matrix array is used to store temporary data which will be written after each update. \n
 * @code{.py}
  class Python:
     pass
  @endcode
 * @warning Only the y-axis on the DISPLAY is inverted. To draw pixels etc you can use a normal (x,y) axis system.
 */
class display{
private:
    hwlib::target::pin_out cs;
    hwlib::target::pin_out clk;
    hwlib::target::pin_out din;
public:
	/**
	 * @brief This is the constructor display driver. 
	 * @param cs : hwlib::target::pin_out : used to push content from the registers to the output
	 * @param clk : hwlib::target::pin_out : used to send a clockpulse 
	 * @param din : hwlib::target::pin_out : used to push content to the registers (1 bit). 
	 */
	display( hwlib::target::pin_out cs, hwlib::target::pin_out clk, hwlib::target::pin_out din);
   
	/**
	 * @brief This 2D matrix array is used as temprary buffer to store data of the location of pixels that needs to be turned on or off. 
	 * @details Lets asume you have 4 8x8 display in a row, you want to turn on the 12th pixel of row 5, than the second byte need to look like this 00001000 (0x08). \n
	 * The entire second colom of the 5th row of the matrix, will look like this: 0x00 0x08 0x00 0x00. \n
	 * The second colom of the array has n (total width/height of one 8x8) rows where each byte represends one 8x8 display row. 
	 */
	int matrix[DISPLAY_HEIGHT][DISPLAY_WIDTH/DISPLAY_HEIGHT] = {{0x00}};
	
	/**
	 * @brief Function that initializes some hardware settings of the diplay. 
	 */
	void init(); 
	
	/**
	 * @brief Function that needs to be used to set the intensity level
	 * @param lvl : uint8_t 
	 */
    void setBrightness( uint8_t lvl );
	
	/**
	 * @brief Function that send a clockpulse by toggling the clk pin
	 */
	void clockPulse();
	
	/**
	 * @brief Function that can be used to select an adress
	 * @param adress : uint8_t
	 */
	void selectAdress( uint8_t adress );
	
	/**
	 * @brief Function that can be used to send data to an adress
	 * @param data : uint8_t
	 */
	void sendData( uint8_t data );
	
	/**
	 * @brief Function that sends data to a specific adress once. 
	 * @param adress : uint8_t
	 * @param data : uint8_t
	 */
	void sendAdressData( uint8_t adress, uint8_t data );
	
	/**
	 * @brief Function that sends data to specific adress until the cs pin is set low. 
	 * @param adress : uint8_t
	 * @param data : uint8_t
	 */
    void setAdressData( uint8_t adress, uint8_t data );
	
	/**
	 * @brief Function that will convert a (x,y) pixel coordinate to byte values which will be stored in the 2d matrix buffer.
	 * @param pos : coordinate
	 * @warning This function WILL NOT draw a pixel on the display. It only changes the buffer. 
	 */
	void set( const coordinate & pos );
	
	/**
	 * @brief Function that will convert a (x,y) pixel coordinate to byte values which will be stored in the 2d matrix buffer.
	 * @details After the byte of the 2d matrix array has been modified it will update the entire buffer of the display and show a pixel on the display.
	 * @param pos : coordinate
	 * @warning This function WILL draw a pixel on the display. It changes the buffer. 
	 */
    void draw( const coordinate & pos );
	
	/**
	 * @brief Function that updates the content of the buffer on the display with the content of the 2d matrix buffer.
	 */
	void update();
	
	/**
	 * @brief Function that can be used for debuggin purposes. 
	 * @details This function will print out the content of the 2d matrix array on the console. 
	 */
    void printFrame();
	
	/**
	 * @brief Function that clears the data of the display buffer.
	 * @details This is advieved by sending empty data (0x00) to all the rows of the display buffer
	 */
	void clean();
	
	/**
	 * @brief Function that clear the data of the 2d matrix buffer.
	 * @details This is advieved by sending empty data (0x00) to all the rows of the 2d matrix buffer
	 */
    void resetMatrix();
	
	/**
	 * @brief Function that translates a userdefined 8x8 matrix (array of 8 elements) to byte data for the 2d matrix buffer
	 * @details A parameter size needs to be given, because c++14 does not allow the retrival of the size of an array inside a function.
	 * @param field : int arrray 
	 * @param size : int : size of the array 
	 * @param displayNr : int : The number of the display that the user wants to draw the 8x8 object. 
	 */
    void drawMatrix( const int field[], int size, int displayNr );
	
	/**
	 * @brief Function that translates a set of userdefined 8x8 matrix frames (array of array of 8 elements) to byte data for the 2d matrix buffer.
	 * @details This function can animate up to a certain animation limit (which can be changed in settings.hpp). \n
	 * The amount of frames need to be specified, because c++14 does not allow the retrival of the size of an 2d array inside a function.   
	 * @param field : 2d int array : used to store the frames
	 * @param frames : int : The amount of frames used. 
	 * @param times : int : The amount of time the animation has to loop. If repeat is true, set this to 0.
	 * @param delay : int: The interval between frames
	 * @param displayNr int : The number of the display that the user wants to draw the 8x8 object. 
	 * @param repeat : bool : Mode to repeat infinitly or to repeat a certain n amount of times
	 */
    void drawAnimation( const int field[ANIMATION_LIMIT][8], int frames, int times, int delay, int displayNr, bool repeat );
    /**
     * @brief Function that translates a 4 character string to text on the display.
     * @param text : char array
     */
	void drawText( char text[5] );
}; 

#endif //MAXIMUS_HPP 