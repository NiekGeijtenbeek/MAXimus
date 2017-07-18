#include "coordinate.hpp"
#include "display.cpp"
#include <iostream>

// needed to get Catch working with MinGW
#define TWOBLUECUBES_CATCH_REPORTER_JUNIT_HPP_INCLUDED
namespace Catch{ class JunitReporter{ ~JunitReporter(); }; };

#include "catch_with_main.hpp"

// Start testing "coordinates"
TEST_CASE ( "constructor, default" ){
   coordinate test;
   std::stringstream s;
   s << test;
   REQUIRE( s.str() == "(0,0)");
}

TEST_CASE ( "constructor, default (error)" ){
   coordinate test;
   std::stringstream s;
   s << test;
   REQUIRE( s.str() != "(1,1)");
}

TEST_CASE ( "constructor, twoParameters" ){
   coordinate test(3, 3);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() == "(3,3)");
}

TEST_CASE ( "constructor, twoParameters (error)" ){
   coordinate test(9, 2);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() != "(92,32)");
}

TEST_CASE ( "invert, twoParameters" ){
   coordinate test(3, 2);
   test.invert();
   std::stringstream s;
   s << test;
   REQUIRE( s.str() == "(2,3)");
}

TEST_CASE ( "invert, twoParameters (false)" ){
   coordinate test(3, 2);
   test.invert();
   std::stringstream s;
   s << test;
   REQUIRE( s.str() != "(3, 2)");
}

TEST_CASE ( "override, twoParameters" ){
   coordinate test(9, 2);
   test = coordinate (3,3);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() == "(3,3)");
}

TEST_CASE ( "override, twoParameters (error)" ){
   coordinate test(9, 2);
   test = coordinate (3,3);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() != "(9,3)");
}

TEST_CASE ( "shiftLeft, twoParameters" ){
   coordinate test(3, 3);
   test.shiftLeft(2);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() == "(1,3)");
}

TEST_CASE ( "shiftLeft, twoParameters (error)" ){
   coordinate test(3, 3);
   test.shiftLeft(2);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() != "(3,3)");
}

TEST_CASE ( "shiftRight, twoParameters" ){
   coordinate test(3, 3);
   test.shiftRight(2);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() == "(5,3)");
}

TEST_CASE ( "shiftRight, twoParameters (errors)" ){
   coordinate test(3, 3);
   test.shiftRight(2);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() != "(3,3)");
}

TEST_CASE ( "shiftUp, twoParameters" ){
   coordinate test(5, 5);
   test.shiftUp(3);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() == "(5,2)");
}

TEST_CASE ( "shiftUp, twoParameters (error)" ){
   coordinate test(5, 5);
   test.shiftUp(3);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() != "(5,5)");
}

TEST_CASE ( "shiftDown, twoParameters" ){
   coordinate test(5, 5);
   test.shiftDown(3);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() == "(5,8)");
}

TEST_CASE ( "shiftDown, twoParameters (error)" ){
   coordinate test(5, 5);
   test.shiftDown(3);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() != "(5,5)");
}

TEST_CASE ( "+=, twoParameters 1" ){
   coordinate test(2, 2);
   test += coordinate (1,1);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() == "(3,3)");
}

TEST_CASE ( "+=, twoParameters 2" ){
   coordinate test(2, 2);
   test += coordinate (2,2);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() == "(4,4)");
}

TEST_CASE ( "*=, twoParameters 1" ){
   coordinate test(2, 2);
   test *= coordinate (2,2);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() == "(4,4)");
}

TEST_CASE ( "*=, twoParameters 2" ){
   coordinate test(2, 2);
   test *= coordinate (3,3);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() == "(6,6)");
}

TEST_CASE ( "-=, twoParameters 1" ){
   coordinate test(2, 2);
   test -= coordinate (1,1);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() == "(1,1)");
}

TEST_CASE ( "-=, twoParameters 2" ){
   coordinate test(5, 5);
   test -= coordinate (3,3);
   std::stringstream s;
   s << test;
   REQUIRE( s.str() == "(2,2)");
}

