#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

 
int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Usage: ./recover image\n");
        return 1;
    }
    else{
        FILE *input = fopen(argv[1], "r");
        if(input==NULL){
            printf("Error: File Cannot Be Opened");
            return 1;
        }
        BYTE buffer[512];
        char filename[8];
        int count=0;
        FILE *pointer = NULL;
        while(fread(&buffer, 512, 1, input)==1){
            if(buffer[0]== 0xff && buffer[1]== 0xd8 && buffer[2]== 0xff && (buffer[3] & 0xf0) == 0xe0){
                if(count != 0){
                fclose(pointer);
                }
            sprintf(filename, "%03i.jpg", count);
            pointer = fopen(filename, "w");
            count++;
            }
            if(count != 0){
                fwrite(&buffer, 512, 1, pointer);
            }
    }
    fclose(pointer);
    fclose(input);
    return 0;
    }
    
}