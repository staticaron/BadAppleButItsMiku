#shader vertex
#version 330 core
		
layout(location = 0) in vec4 position;
layout(location = 1) in vec4 tint;

out vec4 v_Tint;

uniform mat4 u_MVP;

void main()
{
	gl_Position = u_MVP * position;
	v_Tint = tint;
}

#shader fragment
#version 330 core
		
layout(location = 0) out vec4 color;

in vec4 v_Tint;

void main()
{
	color = v_Tint;
}
