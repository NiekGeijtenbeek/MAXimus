/* 
=============================================================================================

	Author		: Arsalan Anwari
	Library		: Pre-Alpha v1.0 DWARF Lite 
	File		: math.hpp
	Part of		: DWARF ENGINE 
	Copyright	: https://github.com/ArsalanAnwari/DWARF_ENGINE 2017

	Distributed under the Boost Software License, Version 1.0.
	(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

==============================================================================================
*/

#ifndef MATH_HPP
#define MATH_HPP

/**
 * @brief Exponentation of a integer
 * @details This function returns a exponentation of a base by a user defined exponent. \n
 * A technique called bitshifting is used to compare the value of the MSB bit of the exponent. \n
 * If the sum of the mask (0x10) is true, a temporary integer result will be incremented(*=) by the base value. \n
 * By shifting all the bits of the exponent to the right by one, you binary deincrement the value. \n
 * The base gets multiplyplied by it self and the loop proceeds until the binary value of the exponent becomes 0x00
 * @param base
 * @param exp
 * @return integer
 */
int pow(int base, int exp){
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

/**
 * @brief Exponentation of floating pointer
 * @details This function returns a exponentation of a base by a user defined exponent. \n
 * There are no special techniques being used in this function. just a simple for loop with a result being multiplied by its base.
 * @param base
 * @param exp
 * @return float
 */
float pow (float base, int exp){
    float p=1.0;
    for (int i=1; i<=exp; i++)
    p=p*base;
    return p;
}

/**
 * @brief Calculation of absolute value of a integer
 * @details This function was made by Jens Gustedt 
 * @ref https://stackoverflow.com/questions/9772348/get-absolute-value-without-using-abs-function-nor-if-statement
 * @param v
 * @return integer
 */
int abs(int v) {
  return v * ((v>0) - (v<0));
}
/**
 * @brief Calculation of absolute value of a floatig pointer
 * @details This function was made by Jens Gustedt 
 * @ref https://stackoverflow.com/questions/9772348/get-absolute-value-without-using-abs-function-nor-if-statement
 * @param v
 * @return floating pointer
 */
float abs(float v) {
  return v * ((v>0) - (v<0));
}

/**
 * @brief Two Babylonian Steps (simplfied) square root 
 * @param x
 * @return float 
 */
float sqrt(const float x) {
  union
  {
    int i;
    float x;
  } u;
  u.x = x;
  u.i = (1<<29) + (u.i >> 1) - (1<<22); 

  u.x =       u.x + x/u.x;
  u.x = 0.25f*u.x + x/u.x;

  return u.x;
} 

/**
 * @brief Function used to round a floating pointer up. 
 * @param num
 * @return 
 */
int ceil(float num) {
    int inum = (int)num;
    if (num == (float)inum) {
        return inum;
    }
    return inum + 1;
}

/**
 * @brief Function used to calculate Bézier points
 * @details In spi_lcd_shapes.hpp and oled_shapes.hpp you are able to make a Bézier based curved lines. \n
 * Here you will generate certain 'bending points' the line had to follow.
 * Bézier was a french engineer who used the Casteljau's algortihm to calculate points of rotation for a straight line. \n
 * The complete explanation of the workings of this point generating method is rather difficult to explain. 
 * Please see the link for more info.
 * @ref https://en.wikipedia.org/wiki/B%C3%A9zier_curve
 * @param n1
 * @param n2
 * @param perc
 * @return 
 */
int getPt( int n1 , int n2 , float perc ){
		int diff = n2 - n1;
		return (n1 + ( diff * perc ));
}

/**
 * @brief Simple Factoral calculation of a floating pointer 
 * @param x
 * @return float 
 */
float fact(int x){
    float f=1.0;
    for (int i=1; i<=x; i++)
    {
    f=f*i;
    }
    return f;
}

/**
 * @brief Modified Taylor series cos alghorithm
 * @details This is a modified algortihm made by a Professor in MIT. His name was unkown however.
 * @param x
 * @return float
 */
float cos(float x){
    float sum_positive = 0.0;
    float sum_negative= 0.0;
    float output=0.0;
    for (int i=4; i<=20; i+=4){
		sum_positive = sum_positive + (pow (x,i) / fact (i));
    }
	
    for (int i=2; i<=20; i+=4){
		sum_negative = sum_negative + (pow (x,i) / fact (i));
    }
	
	output = (1 - (sum_negative) + (sum_positive));
    return output;
}


/**
 * @brief Modified Taylor series sin alghorithm
 * @details This is a modified algortihm made by a Professor in MIT. His name was unkown however.
 * @param x
 * @return float
 */
float sin(float x){
    float sum = 0.0;
    for(int i = 0; i < 9; i++)
    {
        float top = pow(-1, i) * pow(x, 2 * i + 1);
        float bottom = fact(2 * i + 1);
        sum = sum + top / bottom;
    }
    return sum;
}

/**
 * @brief This function will convert a integer to a char array.
 * @details a integer and a char arrray have to be givin to the function. \n 
 * The function converts the integer to a char array and will fill the given char array with the content
 * @param n
 * @param ch1
 */
void int_to_string(int n, char ch1[]){
	char buffer[5];
	int i = 0;

	bool isNeg = n<0;

	unsigned int n1 = isNeg ? -n : n;

	while(n1!=0)
	{
		buffer[i++] = n1%10+'0';
		n1=n1/10;
	}

	if(isNeg)
		buffer[i++] = '-';

	buffer[i] = '\0';

	for(int t = 0; t < i/2; t++)
	{
		buffer[t] ^= buffer[i-t-1];
		buffer[i-t-1] ^= buffer[t];
		buffer[t] ^= buffer[i-t-1];
	}

	if(n == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
	}   
	
	int k = 0;
	int l = 0;
	while(k<5)
    {
        ch1[k]=buffer[l];
        l++;k++;
    }

}

/**
 * @brief This function will return the atan of a float
 * @param inX
 * @return float
 */
float atan(float inX){
	float  x = inX;
	return x*(-0.1784f * abs(x) - 0.0663f * x * x + 1.0301f);
}

/**
 * @brief This function will return the acos of a float
 * @param inX
 * @return float
 */
float acos(float inX){
	float x1 = abs(inX);
	float x2 = x1 * x1;
	float x3 = x2 * x1;
	float s;

	s = -0.2121144f * x1 + 1.5707288f;
	s = 0.0742610f * x2 + s;
	s = -0.0187293f * x3 + s;
	s = sqrt(1.0f - x1) * s;

	float pi = 3.14159265359;
	return inX >= 0.0f ? s : pi - s;
}
#endif //MATH_HPP