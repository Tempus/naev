/*
 * See Licensing and Copyright notice in naev.h
 */



#ifndef IMAGE_H
#  define IMAGE_H


#include "font.h"
#include "colour.h"


/**
 * @brief The image widget data
 */
typedef struct WidgetImageData_{ /* WIDGET_IMAGE */
   glTexture* image; /**< Image to display. */
   glColour* colour; /**< Colour to warp to. */
   int border; /**< 1 if widget should have border. */
} WidgetImageData;


/* Required functions. */
void window_addImage( const unsigned int wid,
      const int x, const int y, /* position */
      char* name, glTexture* image, int border ); /* label and image itself */

/* Misc functions. */
void window_modifyImage( const unsigned int wid,
      char* name, glTexture* image );
void window_imgColour( const unsigned int wid,
      char* name, glColour* colour );


#endif /* IMAGE_H */
