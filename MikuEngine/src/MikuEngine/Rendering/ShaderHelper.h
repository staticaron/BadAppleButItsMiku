#pragma once

#include "Core.h"
#include "pch.h"

namespace MikuEngine {
class ShaderParser {
public:
  static void ParseShader(const std::string &filePath,
                          std::string &vertexShader,
                          std::string &fragmentShader) {
    enum class ShaderType { NONE = -1, VERTEX = 0, FRAGMENT = 1 };

    std::ifstream stream(filePath);

    if (!stream.is_open()) {
      spdlog::error("Unable to open shader file at {}", filePath);
      return;
    }

    ShaderType shaderType = ShaderType::NONE;
    std::stringstream ss[2];

    std::string line;
    while (std::getline(stream, line)) {
      if (line.find("#shader") != std::string::npos) {
        if (line.find("vertex") != std::string::npos)
          shaderType = ShaderType::VERTEX;
        else if (line.find("fragment") != std::string::npos)
          shaderType = ShaderType::FRAGMENT;
      } else {
        ss[(int)shaderType] << line << "\n";
      }
    }

    vertexShader = ss[0].str();
    fragmentShader = ss[1].str();
  }

  static unsigned int CompileShader(const std::string &source,
                                    unsigned int type) {
    unsigned int shaderID = glCreateShader(type);
    const char *src = source.c_str();

    glShaderSource(shaderID, 1, &src, nullptr);
    glCompileShader(shaderID);

    int result = 0;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
      int length;
      glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);

      char *message = (char *)alloca(length * sizeof(char));
      glGetShaderInfoLog(shaderID, length, &length, message);

      spdlog::error("FAILED TO COMPILE {0} SHADER | {1}",
                    type == GL_VERTEX_SHADER ? "Vertex" : "Fragment", message);
      return 0;
    }

    return shaderID;
  }

  static unsigned int CreateShader(const std::string &vertexShader,
                                   const std::string &fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(vertexShader, GL_VERTEX_SHADER);
    unsigned int fs = CompileShader(fragmentShader, GL_FRAGMENT_SHADER);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
  }
};
} // namespace MikuEngine
