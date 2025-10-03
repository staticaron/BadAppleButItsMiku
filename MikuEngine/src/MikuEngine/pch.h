#pragma once

#include <array>
#include <filesystem>
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
#include "stb_image.h"

#include "Core.h"
#include "Error.h"

#include "ApplicationLevelStuff.h"

#include "Managers/ImguiManager.h"
#include "Managers/TextureManager.h"

#include "Rendering/BasicQuad.h"
#include "Rendering/FrameBuffer.h"
#include "Rendering/IndexBuffer.h"
#include "Rendering/Renderer.h"
#include "Rendering/Shader.h"
#include "Rendering/ShaderHelper.h"
#include "Rendering/Texture.h"
#include "Rendering/VertexBuffer.h"
#include "Rendering/Vertices.h"

#include "Scene/Scene.h"
#include "Scene/SceneStuff.h"