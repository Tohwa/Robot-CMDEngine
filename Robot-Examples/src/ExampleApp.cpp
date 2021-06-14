#include <RobotAPI.h>

int main()
{
	//Create an renderer object - Xsize, Ysize, FPS, output stream
	Robot::Renderer renderer(60, 29, 30, std::cout);

	//Sets the character to init the buffer
	renderer.ChangeFillerCharacter('T');

	//Starts the async renderer
	renderer.StartRenderer();

	Robot::Vec2 robotPos(2, 0);

	bool increase = true;

	//Just a simple key detection - Remember, with a low fps rate its unlikely that the key press gets detected
	//To overcome this problem you should use some key event system or buffer the key inputs somehow.
	while (!Robot::Input::IsKeyPressed(ROBOT_KEY_ESC))
	{
		//To begin a new frame - Is a placeholder function, to visualize the structure better.
		renderer.BeginFrame();

		//Draws a string to the scene
		renderer.DrawString("R", robotPos.x, robotPos.y);
		renderer.DrawString("R", robotPos.x, robotPos.y + 2);
		renderer.DrawString("R", robotPos.x, robotPos.y + 4);
		renderer.DrawString("R", robotPos.x, robotPos.y + 6);
		renderer.DrawString("R", robotPos.x, robotPos.y + 8);
		renderer.DrawString("R", robotPos.x, robotPos.y + 10);
		renderer.DrawString("R", robotPos.x, robotPos.y + 12);
		renderer.DrawString("R", robotPos.x, robotPos.y + 14);
		renderer.DrawString("R", robotPos.x, robotPos.y + 16);
		renderer.DrawString("R", robotPos.x, robotPos.y + 18);
		renderer.DrawString("R", robotPos.x, robotPos.y + 20);
		renderer.DrawString("R", robotPos.x, robotPos.y + 22);
		renderer.DrawString("R", robotPos.x, robotPos.y + 24);
		renderer.DrawString("R", robotPos.x, robotPos.y + 26);
		renderer.DrawString("R", robotPos.x, robotPos.y + 28);

		//Generates the buffer and commits the command to the async renderer - The renderer runs normally 20 frames behind.
		renderer.EndFrame();

		if (robotPos.x != 59 && increase)
		{
			robotPos.x++;
		}
		else if(robotPos.x == 59 && increase)
		{
			robotPos.x--;
			increase = false;
		}
		else if (robotPos.x != 0 && !increase)
		{
			robotPos.x--;
		}
		else if (robotPos.x == 0 && !increase)
		{
			robotPos.x++;
			increase = true;
		}
	}

	//Stops the async renderer by the next frame
	renderer.StopRenderer();
}

