#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "Buffer.h"

namespace Robot {


	class RenderCommand
	{
	public:

		/**
		 * Draws a buffer to the screen
		 * @param buffer The buffer to be drawn
		 * @param sizeX The size of the buffer (To define possible sub regions)
		 * @param sizeY The size of the buffer (To define possible sub regions)
		 * @param stream The stream to drawn on
		 */
		static std::ostream& Draw(std::shared_ptr<Buffer> buffer, int sizeX, int sizeY, std::ostream& stream);
	};

}
