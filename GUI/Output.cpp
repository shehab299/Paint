#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	UI.Additional_Items_Mode = NOTHING;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;

	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 40;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = WHITE;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids");
	
	CreateDrawToolBar();
	CreateAdditionalItemsBar(UI.Additional_Items_Mode);
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}


void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}


void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}


void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//paths for menu items
	string MenuItemImages[DRAW_ITM_COUNT];

	string PATH_ICONS_DRAW = "images\\DrawMenuItems\\";

	MenuItemImages[ITM_SAVE] = PATH_ICONS_DRAW + "saved.jpg";
	MenuItemImages[ITM_LOAD] = PATH_ICONS_DRAW + "load.jpg";
	MenuItemImages[ITM_REDO] = PATH_ICONS_DRAW + "undo.jpg";
	MenuItemImages[ITM_UNDO] = PATH_ICONS_DRAW + "redo.jpg";
	MenuItemImages[ITM_PLAY] = PATH_ICONS_DRAW + "play.jpg";
	MenuItemImages[ITM_PAUSE] = PATH_ICONS_DRAW + "pause.jpg";
	MenuItemImages[ITM_ADD] = PATH_ICONS_DRAW + "shapes.jpg";
	MenuItemImages[ITM_SELECT] = PATH_ICONS_DRAW + "select.jpg";
	MenuItemImages[ITM_FILL] = PATH_ICONS_DRAW + "fill.jpg";
	MenuItemImages[ITM_COLOR] = PATH_ICONS_DRAW + "color.jpg";
	MenuItemImages[ITM_MOVE] = PATH_ICONS_DRAW + "move.jpg";
	MenuItemImages[ITM_PLAY_MODE] = PATH_ICONS_DRAW + "playMode.jpg";
	MenuItemImages[ITM_EXIT] = PATH_ICONS_DRAW + "exit.jpg";

	//Draw menu item one image at a time
	int i;
	for (i = 0; i < ITM_EXIT; i++) {
		pWind->DrawImage(MenuItemImages[i], i * (UI.MenuItemWidth + 5) , 10 , UI.MenuItemWidth, UI.ToolBarHeight - 15);
	}
	pWind->DrawImage(MenuItemImages[i], UI.width - (UI.MenuItemWidth + 15), 10 , UI.MenuItemWidth, UI.ToolBarHeight - 15);


	//Draw a line under the toolbar
	pWind->SetPen(BLACK , 1);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}


void Output::CreateAdditionalItemsBar(ADDIONAL_MODE mode) const
{
	//paths for colors and shapes
	string COLORS_PATH = "images\\colors\\";
	string SHAPES_PATH = "images\\shapes\\";

	//draw the Bar
	pWind->SetPen(BLACK, 1);
	pWind->DrawRectangle(0, UI.ToolBarHeight + 1 , UI.width, UI.ToolBarHeight + 33 );

	//check the mode and show the suitable icons
	if(mode == COLORS)
	{
		
		string ColorsItems[COLORS_COUNT];
			ColorsItems[RED_] = COLORS_PATH + "red.jpg";
			ColorsItems[BLACK_] = COLORS_PATH + "black.jpg";
			ColorsItems[YELLOW_] = COLORS_PATH + "yellow.jpg";
			ColorsItems[BLUE_] = COLORS_PATH + "blue.jpg";

		for(int i = 0 ; i < COLORS_COUNT ; i++)
		{
			pWind->DrawImage(ColorsItems[i], i * (UI.MenuItemWidth + 5), UI.ToolBarHeight + 2, UI.MenuItemWidth, 30);
		}
	}
	else if(mode == SHAPES)
	{
		string ShapesItems[SHAPES_COUNT];
			ShapesItems[RECTANGLE] = SHAPES_PATH + "rectange.jpg";
			ShapesItems[CIRCLE] = SHAPES_PATH + "circle.jpg";
			ShapesItems[HEXAGON] = SHAPES_PATH + "hexagon.jpg";
			ShapesItems[SQUARE] = SHAPES_PATH + "square.jpg";
			ShapesItems[TRIANGLE] = SHAPES_PATH + "triangle.jpg";

		for (int i = 0; i < SHAPES_COUNT; i++)
		{
			pWind->DrawImage(ShapesItems[i], i * (UI.MenuItemWidth + 5), UI.ToolBarHeight + 2, UI.MenuItemWidth, 30);
		}
	}


}


void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	string PATH_ICONS_PLAY = "images\\PlayMenuItems\\";
	string PlayMenuItems[PLAY_ITM_COUNT];
		PlayMenuItems[PLAY_COLOR] = PATH_ICONS_PLAY + "bycolor.jpg";
		PlayMenuItems[PLAY_SHAPE] = PATH_ICONS_PLAY + "byshape.jpg";
		PlayMenuItems[PLAY_COLORNSHAPE] = PATH_ICONS_PLAY + "bycolshape.jpg";
		PlayMenuItems[PLAY_EXIT] = PATH_ICONS_PLAY + "exit.jpg";
		PlayMenuItems[PLAY_DRAW_MODE] = PATH_ICONS_PLAY + "draw_mode.jpg";
	
	//Draw menu item one image at a time
	int i;
	for (i = 0; i < ITM_EXIT; i++) {
		pWind->DrawImage(PlayMenuItems[i], i * (UI.MenuItemWidth + 5) , 10 , UI.MenuItemWidth, UI.ToolBarHeight - 15);
	}
	pWind->DrawImage(PlayMenuItems[i], UI.width - (UI.MenuItemWidth + 15), 10 , UI.MenuItemWidth, UI.ToolBarHeight - 15);


	//Draw a line under the toolbar
	pWind->SetPen(BLACK , 1);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
	
}


void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}


void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}


color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}



//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawTriangle(Point P1, Point P2,Point p3, GfxInfo triGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = triGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (triGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(triGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y,p3.x,p3.y, style);

}

void Output::DrawSqr(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	int side = 80;
	Point P2;
	Point P3;
	P2.x = P1.x - (side / 2);
	P2.y = P1.y + (side / 2);
	P3.x = P1.x + (side / 2);
	P3.y = P1.y - (side / 2);
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawRectangle(P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawCrcl(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	int deltX = pow((P1.x - P2.x), 2);
	int deltY = pow((P1.y - P2.y), 2);
	int r = sqrt(deltX + deltY);
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawCircle(P1.x, P1.y, r, style);
}



void Output::CalcHxgVer(Point Pc, int XVer[], int YVer[], int NumVer, int side) const
{
	for (int i = 0; i < NumVer; i++)
	{
		//calculate the x coordinates of the vertices
		if (i == 0 || i == 2)
			XVer[i] = Pc.x + (0.5 * side);
		else if (i == 3 || i == 5)
			XVer[i] = Pc.x - (0.5 * side);
		else if (i == 1)
			XVer[i] = Pc.x + side;
		else
			XVer[i] = Pc.x - side;


		//calculate the y coordinates of the vertices
		if (i == 0 || i == 5)
			YVer[i] = Pc.y - (0.866025 * side);
		else if (i == 3 || i == 2)
			YVer[i] = Pc.y + (0.866025 * side);
		else
			YVer[i] = Pc.y;

	}

}


void Output::DrawHxg(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	int side = 120;
	const int VerNum = 6;
	int VerX[VerNum];
	int VerY[VerNum];
	CalcHxgVer(P1, VerX, VerY, VerNum, side); //calculate the vertices of hexagon
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawPolygon(VerX, VerY, VerNum, style);
}



Output::~Output()
{
	delete pWind;
}

