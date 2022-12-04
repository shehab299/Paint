#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind-> WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind-> WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight-15)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / (UI.MenuItemWidth+5));

			int boundary_item = (ClickedItemOrder+1) * UI.MenuItemWidth;
			int boundary_empty = boundary_item - 5;

			if(x < boundary_item && x > boundary_empty)
			return EMPTY;	
			else
			{

			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SAVE : return SAVE;
			case ITM_LOAD : return LOAD;
			case ITM_REDO : return REDO;
			case ITM_UNDO : return UNDO;
            case ITM_PLAY:  return  PLAY;
            case ITM_PAUSE: return PAUSE;
            case ITM_ADD:   return ADD;
			case ITM_SELECT :  return SELECT;
			case ITM_FILL:   return FILL;
            case ITM_COLOR:  return DCOLOR;
            case ITM_MOVE:   return MOVE; 
            case ITM_PLAY_MODE: return TO_PLAY; 
			case ITM_EXIT: return EXIT;						 
			default: return EMPTY;					//A click on empty place in desgin toolbar
			}
			}
		}
		//[3] User clicks on  ADDITIONAL ITEMSBAR
		if(y>=(UI.ToolBarHeight+1) && y< (UI.ToolBarHeight + UI.Additional_Items_Height + 1))
		{
			if(UI. Additional_Items_Mode==NOTHING)
				return EMPTY;
			else
			{
			int ClickedItemOrder = (x / (UI.MenuItemWidth+5));

			int boundary_item = (ClickedItemOrder+1) * UI.MenuItemWidth;
			int boundary_empty = boundary_item - 5;

			if(x < boundary_item && x > boundary_empty)
				return EMPTY;
			if(UI. Additional_Items_Mode==COLORS)
			{
				switch (ClickedItemOrder)
				{
			case BLACK_: return black;
			case YELLOW_ :return yellow; 
			case ORANGE_ :return orange;
			case RED_: return red;
			case GREEN_ : return green;
			case BLUE_ : return blue;
				}
			
			}
			else
			{
				switch (ClickedItemOrder)
				{
			case RECTANGLE: return rectangle;
			case CIRCLE :return circle;
			case HEXAGON : return hexagon;
			case SQUARE  : return square;
			case TRIANGLE: return triangle;   
				}		
			
			}	
			
			}		
		
		
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	
	else
	{
			//GUI is in PLAY mode
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
		switch (ClickedItemOrder)
		{
		case PLAY_COLOR:return PCOLOR;
		case PLAY_SHAPE: return PSHAPE;
		case PLAY_COLORNSHAPE : return PCOLORNSHAPE;
		case PLAY_DRAW_MODE: return TO_DRAW;
        case ITM_EXIT: return EXIT;			
		}		
		}			//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}		
		//[3] User clicks on the status bar
		return STATUS;
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
