#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x, y;

	//Create Input and Output objects to test
	Output* pOut = new Output();
	Input* pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	GfxInfo gfxInfo_non_fill;//to be used with draw function of the class Ouput
	GfxInfo gfxInfo_fill;
	Point P1, P2, P3;

	gfxInfo_non_fill.BorderWdth = UI.PenWidth;
	gfxInfo_non_fill.DrawClr = BLACK;	//any color for border
	gfxInfo_non_fill.isFilled = false;	//Figure is NOT filled

	gfxInfo_fill.BorderWdth = UI.PenWidth;
	gfxInfo_fill.DrawClr = BLACK;
	gfxInfo_fill.FillClr = UI.FillColor;
	gfxInfo_fill.isFilled = true;//Figure is filled	

	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);


	pOut->DrawRect(P1, P2, gfxInfo_non_fill, false);

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo_non_fill, true);


	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);


	pOut->DrawRect(P1, P2, gfxInfo_fill, false);


	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo_fill, true);



	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();
	/// 2.2- Square Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Square, normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///TODO: Add code to draw Square, Normal and Highlighted



	// 2.2.1 - Drawing non-filled square
	pOut->PrintMessage("Drawing a Square ==> non-filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);


	pOut->DrawSqr(P1, gfxInfo_non_fill, false);

	// 2.2.2 - Drawing highlighted non-filled square
	pOut->PrintMessage("Drawing a Square ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawSqr(P1, gfxInfo_non_fill, true);


	// 2.2.3 - Drawing a filled square
	pOut->PrintMessage("Drawing a Square ==> filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);


	pOut->DrawSqr(P1, gfxInfo_fill, false);


	// 2.2.4 - Drawing a highlighted filled square
	pOut->PrintMessage("Drawing a Square ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawSqr(P1, gfxInfo_fill, true);


	pOut->PrintMessage("Drawing a Square Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();


	// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	//2.3.1-Drawing non-filled Triangle
	pOut->PrintMessage("Drawing a Triangle ==> non-filled,  Click three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);


	pOut->DrawTriangle(P1, P2, P3, gfxInfo_non_fill, false);

	//2.3.2-Drawing highlighted non-filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawTriangle(P1, P2, P3, gfxInfo_non_fill, true);

	//2.3.3-Drawing a filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> filled,  Click three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);


	pOut->DrawTriangle(P1, P2, P3, gfxInfo_fill, false);

	//2.3.4-Drawing a highlited filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawTriangle(P1, P2, P3, gfxInfo_fill, true);

	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();


	/// 2.4- Hexagon Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Hexagon, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Hexagon in all possible states


	// 2.4.1 - Drawing non-filled Hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> non-filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);


	pOut->DrawHxg(P1, gfxInfo_non_fill, false);

	// 2.4.2 - Drawing highlighted non-filled Hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawHxg(P1, gfxInfo_non_fill, true);


	// 2.4.3 - Drawing a filled Hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);


	pOut->DrawHxg(P1, gfxInfo_fill, false);


	// 2.4.4 - Drawing a highlighted filled Hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawHxg(P1, gfxInfo_fill, true);



	pOut->PrintMessage("Drawing a Hexagon Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();



	/// 2.5- Circle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing an Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Circle in all possible states


	// 2.5.1 - Drawing non-filled circle
	pOut->PrintMessage("Drawing a Cirle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);


	pOut->DrawCrcl(P1, P2, gfxInfo_non_fill, false);

	// 2.5.2 - Drawing highlighted non-filled circle
	pOut->PrintMessage("Drawing a Circle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawCrcl(P1, P2, gfxInfo_non_fill, true);


	// 2.5.3 - Drawing a filled circle
	pOut->PrintMessage("Drawing a Circle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);


	pOut->DrawCrcl(P1, P2, gfxInfo_fill, false);


	// 2.5.4 - Drawing a highlighted filled circle
	pOut->PrintMessage("Drawing a Circle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawCrcl(P1, P2, gfxInfo_fill, true);



	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("Testing Input ability to read strings");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the string clear the status bar
	// 3- print on the status bar "You Entered" then pri-nt the string

	pOut->PrintMessage("Please input a string, then click anywhere to continue : ");
	pIn->GetSrting(pOut);


	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction(pOut);
		//pOut->PrintMessage(to_string(UI.Additional_Items_Mode));
		switch (ActType)
		{
		case rectangle:
			pOut->PrintMessage("Action: Draw a Rectangle , Click anywhere");
			break;
		case triangle:
			pOut->PrintMessage("Action: Draw a Triangle , Click anywhere");
			break;
		case circle:
			pOut->PrintMessage("Action: Draw a Circle , Click anywhere");
			break;
		case hexagon:
			pOut->PrintMessage("Action: Draw a Hexagon , Click anywhere");
			break;
		case square:
			pOut->PrintMessage("Action: Draw a Square , Click anywhere");
			break;
		case red:
			pOut->PrintMessage("Action: choose Red , Click anywhere");
			break;
		case blue:
			pOut->PrintMessage("Action: choose Blue , Click anywhere");
			break;
		case yellow:
			pOut->PrintMessage("Action: choose Yellow , Click anywhere");
			break;
		case orange:
			pOut->PrintMessage("Action: choose Orange , Click anywhere");
			break;
		case black:
			pOut->PrintMessage("Action: choose Black , Click anywhere");
			break;
		case green:
			pOut->PrintMessage("Action: choose Green , Click anywhere");
			break;
		case SAVE:
			pOut->PrintMessage("Action: Save Figure , Click anywhere");
			break;
		case LOAD:
			pOut->PrintMessage("Action: Load Figure , Click anywhere");
			break;
		case UNDO:
			pOut->PrintMessage("Action: Undo Action , Click anywhere");
			break;
		case REDO:
			pOut->PrintMessage("Action: Redo Action , Click anywhere");
			break;
		case PLAY:
			pOut->PrintMessage("Action: Play Audio , Click anywhere");
			break;
		case PAUSE:
			pOut->PrintMessage("Action: Pause Audio , Click anywhere");
			break;
		case ADD:
			pOut->CreateAdditionalItemsBar(SHAPES);
			pOut->PrintMessage("Action: Add Figure , Click anywhere");
			break;
		case SELECT:
			pOut->PrintMessage("Action: Select Figure , Click anywhere");
			break;
		case FILL:
			pOut->PrintMessage("Action: Fill Figure , Click anywhere");
			pOut->CreateAdditionalItemsBar(COLORS);
			break;
		case DCOLOR:
			pOut->PrintMessage("Action: choose Color , Click anywhere");
			pOut->CreateAdditionalItemsBar(COLORS);
			break;
		case MOVE:
			pOut->PrintMessage("Action: Move Figure , Click anywhere");
			break;
		case PCOLOR:
			pOut->PrintMessage("Action: PLAY MODE COLORS , Click anywhere");
			break;
		case PSHAPE:
			pOut->PrintMessage("Action: PLAY MODE SHAPES , Click anywhere");
			break;
		case PCOLORNSHAPE:
			pOut->PrintMessage("Action: PLAY MODE COLORS AND SHAPES , Click anywhere");
			break;
		case STATUS:
			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
			break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;

		case TO_DRAW:
			pOut->PrintMessage("Action: Switch to Draw Mode, creating Draw tool bar");
			pOut->CreateDrawToolBar();
			break;

		case TO_PLAY:
			pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
			pOut->CreatePlayToolBar();
			break;
		case EXIT:
			pOut->PrintMessage("Action: Exit");

			///TODO: Add more cases for the other action types
		case EXIT_PLAY:
			pOut->PrintMessage("Action: Exit");


		}
	} while (ActType!=EXIT);


	/// Exiting
	pIn->GetPointClicked(x, y);


	delete pIn;
	delete pOut;
	return 0;
}



