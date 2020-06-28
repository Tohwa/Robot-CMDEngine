#pragma once

#include <vector>
#include <string>
#include <memory>
#include <mutex>
#include <iostream>

#include "Timer.h"
#include "Buffer.h"


namespace Robot
{

	//A String to draw
	struct Command
	{
		Command(const std::string& draw, int x, int y)
			: m_X(x), m_Y(y), m_Draw(draw) {}

		int GetX() const { return m_X; }
		int GetY() const { return m_Y; }

		std::string GetDraw() const { return m_Draw; }

	private:

		int m_X, m_Y;
		std::string m_Draw;
	};

	class Renderer
	{
	
	public:
		Renderer(int sizeX, int sizeY, int fps, std::ostream& out);

		void DrawString(const std::string& draw, int x, int y);

		void ChangeFillerCharacter(const char fillerchar);

		void StartRenderer();

		void StopRenderer();

		void BeginFrame();
		void EndFrame();

	private:
		void UpdateScreen();

		bool SwapBuffers();
	private:

		int m_SizeX;
		int m_SizeY;

		int m_Fps;

		char m_Filler;

		std::ostream& m_OutStream;

		//Mutex lock needed
		std::shared_ptr<Buffer> m_ScreenBuffer;

	private:
		std::vector<Command> m_CommandQueue;

		Timer m_Timer;

		std::mutex m_BufferMutex;

		//Mutex lock needed
		std::vector<std::shared_ptr<Buffer>> m_DrawCommandQueue;
	};
}
