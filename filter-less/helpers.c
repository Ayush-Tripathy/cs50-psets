#include <math.h>
#include <stdint.h>

#include "helpers.h"

void swapPixel(RGBTRIPLE pixel1, RGBTRIPLE pixel2);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int new_amount;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_amount = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            image[i][j].rgbtBlue = new_amount;
            image[i][j].rgbtGreen = new_amount;
            image[i][j].rgbtRed = new_amount;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = (0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sepiaGreen = (0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            sepiaBlue = (0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtBlue = round(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            int temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed =  image[i][width-j-1].rgbtRed;
            image[i][width-j-1].rgbtRed = temp;

            temp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width-j-1].rgbtGreen;
            image[i][width-j-1].rgbtGreen = temp;

            temp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width-j-1].rgbtBlue;
            image[i][width-j-1].rgbtBlue = temp;
            //swapPixel(image[i][j], image[i][width-j-1]);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = 0;
            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;
            int count = 0;
            if ((i-1) >= 0 && (j-1) >= 0)
            {
                sum_red += image[i-1][j-1].rgbtRed;
                sum_green += image[i-1][j-1].rgbtGreen;
                sum_blue += image[i-1][j-1].rgbtBlue;
                count++;
            }
            if ((i-1) >= 0 && (j) >= 0)
            {
                sum_red += image[i-1][j].rgbtRed;
                sum_green += image[i-1][j].rgbtGreen;
                sum_blue += image[i-1][j].rgbtBlue;
                count++;
            }
            if ((i-1) >= 0 && (j+1) < width)
            {
                sum_red += image[i-1][j+1].rgbtRed;
                sum_green += image[i-1][j+1].rgbtGreen;
                sum_blue += image[i-1][j+1].rgbtBlue;
                count++;
            }

            if ((i) >= 0 && (j-1) >= 0)
            {
                sum_red += image[i][j-1].rgbtRed;
                sum_green += image[i][j-1].rgbtGreen;
                sum_blue += image[i][j-1].rgbtBlue;
                count++;
            }
            if ((i) >= 0 && (j) >= 0)
            {
                sum_red += image[i][j].rgbtRed;
                sum_green += image[i][j].rgbtGreen;
                sum_blue += image[i][j].rgbtBlue;
                count++;
            }
            if ((i) >= 0 && (j+1) < width)
            {
                sum_red += image[i][j+1].rgbtRed;
                sum_green += image[i][j+1].rgbtGreen;
                sum_blue += image[i][j+1].rgbtBlue;
                count++;
            }

            if ((i+1) < height && (j-1) >= 0)
            {
                sum_red += image[i+1][j-1].rgbtRed;
                sum_green += image[i+1][j-1].rgbtGreen;
                sum_blue += image[i+1][j-1].rgbtBlue;
                count++;
            }
            if ((i+1) < height && (j) >= 0)
            {
                sum_red += image[i+1][j].rgbtRed;
                sum_green += image[i+1][j].rgbtGreen;
                sum_blue += image[i+1][j].rgbtBlue;
                count++;
            }
            if ((i+1) < height && (j+1) < width)
            {
                sum_red += image[i+1][j+1].rgbtRed;
                sum_green += image[i+1][j+1].rgbtGreen;
                sum_blue += image[i+1][j+1].rgbtBlue;
                count++;
            }

            avg = sum_red/count;
            image[i][j].rgbtRed = round(avg);

            avg = sum_green/count;
            image[i][j].rgbtGreen = round(avg);

            avg = sum_blue/count;
            image[i][j].rgbtBlue = round(avg);
        }
    }
    return;
}


void swapPixel(RGBTRIPLE pixel1, RGBTRIPLE pixel2)
{
    BYTE temp = pixel1.rgbtRed;
    pixel1.rgbtRed =  pixel2.rgbtRed;
    pixel2.rgbtRed = temp;

    temp = pixel1.rgbtGreen;
    pixel1.rgbtGreen = pixel2.rgbtGreen;
    pixel2.rgbtGreen = temp;

    temp = pixel1.rgbtBlue;
    pixel1.rgbtBlue = pixel2.rgbtBlue;
    pixel2.rgbtBlue = temp;
}