#version 440
layout( location = 0 ) uniform sampler2D Texture0;
layout( location = 3 ) uniform vec2 offset;

out vec4 FragColor;

vec2 texelSize = 1.0 / vec2(textureSize(Texture0, 0));
vec2 viewport_position = (gl_FragCoord.xy - offset) * texelSize; 

// PASSTHROUGH
// void main(){
//     FragColor = texture2D(Texture0, gl_FragCoord.xy * texelSize);
// }

vec2 lens_centre     = vec2(0.5);
vec2 screen_centre   = vec2(0.5);
vec2 scale           = vec2(0.8);
vec4 warp_params = vec4(1, 0.22, 0.24, 0);


vec2 barrel_warp(vec2 viewport_pos){
    vec2  relative_pos = viewport_pos - lens_centre;
    float r            = length( relative_pos );
    vec2  warped_pos  = 
	relative_pos * warp_params.x +
	relative_pos * warp_params.y * r +
	relative_pos * warp_params.z * r * r +
	relative_pos * warp_params.z * r * r * r;
	
    return lens_centre + (warped_pos * scale);
}
 
void main(){
    vec2 coord = barrel_warp(viewport_position);

    clamp(coord, vec2(0), vec2(1));

//    if (viewport_position.x > 0.5)
//	FragColor = vec4(0.4, 0, 0, 0.5);
//    else
//	FragColor = vec4(0, 0.4, 0, 0.5);

    FragColor = texture2D(Texture0, coord);

}
