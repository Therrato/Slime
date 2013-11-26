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
