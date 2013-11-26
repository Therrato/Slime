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
	//gl_Position.x *= sin( time ); // funny effect

	// calc light manipulation
	//intensity = 0.5 + 0.5*sin( time ); // vary between 0 and 1

	texCoord = uv; // gives interpolated uv in fs
}
