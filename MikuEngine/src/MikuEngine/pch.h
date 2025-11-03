#pragma once

#include <algorithm>
#include <array>
#include <filesystem>
#include <fmod.hpp>
#include <fstream>
#include <iostream>
#include <memory>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "glad/gl.h"

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "GLFW/glfw3.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/random.hpp"
#include "imgui.h"
#include "spdlog/spdlog.h"

#include "Core.h"
#include "Error.h"

#include "Application.h"
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

#include "Data/DataContainer.h"
