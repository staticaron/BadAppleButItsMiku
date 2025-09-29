#pragma once

#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "glad/gl.h"
#include "glfw/glfw3.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/random.hpp"
#include "imgui.h"
#include "spdlog/spdlog.h"

#include "Managers/ImguiManager.h"

#include "Camera/Camera.h"
#include "Core.h"
#include "Error.h"
#include "Rendering/BasicQuad.h"
#include "Rendering/IndexBuffer.h"
#include "Rendering/Renderer.h"
#include "Rendering/Shader.h"
#include "Rendering/ShaderHelper.h"
#include "Rendering/VertexBuffer.h"
#include "Rendering/Vertices.h"
#include "Scene/SceneLevelValues.h"