TEST_CASE ( "+, twoParameters 1" ){
   coordinate test(5,5);
   coordinate test2(2,2);
   coordinate test3 = test + test2;
   std::stringstream s;
   s << test3;
   REQUIRE( s.str() == "(7,7)");
}

TEST_CASE ( "+, twoParameters 2" ){
   coordinate test(5,5);
   coordinate test3 = test + coordinate (5,5);
   std::stringstream s;
   s << test3;
   REQUIRE( s.str() == "(10,10)");
}

TEST_CASE ( "*, twoParameters 1" ){
   coordinate test(2,2);
   coordinate test2(3,3);
   coordinate test3 = test * test2;
   std::stringstream s;
   s << test3;
   REQUIRE( s.str() == "(6,6)");
}

TEST_CASE ( "*, twoParameters 2" ){
   coordinate test(2,2);
   coordinate test3 = test * coordinate(3,3);
   std::stringstream s;
   s << test3;
   REQUIRE( s.str() == "(6,6)");
}

TEST_CASE ( "-, twoParameters 1" ){
   coordinate test(3,3);
   coordinate test2(2,2);
   coordinate test3 = test - test2;
   std::stringstream s;
   s << test3;
   REQUIRE( s.str() == "(1,1)");
}

TEST_CASE ( "-, twoParameters 2" ){
   coordinate test(3,3);
   coordinate test3 = test - coordinate(2,2);
   std::stringstream s;
   s << test3;
   REQUIRE( s.str() == "(1,1)");
}
// End testing "coordinates"


// Start testing "sets"
TEST_CASE ("set, oneParameter 1"){
   set(coordinate (3,3));
   std::stringstream s;
   printFrame(s);
   std::stringstream test;
   test << "0-0-0-0-0-0-0-0-32-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-";

   
   REQUIRE (s.str() == test.str());
   resetMatrix();
}

TEST_CASE ("set, oneParameter 2"){
   set(coordinate (1,1));
   std::stringstream s;
   printFrame(s);
   std::stringstream test;
   test << "128-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-";
   
   REQUIRE (s.str() == test.str());
   resetMatrix();
}

TEST_CASE ("set, oneParameter (empty)"){
   std::stringstream s;
   printFrame(s);
   std::stringstream test;
   test << "0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-";
   
   REQUIRE (s.str() == test.str());
   resetMatrix();
}

TEST_CASE ("set, oneParameter Line"){
   set(coordinate (1,1));
   set(coordinate (2,1));
   set(coordinate (3,1));
   set(coordinate (4,1));
   set(coordinate (5,1));
   set(coordinate (6,1));
   set(coordinate (7,1));
   set(coordinate (8,1));
   std::stringstream s;
   printFrame(s);
   std::stringstream test;
   test << "255-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-";
   
   REQUIRE (s.str() == test.str());
   resetMatrix();
}

TEST_CASE ("Output test 1"){
   std::stringstream s;
   setAdressData(0x0F, 0X0E, s);
   std::stringstream test;
   test << "0000111100001110";
   
   REQUIRE (s.str() == test.str());
   resetMatrix();
}

TEST_CASE ("Output test 2"){
   std::stringstream s;
   setAdressData(0xFF, 0X0E, s);
   std::stringstream test;
   test << "1111111100001110";
   
   REQUIRE (s.str() == test.str());
   resetMatrix();
}

TEST_CASE ("Output test 3"){
   std::stringstream s;
   setAdressData(0x02, 0x02, s);
   std::stringstream test;
   test << "0000001000000010";
   
   REQUIRE (s.str() == test.str());
   resetMatrix();
}

TEST_CASE ("Output test 4"){
   std::stringstream s;
   setAdressData(0xAE, 0xAA, s);
   std::stringstream test;
   test <<  "1010111010101010";
   
   REQUIRE (s.str() == test.str());
   resetMatrix();
}