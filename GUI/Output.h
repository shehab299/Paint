#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreateAdditionalItemsBar(ADDIONAL_MODE) const; // creates Additonal Items  menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawTriangle(Point p1, Point p2, Point p3, GfxInfo triGfxInfo, bool selected = false) const;//Draw triangle
	void DrawSqr(Point P1, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a square with a default side =80
	void DrawCrcl(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a circle
	void DrawHxg(Point P1, GfxInfo RectGfxInfo, bool selected = false) const;	//Draw a hexagon with a default side =120
	void CalcHxgVer(Point Pc, int XVer[], int YVer[], int NumVer, int side) const; // calcuate the X & Y coordinates of hexagon vertices 

	///Make similar functions for drawing all other figure types.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	
	~Output();
};

#endif
