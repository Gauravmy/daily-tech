#include <stdio.h>
#include <string.h>
#include <gd.h>

int main() {
    /* Declare the image */
    gdImagePtr img;
    /* Output file */
    FILE *out = fopen("text.png", "wb");
    /* Declare color indexes */
    int black;
    int white;

    /* Allocate the image: 64 pixels across by 64 pixels tall */
    img = gdImageCreate(400, 300);

    /* Allocate the color black (red, green and blue all minimum).
       Since this is the first color in a new image, it will
       be the background color. */
    black = gdImageColorAllocate(img, 0, 0, 0);

    /* Allocate the color white (red, green and blue all maximum). */
    white = gdImageColorAllocate(img, 255, 255, 255);

    /* Draw a string at the specified location in the specified color. */
    gdImageString(img, gdFontGetGiant(), 10, 10, "Hello, world!", white);

    /* Write PNG format image to file. */
    gdImagePng(img, out);

    /* Close file */
    fclose(out);

    /* Destroy image in memory. */
    gdImageDestroy(img);

    return 0;
}
