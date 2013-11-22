
[Vertex Shader]
// Shader OpenGL ID 1

#version 150 // for glsl version (12 is for older versions , say opengl 2.1

uniform	mat4 	projection;	// set for all vertices
uniform	mat4 	view;			// set for all vertices
uniform	mat4 	model;		// set for all vertices
uniform	vec3 	light;		// set for all vertices
uniform	float 	time;		// set for all vertices

in vec3 vertex; 					// attribute-input per vertex from vertices
in vec3 normal;						// attribute-input per normal from normals
in vec2 uv;

out vec2 texCoord; // uv forwarded to fs
out float intensity;

void main( void ){
	gl_Position = projection * view * model * vec4( vertex, 1.f );
	gl_Position.z *= sin( time ); // funny effect

	// calc light manipulation
	//intensity = 0.5 + 0.5*sin( time ); // vary between 0 and 1

	texCoord = uv; // gives interpolated uv in fs
}
[Fragment Shader]
// Shader OpenGL ID 2

#version 150 // for glsl version (12 is for older versions , say opengl 2.1

uniform sampler2D colorMap;
uniform float time;

in vec2 texCoord; // interpolated from vs
in float intensity;

out vec4 fragment_color;


void main( void ) {
	//fragment_color = vec4( 1,0,0,1 );
	fragment_color = texture( colorMap, texCoord );
	//fragment_color = intensity * vec4( 1,0,0,1 );
	//fragment_color = intensity * texture( colorMap, texCoord );
}