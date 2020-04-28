//
// Created by Cameron Hudson on 4/27/20.
//
#include "Button.h"
#include "Graphics.h"
#include <iostream>
using namespace std;

Button::Button(color fill, point center, unsigned int width, unsigned int height, std::string label) : Quad(fill, center, width, height) {
    this->label = label;
    originalFill = fill;
    hoverFill = {fill.red + 0.5, fill.green + 0.5, fill.blue + 0.5};
    pressFill = {fill.red - 0.5, fill.green - 0.5, fill.blue - 0.5};
}

void Button::draw() const {
    Quad::draw();
    glColor3f(0, 0, 0);
    glRasterPos2i(center.x - (4 * label.length()), center.y + 7);
    for (const char &letter : label) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }
}

/* Returns true if the coordinate is inside the box */
bool Button::isOverlapping(int x, int y) const {
    if((x > getLeftX() && x < getRightX()) && (y > getTopY() && y < getBottomY())) {
        return true;
    }
    return false; // Placeholder for compilation
}

/* Change color of the box when the user is hovering over it */
void Button::hover() {
    setColor(hoverFill);
}

/* Change color of the box when the user is clicking on it */
void Button::pressDown() {
    setColor(pressFill);
    try {
        artistAlbum();
    } catch (...) {
        cout << "Something went wrong, please make sure everything is spelled correctly." << endl;
    }

}

/* Change the color back when the user is not clicking/hovering */
void Button::release() {
    setColor(originalFill);
}