#include "Renderer.h"

#include "RenderCommand.h"

#include <stdexcept>

#include <assert.h>

namespace Robot {

	Renderer::Renderer(int sizeX, int sizeY, int fps, std::ostream& out)
		: m_SizeX(sizeX), m_SizeY(sizeY), m_Fps(fps), m_Filler(' '), m_OutStream(out), m_ScreenBuffer(std::make_shared<Buffer>(m_SizeX, m_SizeY))
	{
		std::cout << "Initialize Renderer..." << std::endl;

		if (fps > 60 || fps < 1)
		{
			throw std::runtime_error("Ungueltige FPS Anzahl! Nur Werte zwischen 1 und 60 sind erlaubt!");
		}

		if (sizeX < 1 || sizeY < 1)
		{
			throw std::runtime_error("sizeX oder sizeY ist ungueltig!");
		}
	}

	void Renderer::DrawString(const std::string& draw, int x, int y)
	{
		m_CommandQueue.push_back(Command(draw, x, y));
	}

	/**Every frame the screen buffer will be initialized with this character*/
	void Renderer::ChangeFillerCharacter(const char fillerchar)
	{
		m_Filler = fillerchar;
	}

	void Renderer::UpdateScreen()
	{
		if(!SwapBuffers()) return;

		m_BufferMutex.lock();
		RenderCommand::Draw(m_ScreenBuffer, m_SizeX, m_SizeY);
		m_BufferMutex.unlock();
	}

	bool Renderer::SwapBuffers()
	{
		if (m_DrawCommandQueue.empty()) return false;

		m_BufferMutex.lock();

		assert((*m_DrawCommandQueue.begin()) != nullptr);

		m_ScreenBuffer = (*m_DrawCommandQueue.begin());

		m_DrawCommandQueue.erase(m_DrawCommandQueue.begin());

		m_BufferMutex.unlock();

		return true;
	}

	/** Initialize the renderer*/
	void Renderer::StartRenderer()
	{
		m_Timer.ExecuteInterval([this]()
		{
			UpdateScreen();
		}, 1000 / m_Fps);
	}

	void Renderer::StopRenderer()
	{
		m_Timer.Stop();
	}

	//Just a placeholder to decomplicate the renderer
	void Renderer::BeginFrame() {}

	void Renderer::EndFrame()
	{
		std::shared_ptr<Buffer> buffer = std::make_shared<Buffer>(m_SizeX, m_SizeY);

		//Set to standard filler char
		buffer->SetMemory(m_Filler);

		//Draws the string to the array
		for (const Command& command : m_CommandQueue)
		{
			int index = command.GetX();
			int offset = 0;

			for (size_t i = 0; i < command.GetDraw().size(); i++)
			{
				if (index >= m_SizeX)
				{
					offset += index / m_SizeX;
					index = index % m_SizeX;
				}

				if (command.GetY() + offset >= m_SizeY)
				{
					throw std::runtime_error("ERROR: Bufferoverflow: The given coordinates are bigger than the buffer size - Consider that if the x coordinate is bigger than the buffers x size, it will increment the y coordinate to compensate the overflow");
					break;
				}

				(*buffer)[command.GetY() + offset][index] = command.GetDraw().at(i);

				index++;
			}
		}

		m_CommandQueue.clear();


		//Sleep if we have enough commands in the queue
		while(m_DrawCommandQueue.size() > 20)
		{
			Timer::SetTimeout(40);
		}

		m_BufferMutex.lock();

		m_DrawCommandQueue.push_back(buffer);

		m_BufferMutex.unlock();
	}

}