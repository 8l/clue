/* Hacked CLBG benchmark.
 *
 * This file is available under the Revised BSD open source license. To get
 * the full license text, see:
 * http://shootout.alioth.debian.org/gp4/miscfile.php?file=license&title=revised%20BSD%20license
 *
 * $Id: clbg-nsieve.c 48 2008-12-07 23:34:40Z dtrg $
 * $HeadURL: https://cluecc.svn.sourceforge.net/svnroot/cluecc/clue/test/clbg-nsieve.c $
 * $LastChangedDate: 2007-04-30 22:41:42 +0000 (Mon, 30 Apr 2007) $
 */

// The Computer Language Shootout
// http://shootout.alioth.debian.org/
// Precedent C entry modified by bearophile for speed and size, 31 Jan 2006
// Compile with:  -O3 -s -std=c99 -fomit-frame-pointer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clbg.h"

typedef unsigned char boolean;


static void nsieve(int m) {
    unsigned int count = 0, i, j;
    boolean * flags = (boolean *) malloc(m * sizeof(boolean));
    memset(flags, 1, m);

    for (i = 2; i < m; ++i)
        if (flags[i]) {
            ++count;
            for (j = i << 1; j < m; j += i)
//                if (flags[j])
                   flags[j] = 0;
    }

    free(flags);
    printf("Primes up to %8u %8u\n", m, count);
}

int clbgmain(int argc, const char * argv[]) {
    int m = atoi(argv[1]);
    int i;

    for (i = 0; i < 3; i++)
        nsieve(10000 << (m-i));
    return 0;
}
