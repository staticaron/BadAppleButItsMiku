#pragma once

#include <array>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "glad/gl.h"
#include "glfw/glfw3.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/random.hpp"
#include "spdlog/spdlog.h"

#include "Core.h"
#include "Error.h"
#include "Rendering/IndexBuffer.h"
#include "Rendering/Renderer.h"
#include "Rendering/VertexBuffer.h"