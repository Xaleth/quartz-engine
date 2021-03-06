// Copyright 2019 Genten Studios
// 
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the 
// following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the 
// following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the 
// following disclaimer in the documentation and/or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote 
// products derived from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED 
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY 
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH 
// DAMAGE.

#pragma once

#include <quartz/core/Core.hpp>
#include <quartz/core/math/Math.hpp>
#include <quartz/core/graphics/API/gl/GLCommon.hpp>
#include <quartz/core/graphics/API/IShaderPipeline.hpp>

#include <vector>
#include <string>

namespace qz
{
	namespace gfx
	{
		namespace api
		{
			namespace gl
			{
				class QZ_API GLShaderPipeline : public IShaderPipeline
				{
				public:
					GLShaderPipeline();
					~GLShaderPipeline();

					GLShaderPipeline(const GLShaderPipeline& o) = default;
					GLShaderPipeline& operator=(const GLShaderPipeline& o) = default;

					GLShaderPipeline(GLShaderPipeline&& o) noexcept;
					GLShaderPipeline& operator=(GLShaderPipeline&& o) noexcept;

					void addStage(ShaderType stage, const std::string& shaderSource) override;
					void build() override;

					void use() const override;

					void setUniform1(const std::string& name, int a) const override;
					void setUniform2(const std::string& name, int a, int b) const override;
					void setUniform3(const std::string& name, int a, int b, int c) const override;
					void setUniform4(const std::string& name, int a, int b, int c, int d) const override;

					void setUniform1(const std::string& name, float a) const override;
					void setUniform2(const std::string& name, float a, float b) const override;
					void setUniform3(const std::string& name, float a, float b, float c) const override;
					void setUniform4(const std::string& name, float a, float b, float c, float d) const override;

					void setVec2(const std::string& name, const Vector2& data) const override;
					void setVec3(const std::string& name, const Vector3& data) const override;
					void setMat4(const std::string& name, const Matrix4x4& mat) const override;

					void bindAttributeLocation(const std::string& attribName, int index) override;
					int retrieveAttributeLocation(const std::string& attribName) override;

				private:
					unsigned int m_id;

					std::vector<unsigned int> m_shaders;
				};
			}
		}
	}
}

