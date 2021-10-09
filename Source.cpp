#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <GL/glut.h>

float u = 1.00; // Scaling factor of the cube.
int angle = 1; // Spinning angle of the cube.
bool flag = true; // Boolean variable that cotnrol whether the cube is spinning (0, 0, -70) or (0, 0, -5.6).
bool temp = true; // Boolean variable that controls wheter the cube will grow or shrink.

const int rect = 1;

// Initializing a list for creating a rectangle.
void initRectList(void)
{
    // Creating a list for drawing a cube.
    glNewList(rect, GL_COMPILE);
        glBegin(GL_POLYGON);
            glVertex3f(-1, 1, 1);
            glVertex3f(1, 1, 1);
            glVertex3f(1, -1, 1);
            glVertex3f(-1, -1, 1);
        glEnd();
    glEndList();
}

// GLUT callback for window resizing
void reshape(int width, int height)
{
    // Updating viewport
    glViewport(0, 0, width, height);

    // Setting projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-42.0, 42.0, -42.0, 42.0, 100.0, 300.0);
    glMatrixMode(GL_MODELVIEW);
}

// Glut idle function for spinning the cube
void idle()
{
    glutPostRedisplay();
    // Rotating the cube
    angle += 2;
    // Growing or shrinking the cube.
    if (u < 1.00)
        temp = true;
    if (u >= 3.00)
        temp = false;
    if (temp)
        u += 0.02;
    else
        u -= 0.02;
}

// GLUT callback for window drawing
void display(void)
{
    // Clear Window
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glLoadIdentity();
    glScalef(3.5, 3.5, 3.5);
    glTranslatef(0, 0, -70);
    glutIdleFunc(idle);
    glRotatef(angle, 1.0, 2.0, 4.0);
    if (!flag)
    {
        glTranslatef(0, 0, -5.6);
        glutIdleFunc(idle);
        glRotatef(angle, 1.0, 2.0, 4.0);
    }
    glScalef(u, u, u);
    // Drawing each side of the cube.
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(0.0, 0.0, 0.0);
        glCallList(rect);
        glPopMatrix();
    glPushMatrix();
        glColor3f(0.0, 0.0, 1.0);
        glRotatef(90, 0.0, 1.0, 0.0);
        glCallList(rect);
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.0, 1.0, 0.0);
        glRotatef(-90, 0.0, 1.0, 0.0);
        glCallList(rect);
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.0, 0.9, 1.0);
        glRotatef(90, 1.0, 0.0, 0.0);
        glCallList(rect);
    glPopMatrix();
    glPushMatrix();
        glColor3f(1.0, 0.0, 1.0);
        glRotatef(-90, 1.0, 0.0, 0.0);
        glCallList(rect);
    glPopMatrix();
    glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
        glRotatef(90, 0.0, 0.0, 1);
        glTranslatef(0.0, 0.0, -2.0);
        glCallList(rect);
    glPopMatrix();

    glutSwapBuffers();
}

// GLUT callback for menu options
void MenuOptions(int selection)
{
    switch (selection)
    {
    case 1: // Rotate around (0,0,-70)
        flag = true;
        break;
    case 2: // Rotate around (0,0,-5.6)
        flag = false;
        break;
    case 3: // Shut Down
        exit(0);
    }
}

// Creating a menu
void menu()
{
    int menu;
    menu = glutCreateMenu(MenuOptions);
    glutAddMenuEntry("Rotate around (0,0,-70)", 1);
    glutAddMenuEntry("Rotate around (0,0,-5.6)", 2);
    glutAddMenuEntry("Shut Down", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Main
int main(int argc, char** argv)
{
    // Creating the main window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Spinning-Scaling Cube");

    // Setting callbacks
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // Creating the menu
    menu();

    // Initalizing the rectange list
    initRectList();

    // Starting the event processing loop
    glutMainLoop();
    return 0;
}
