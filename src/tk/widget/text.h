/*
 * See Licensing and Copyright notice in naev.h
 */



#ifndef TEXT_H
#  define TEXT_H


#include "font.h"
#include "colour.h"


/**
 * @brief The button widget.
 */
typedef struct WidgetTextData_ { /* WIDGET_TEXT */
   char *text; /**< Text to display, using printMid if centered, else printText. */
   glFont* font; /**< Text font. */
   glColour* colour; /**< Text colour. */
   int centered; /**< 1 if text is centered, 0 if it isn't. */
} WidgetTextData;


/* Required functions. */
void window_addText( const unsigned int wid,
      const int x, const int y, /* position */
      const int w, const int h, /* size */
      const int centered, char* name, /* text is centered? label name */
      glFont* font, glColour* colour, const char* string ); /* font, colour and actual text */

/* Misc functions. */
void window_modifyText( const unsigned int wid,
      char* name, char* newstring );


#endif /* TEXT_H */
