#include "stenography.h"
#include <stdio.h>
#include "utilities.h"
/**
 * This method hides a text file within an image.
 * The text file will be decomposed into bytes and
 * then into bits in order to alter the pixels of the image.
 * @param txt
 * @param image
 * @return
 */
int hiding(FILE* txt, FILE* img){
    /*
     * CREATION FILE OUTPUT
     */
    FILE *out = fopen("output.bmp", "w");
    //image.seek(10);
    setFileOffset(img, 10);

    long offset = 0;

    offset = ftell(img);
    //image.read(&offset, sizeof(offset));

    setFileOffset(img, 0);
    //image.seek(0);
    byte *charatter;
    for (int j = 0; j < offset; ++j) {
        //char x;
        readNextByte(charatter, img);
        //image.read(&x, sizeof(char));
        fprintf(out, "%s", charatter);
        //out.write(x);
    }
    setFileOffset(img, offset);
    //image.seek(offset);
    byte *text_byte;
    while (readNextByte(charatter, img) != -1) {

        if (readNextByte(text_byte, txt) != -1) {
            //char text_byte = text.read();
            byte x = 0x01;

            for (int i = 0; i < 8; ++i) {
                //char image_byte;
                //image.read(&image_byte, sizeof(char));
                readNextByte(charatter, img);
                char to_write = (((char)charatter & 0xFE) | (((char) text_byte & x) >> i));
                x <<= 1;
                //out.write(to_write);
                fprintf(out, to_write);

                if ((i + 1) % 3 == 0) {
                byte *x; //= image.read();
                readNextByte(x, img);
                fprintf(out, x);
                }
            }

            byte y;// = image.read();
            readNextByte(y, img);
            fprintf(out, y);
            //out.write(y);
        }
    else{
        byte x;// = image.read();
        readNextByte(x, img);
        x &= 0xFE;
        fprintf(out, x);
        //out.write(x);
    }
}

/**
 * This method unveil a text file from an image.
 * The text file will be recomposed into bytes and
 * then into bits in order to alter the pixels of the image.
 * @param txt
 * @param image
 * @return
 */
int unveiling(FILE* img, FILE* txt) {
    image.seek(10);
    int offset = 0;
    image.read(&offset, sizeof(offset));

    image.seek(offset);
    while (image.available()) {
        setRgb(image.size(), image.position());

        for ( i = 0; i < 8; ++i) {
            image.read(&image_byte, sizeof(char));
                asm(
                    "lds r24, (image_byte) \n"
                    "lds r26, (text_byte) \n"
                    "and r24, 0x01 \n"
                    "lds r25, (i) \n"
                    "loop:"
                    "lsl r24 \n"
                    "dec r25 \n"
                    "brne loop \n"
                    "or r26, r24 \n"
                    :::"r24", "r26", "r25"
                    );
            if ((i + 1) % 3 == 0)
                image.read();
        }

        image.read();
        text.write(text_byte);

        if (text_byte == 0)
                break;
    }
    return 0;
}