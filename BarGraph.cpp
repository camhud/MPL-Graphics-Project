
#include "BarGraph.h"

BarGraph::BarGraph() {

}
BarGraph::BarGraph(int startPixelx, int startPixely, int maxHeight, int yAxisHeight, int xAxisLength, int yAxisLength, string yAxisTitle, string xAxisTitle, vector<double> uniqueStats){
    this->startPixelx = startPixelx;
    this->startPixely = startPixely;
    this->maxHeight = maxHeight;
    this->yAxisHeight = yAxisHeight;
    this->xAxisLength = xAxisLength;
    this->yAxisTitle = yAxisTitle;
    this->xAxisTitle = xAxisTitle;
    this->uniqueStats = uniqueStats;
    numBars = uniqueStats.size();
}
void BarGraph::drawGraph() {
    glBegin(GL_QUADS);
    glColor3f(getRed(), getGreen(), getBlue());
    // top left
    glVertex2i(getLeftX(), getTopY());

    // bottom left
    glVertex2i(getLeftX(), getBottomY());

    // bottom right
    glVertex2i(getRightX(), getBottomY());

    // top right
    glVertex2i(getRightX(), getTopY());

    glEnd();
    // Don't forget to set the color to the fill field
}