#include <string.h>
#include "stenography.h"
#include "manageFile.h"
#include "byteType.h"
#include "list.h"

void*  hiding(void* list) {
    Node *list_casted = list;

    FILE *file_img = fopen(list_casted->name_file_bmp, "rb");
    FILE *file_txt = fopen(list_casted->name_file_txt, "rb");
//    char st[MAX_LENGTH_STRING];
//    strcpy(list_casted->name_file_generate,"lala");
    FILE *file_img_output = fopen(list_casted->name_file_generate, "ab");

    byte byte_img;
    byte byte_text;

    //Sposto il puntatore dopo l'header
    setFileOffset(file_img, 54);
    long offset = ftell(file_img);
    //Sposto il puntatore all'inizio del file
    setFileOffset(file_img, 0);
    //Sovrascrivo l'header dell'immagine di output
    for (int index = 0; index < offset; index++) {
        fread(&byte_img, sizeof(byte), 1, file_img);
        fwrite(&byte_img, sizeof(byte), 1, file_img_output);
    }

    //Sposto il puntatore dopo l'header.
    setFileOffset(file_img, offset);

    while (!feof(file_img)) {
        //Controllo se il txt è stato ricopiato interamente.
        if (!feof(file_txt)) {
            fread(&byte_text, sizeof(byte), 1, file_txt);
            byte to_compare = 0x01;

            //Scrivo ogni bit del byte_text su tre byte dell'immagine
            for (int index = 0; index < 8; index++) {
                fread(&byte_img, sizeof(byte), 1, file_img);
                //Operazione bit a bit sul byte to_write
                byte to_write = ((byte_img & 0xFE) | ((byte_text & to_compare) >> index));
                to_compare <<= 1;
                fwrite(&to_write, sizeof(byte), 1, file_img_output);

                //Essendo privo di significato, il quarto byte deve essere saltato in quanto non modificabile
                //Ricopio il byte dell'immagine originale.
                if ((index + 1) % 3 == 0)
                    toSkip(file_img, file_img_output);
            }
        } else {
         //   //Ricopio i byte dell'immagine originale in quanto il txt è terminato.
            //ALTRIMENTI ricopio il byte dell'immagine non modificati
            byte copy_of_byte_img;
            fread(&copy_of_byte_img, sizeof(byte), 1, file_img);
            copy_of_byte_img &= 0xFE;
            fwrite(&copy_of_byte_img, sizeof(byte), 1, file_img_output);
        }
    }
    fclose(file_img);
    fclose(file_img_output);
    fclose(file_txt);
    return NULL;
}

void toSkip(FILE *file_img, FILE *file_img_output) {
    byte to_skip;
    fread(&to_skip, sizeof(byte), 1, file_img);
    fwrite(&to_skip, sizeof(byte), 1, file_img_output);
}

void* unveiling(void* list) {
    Node* list_casted = list;
    FILE *file_img = fopen(list_casted->name_file_bmp, "rb");
    FILE *file_txt_output = fopen(list_casted->name_file_generate, "w");
    byte byte_img = 0x00;
    byte byte_text;

    //Sposto il puntatore dopo l'header.
    setFileOffset(file_img, 54);
    while (!feof(file_img)) {
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
        if (byte_text == 0)
            break;

        fwrite(&byte_text, sizeof(byte), 1, file_txt_output);
        //Se leggo il terminatore di stringa '\0' concludo la funzione.

    }
    fclose(file_img);
    fclose(file_txt_output);
    return NULL;
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