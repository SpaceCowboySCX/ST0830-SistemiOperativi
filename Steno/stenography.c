#include "stenography.h"
#include <stdio.h>
#include "utilities.h"

int hiding(FILE* txt, FILE* img) {
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
        fprintf(out, "%c", charatter);
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
                char to_write = (((char) charatter & 0xFE) | (((char) text_byte & x) >> i));
                x <<= 1;
                //out.write(to_write);
                fprintf(out, "%c",to_write);

                if ((i + 1) % 3 == 0) {
                    byte *x; //= image.read();
                    readNextByte(x, img);
                    fprintf(out, "%c",x);
                }
            }

            byte y;// = image.read();
            readNextByte(y, img);
            fprintf(out, "%c",y);
            //out.write(y);
        } else {
            byte x;// = image.read();
            readNextByte(x, img);
            x &= 0xFE;
            fprintf(out, "%c", x);
            //out.write(x);
        }
    }
}

int unveiling(FILE* img, FILE* txt) {
    //image.seek(10);
    setFileOffset(img, 10);
    long offset = 0;
    //image.read(&offset, sizeof(offset));
    offset = ftell(img);

    //image.seek(offset);
    setFileOffset(img, offset);
    byte *charatter;
    byte *text_byte;
    while (readNextByte(charatter, img)) {
        text_byte = 0;
        for (int i = 0; i < 8; ++i) {

            //image.read(&image_byte, sizeof(char));
            text_byte =  text_byte | ((charatter & 0x01) << i);
            if ((i + 1) % 3 == 0)
                fseek(img, sizeof (byte), SEEK_CUR);
                //image.read();

        }

        fseek(img, sizeof (byte), SEEK_CUR);
        fprintf(txt, "%c", text_byte);
        //text.write(text_byte);

        if (text_byte == 0) {
            break;
        }
    }
    return 0;
}