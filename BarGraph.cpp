#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif
#include "BarGraph.h"
#include<iostream>
using namespace std;


BarGraph::BarGraph(int startPixelx, int startPixely, int yAxisHeight, int xAxisLength, string title, string yAxisTitle, string xAxisTitle, vector<double> uniqueStats){
    this->startPixelx = startPixelx;
    this->startPixely = startPixely;
    this->yAxisHeight = yAxisHeight;
    this->xAxisLength = xAxisLength;
    this->title = title;
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

    int leftX = startPixelx;
    int bottomY = startPixely;
    // draws the bars of the bar graph
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

    //Draws x-axis title
    int xCenterTitle = startPixelx + (xAxisLength/2);
    int yCenterTitle = startPixely - yAxisHeight - 15;
    glColor3f(0, 0, 0);
    glRasterPos2i(xCenterTitle - (4 * title.length()), yCenterTitle - 15);
    for (const char &letter : title) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }

    //Draws x-axis title
    int xCenter = startPixelx + (xAxisLength/2);
    int yCenter = startPixely + 15;
    glColor3f(0, 0, 0);
    glRasterPos2i(xCenter - (4 * xAxisTitle.length()), yCenter + 7);
    for (const char &letter : xAxisTitle) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }

    //Draws y-axis title
    int xCenterYTitle = startPixelx - 5*(yAxisTitle.length()) - 7;
    int yCenterYTitle = startPixely - (yAxisHeight/2);
    glColor3f(0, 0, 0);
    glRasterPos2i(xCenterYTitle - (4 * yAxisTitle.length()), yCenterYTitle);
    for (const char &letter : yAxisTitle) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }


    // Don't forget to set the color to the fill field
}