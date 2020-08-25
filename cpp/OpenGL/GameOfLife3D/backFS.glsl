#version 410

in vec3 tc;
out vec4 fc;

uniform sampler2D frontFaces;
uniform sampler3D grid;

uniform float stepCount = 100;

vec4 transferFunction(float v, vec3 pos) {
  return v < 0.5 ? vec4(0.0) : vec4(pos,1.0);
}

vec4 blend(float currentScalar, vec4 last, vec3 pos) {
  vec4 current = transferFunction(currentScalar, pos);
  last.rgb = last.rgb + (1.0-last.a) * current.a * current.rgb;
  last.a = last.a + (1.0-last.a) * current.a;
  return last;
}

bool inBounds(vec3 pos) {
  return pos.x >= 0.0 && pos.y >= 0.0 && pos.z >= 0.0 &&
         pos.x <= 1.0 && pos.y <= 1.0 && pos.z <= 1.0;
}

void main() {
  vec3 currentPoint = texelFetch(frontFaces,ivec2(gl_FragCoord),0).xyz;
  vec3 exitPoint = tc;
  vec3 direction = normalize(exitPoint-currentPoint)/stepCount;
  
  fc = vec4(0.0);
  while (inBounds(currentPoint)) {
    float gridValue = texture(grid, currentPoint).r;
    fc = blend(gridValue, fc, currentPoint);
    currentPoint+=direction;
    if (fc.a > 0.95) break;
  }
  
}
