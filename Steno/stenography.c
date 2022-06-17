#include "stenography.h"
#include "manageFile.h"
#include "byteType.h"

int hiding(FILE* file_img, FILE* file_txt, FILE* file_img_output){
    byte byte_img;
    byte byte_text;

    //Sposto il puntatore dopo l'header
    setFileOffset(file_img, 10);
    long offset = ftell(file_img);
    //Sposto il puntatore all'inizio del file
    setFileOffset(file_img, 0);
    //Sovrascrivo l'header dell'immagine di output
    for (int index = 0; index < offset; index++) {
        readNextByte(&byte_img, file_img);
        fprintf(file_img_output, "%c", byte_img);
    }

    //Sposto il puntatore dopo l'header.
    setFileOffset(file_img, offset);
    while (readNextByte(&byte_img, file_img) == 0) {
        //Controllo se il txt è stato ricopiato interamente.
        if (readNextByte(&byte_text, file_txt) == 0) {
            byte to_compare = 0x01;

            //Scrivo ogni bit del byte_text su tre byte dell'immagine
            for (int index = 0; index < 8; index++) {
                readNextByte(&byte_img, file_img);
                //Operazione bit a bit sul byte to_write
                byte to_write = (( byte_img & 0xFE) | (( byte_text & to_compare) >> index));
                to_compare <<= 1;
                fprintf(file_img_output, "%c",to_write);

                //Essendo privo di significato, il quarto byte deve essere saltato in quanto non modificabile
                //Ricopio il byte dell'immagine originale.
                if ((index + 1) % 3 == 0)
                    toSkip(file_img, file_img_output);
            }

            //Ricopio i byte dell'immagine originale in quanto il txt è terminato.
            toSkip(file_img, file_img_output);
        } else {
            //ALTRIMENTI ricopio il byte dell'immagine non modificati
            byte copy_of_byte_img;
            readNextByte(&copy_of_byte_img, file_img);
            copy_of_byte_img &= 0xFE;
            fprintf(file_img_output, "%c", copy_of_byte_img);
        }
    }
    return 0;
}

void toSkip(FILE* file_img, FILE* file_img_output){
    byte to_skip; //= image.read();
    readNextByte(&to_skip, file_img);
    fprintf(file_img_output, "%c",to_skip);
}

int unveiling(FILE* file_img, FILE* file_txt_output) {

    byte byte_img;
    byte byte_text;

    //Sposto il puntatore dopo l'header.
    setFileOffset(file_img, 10);

    while (readNextByte(&byte_img, file_img) == 0) {
        //Reset di byte_text.
        byte_text = 0;
        //Index rappresenterà il singolo bit.
        for (int index = 0; index < 8; index++) {
            byte_text |= ((byte_img & 0x01) << index);
            //Essendo privo di significato, il quarto byte deve essere saltato.
            if ((index + 1) % 3 == 0)
                fseek(file_img, sizeof (byte), SEEK_CUR);
        }

        fseek(file_img, sizeof (byte), SEEK_CUR);
        fprintf(file_txt_output, "%c", byte_text);

        //Se leggo il terminatore di stringa '\0' concludo la funzione.
        if (byte_text == 0)
            break;
    }
    return 0;
}

int lengthFileCheck(FILE* file_img, FILE* file_txt){
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

    if((txt_length + txt_length / 4) * 8 > img_length){
        printf("Text too long for the image to be hidden.");
        return -1;
    }

    return index;
}