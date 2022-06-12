#include "stenography.h"
#include <stdio.h>
#include "utilities.h"

//TODO polish
int hiding(FILE* file_img, FILE* file_txt, FILE* file_img_output){
    /*
     * CREATION FILE OUTPUT
     */

    byte byte_img;
    byte byte_text;
    //FILE *out = fopen("output.bmp", "w");
    //image.seek(10);
    setFileOffset(file_img, 10);

    long offset = ftell(file_img);
    //image.read(&offset, sizeof(offset));
    setFileOffset(file_img, 0);
    //image.seek(0);
    //Sovrascrivo l'header dell'immagine di output
    for (int index = 0; index < offset; index++) {
        //char x;
        readNextByte(&byte_img, file_img);
        //image.read(&x, sizeof(char));
        fprintf(file_img_output, "%c", byte_img);
        //out.write(x);
    }

    setFileOffset(file_img, offset);
    //image.seek(offset);
    while (readNextByte(&byte_img, file_img) == 0) {
        if (readNextByte(&byte_text, file_txt) == 0) {
            //char text_byte = text.read();
            byte to_compare = 0x01;

            for (int index = 0; index < 8; index++) {
                //char image_byte;
                //image.read(&image_byte, sizeof(char));
                readNextByte(&byte_img, file_img);
                byte to_write = (( byte_img & 0xFE) | (( byte_text & to_compare) >> index));
                to_compare<<= 1;
                //out.write(to_write);
                fprintf(file_img_output, "%c",to_write);

                if ((index + 1) % 3 == 0) {
                    byte to_skip; //= image.read();
                    readNextByte(&to_skip, file_img);
                    fprintf(file_img_output, "%c",to_skip);
                }
            }

            byte to_skip; //= image.read();
            readNextByte(&to_skip, file_img);
            fprintf(file_img_output, "%c",to_skip);
            //out.write(y);
        } else {
            byte copy_of_byte_img;// = image.read();
            readNextByte(&copy_of_byte_img, file_img);
            copy_of_byte_img &= 0xFE;
            fprintf(file_img_output, "%c", copy_of_byte_img);
            //out.write(x);
        }
    }
}

//TODO polish
//file_txt è il file dove andremo a scrivere il testo nascosto nell'immagine.
int unveiling(FILE* file_img, FILE* file_txt_output) {
    //image.seek(10);
    setFileOffset(file_img, 10);
    //image.read(&offset, sizeof(offset));
    //long offset_file_img = ftell(file_img);
    //image.seek(offset);
    //setFileOffset(file_img, offset_file_img);
    byte byte_img;
    byte byte_text;

    while (readNextByte(&byte_img, file_img) == 0) {
        //Reset di byte_text
        byte_text = 0;
        //index rappresenta il singolo bit
        for (int index = 0; index < 8; index++) {
            //image.read(&image_byte, sizeof(char));
            byte_text |= ((byte_img & 0x01) << index);

            if ((index + 1) % 3 == 0)
                fseek(file_img, sizeof (byte), SEEK_CUR);
                //image.read();
        }

        fseek(file_img, sizeof (byte), SEEK_CUR);
        fprintf(file_txt_output, "%c", byte_text);
        //text.write(text_byte);

        if (byte_text == 0)
            break;
    }
    return 0;
}