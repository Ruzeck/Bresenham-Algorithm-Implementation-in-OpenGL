#include<GL/glut.h>
#include<bits/stdc++.h> 
#include <GL/gl.h>
#include <math.h>
#include <stdio.h>
#include<cstring>

using namespace std;
void bresenham();
void display();
void reshape(int,int);
float x1,y3,x2,y2;
int check=0;
string s = "Ruzeck";
float m;
char s1[50];

void name()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	if(0<m && m<1)
	{
	        glColor3f(1.0,1.0,1.0);
		glRasterPos2f(200,10);
    		int n = s.size();
    		for(int i=0;i<n;i++)
        		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
        
        	sprintf(s1, "SLOPE = %f", m);
        
    		glRasterPos2f(100,50);
    		n = 50;
    		for(int i=0;i<n;i++)
        	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s1[i]);
        	
        	glEnd();
    		glFlush();
    		glutSwapBuffers();
	}
	
	if(m>1)
	{
		glColor3f(1.0,1.0,1.0);
		glRasterPos2f(200,10);
    		int n = s.size();
    		for(int i=0;i<n;i++)
        		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
        
        	sprintf(s1, "SLOPE = %f", m);
        
    		glRasterPos2f(100,50);
    		n = 50;
    		for(int i=0;i<n;i++)
        	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s1[i]);
        	
        	glEnd();
    		glFlush();
    		glutSwapBuffers();
	} 

	if(0>m && m>-1)
	{
	        glColor3f(1.0,1.0,1.0);
		glRasterPos2f(200,10);
    		int n = s.size();
    		for(int i=0;i<n;i++)
        		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
        
        	sprintf(s1, "SLOPE = %f", m);
        
    		glRasterPos2f(100,50);
    		n = 50;
    		for(int i=0;i<n;i++)
        	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s1[i]);
        	
        	glEnd();
    		glFlush();
    		glutSwapBuffers();
	}

	if(m<-1)
	{
	        glColor3f(1.0,1.0,1.0);
		glRasterPos2f(200,10);
    		int n = s.size();
    		for(int i=0;i<n;i++)
        		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
        
        	sprintf(s1, "SLOPE = %f", m);
        
    		glRasterPos2f(100,50);
    		n = 50;
    		for(int i=0;i<n;i++)
        	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s1[i]);
        	
        	glEnd();
    		glFlush();
    		glutSwapBuffers();
	}
  }

void putpixel(int x, int y)
{
	if(0<m && m<1)
	{
	        glColor3f(0.0,1.0,1.0);
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		glFlush();
	}
	
	if(m>1)
	{
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		glFlush();
	} 

	if(0>m && m>-1)
	{
	        glColor3f(1.0,0.0,1.0);
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		glFlush();
	}

	if(m<-1)
	{
	        glColor3f(1.0,1.0,0.0);
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		glFlush();
	}
}

void bresenham()
{
	if(x1>x2)
	{
		float temp;
		temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y3;
		y3 = y2;
		y2 = temp;
	}
	
	int x = x1, y = y3;
	int dx = x2-x1;
	int dy = y2-y3;
	int dT = 2*(dy-dx);
	int dS = 2*dy;
	int d = 2*dy-dx;	
	
	name();
	putpixel(x,y);
	
	while(x<x2)
	{
		x++;
		if(d<0)
		{
			d = d+dS;
		}
		else
		{
			d = d+dT;
			y++;
		}

		putpixel(x,y);
	}

	putpixel(x2,y2);
}

void bresenham2()
{
	if(x1>x2)
	{
		float temp;
		temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y3;
		y3 = y2;
		y2 = temp;
	}
	
	int x = x1, y = y3;
	int dx = x2-x1;
	int dy = y2-y3;
	int dT = 2*(dy+dx);
	int dS = 2*dy;
	int d = -(2*dx+dy);	

	name();
	putpixel(x,y);

	while(x<x2)
	{
		x++;
		if(d<0)
		{
			d = d-dS;
		}
		else
		{
			y--;
			d = d-dT;
		}

		putpixel(x,y);
	}

	putpixel(x2,y2);
}

void bresenham3()
{
	if(y3>y2)
	{
		float temp;
		temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y3;
		y3 = y2;
		y2 = temp;
	}

	int x = x1, y = y3;
	int dx = x2-x1;
	int dy = y2-y3;
	int dT = 2*(dx-dy);
	int dS = 2*dx;
	int d = 2*dx-dy;	
	
	name();
	putpixel(x,y);

	while(y<y2)
	{
		y++;
		if(d<0)
		{
			d = d+dS;
		}
		else
		{
			x++;
			d = d+dT;
		}

		putpixel(x,y);
	}
	putpixel(x2,y2);
}

void bresenham4()	
{
	if(y3>y2)
	{
		float temp;
		temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y3;
		y3 = y2;
		y2 = temp;
	}

	int x = x1, y = y3;
	int dx = x2-x1;
	int dy = y2-y3;
	int dT = 2*(dy+dx);
	int dS = 2*dx;
	int d = -(2*dy+dx);	

	name();
	putpixel(x,y);
	while(y<y2)
	{
		y++;
		if(d<0)
		{
			d = d-dS;
		}
		else
		{
			x--;
			d = d-dT;
		}
		putpixel(x,y);
	}
	putpixel(x2,y2);
}

void mouseCB(int button, int state, int x, int y)
{	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(check==0)
		{
			x1 = x;
			y3 = 500-y;
			check = 1;
		}

		else if(check==1)
		{
			x2 = x;
			y2 = 500-y;
			check = 0;

			
			m = (y2-y3)/(x2-x1);

			bresenham();
		}
	}
}
  

void displayCB()
{
    
    
    
   glutMouseFunc(mouseCB);
    
     name();

}
void init()
{
    glClearColor(1.0,0.0,0.0,1.0);

}
    void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);

    glutCreateWindow("Line Generation using Bresenhams Algorithm");

    glutDisplayFunc(displayCB);
    glutReshapeFunc (reshape);
    
    init();
      
      
    glutMainLoop();

}
