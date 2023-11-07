#include "color.h"

const char * str_color[] = {
  "Black",
  "Blue",
  "Green",
  "Red",
  "White",
  "Gold",
  "Pearl",
  "Aquamarine",
  "Octarine",
  "Chestnut"
};

const char * str_short_color[] = {
  "K",
  "B",
  "G",
  "R",
  "W",
  "D",
  "P",
  "A",
  "O",
  "C"
};

const char* color_to_string(enum color_t c)
{
  return str_color[c];
  
}

const char* color_to_short_string(enum color_t c)
{
  return str_short_color[c];
}
  
  
