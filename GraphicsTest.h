//
// Created by Cameron Hudson on 4/27/20.
//
#ifndef BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_GRAPHICSTEST_H
#define BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_GRAPHICSTEST_H
#define GL_SILENCE_DEPRECATION

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Program initialization NOT OpenGL/GLUT dependent,
// as we haven't created a GLUT window yet
void init();

// Initialize OpenGL Graphics
void InitGL();

// Callback functions for GLUT

// Draw the window - this is where all the GL actions are
void display();

// Trap and process alphanumeric keyboard events
void kbd(unsigned char key, int x, int y);

// Trap and process special keyboard events
void kbdS(int key, int x, int y);

// Handle "mouse cursor moved" events
void cursor(int x, int y);

// Calls itself after a specified time
void timer(int dummy);

// Handle mouse button pressed and released events
void mouse(int button, int state, int x, int y);

#endif //BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_GRAPHICSTEST_H
