
#include "BarGraph.h"
#include "Graphics.h"

BarGraph::BarGraph() {

}
BarGraph::BarGraph(int startPixelx, int startPixely, int yAxisHeight, int xAxisLength, int yAxisLength, string yAxisTitle, string xAxisTitle, vector<double> uniqueStats){
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
    maxHeight = maxIndex;
}
void BarGraph::drawGraph() {
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
    glVertex2f(startPixelx,  startPixely + yAxisHeight);
    glEnd();



    // Don't forget to set the color to the fill field
}