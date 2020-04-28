
#ifndef BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_BARGRAPH_H
#define BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_BARGRAPH_H

#include <string>
#include <vector>
#include "Graphics.h"

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
    BarGraph(int startPixelx, int startPixely, int yAxisHeight, int xAxisLength, string yAxisTitle, string xAxisTitle, vector<double> uniqueStats);
    virtual void draw() const;

    int getStartPixelx();

};


#endif //BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_BARGRAPH_H
