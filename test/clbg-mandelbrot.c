/* Hacked CLBG benchmark.
 *
 * This file is available under the Revised BSD open source license. To get
 * the full license text, see:
 * http://shootout.alioth.debian.org/gp4/miscfile.php?file=license&title=revised%20BSD%20license
 *
 * $Id: clbg-mandelbrot.c 48 2008-12-07 23:34:40Z dtrg $
 * $HeadURL: https://cluecc.svn.sourceforge.net/svnroot/cluecc/clue/test/clbg-mandelbrot.c $
 * $LastChangedDate: 2007-04-30 22:41:42 +0000 (Mon, 30 Apr 2007) $
 */

/* The Computer Language Shootout
   http://shootout.alioth.debian.org/

   contributed by Greg Buchholz

   for the debian (AMD) machine...
   compile flags:  -O3 -ffast-math -march=athlon-xp -funroll-loops

   for the gp4 (Intel) machine...
   compile flags:  -O3 -ffast-math -march=pentium4 -funroll-loops
*/

#include <stdio.h>
#include "clbg.h"

int clbgmain (int argc, const char **argv)
{
    int w, h, bit_num = 0;
    char byte_acc = 0;
    int i, iter = 50;
    double x, y, limit = 2.0;
    double Zr, Zi, Cr, Ci, Tr, Ti;

    w = h = atoi(argv[1]);

    printf("Image data width=%d height=%d",w,h);

    for(y=0;y<h;++y)
    {
        for(x=0;x<w;++x)
        {
            Zr = Zi = Tr = Ti = 0.0;
            Cr = (2.0*x/w - 1.5); Ci=(2.0*y/h - 1.0);

            for (i=0;i<iter && (Tr+Ti <= limit*limit);++i)
            {
                Zi = 2.0*Zr*Zi + Ci;
                Zr = Tr - Ti + Cr;
                Tr = Zr * Zr;
                Ti = Zi * Zi;
            }

            byte_acc <<= 1;
            if(Tr+Ti <= limit*limit) byte_acc |= 0x01;

            ++bit_num;

            if(bit_num == 8)
            {
            	printf("%d\n", byte_acc);
                byte_acc = 0;
                bit_num = 0;
            }
            else if(x == w-1)
            {
                byte_acc <<= (8-w%8);
            	printf("%d\n", byte_acc);
                byte_acc = 0;
                bit_num = 0;
            }
        }
    }

    return 0;
}
