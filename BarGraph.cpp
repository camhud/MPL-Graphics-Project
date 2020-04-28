#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif
#include "BarGraph.h"
#include<iostream>
using namespace std;


BarGraph::BarGraph(int startPixelx, int startPixely, int yAxisHeight, int xAxisLength, string yAxisTitle, string xAxisTitle, vector<double> uniqueStats){
    this->startPixelx = startPixelx;
    this->startPixely = startPixely;
    this->yAxisHeight = yAxisHeight;
    this->xAxisLength = xAxisLength;
    this->yAxisTitle = yAxisTitle;
    this->xAxisTitle = xAxisTitle;
    this->uniqueStats = uniqueStats;
    numBars = uniqueStats.size();
    int maxIndex = 0;
    for(int c = 0; c < numBars; ++c){
        if (uniqueStats[c] > uniqueStats[maxIndex]){
            maxIndex = c;
        }
    }
    maxHeight = uniqueStats[maxIndex];
}
void BarGraph::draw() const{
    //Draw x-axis
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(startPixelx, startPixely);
    glVertex2f(startPixelx + xAxisLength,  startPixely);
    glEnd();

    //Draw y-axis
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(startPixelx, startPixely);
    glVertex2f(startPixelx,  startPixely - yAxisHeight);
    glEnd();

    //calculate bar lengths and heights
    int barWidth = (xAxisLength - (2*numBars))/numBars;
    int heightMultiplier = (yAxisHeight)/maxHeight;
<<<<<<< Updated upstream
    // cout<<heightMultiplier << ", " << yAxisHeight << ", " << maxHeight << endl;
=======
    //cout<<heightMultiplier << ", " << yAxisHeight << ", " << maxHeight << endl;
>>>>>>> Stashed changes
    int leftX = startPixelx;
    int bottomY = startPixely;

    for(int c = 0; c < numBars; c++){

        leftX = leftX + 2;
        int rightX = leftX + barWidth;
        int topY = bottomY - (uniqueStats[c] * heightMultiplier);

        glBegin(GL_QUADS);
        glColor3f(0,0,1);
        // top left
        glVertex2i(leftX, topY);

        // bottom left
        glVertex2i(leftX, bottomY);

        // bottom right
        glVertex2i(rightX, bottomY);

        // top right
        glVertex2i(rightX, topY);

        glEnd();

        leftX = rightX;
    }
    int xCenter = startPixelx + (xAxisLength/2);
    int yCenter = startPixely + 15;
    glColor3f(0, 0, 0);
    glRasterPos2i(xCenter - (4 * xAxisTitle.length()), yCenter + 7);
    for (const char &letter : xAxisTitle) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }



    // Don't forget to set the color to the fill field
}