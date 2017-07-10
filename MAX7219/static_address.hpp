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
	File:		   static_adress.hpp
	
	Copyright Niek Geijtenbeek 2017.
	Distrubyted under the Boost Software License, Version 1.0.
	(See accompanying file "license.txt" or copy at
			http://www.boost.org/LICENSE_1_0.txt)	
*/

#ifndef STATIC_ADDRESS_HPP
#define STATIC_ADDRESS_HPP

/**
 * @page Static adresses
 * @brief Headerfile with some const variables that are used by the display.hpp.
 */ 
 
/**
 * @brief MACRO that defines the adress of the display_test
 */ 
const uint8_t DISPLAY_TEST  = 0x0F;

/**
 * @brief MACRO that defines the data of the display_test
 */ 
const uint8_t DISPLAY_TEST_MODE  = 0x01;

/**
 * @brief MACRO that defines the adress of the shutdown_mode
 */ 
const uint8_t SHUTDOWN = 0x0C;

/**
 * @brief MACRO that defines the data of the shutdown_mode
 */ 
const uint8_t SHUTDOWN_MODE = 0x01;

/**
 * @brief MACRO that defines the adress of the scan_limit
 */ 
const uint8_t SCAN_LIMIT = 0x0B;

/**
 * @brief MACRO that defines the data of the scan_limit
 */ 
const uint8_t SCAN_LIMIT_MODE = 0x07;

/**
 * @brief MACRO that defines the adress of the decode mode
 */ 
const uint8_t DECODE = 0x09;

/**
 * @brief MACRO that defines the data of the decode mode
 */ 
const uint8_t DECODE_MODE = 0x00;

/**
 * @brief MACRO that defines the adress of the intensity_lvl
 */ 
const uint8_t INTENSITY = 0x0A;

/**
 * @brief MACRO'S that defines the data of the intensity_lvl
 * @details \n
 * \li const uint8_t INTENSITY_LVL_1 = 0x00;
 * \li const uint8_t INTENSITY_LVL_2 = 0x01;
 * \li const uint8_t INTENSITY_LVL_3 = 0x02;
 * \li const uint8_t INTENSITY_LVL_4 = 0x03;
 * \li const uint8_t INTENSITY_LVL_5 = 0x04;
 * \li const uint8_t INTENSITY_LVL_6 = 0x05;
 * \li const uint8_t INTENSITY_LVL_7 = 0x06;
 * \li const uint8_t INTENSITY_LVL_8 = 0x07;
 * \li const uint8_t INTENSITY_LVL_9 = 0x08;
 * \li const uint8_t INTENSITY_LVL_10 = 0x09;
 * \li const uint8_t INTENSITY_LVL_11 = 0x0A;
 * \li const uint8_t INTENSITY_LVL_12 = 0x0B;
 * \li const uint8_t INTENSITY_LVL_13 = 0x0C;
 * \li const uint8_t INTENSITY_LVL_14 = 0x0D;
 * \li const uint8_t INTENSITY_LVL_15 = 0x0E;
 * \li const uint8_t INTENSITY_LVL_16 = 0x0F;
 */ 
const uint8_t INTENSITY_LVL_1 = 0x00;
const uint8_t INTENSITY_LVL_2 = 0x01;
const uint8_t INTENSITY_LVL_3 = 0x02;
const uint8_t INTENSITY_LVL_4 = 0x03;

const uint8_t INTENSITY_LVL_5 = 0x04;
const uint8_t INTENSITY_LVL_6 = 0x05;
const uint8_t INTENSITY_LVL_7 = 0x06;
const uint8_t INTENSITY_LVL_8 = 0x07;

const uint8_t INTENSITY_LVL_9 = 0x08;
const uint8_t INTENSITY_LVL_10 = 0x09;
const uint8_t INTENSITY_LVL_11 = 0x0A;
const uint8_t INTENSITY_LVL_12 = 0x0B;

const uint8_t INTENSITY_LVL_13 = 0x0C;
const uint8_t INTENSITY_LVL_14 = 0x0D;
const uint8_t INTENSITY_LVL_15 = 0x0E;
const uint8_t INTENSITY_LVL_16 = 0x0F;

/**
 * @brief MACRO that defines a NO operation command or data to the register
 */ 
const uint8_t NO_OP = 0x00;

#endif //STATIC_ADDRESS_HPP