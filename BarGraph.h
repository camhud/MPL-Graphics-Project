
#ifndef BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_QUAD_H
#define BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_QUAD_H

#include "Quad.h"
#include <string>
#include <vector>

using namespace std;
class BarGraph {
protected:
    int startPixelx;
    int startPixely;
    int numBars;
    int maxHeight;
    int yAxisHeight;
    int xAxisLength;
    string yAxisTitle;
    string xAxisTitle;
    vector<double> uniqueStats;

public:
    BarGraph();
    BarGraph(int startPixelx, int startPixely, int yAxisHeight, int xAxisLength, int yAxisLength, string yAxisTitle, string xAxisTitle, vector<double> uniqueStats);
    void drawGraph();

};


#endif //BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_QUAD_H
