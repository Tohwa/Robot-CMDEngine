#include "RenderCommand.h"

#include "Platform/Platform.h"

namespace Robot {
	
	void RenderCommand::Draw(std::shared_ptr<Buffer> buffer, int sizeX, int sizeY)
	{
		Ref<Platform> platform = Platform::get_platform();

		platform->SetTerminalSize(Vec2(sizeX, sizeY));
		platform->SetCursorPosition(Vec2(0, 0));

		std::string s;

		for (int i = 0; i < sizeY; i++)
		{
			s += std::string((*buffer)[i], (*buffer)[i] + sizeX * sizeof((*buffer)[i][0]));
			s += '\n';
		}

		printf("%s", s.c_str());
	}
}