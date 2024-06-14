#version 330 core

layout (location = 0) in vec3 aPos; 
layout (location = 1) in vec3 aColor; 

out vec3 ourColor; 

uniform float xOffsetPer100Frames;


void main()
{
	gl_Position = vec4(aPos.x + xOffsetPer100Frames, aPos.y, aPos.z, 1.0); //make -aPos to flip
	ourColor = aColor; 
}