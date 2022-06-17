#include "stenography.h"
#include "manageFile.h"
#include "byteType.h"

int hiding(char *file_img_dot, char *file_txt_dot, char *file_img_output_dot) {
    FILE *file_img = fopen(file_img_dot, "rb");
    FILE *file_txt = fopen(file_txt_dot, "rb");
    FILE *file_img_output = fopen(file_img_output_dot, "ab");

    //TODO vedere se farlo sotto forma di puntatore
    byte byte_img;
    byte byte_text;

    //Sposto il puntatore dopo l'header
    //setFileOffset(file_img, 10);
    setFileOffset(file_img, 54);// forse l'header parte da 14
    long offset = ftell(file_img);
    //Sposto il puntatore all'inizio del file
    setFileOffset(file_img, 0);
    //Sovrascrivo l'header dell'immagine di output
    for (int index = 0; index < offset; index++) {
        fread(&byte_img, sizeof(byte), 1, file_img);
        fwrite(&byte_img, sizeof(byte), 1, file_img_output);

        //readNextByte(&byte_img, file_img);
        //fprintf(file_img_output, "%c", byte_img);
    }

    //Sposto il puntatore dopo l'header.
    setFileOffset(file_img, offset);

    while (!feof(file_img)) {
        //readNextByte(&byte_img, file_img) == 0
        //fread(&byte_img, sizeof (char), 1, file_img);
        //Controllo se il txt è stato ricopiato interamente.
        if (!feof(file_txt)) {
            //readNextByte(&byte_text, file_txt) == 0
            fread(&byte_text, sizeof(byte), 1, file_txt);
            byte to_compare = 0x01;

            //Scrivo ogni bit del byte_text su tre byte dell'immagine
            for (int index = 0; index < 8; index++) {
                fread(&byte_img, sizeof(byte), 1, file_img);
                //readNextByte(&byte_img, file_img);
                //Operazione bit a bit sul byte to_write
                byte to_write = ((byte_img & 0xFE) | ((byte_text & to_compare) >> index));
                to_compare <<= 1;
                //fprintf(file_img_output, "%c",to_write);
                fwrite(&to_write, sizeof(byte), 1, file_img_output);

                //Essendo privo di significato, il quarto byte deve essere saltato in quanto non modificabile
                //Ricopio il byte dell'immagine originale.
                if ((index + 1) % 3 == 0)
                    toSkip(file_img, file_img_output);
            }
        } else {
         //   //Ricopio i byte dell'immagine originale in quanto il txt è terminato.
         //   toSkip(file_img, file_img_output);
            //ALTRIMENTI ricopio il byte dell'immagine non modificati
            byte copy_of_byte_img;
            //readNextByte(&copy_of_byte_img, file_img);
            fread(&copy_of_byte_img, sizeof(byte), 1, file_img);
            copy_of_byte_img &= 0xFE;
            //fprintf(file_img_output, "%c", copy_of_byte_img);
            fwrite(&copy_of_byte_img, sizeof(byte), 1, file_img_output);
        }
    }
    fclose(file_img);
    fclose(file_img_output);
    fclose(file_txt);
    return 0;
}

void toSkip(FILE *file_img, FILE *file_img_output) {
    byte to_skip; //= image.read();
    //readNextByte(&to_skip, file_img);
    fread(&to_skip, sizeof(byte), 1, file_img);
    //fprintf(file_img_output, "%c",to_skip);
    fwrite(&to_skip, sizeof(byte), 1, file_img_output);
}

int unveiling(char *file_img_dot, char *file_txt_output_dot) {
    FILE *file_img = fopen(file_img_dot, "rb");
    FILE *file_txt_output = fopen(file_txt_output_dot, "w");
    byte byte_img = 0x00;
    byte byte_text;

    //Sposto il puntatore dopo l'header.
    //setFileOffset(file_img, 10);
    setFileOffset(file_img, 54);
    while (!feof(file_img)) {
        //readNextByte(&byte_img, file_img) == 0
        //Reset di byte_text.
        byte_text = 0x00;
        //Index rappresenterà il singolo bit.
        for (int index = 0; index < 8; index++) {
            fread(&byte_img, sizeof(byte), 1, file_img);
            byte_text = byte_text | ((byte_img & 0x01) << index);
            //Essendo privo di significato, il quarto byte deve essere saltato.

            if ((index + 1) % 3 == 0)
                fseek(file_img, sizeof(byte), SEEK_CUR);
        }
        //fseek(file_img, sizeof(byte), SEEK_CUR);
        //fprintf(file_txt_output, "%c", byte_text);
        if (byte_text == 0)
            break;

        fwrite(&byte_text, sizeof(byte), 1, file_txt_output);
        //Se leggo il terminatore di stringa '\0' concludo la funzione.

    }
    fclose(file_img);
    fclose(file_txt_output);
    return 0;
}

int lengthFileCheck(FILE *file_img, FILE *file_txt) {
    int index;
    long int img_length, txt_length;

    //I primi 10 byte appartengono all' header e non devono essere modificati.
    fseek(file_img, 10, SEEK_CUR);

    //Il primo byte appartenente a un pixel
    fread(&index, 1, sizeof(int), file_img);
    fseek(file_img, 2, SEEK_SET);
    fread(&img_length, 1, sizeof(int), file_img);

    img_length -= index;
    txt_length = getFileLength(file_txt);

    if ((txt_length + txt_length / 4) * 8 > img_length) {
        printf("Text too long for the image to be hidden.");
        return -1;
    }

    return index;
}