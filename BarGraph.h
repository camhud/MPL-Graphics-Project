
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
    double maxHeight;
    int yAxisHeight;
    int xAxisLength;
    string title;
    string yAxisTitle;
    string xAxisTitle;
    vector<double> uniqueStats;

public:
    //Takes in start pixel for x,y (this is where the graph will "start"). THe axis length is also inputted as will as the titles.
    //This also takes in a vector of unique stats. These unique stats are EXPECTED to be in order of tracklist, so that the first element
    //corresponds to the first song
    BarGraph(int startPixelx, int startPixely, int yAxisHeight, int xAxisLength, string title, string yAxisTitle, string xAxisTitle, vector<double> uniqueStats);
    virtual void draw() const;

    int getStartPixelx();

};


#endif //BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_BARGRAPH_H
