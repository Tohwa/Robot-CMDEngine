#pragma once

namespace Robot {

	class Buffer
	{
	public:
		Buffer(int sizeX, int sizeY);
		Buffer(const Buffer& buffer);

		Buffer& operator=(const Buffer& right);

		char* operator[](int index);

		~Buffer();

		/**
		 * Set the buffer to a specified value
		 * @param c The char to fill the buffer
		 */
		void SetMemory(char c);

		int GetX();
		int GetY();

	private:
		/*Creates the buffer*/
		void Create();

		/*Deletes the buffer*/
		void Delete();

	private:
		char** m_Buffer;

		int m_SizeX, m_SizeY;
	};

}