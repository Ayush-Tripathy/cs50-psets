#include <math.h>
#include <stdio.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1},
                    {-2, 0, 2},
                    {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1},
                    {0, 0, 0},
                    {1, 2, 1}};

    int count = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double redNewValue = 0.0;
            double greenNewValue = 0.0;
            double blueNewValue = 0.0;

            int sum_redgx = 0;
            int sum_greengx = 0;
            int sum_bluegx = 0;

            int sum_redgy = 0;
            int sum_greengy = 0;
            int sum_bluegy = 0;

            if ((i-1) >= 0 && (j-1) >= 0)
            {
                sum_redgx += (Gx[0][0] * image[i-1][j-1].rgbtRed);
                sum_greengx += (Gx[0][0] * image[i-1][j-1].rgbtGreen);
                sum_bluegx += (Gx[0][0] * image[i-1][j-1].rgbtBlue);

                sum_redgy += (Gy[0][0] * image[i-1][j-1].rgbtRed);
                sum_greengy += (Gy[0][0] * image[i-1][j-1].rgbtGreen);
                sum_bluegy += (Gy[0][0] * image[i-1][j-1].rgbtBlue);

            }
            if ((i-1) >= 0 && (j) >= 0)
            {
                sum_redgx += (Gx[0][1] * image[i-1][j].rgbtRed);
                sum_greengx += (Gx[0][1] * image[i-1][j].rgbtGreen);
                sum_bluegx += (Gx[0][1] * image[i-1][j].rgbtBlue);

                sum_redgy += (Gy[0][1] * image[i-1][j].rgbtRed);
                sum_greengy += (Gy[0][1] * image[i-1][j].rgbtGreen);
                sum_bluegy += (Gy[0][1] * image[i-1][j].rgbtBlue);

            }
            if ((i-1) >= 0 && (j+1) < width)
            {
                sum_redgx += (Gx[0][2] * image[i-1][j+1].rgbtRed);
                sum_greengx += (Gx[0][2] * image[i-1][j+1].rgbtGreen);
                sum_bluegx += (Gx[0][2] * image[i-1][j+1].rgbtBlue);

                sum_redgy += (Gy[0][2] * image[i-1][j+1].rgbtRed);
                sum_greengy += (Gy[0][2] * image[i-1][j+1].rgbtGreen);
                sum_bluegy += (Gy[0][2] * image[i-1][j+1].rgbtBlue);

            }

            if ((i) >= 0 && (j-1) >= 0)
            {
                sum_redgx += (Gx[1][0] * image[i][j-1].rgbtRed);
                sum_greengx += (Gx[1][0] * image[i][j-1].rgbtGreen);
                sum_bluegx += (Gx[1][0] * image[i][j-1].rgbtBlue);

                sum_redgy += (Gy[1][0] * image[i][j-1].rgbtRed);
                sum_greengy += (Gy[1][0] * image[i][j-1].rgbtGreen);
                sum_bluegy += (Gy[1][0] * image[i][j-1].rgbtBlue);

            }
            if ((i) >= 0 && (j) >= 0)
            {
                sum_redgx += (Gx[1][1] * image[i][j].rgbtRed);
                sum_greengx += (Gx[1][1] * image[i][j].rgbtGreen);
                sum_bluegx += (Gx[1][1] * image[i][j].rgbtBlue);

                sum_redgy += (Gy[1][1] * image[i][j].rgbtRed);
                sum_greengy += (Gy[1][1] * image[i][j].rgbtGreen);
                sum_bluegy += (Gy[1][1] * image[i][j].rgbtBlue);

            }
            if ((i) >= 0 && (j+1) < width)
            {
                sum_redgx += (Gx[1][2] * image[i][j+1].rgbtRed);
                sum_greengx += (Gx[1][2] * image[i][j+1].rgbtGreen);
                sum_bluegx += (Gx[1][2] * image[i][j+1].rgbtBlue);

                sum_redgy += (Gy[1][2] * image[i][j+1].rgbtRed);
                sum_greengy += (Gy[1][2] * image[i][j+1].rgbtGreen);
                sum_bluegy += (Gy[1][2] * image[i][j+1].rgbtBlue);

            }

            if ((i+1) < height && (j-1) >= 0)
            {
                sum_redgx += (Gx[2][0] * image[i+1][j-1].rgbtRed);
                sum_greengx += (Gx[2][0] * image[i+1][j-1].rgbtGreen);
                sum_bluegx += (Gx[2][0] * image[i+1][j-1].rgbtBlue);

                sum_redgy += (Gy[2][0] * image[i+1][j-1].rgbtRed);
                sum_greengy += (Gy[2][0] * image[i+1][j-1].rgbtGreen);
                sum_bluegy += (Gy[2][0] * image[i+1][j-1].rgbtBlue);

            }
            if ((i+1) < height && (j) >= 0)
            {
                sum_redgx += (Gx[2][1] * image[i+1][j].rgbtRed);
                sum_greengx += (Gx[2][1] * image[i+1][j].rgbtGreen);
                sum_bluegx += (Gx[2][1] * image[i+1][j].rgbtBlue);

                sum_redgy += (Gy[2][1] * image[i+1][j].rgbtRed);
                sum_greengy += (Gy[2][1] * image[i+1][j].rgbtGreen);
                sum_bluegy += (Gy[2][1] * image[i+1][j].rgbtBlue);

            }
            if ((i+1) < height && (j+1) < width)
            {
                sum_redgx += (Gx[2][2] * image[i+1][j+1].rgbtRed);
                sum_greengx += (Gx[2][2] * image[i+1][j+1].rgbtGreen);
                sum_bluegx += (Gx[2][2] * image[i+1][j+1].rgbtBlue);

                sum_redgy += (Gy[2][2] * image[i+1][j+1].rgbtRed);
                sum_greengy += (Gy[2][2] * image[i+1][j+1].rgbtGreen);
                sum_bluegy += (Gy[2][2] * image[i+1][j+1].rgbtBlue);

            }

            redNewValue = sqrt((pow(sum_redgx, 2) + pow(sum_redgy, 2)));
            if (redNewValue > 255)
            {
                //redNewValue = (redNewValue-255)/2 + 255;
                redNewValue /= 2.0;
            }
            image[i][j].rgbtRed = round(redNewValue);

            greenNewValue = sqrt((pow(sum_greengx, 2) + pow(sum_greengy, 2)));
            if (greenNewValue > 255)
            {
                //greenNewValue = (greenNewValue-255)/2 + 255;
                greenNewValue /= 2.0;
            }
            image[i][j].rgbtGreen = round(greenNewValue);

            blueNewValue = sqrt((pow(sum_bluegx, 2) + pow(sum_bluegy, 2)));
            if (blueNewValue > 255)
            {
                //blueNewValue = (blueNewValue-255)/2 + 255;
                blueNewValue /= 2.0;
            }
            image[i][j].rgbtBlue = round(blueNewValue);

            if (count < 3)
            {
                printf("%d Red: %lf\n", count+1, redNewValue);
                printf("%d Green: %lf\n", count+1, greenNewValue);
                printf("%d Blue: %lf\n", count+1, blueNewValue);
                count++;
            }

        }
    }
    return;
}
