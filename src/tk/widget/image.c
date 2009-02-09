/*
 * See Licensing and Copyright notice in naev.h
 */

/**
 * @file text.c
 *
 * @brief Text widget.
 */


#include "tk/toolkit_priv.h"


static void img_render( Widget* img, double bx, double by );


/**
 * @brief Adds an image widget to the window.
 *
 * Position origin is 0,0 at bottom left.  If you use negative X or Y
 *  positions.  They actually count from the opposite side in.
 *
 *    @param wid ID of the window to add the widget to.
 *    @param x X position within the window to use.
 *    @param y Y position within the window to use.
 *    @param name Name of the widget to use internally.
 *    @param image Image to use.
 *    @param border Whether to use a border.
 */
void window_addImage( const unsigned int wid,
                      const int x, const int y,
                      char* name, glTexture* image, int border )
{
   Window *wdw = window_wget(wid);
   Widget *wgt = window_newWidget(wdw);

   /* generic */
   wgt->type   = WIDGET_IMAGE;
   wgt->name   = strdup(name);
   wgt->wdw    = wid;

   /* specific */
   wgt->render          = img_render;
   wgt->dat.img.image   = image;
   wgt->dat.img.border  = border;
   wgt->dat.img.colour  = NULL; /* normal colour */

   /* position/size */
   wgt->w = (image==NULL) ? 0 : wgt->dat.img.image->sw;
   wgt->h = (image==NULL) ? 0 : wgt->dat.img.image->sh;
   toolkit_setPos( wdw, wgt, x, y );
}


/**
 * @brief Renders a image widget.
 *
 *    @param img Image widget to render.
 *    @param bx Base X position.
 *    @param by Base Y position.
 */
static void img_render( Widget* img, double bx, double by )
{
   double x,y;

   if (img->dat.img.image == NULL) return;

   x = bx + img->x;
   y = by + img->y;

   /*
    * image
    */
   gl_blitStatic( img->dat.img.image,
         x + (double)SCREEN_W/2.,
         y + (double)SCREEN_H/2.,
         img->dat.img.colour );

   if (img->dat.img.border) {
      /* inner outline (outwards) */
      toolkit_drawOutline( x, y+1, img->dat.img.image->sw-1,
         img->dat.img.image->sh-1, 1., toolkit_colLight, toolkit_col );
      /* outter outline */
      toolkit_drawOutline( x, y+1, img->dat.img.image->sw-1,
            img->dat.img.image->sh-1, 2., toolkit_colDark, NULL );
   }
}

