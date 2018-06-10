#include "Food.hpp"

/** A Food class constructor
*   @param x a float percentage number that defines horizontal position
*   @param y a float percentage number that defines vertical position
*   @param r a float number representing radius of a balls
*   @param red a integer number representing red color in RGB
*   @param green a integer number representing green color in RGB
*   @param blue a integer number representing blue color in RGB
*/
Food::Food(float x, float y, float r, int red, int green, int blue) :    Ball(x, y, r, red, green, blue) {}

Food::~Food() { }
