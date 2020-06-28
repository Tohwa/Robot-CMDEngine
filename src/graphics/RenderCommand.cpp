#include "RenderCommand.h"

namespace Robot {
	
	std::ostream& RenderCommand::Draw(std::shared_ptr<Buffer> buffer, int sizeX, int sizeY, std::ostream& stream)
	{
		std::string s;

		for (int i = 0; i < sizeY; i++)
		{
			s += std::string((*buffer)[i], (*buffer)[i] + sizeX * sizeof((*buffer)[i][0]));
			s += '\n';
		}

		stream << s;

		return stream;
	}
}