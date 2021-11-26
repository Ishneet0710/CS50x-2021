#include "helpers.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i < height; i++){
        for(int j=0; j<width; j++){
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;
            int avg = round(((float)red + (float)blue + (float)green)/3);
            image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i< height; i++){
        for(int j=0; j<width; j++){
            int oblue = image[i][j].rgbtBlue;
            int ogreen = image[i][j].rgbtGreen;
            int ored = image[i][j].rgbtRed;
            int nred = round(0.393 * ored + 0.769 * ogreen + 0.189 * oblue);
            int ngreen = round(0.349 * ored + 0.686 * ogreen + 0.168 * oblue);
            int nblue = round(0.272 * ored + 0.534 * ogreen + 0.131 * oblue);
            if(nred>255){
                image[i][j].rgbtRed = 255;
            }
            else{
                image[i][j].rgbtRed = nred;
            }

            if(ngreen>255){
                image[i][j].rgbtGreen = 255;
            }
            else{
                image[i][j].rgbtGreen = ngreen;
            }

            if(nblue>255){
                image[i][j].rgbtBlue = 255;
            }
            else{
                image[i][j].rgbtBlue = nblue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++){
        for(int j=0;j<(width/2);j++){
            RGBTRIPLE temporary = image[i][j];
            image[i][j] = image[i][width-(j+1)];
            image[i][width-(j+1)] = temporary;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sBlue;
    int sGreen;
    int sRed;
    float counter;
    //create a temporary table of colors to not alter the calculations
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sBlue = 0;
            sGreen = 0;
            sRed = 0;
            counter = 0.00;

            // sums values of the pixel and 8 neighboring ones, skips iteration if it goes outside the pic
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    sBlue += image[j + k][i + h].rgbtBlue;
                    sGreen += image[j + k][i + h].rgbtGreen;
                    sRed += image[j + k][i + h].rgbtRed;
                    counter++;
                }
            }

            // averages the sum to make picture look blurrier
            temp[j][i].rgbtBlue = round(sBlue / counter);
            temp[j][i].rgbtGreen = round(sGreen / counter);
            temp[j][i].rgbtRed = round(sRed / counter);
        }
    }

    //copies values from temporary table
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
}
