#pragma once

#include <engine/common.hpp>
#include <engine/math/vector3.hpp>

#include <engine/graphics/opengl/buffer.hpp>
#include <engine/graphics/opengl/vertexArray.hpp>

#include <vector>

#include <GL/glew.h>

namespace pheonix {
	namespace graphics {

		enum class BlockFace
		{
			FRONT,
			BACK,
			RIGHT,
			LEFT,
			BOTTOM,
			TOP
		};

		enum class BlockType
		{
			EMPTY,
			SOLID,
		};

		class Chunk
		{
		public:
			Chunk();
			~Chunk();

			void populateChunk( unsigned int chunkSize );
			void build();
			void draw();

			void blockPlaceAt( int x, int y, int z );
			void blockDestroyAt( int x, int y, int z );
			BlockType blockExists( float x, float y, float z );

		private:
			void setChunkSize( unsigned int chunkSize );

            void blockAddFace(phoenix::Vector3* vertices, int x, int y, int z, BlockFace face);
            void blockRemoveFace(phoenix::Vector3* vertices, int x, int y, int z, BlockFace face);
			unsigned int m_shaderProgram;

			int m_chunkSize, m_vertsInChunk, m_uvsInChunk;

			glm::vec3* m_chunkVertices;

      phoenix::Vector3* m_chunkVertices;
			bool m_populated;

			opengl::VertexArray* m_vao;
			opengl::Buffer* m_vbo;
			opengl::Buffer* m_uvbo;

			const int vertInCube = 36;
			const int uvInCube = 36;

			/// @brief 3-Dimensional Array of vector inside vector inside vector,
			/// for an overall layout like m_chunkBlocks[x][y][z]
			std::vector< std::vector< std::vector< BlockType > > > m_chunkBlocks;
		};

	}
}
