#shader vertex
#version 330 core

layout(location = 0) in vec4 position;

void main()
{
	gl_Position = position;
}

#shader geometry
#version 330 core

layout(points) in;
layout(triangle_strip, max_vertices = 4) out;

out vec2 v_UV;

uniform mat4 u_MVP = mat4(1.0);
uniform float u_QuadWidth = 0.0;

void main()
{
	gl_Position = gl_in[0].gl_Position + u_MVP * vec4( -u_QuadWidth, -u_QuadWidth, 0.0, 0.0 );
	v_UV = vec2( 0.0, 0.0 );
	EmitVertex();

	gl_Position = gl_in[0].gl_Position + u_MVP * vec4(u_QuadWidth, -u_QuadWidth, 0.0, 0.0);
	v_UV = vec2( 1.0, 0.0 );
	EmitVertex();

	gl_Position = gl_in[0].gl_Position + u_MVP * vec4(-u_QuadWidth, u_QuadWidth, 0.0, 0.0);
	v_UV = vec2( 0.0, 1.0 );
	EmitVertex();

	gl_Position = gl_in[0].gl_Position + u_MVP * vec4(u_QuadWidth, u_QuadWidth, 0.0, 0.0);
	v_UV = vec2( 1.0, 1.0 );
	EmitVertex();

	EndPrimitive();
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_UV;

uniform sampler2D u_Tex;

void main()
{
	color = texture( u_Tex, v_UV );
}