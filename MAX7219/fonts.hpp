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
	File:		   fonts.hpp
	
	Copyright Niek Geijtenbeek 2017.
	Distrubyted under the Boost Software License, Version 1.0.
	(See accompanying file "license.txt" or copy at
			http://www.boost.org/LICENSE_1_0.txt)	
*/

#ifndef FONTS_HPP
#define FONTS_HPP

const int A[8] = {0x66, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x3c, 0x00}; //uppercaseA
const int B[8] = {0x3e, 0x66, 0x66, 0x3e, 0x66, 0x66, 0x3e, 0x00}; //uppercaseB
const int C[8] = {0x3c, 0x66, 0x06, 0x06, 0x06, 0x66, 0x3c, 0x00}; //uppercaseC
const int D[8] = {0x3e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3e, 0x00}; //uppercaseD
const int E[8] = {0x7e, 0x06, 0x06, 0x3e, 0x06, 0x06, 0x7e, 0x00}; //uppercaseE
const int F[8] = {0x06, 0x06, 0x06, 0x3e, 0x06, 0x06, 0x7e, 0x00}; //uppercaseF
const int G[8] = {0x3c, 0x66, 0x76, 0x06, 0x06, 0x66, 0x3c, 0x00}; //uppercaseG
const int H[8] = {0x66, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x66, 0x00}; //uppercaseH
const int I[8] = {0x3c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00}; //uppercaseI
const int J[8] = {0x1c, 0x36, 0x36, 0x30, 0x30, 0x30 ,0x78, 0x00}; //uppercaseJ
const int K[8] = {0x66, 0x36, 0x1e, 0x0e, 0x1e, 0x36, 0x66, 0x00}; //uppercaseK
const int L[8] = {0x7e, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00}; //uppercaseL
const int M[8] = {0xc6, 0xc6, 0xc6, 0xd6, 0xfe, 0xee, 0xc6, 0x00}; //uppercaseM
const int N[8] = {0Xc6, 0Xc6, 0Xe6, 0Xf6, 0Xde, 0Xce, 0Xc6, 0X00}; //uppercaseN
const int O[8] = {0x3c, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x00}; //uppercaseO
const int P[8] = {0x06, 0X06, 0X3e, 0X66, 0X66, 0X66, 0X3e, 0X00}; //uppercaseP
const int Q[8] = {0x60, 0x3c, 0x76, 0x66, 0x66, 0x66, 0x3c, 0x00}; //uppercaseQ
const int R[8] = {0x66, 0x36, 0x1e, 0x3e, 0x66, 0x66, 0x3e, 0x00}; //uppercaseR
const int S[8] = {0x3c, 0x66, 0x60, 0x3c, 0x06, 0x66, 0x3c, 0x00}; //uppercaseS
const int T[8] = {0x18, 0x18, 0x18, 0x18, 0x18, 0x5a, 0x7e, 0x00}; //uppercaseT
const int U[8] = {0x7c, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00}; //uppercaseU
const int V[8] = {0x18, 0x3c, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00}; //uppercaseV
const int W[8] = {0xc6, 0xee, 0xfe, 0xd6, 0xc6, 0xc6, 0xc6, 0x00}; //uppercaseW
const int X[8] = {0xc6, 0xc6, 0x6c, 0x38, 0x6c, 0xc6, 0xc6, 0x00}; //uppercaseX
const int Y[8] = {0x18, 0x18, 0x18, 0x3c, 0x66, 0x66, 0x66, 0x00}; //uppercaseY
const int Z[8] = {0X7e, 0x06, 0x0c, 0x18, 0x30, 0x60, 0x7e, 0x00}; //uppercaseZ
const int space[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 ,0x00}; //characterSpace

#endif //FONTS_HPP