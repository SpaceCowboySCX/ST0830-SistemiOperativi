#include "stenography.h"
#include <stdio.h>
/**
 * This method hides a text file within an image.
 * The text file will be decomposed into bytes and
 * then into bits in order to alter the pixels of the image.
 * @param txt
 * @param image
 * @return
 */
int hiding(FILE txt, FILE image){
    image.seek(10);
    int offset = 0;
    image.read(&offset, sizeof(offset));
    image.seek(0);

    for (int j = 0; j < offset; ++j) {
        char x;
        image.read(&x, sizeof(char));
        out.write(x);
    }

    image.seek(offset);

    while (image.available()) {
        setRgb(image.size(), image.position());

        if (text.available()) {
            char text_byte = text.read();
            char x = 0x01;

            for (int i = 0; i < 8; ++i) {
                char image_byte;
                image.read(&image_byte, sizeof(char));
                char to_write = ((image_byte & 0xFE) | ((text_byte & x) >> i));
                x <<= 1;
                asm(
                    "lds r24, (image_byte) \n"
                    "lds r26, (text_byte) \n"
                    "and r24, 0xFE \n"
                    "and r24, 0x01 \n"
                    "lds r25, (i) \n"
                    "loop:"
                    "lsr r26"
                    "dec r25 \n"
                    "brne loop \n"
                    "or r24, r26 \n"
                    "lds r28, (to_write) \n"
                    "mov r28, r24 \n"
                    :: :"r26", "r24", "r25", "r26"
                    );

                x <<= 1;
                out.write(to_write);

                if ((i + 1) % 3 == 0) {
                char x = image.read();
                out.write(x);
                }
            }

            char y = image.read();
            out.write(y);
        }
    else{
        char x = image.read();
        x &= 0xFE;
        out.write(x);
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
int unveiling(FILE image, FILE text) {
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