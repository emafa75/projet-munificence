#ifndef __COLOR_SECONDE_HEADER_h__
#define __COLOR_SECONDE_HEADER_h__

#include "color.h"
/*
    Return the prefix for the color
*/
const char* color_prefix(enum color_t color);

/*
    Print very short display for token
*/
void token_short_diplay(struct token_t t);

#endif