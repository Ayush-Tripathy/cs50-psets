#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int BLOCK_SIZE = 512; //size of one block on card.

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

    uint8_t buffer[BLOCK_SIZE];
    int count = 0;
    char *filename = malloc(8 * sizeof(char));
    FILE *image = NULL;
    while (fread(buffer, sizeof(uint8_t), BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count == 0)
            {
                image = fopen("000.jpg", "w");
                if (image == NULL)
                {
                    printf("Could not create file.\n");
                    return 3;
                }

                fwrite(buffer, sizeof(uint8_t), BLOCK_SIZE, image);
                count++;
            }
            else
            {
                fclose(image);

                sprintf(filename, "%03i.jpg", count);
                image = fopen(filename, "w");
                if (image == NULL)
                {
                    printf("Could not create file.\n");
                    return 3;
                }

                fwrite(buffer, sizeof(uint8_t), BLOCK_SIZE, image);
                count++;
            }
        }
        else if (image != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), BLOCK_SIZE, image);
        }
    }
    free(filename);
    fclose(image);
}