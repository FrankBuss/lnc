#include "AbstractParticleSystem.h"

std::vector<uint8_t> spritePixel{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,2,2,2,2,3,3,3,4,4,4,4,4,4,5,5,5,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,6,6,6,5,5,5,5,5,5,6,6,6,5,5,5,4,4,4,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,4,4,4,5,5,5,5,5,5,5,5,5,8,8,8,9,9,9,10,10,10,9,9,9,8,8,8,10,10,10,7,7,7,11,11,11,11,11,11,8,8,8,5,5,5,4,4,4,3,3,3,2,2,2,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,5,5,5,1,1,1,7,7,7,4,4,4,10,10,10,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,11,11,11,11,11,11,12,12,12,11,11,11,12,12,12,13,13,13,12,12,12,12,12,12,10,10,10,7,7,7,10,10,10,9,9,9,3,3,3,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,3,3,3,3,3,3,5,5,5,5,5,5,6,6,6,11,11,11,10,10,10,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,13,13,13,12,12,12,12,12,12,12,12,12,12,12,12,13,13,13,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,10,10,10,9,9,9,7,7,7,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,8,8,8,8,8,8,5,5,5,11,11,11,12,12,12,12,12,12,13,13,13,14,14,14,14,14,14,13,13,13,13,13,13,16,16,16,21,21,21,20,20,20,20,20,20,19,19,19,16,16,16,20,20,20,15,15,15,14,14,14,13,13,13,12,12,12,11,11,11,12,12,12,12,12,12,12,12,12,13,13,13,12,12,12,8,8,8,5,5,5,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,5,5,5,8,8,8,12,12,12,13,13,13,13,13,13,12,12,12,12,12,12,11,11,11,16,16,16,22,22,22,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,20,20,20,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,17,17,17,16,16,16,17,17,17,16,16,16,11,11,11,12,12,12,12,12,12,12,12,12,11,11,11,7,7,7,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,8,8,8,8,8,8,11,11,11,13,13,13,12,12,12,12,12,12,12,12,12,12,12,12,16,16,16,19,19,19,19,19,19,22,22,22,23,23,23,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,23,23,23,25,25,25,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,22,22,22,20,20,20,22,22,22,20,20,20,11,11,11,12,12,12,12,12,12,12,12,12,12,12,12,13,13,13,12,12,12,9,9,9,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,9,9,12,12,12,12,12,12,12,12,12,12,12,12,11,11,11,12,12,12,15,15,15,21,21,21,20,20,20,22,22,22,22,22,22,26,26,26,25,25,25,24,24,24,26,26,26,26,26,26,26,26,26,27,27,27,27,27,27,26,26,26,26,26,26,26,26,26,26,26,26,27,27,27,26,26,26,25,25,25,22,22,22,20,20,20,19,19,19,20,20,20,16,16,16,15,15,15,13,13,13,11,11,11,12,12,12,12,12,12,12,12,12,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,6,6,6,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,17,17,17,17,17,17,20,20,20,20,20,20,20,20,20,24,24,24,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,26,26,26,27,27,27,27,27,27,26,26,26,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,24,24,24,23,23,23,24,24,24,22,22,22,21,21,21,18,18,18,18,18,18,15,15,15,11,11,11,12,12,12,10,10,10,6,6,6,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,4,4,4,4,4,4,11,11,11,12,12,12,12,12,12,11,11,11,16,16,16,20,20,20,22,22,22,21,21,21,21,21,21,21,21,21,23,23,23,27,27,27,27,27,27,27,27,27,27,27,27,28,28,28,26,26,26,27,27,27,27,27,27,27,27,27,27,27,27,28,28,28,27,27,27,27,27,27,27,27,27,27,27,27,26,26,26,27,27,27,27,27,27,27,27,27,26,26,26,27,27,27,25,25,25,23,23,23,21,21,21,21,21,21,21,21,21,14,14,14,12,12,12,12,12,12,11,11,11,5,5,5,6,6,6,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,5,5,5,6,6,6,11,11,11,13,13,13,12,12,12,16,16,16,21,21,21,21,21,21,21,21,21,22,22,22,25,25,25,27,27,27,27,27,27,26,26,26,26,26,26,27,27,27,29,29,29,33,33,33,29,29,29,29,29,29,30,30,30,31,31,31,34,34,34,34,34,34,33,33,33,29,29,29,28,28,28,27,27,27,28,28,28,28,28,28,27,27,27,27,27,27,26,26,26,26,26,26,27,27,27,25,25,25,22,22,22,20,20,20,21,21,21,22,22,22,20,20,20,13,13,13,12,12,12,11,11,11,11,11,11,5,5,5,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,3,3,3,5,5,5,6,6,6,11,11,11,12,12,12,11,11,11,15,15,15,20,20,20,21,21,21,21,21,21,22,22,22,26,26,26,27,27,27,26,26,26,27,27,27,27,27,27,27,27,27,26,26,26,31,31,31,37,37,37,34,34,34,35,35,35,37,37,37,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,33,33,33,30,30,30,33,33,33,34,34,34,29,29,29,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,24,24,24,20,20,20,20,20,20,22,22,22,17,17,17,11,11,11,12,12,12,12,12,12,6,6,6,4,4,4,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,7,7,7,10,10,10,12,12,12,13,13,13,11,11,11,15,15,15,21,21,21,22,22,22,22,22,22,25,25,25,27,27,27,27,27,27,27,27,27,27,27,27,29,29,29,29,29,29,28,28,28,34,34,34,36,36,36,36,36,36,36,36,36,35,35,35,36,36,36,35,35,35,35,35,35,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,34,34,34,32,32,32,31,31,31,28,28,28,27,27,27,26,26,26,26,26,26,27,27,27,24,24,24,21,21,21,20,20,20,20,20,20,14,14,14,12,12,12,12,12,12,10,10,10,6,6,6,6,6,6,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,10,10,10,12,12,12,12,12,12,12,12,12,13,13,13,21,21,21,20,20,20,26,26,26,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,29,29,29,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,37,37,37,36,36,36,37,37,37,38,38,38,37,37,37,37,37,37,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,35,35,35,35,35,35,36,36,36,36,36,36,36,36,36,35,35,35,28,28,28,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,23,23,23,21,21,21,21,21,21,14,14,14,11,11,11,12,12,12,11,11,11,9,9,9,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,1,1,1,4,4,4,10,10,10,12,12,12,12,12,12,11,11,11,12,12,12,17,17,17,23,23,23,25,25,25,23,23,23,26,26,26,28,28,28,27,27,27,27,27,27,27,27,27,32,32,32,36,36,36,35,35,35,35,35,35,36,36,36,36,36,36,39,39,39,41,41,41,39,39,39,45,45,45,43,43,43,43,43,43,43,43,43,40,40,40,40,40,40,39,39,39,38,38,38,38,38,38,37,37,37,35,35,35,36,36,36,35,35,35,36,36,36,34,34,34,29,29,29,27,27,27,27,27,27,27,27,27,27,27,27,25,25,25,21,21,21,21,21,21,21,21,21,14,14,14,11,11,11,11,11,11,11,11,11,5,5,5,4,4,4,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,3,3,3,6,6,6,11,11,11,13,13,13,12,12,12,14,14,14,18,18,18,21,21,21,23,23,23,27,27,27,26,26,26,26,26,26,27,27,27,27,27,27,32,32,32,36,36,36,36,36,36,36,36,36,37,37,37,37,37,37,38,38,38,42,42,42,45,45,45,44,44,44,46,46,46,49,49,49,45,45,45,45,45,45,46,46,46,45,45,45,45,45,45,45,45,45,44,44,44,43,43,43,39,39,39,37,37,37,38,38,38,36,36,36,36,36,36,36,36,36,36,36,36,33,33,33,27,27,27,27,27,27,27,27,27,27,27,27,25,25,25,20,20,20,21,21,21,21,21,21,15,15,15,12,12,12,12,12,12,10,10,10,5,5,5,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,4,4,4,9,9,9,13,13,13,12,12,12,13,13,13,21,21,21,21,21,21,20,20,20,25,25,25,27,27,27,27,27,27,26,26,26,26,26,26,31,31,31,37,37,37,36,36,36,35,35,35,36,36,36,40,40,40,43,43,43,44,44,44,45,45,45,44,44,44,46,46,46,48,48,48,55,55,55,50,50,50,46,46,46,47,47,47,48,48,48,48,48,48,46,46,46,44,44,44,46,46,46,43,43,43,43,43,43,41,41,41,38,38,38,36,36,36,36,36,36,36,36,36,34,34,34,29,29,29,27,27,27,26,26,26,26,26,26,27,27,27,24,24,24,21,21,21,21,21,21,20,20,20,12,12,12,12,12,12,9,9,9,4,4,4,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,2,2,2,8,8,8,12,12,12,12,12,12,12,12,12,18,18,18,21,21,21,23,23,23,25,25,25,27,27,27,27,27,27,26,26,26,26,26,26,33,33,33,36,36,36,36,36,36,36,36,36,36,36,36,39,39,39,44,44,44,46,46,46,45,45,45,47,47,47,49,49,49,53,53,53,56,56,56,60,60,60,57,57,57,53,53,53,54,54,54,54,54,54,54,54,54,50,50,50,49,49,49,48,48,48,46,46,46,45,45,45,45,45,45,42,42,42,37,37,37,36,36,36,35,35,35,36,36,36,35,35,35,32,32,32,31,31,31,27,27,27,26,26,26,27,27,27,24,24,24,21,21,21,20,20,20,13,13,13,12,12,12,11,11,11,11,11,11,6,6,6,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,4,4,4,7,7,7,11,11,11,12,12,12,13,13,13,19,19,19,23,23,23,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,33,33,33,37,37,37,36,36,36,36,36,36,37,37,37,40,40,40,44,44,44,45,45,45,47,47,47,51,51,51,53,53,53,57,57,57,57,57,57,58,58,58,65,65,65,62,62,62,58,58,58,57,57,57,57,57,57,57,57,57,57,57,57,55,55,55,53,53,53,52,52,52,49,49,49,46,46,46,45,45,45,45,45,45,41,41,41,36,36,36,36,36,36,36,36,36,34,34,34,31,31,31,28,28,28,27,27,27,26,26,26,27,27,27,24,24,24,19,19,19,14,14,14,12,12,12,12,12,12,11,11,11,6,6,6,4,4,4,1,1,1,0,0,0,0,0,0,0,0,0,
	2,2,2,2,2,2,6,6,6,7,7,7,11,11,11,12,12,12,16,16,16,20,20,20,23,23,23,27,27,27,27,27,27,27,27,27,27,27,27,30,30,30,36,36,36,36,36,36,35,35,35,36,36,36,40,40,40,45,45,45,45,45,45,47,47,47,50,50,50,57,57,57,58,58,58,59,59,59,59,59,59,59,59,59,69,69,69,69,69,69,60,60,60,59,59,59,59,59,59,59,59,59,59,59,59,56,56,56,56,56,56,58,58,58,54,54,54,51,51,51,45,45,45,45,45,45,45,45,45,39,39,39,36,36,36,36,36,36,36,36,36,33,33,33,27,27,27,27,27,27,27,27,27,27,27,27,23,23,23,20,20,20,20,20,20,14,14,14,12,12,12,10,10,10,6,6,6,6,6,6,1,1,1,0,0,0,0,0,0,0,0,0,
	3,3,3,2,2,2,9,9,9,12,12,12,12,12,12,14,14,14,21,21,21,21,21,21,26,26,26,27,27,27,26,26,26,28,28,28,33,33,33,36,36,36,36,36,36,36,36,36,36,36,36,37,37,37,41,41,41,45,45,45,45,45,45,51,51,51,56,56,56,58,58,58,59,59,59,61,61,61,62,62,62,68,68,68,72,72,72,72,72,72,68,68,68,67,67,67,67,67,67,63,63,63,61,61,61,61,61,61,59,59,59,58,58,58,56,56,56,55,55,55,49,49,49,47,47,47,45,45,45,44,44,44,39,39,39,36,36,36,36,36,36,36,36,36,33,33,33,27,27,27,27,27,27,27,27,27,24,24,24,21,21,21,20,20,20,20,20,20,13,13,13,12,12,12,11,11,11,4,4,4,1,1,1,0,0,0,0,0,0,0,0,0,
	4,4,4,4,4,4,12,12,12,12,12,12,12,12,12,14,14,14,21,21,21,21,21,21,26,26,26,27,27,27,27,27,27,28,28,28,31,31,31,36,36,36,36,36,36,37,37,37,39,39,39,43,43,43,45,45,45,46,46,46,50,50,50,55,55,55,56,56,56,59,59,59,63,63,63,69,69,69,70,70,70,73,73,73,79,79,79,77,77,77,72,72,72,72,72,72,72,72,72,73,73,73,70,70,70,68,68,68,65,65,65,59,59,59,59,59,59,57,57,57,56,56,56,53,53,53,46,46,46,45,45,45,42,42,42,38,38,38,36,36,36,35,35,35,36,36,36,30,30,30,27,27,27,27,27,27,27,27,27,25,25,25,20,20,20,21,21,21,12,12,12,12,12,12,12,12,12,7,7,7,2,2,2,0,0,0,0,0,0,0,0,0,
	4,4,4,6,6,6,13,13,13,13,13,13,16,16,16,20,20,20,21,21,21,24,24,24,27,27,27,27,27,27,25,25,25,29,29,29,34,34,34,36,36,36,36,36,36,39,39,39,45,45,45,46,46,46,45,45,45,51,51,51,55,55,55,56,56,56,58,58,58,62,62,62,69,69,69,72,72,72,77,77,77,81,81,81,84,84,84,80,80,80,79,79,79,79,79,79,78,78,78,79,79,79,76,76,76,71,71,71,70,70,70,66,66,66,61,61,61,58,58,58,56,56,56,55,55,55,49,49,49,45,45,45,44,44,44,40,40,40,36,36,36,36,36,36,37,37,37,31,31,31,26,26,26,27,27,27,27,27,27,26,26,26,21,21,21,21,21,21,12,12,12,12,12,12,12,12,12,12,12,12,4,4,4,0,0,0,0,0,0,0,0,0,
	4,4,4,2,2,2,10,10,10,12,12,12,18,18,18,26,26,26,26,26,26,27,27,27,27,27,27,28,28,28,29,29,29,31,31,31,35,35,35,36,36,36,36,36,36,41,41,41,45,45,45,48,48,48,54,54,54,56,56,56,58,58,58,59,59,59,63,63,63,69,69,69,72,72,72,75,75,75,85,85,85,88,88,88,99,99,99,101,101,101,97,97,97,97,97,97,98,98,98,92,92,92,83,83,83,79,79,79,76,76,76,70,70,70,68,68,68,61,61,61,59,59,59,57,57,57,52,52,52,48,48,48,45,45,45,43,43,43,39,39,39,36,36,36,36,36,36,34,34,34,28,28,28,27,27,27,27,27,27,27,27,27,24,24,24,21,21,21,19,19,19,11,11,11,13,13,13,10,10,10,4,4,4,1,1,1,0,0,0,0,0,0,
	4,4,4,5,5,5,11,11,11,12,12,12,18,18,18,22,22,22,23,23,23,27,27,27,27,27,27,31,31,31,37,37,37,36,36,36,36,36,36,36,36,36,39,39,39,44,44,44,44,44,44,47,47,47,55,55,55,59,59,59,59,59,59,60,60,60,65,65,65,73,73,73,79,79,79,80,80,80,90,90,90,104,104,104,120,120,120,119,119,119,108,108,108,110,110,110,118,118,118,108,108,108,99,99,99,91,91,91,80,80,80,75,75,75,71,71,71,66,66,66,59,59,59,59,59,59,56,56,56,52,52,52,46,46,46,46,46,46,41,41,41,36,36,36,36,36,36,36,36,36,31,31,31,27,27,27,26,26,26,27,27,27,26,26,26,22,22,22,18,18,18,11,11,11,12,12,12,11,11,11,6,6,6,0,0,0,0,0,0,0,0,0,
	5,5,5,8,8,8,15,15,15,13,13,13,19,19,19,22,22,22,21,21,21,25,25,25,26,26,26,27,27,27,35,35,35,37,37,37,38,38,38,40,40,40,44,44,44,46,46,46,46,46,46,48,48,48,54,54,54,56,56,56,65,65,65,68,68,68,72,72,72,75,75,75,84,84,84,99,99,99,107,107,107,112,112,112,124,124,124,130,130,130,115,115,115,118,118,118,125,125,125,114,114,114,110,110,110,108,108,108,89,89,89,82,82,82,79,79,79,71,71,71,65,65,65,59,59,59,56,56,56,53,53,53,47,47,47,46,46,46,41,41,41,35,35,35,36,36,36,36,36,36,33,33,33,27,27,27,27,27,27,27,27,27,27,27,27,23,23,23,19,19,19,12,12,12,13,13,13,13,13,13,7,7,7,0,0,0,0,0,0,0,0,0,
	6,6,6,4,4,4,17,17,17,19,19,19,23,23,23,27,27,27,27,27,27,27,27,27,28,28,28,30,30,30,33,33,33,36,36,36,36,36,36,39,39,39,45,45,45,50,50,50,53,53,53,57,57,57,57,57,57,56,56,56,62,62,62,69,69,69,79,79,79,82,82,82,91,91,91,114,114,114,119,119,119,118,118,118,137,137,137,148,148,148,137,137,137,137,137,137,141,141,141,127,127,127,113,113,113,107,107,107,113,113,113,99,99,99,84,84,84,72,72,72,68,68,68,61,61,61,58,58,58,55,55,55,51,51,51,46,46,46,45,45,45,39,39,39,36,36,36,36,36,36,35,35,35,27,27,27,27,27,27,27,27,27,27,27,27,23,23,23,21,21,21,16,16,16,11,11,11,12,12,12,8,8,8,0,0,0,0,0,0,0,0,0,
	6,6,6,4,4,4,12,12,12,13,13,13,18,18,18,23,23,23,27,27,27,27,27,27,31,31,31,37,37,37,37,37,37,36,36,36,37,37,37,39,39,39,45,45,45,46,46,46,52,52,52,58,58,58,60,60,60,64,64,64,68,68,68,72,72,72,75,75,75,88,88,88,108,108,108,109,109,109,125,125,125,142,142,142,149,149,149,171,171,171,162,162,162,165,165,165,158,158,158,140,140,140,129,129,129,127,127,127,121,121,121,104,104,104,81,81,81,78,78,78,73,73,73,66,66,66,60,60,60,56,56,56,54,54,54,47,47,47,44,44,44,41,41,41,36,36,36,36,36,36,35,35,35,27,27,27,28,28,28,27,27,27,27,27,27,23,23,23,20,20,20,19,19,19,12,12,12,12,12,12,10,10,10,1,1,1,0,0,0,0,0,0,
	6,6,6,7,7,7,13,13,13,11,11,11,17,17,17,21,21,21,25,25,25,27,27,27,27,27,27,28,28,28,32,32,32,36,36,36,36,36,36,41,41,41,47,47,47,49,49,49,55,55,55,58,58,58,60,60,60,70,70,70,74,74,74,86,86,86,89,89,89,98,98,98,110,110,110,113,113,113,129,129,129,155,155,155,175,175,175,198,198,198,203,203,203,199,199,199,183,183,183,160,160,160,155,155,155,137,137,137,112,112,112,107,107,107,93,93,93,84,84,84,76,76,76,69,69,69,60,60,60,59,59,59,57,57,57,49,49,49,46,46,46,41,41,41,36,36,36,36,36,36,34,34,34,27,27,27,27,27,27,27,27,27,27,27,27,21,21,21,20,20,20,21,21,21,14,14,14,12,12,12,11,11,11,1,1,1,0,0,0,0,0,0,
	6,6,6,7,7,7,13,13,13,11,11,11,17,17,17,23,23,23,27,27,27,26,26,26,26,26,26,29,29,29,34,34,34,36,36,36,35,35,35,40,40,40,44,44,44,47,47,47,52,52,52,59,59,59,61,61,61,69,69,69,73,73,73,85,85,85,98,98,98,119,119,119,131,131,131,135,135,135,147,147,147,165,165,165,195,195,195,223,223,223,232,232,232,229,229,229,214,214,214,193,193,193,163,163,163,136,136,136,119,119,119,111,111,111,104,104,104,85,85,85,78,78,78,70,70,70,61,61,61,57,57,57,55,55,55,50,50,50,46,46,46,41,41,41,37,37,37,36,36,36,36,36,36,32,32,32,28,28,28,26,26,26,26,26,26,22,22,22,20,20,20,21,21,21,14,14,14,12,12,12,12,12,12,1,1,1,0,0,0,1,1,1,
	6,6,6,7,7,7,13,13,13,12,12,12,18,18,18,22,22,22,24,24,24,27,27,27,26,26,26,29,29,29,33,33,33,36,36,36,36,36,36,37,37,37,42,42,42,44,44,44,49,49,49,56,56,56,56,56,56,62,62,62,71,71,71,79,79,79,88,88,88,113,113,113,120,120,120,140,140,140,163,163,163,188,188,188,215,215,215,237,237,237,241,241,241,240,240,240,234,234,234,211,211,211,174,174,174,153,153,153,135,135,135,121,121,121,111,111,111,86,86,86,78,78,78,70,70,70,64,64,64,58,58,58,56,56,56,49,49,49,45,45,45,41,41,41,37,37,37,36,36,36,36,36,36,35,35,35,29,29,29,27,27,27,27,27,27,22,22,22,21,21,21,21,21,21,14,14,14,12,12,12,12,12,12,1,1,1,0,0,0,1,1,1,
	5,5,5,7,7,7,13,13,13,13,13,13,19,19,19,23,23,23,26,26,26,27,27,27,27,27,27,26,26,26,29,29,29,35,35,35,37,37,37,37,37,37,42,42,42,45,45,45,49,49,49,56,56,56,58,58,58,62,62,62,69,69,69,78,78,78,82,82,82,106,106,106,108,108,108,124,124,124,150,150,150,183,183,183,220,220,220,238,238,238,239,239,239,240,240,240,236,236,236,211,211,211,177,177,177,147,147,147,129,129,129,112,112,112,105,105,105,81,81,81,78,78,78,70,70,70,63,63,63,59,59,59,57,57,57,50,50,50,45,45,45,44,44,44,37,37,37,35,35,35,36,36,36,34,34,34,28,28,28,27,27,27,27,27,27,22,22,22,21,21,21,19,19,19,13,13,13,12,12,12,11,11,11,1,1,1,0,0,0,1,1,1,
	5,5,5,7,7,7,12,12,12,16,16,16,21,21,21,22,22,22,27,27,27,26,26,26,27,27,27,29,29,29,34,34,34,35,35,35,36,36,36,40,40,40,44,44,44,47,47,47,51,51,51,58,58,58,59,59,59,63,63,63,72,72,72,78,78,78,86,86,86,112,112,112,118,118,118,138,138,138,159,159,159,181,181,181,211,211,211,237,237,237,241,241,241,243,243,243,230,230,230,204,204,204,169,169,169,135,135,135,114,114,114,106,106,106,101,101,101,82,82,82,73,73,73,68,68,68,60,60,60,58,58,58,56,56,56,48,48,48,46,46,46,45,45,45,37,37,37,35,35,35,35,35,35,30,30,30,27,27,27,26,26,26,27,27,27,23,23,23,21,21,21,19,19,19,13,13,13,12,12,12,11,11,11,1,1,1,0,0,0,1,1,1,
	4,4,4,6,6,6,12,12,12,16,16,16,21,21,21,21,21,21,27,27,27,27,27,27,27,27,27,29,29,29,35,35,35,36,36,36,36,36,36,37,37,37,44,44,44,47,47,47,51,51,51,55,55,55,58,58,58,61,61,61,71,71,71,81,81,81,91,91,91,110,110,110,119,119,119,125,125,125,138,138,138,158,158,158,196,196,196,221,221,221,229,229,229,225,225,225,209,209,209,181,181,181,162,162,162,147,147,147,123,123,123,110,110,110,101,101,101,81,81,81,73,73,73,67,67,67,61,61,61,57,57,57,55,55,55,49,49,49,46,46,46,42,42,42,37,37,37,36,36,36,36,36,36,34,34,34,28,28,28,26,26,26,26,26,26,26,26,26,21,21,21,20,20,20,14,14,14,12,12,12,11,11,11,1,1,1,0,0,0,1,1,1,
	4,4,4,6,6,6,12,12,12,14,14,14,20,20,20,21,21,21,25,25,25,27,27,27,27,27,27,27,27,27,32,32,32,36,36,36,36,36,36,36,36,36,43,43,43,46,46,46,48,48,48,54,54,54,59,59,59,59,59,59,67,67,67,74,74,74,79,79,79,89,89,89,107,107,107,106,106,106,129,129,129,158,158,158,172,172,172,189,189,189,195,195,195,191,191,191,183,183,183,161,161,161,135,135,135,129,129,129,122,122,122,116,116,116,95,95,95,80,80,80,74,74,74,66,66,66,59,59,59,58,58,58,56,56,56,50,50,50,46,46,46,43,43,43,37,37,37,36,36,36,36,36,36,30,30,30,27,27,27,26,26,26,27,27,27,25,25,25,21,21,21,18,18,18,12,12,12,12,12,12,11,11,11,1,1,1,0,0,0,1,1,1,
	3,3,3,6,6,6,13,13,13,11,11,11,17,17,17,22,22,22,25,25,25,27,27,27,27,27,27,27,27,27,30,30,30,36,36,36,35,35,35,37,37,37,42,42,42,45,45,45,46,46,46,53,53,53,57,57,57,57,57,57,65,65,65,70,70,70,76,76,76,82,82,82,101,101,101,115,115,115,131,131,131,134,134,134,153,153,153,160,160,160,160,160,160,166,166,166,147,147,147,154,154,154,128,128,128,106,106,106,107,107,107,100,100,100,87,87,87,81,81,81,71,71,71,66,66,66,60,60,60,57,57,57,55,55,55,48,48,48,46,46,46,41,41,41,36,36,36,37,37,37,36,36,36,30,30,30,27,27,27,28,28,28,26,26,26,22,22,22,20,20,20,21,21,21,14,14,14,12,12,12,9,9,9,0,0,0,0,0,0,1,1,1,
	3,3,3,5,5,5,12,12,12,12,12,12,16,16,16,20,20,20,24,24,24,26,26,26,26,26,26,27,27,27,28,28,28,36,36,36,36,36,36,37,37,37,42,42,42,45,45,45,47,47,47,53,53,53,55,55,55,59,59,59,62,62,62,65,65,65,73,73,73,78,78,78,95,95,95,119,119,119,112,112,112,119,119,119,136,136,136,130,130,130,145,145,145,148,148,148,125,125,125,124,124,124,123,123,123,111,111,111,100,100,100,84,84,84,78,78,78,74,74,74,67,67,67,60,60,60,58,58,58,57,57,57,52,52,52,45,45,45,45,45,45,39,39,39,36,36,36,35,35,35,36,36,36,30,30,30,27,27,27,27,27,27,27,27,27,26,26,26,21,21,21,21,21,21,13,13,13,12,12,12,7,7,7,0,0,0,0,0,0,1,1,1,
	2,2,2,4,4,4,12,12,12,12,12,12,15,15,15,21,21,21,23,23,23,26,26,26,27,27,27,27,27,27,28,28,28,36,36,36,36,36,36,36,36,36,38,38,38,44,44,44,46,46,46,49,49,49,54,54,54,59,59,59,60,60,60,61,61,61,69,69,69,82,82,82,88,88,88,88,88,88,105,105,105,118,118,118,123,123,123,113,113,113,123,123,123,132,132,132,111,111,111,106,106,106,117,117,117,111,111,111,88,88,88,76,76,76,74,74,74,71,71,71,65,65,65,59,59,59,55,55,55,54,54,54,48,48,48,46,46,46,44,44,44,41,41,41,36,36,36,36,36,36,36,36,36,29,29,29,27,27,27,27,27,27,27,27,27,25,25,25,21,21,21,21,21,21,14,14,14,12,12,12,10,10,10,0,0,0,0,0,0,0,0,0,
	1,1,1,6,6,6,12,12,12,12,12,12,14,14,14,21,21,21,21,21,21,25,25,25,27,27,27,26,26,26,27,27,27,33,33,33,35,35,35,36,36,36,37,37,37,41,41,41,45,45,45,45,45,45,51,51,51,57,57,57,59,59,59,59,59,59,67,67,67,75,75,75,75,75,75,78,78,78,88,88,88,107,107,107,113,113,113,110,110,110,121,121,121,125,125,125,114,114,114,99,99,99,97,97,97,91,91,91,81,81,81,73,73,73,72,72,72,64,64,64,60,60,60,57,57,57,55,55,55,51,51,51,47,47,47,46,46,46,41,41,41,37,37,37,36,36,36,36,36,36,35,35,35,27,27,27,28,28,28,27,27,27,25,25,25,21,21,21,21,21,21,17,17,17,12,12,12,12,12,12,9,9,9,0,0,0,0,0,0,0,0,0,
	1,1,1,5,5,5,13,13,13,12,12,12,12,12,12,20,20,20,21,21,21,25,25,25,27,27,27,27,27,27,26,26,26,29,29,29,32,32,32,36,36,36,36,36,36,37,37,37,44,44,44,45,45,45,48,48,48,55,55,55,55,55,55,58,58,58,63,63,63,67,67,67,70,70,70,77,77,77,82,82,82,89,89,89,89,89,89,87,87,87,96,96,96,98,98,98,92,92,92,84,84,84,83,83,83,81,81,81,76,76,76,69,69,69,63,63,63,60,60,60,57,57,57,55,55,55,54,54,54,48,48,48,44,44,44,43,43,43,37,37,37,36,36,36,36,36,36,36,36,36,31,31,31,27,27,27,27,27,27,27,27,27,24,24,24,21,21,21,18,18,18,12,12,12,12,12,12,9,9,9,5,5,5,1,1,1,0,0,0,0,0,0,
	1,1,1,3,3,3,12,12,12,12,12,12,12,12,12,16,16,16,20,20,20,25,25,25,27,27,27,28,28,28,27,27,27,28,28,28,31,31,31,36,36,36,36,36,36,36,36,36,40,40,40,44,44,44,46,46,46,50,50,50,54,54,54,59,59,59,58,58,58,60,60,60,67,67,67,72,72,72,74,74,74,78,78,78,77,77,77,79,79,79,85,85,85,87,87,87,82,82,82,78,78,78,74,74,74,74,74,74,72,72,72,64,64,64,59,59,59,58,58,58,57,57,57,54,54,54,48,48,48,46,46,46,45,45,45,41,41,41,36,36,36,36,36,36,35,35,35,31,31,31,27,27,27,26,26,26,27,27,27,27,27,27,22,22,22,22,22,22,19,19,19,11,11,11,12,12,12,10,10,10,2,2,2,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,1,7,7,7,13,13,13,12,12,12,13,13,13,21,21,21,25,25,25,27,27,27,26,26,26,27,27,27,27,27,27,31,31,31,36,36,36,35,35,35,36,36,36,37,37,37,42,42,42,45,45,45,46,46,46,52,52,52,56,56,56,56,56,56,58,58,58,62,62,62,64,64,64,69,69,69,72,72,72,71,71,71,72,72,72,79,79,79,83,83,83,74,74,74,70,70,70,68,68,68,67,67,67,62,62,62,58,58,58,58,58,58,56,56,56,53,53,53,49,49,49,46,46,46,45,45,45,43,43,43,37,37,37,36,36,36,36,36,36,35,35,35,29,29,29,27,27,27,27,27,27,27,27,27,23,23,23,21,21,21,20,20,20,13,13,13,12,12,12,12,12,12,10,10,10,1,1,1,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,1,5,5,5,10,10,10,13,13,13,13,13,13,19,19,19,21,21,21,24,24,24,26,26,26,26,26,26,27,27,27,30,30,30,32,32,32,36,36,36,36,36,36,35,35,35,39,39,39,43,43,43,45,45,45,46,46,46,49,49,49,53,53,53,57,57,57,60,60,60,60,60,60,60,60,60,61,61,61,61,61,61,67,67,67,72,72,72,73,73,73,70,70,70,65,65,65,61,61,61,59,59,59,59,59,59,55,55,55,55,55,55,54,54,54,48,48,48,45,45,45,45,45,45,43,43,43,39,39,39,36,36,36,36,36,36,37,37,37,31,31,31,26,26,26,27,27,27,26,26,26,26,26,26,21,21,21,21,21,21,14,14,14,11,11,11,12,12,12,11,11,11,8,8,8,2,2,2,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,2,2,2,6,6,6,13,13,13,11,11,11,14,14,14,20,20,20,20,20,20,24,24,24,26,26,26,26,26,26,27,27,27,27,27,27,33,33,33,36,36,36,35,35,35,37,37,37,40,40,40,43,43,43,45,45,45,45,45,45,49,49,49,55,55,55,57,57,57,57,57,57,58,58,58,58,58,58,58,58,58,59,59,59,65,65,65,70,70,70,64,64,64,58,58,58,59,59,59,57,57,57,57,57,57,56,56,56,53,53,53,48,48,48,45,45,45,45,45,45,42,42,42,39,39,39,36,36,36,36,36,36,35,35,35,31,31,31,26,26,26,27,27,27,27,27,27,27,27,27,24,24,24,21,21,21,18,18,18,13,13,13,12,12,12,12,12,12,8,8,8,3,3,3,1,1,1,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,1,1,1,9,9,9,12,12,12,12,12,12,12,12,12,18,18,18,21,21,21,23,23,23,27,27,27,27,27,27,28,28,28,27,27,27,28,28,28,35,35,35,36,36,36,37,37,37,37,37,37,38,38,38,43,43,43,44,44,44,47,47,47,49,49,49,50,50,50,54,54,54,54,54,54,55,55,55,56,56,56,58,58,58,59,59,59,67,67,67,63,63,63,57,57,57,56,56,56,54,54,54,51,51,51,50,50,50,48,48,48,45,45,45,44,44,44,42,42,42,37,37,37,36,36,36,36,36,36,36,36,36,36,36,36,28,28,28,26,26,26,26,26,26,27,27,27,27,27,27,22,22,22,20,20,20,12,12,12,12,12,12,12,12,12,11,11,11,7,7,7,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,5,5,5,11,11,11,12,12,12,12,12,12,15,15,15,21,21,21,21,21,21,23,23,23,27,27,27,27,27,27,27,27,27,28,28,28,31,31,31,35,35,35,36,36,36,35,35,35,36,36,36,38,38,38,40,40,40,44,44,44,45,45,45,46,46,46,47,47,47,49,49,49,53,53,53,52,52,52,55,55,55,56,56,56,61,61,61,59,59,59,54,54,54,52,52,52,48,48,48,45,45,45,45,45,45,46,46,46,44,44,44,39,39,39,37,37,37,36,36,36,36,36,36,35,35,35,33,33,33,31,31,31,28,28,28,26,26,26,27,27,27,26,26,26,23,23,23,21,21,21,17,17,17,12,12,12,13,13,13,10,10,10,5,5,5,5,5,5,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,1,1,1,5,5,5,11,11,11,12,12,12,11,11,11,16,16,16,21,21,21,21,21,21,24,24,24,26,26,26,26,26,26,27,27,27,28,28,28,30,30,30,34,34,34,36,36,36,36,36,36,36,36,36,37,37,37,40,40,40,42,42,42,45,45,45,45,45,45,46,46,46,46,46,46,46,46,46,50,50,50,50,50,50,54,54,54,54,54,54,47,47,47,47,47,47,46,46,46,45,45,45,44,44,44,42,42,42,39,39,39,37,37,37,36,36,36,36,36,36,36,36,36,33,33,33,27,27,27,26,26,26,27,27,27,27,27,27,27,27,27,23,23,23,20,20,20,21,21,21,12,12,12,12,12,12,12,12,12,10,10,10,5,5,5,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,9,9,9,12,12,12,12,12,12,13,13,13,20,20,20,21,21,21,22,22,22,26,26,26,27,27,27,27,27,27,27,27,27,27,27,27,29,29,29,35,35,35,36,36,36,36,36,36,36,36,36,36,36,36,37,37,37,39,39,39,41,41,41,43,43,43,44,44,44,43,43,43,46,46,46,46,46,46,48,48,48,49,49,49,45,45,45,44,44,44,42,42,42,39,39,39,39,39,39,37,37,37,36,36,36,37,37,37,36,36,36,35,35,35,35,35,35,31,31,31,27,27,27,27,27,27,27,27,27,26,26,26,23,23,23,20,20,20,20,20,20,14,14,14,12,12,12,12,12,12,12,12,12,8,8,8,5,5,5,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,4,4,4,10,10,10,13,13,13,12,12,12,14,14,14,17,17,17,21,21,21,22,22,22,26,26,26,27,27,27,27,27,27,27,27,27,27,27,27,29,29,29,33,33,33,36,36,36,37,37,37,36,36,36,36,36,36,36,36,36,36,36,36,38,38,38,38,38,38,39,39,39,43,43,43,44,44,44,44,44,44,48,48,48,42,42,42,40,40,40,37,37,37,36,36,36,36,36,36,35,35,35,36,36,36,37,37,37,33,33,33,29,29,29,28,28,28,27,27,27,26,26,26,27,27,27,27,27,27,24,24,24,20,20,20,21,21,21,18,18,18,11,11,11,12,12,12,13,13,13,9,9,9,5,5,5,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,3,3,3,8,8,8,13,13,13,12,12,12,12,12,12,12,12,12,21,21,21,21,21,21,21,21,21,24,24,24,27,27,27,27,27,27,27,27,27,27,27,27,30,30,30,32,32,32,34,34,34,35,35,35,36,36,36,36,36,36,36,36,36,36,36,36,35,35,35,36,36,36,40,40,40,40,40,40,39,39,39,41,41,41,38,38,38,36,36,36,36,36,36,36,36,36,36,36,36,35,35,35,36,36,36,35,35,35,31,31,31,27,27,27,27,27,27,26,26,26,27,27,27,26,26,26,25,25,25,22,22,22,21,21,21,16,16,16,17,17,17,11,11,11,12,12,12,11,11,11,8,8,8,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,5,5,5,10,10,10,12,12,12,12,12,12,11,11,11,14,14,14,20,20,20,20,20,20,22,22,22,24,24,24,24,24,24,27,27,27,27,27,27,27,27,27,27,27,27,28,28,28,30,30,30,34,34,34,34,34,34,35,35,35,36,36,36,36,36,36,36,36,36,37,37,37,37,37,37,37,37,37,39,39,39,35,35,35,35,35,35,35,35,35,36,36,36,35,35,35,31,31,31,30,30,30,30,30,30,27,27,27,27,27,27,26,26,26,26,26,26,27,27,27,22,22,22,20,20,20,20,20,20,21,21,21,14,14,14,12,12,12,12,12,12,13,13,13,8,8,8,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,5,5,5,7,7,7,11,11,11,12,12,12,12,12,12,12,12,12,14,14,14,20,20,20,20,20,20,20,20,20,20,20,20,24,24,24,27,27,27,27,27,27,27,27,27,27,27,27,28,28,28,29,29,29,32,32,32,33,33,33,33,33,33,34,34,34,33,33,33,36,36,36,35,35,35,35,35,35,37,37,37,34,34,34,33,33,33,36,36,36,35,35,35,29,29,29,26,26,26,27,27,27,26,26,26,27,27,27,27,27,27,27,27,27,26,26,26,26,26,26,21,21,21,20,20,20,21,21,21,18,18,18,12,12,12,12,12,12,13,13,13,11,11,11,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,4,4,4,4,4,4,7,7,7,10,10,10,13,13,13,12,12,12,12,12,12,12,12,12,17,17,17,22,22,22,21,21,21,24,24,24,27,27,27,26,26,26,27,27,27,26,26,26,26,26,26,27,27,27,27,27,27,27,27,27,27,27,27,28,28,28,27,27,27,36,36,36,32,32,32,30,30,30,33,33,33,29,29,29,27,27,27,28,28,28,28,28,28,27,27,27,27,27,27,26,26,26,27,27,27,27,27,27,26,26,26,24,24,24,21,21,21,21,21,21,20,20,20,19,19,19,13,13,13,12,12,12,12,12,12,13,13,13,9,9,9,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,5,5,5,4,4,4,5,5,5,8,8,8,12,12,12,13,13,13,11,11,11,14,14,14,17,17,17,21,21,21,22,22,22,23,23,23,25,25,25,27,27,27,27,27,27,27,27,27,27,27,27,26,26,26,27,27,27,26,26,26,27,27,27,26,26,26,32,32,32,31,31,31,26,26,26,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,26,26,26,24,24,24,23,23,23,21,21,21,21,21,21,20,20,20,14,14,14,11,11,11,12,12,12,12,12,12,12,12,12,10,10,10,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,3,3,3,4,4,4,5,5,5,4,4,4,8,8,8,12,12,12,12,12,12,11,11,11,11,11,11,13,13,13,17,17,17,21,21,21,22,22,22,25,25,25,26,26,26,26,26,26,26,26,26,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,28,28,28,27,27,27,27,27,27,26,26,26,27,27,27,27,27,27,27,27,27,26,26,26,26,26,26,27,27,27,24,24,24,20,20,20,21,21,21,21,21,21,21,21,21,14,14,14,12,12,12,12,12,12,12,12,12,13,13,13,8,8,8,3,3,3,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,5,5,5,4,4,4,5,5,5,5,5,5,6,6,6,5,5,5,9,9,9,12,12,12,11,11,11,13,13,13,14,14,14,19,19,19,20,20,20,21,21,21,21,21,21,21,21,21,22,22,22,26,26,26,23,23,23,25,25,25,25,25,25,27,27,27,26,26,26,25,25,25,27,27,27,27,27,27,25,25,25,21,21,21,23,23,23,25,25,25,23,23,23,21,21,21,22,22,22,22,22,22,19,19,19,13,13,13,12,12,12,12,12,12,12,12,12,10,10,10,13,13,13,8,8,8,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,2,5,5,5,4,4,4,5,5,5,5,5,5,5,5,5,9,9,9,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,14,14,14,17,17,17,21,21,21,21,21,21,21,21,21,22,22,22,22,22,22,22,22,22,22,22,22,26,26,26,24,24,24,20,20,20,23,23,23,24,24,24,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,17,17,17,15,15,15,16,16,16,13,13,13,12,12,12,12,12,12,12,12,12,12,12,12,6,6,6,5,5,5,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,2,3,3,3,5,5,5,4,4,4,5,5,5,5,5,5,6,6,6,11,11,11,13,13,13,13,13,13,12,12,12,12,12,12,12,12,12,13,13,13,14,14,14,18,18,18,16,16,16,20,20,20,21,21,21,20,20,20,25,25,25,24,24,24,21,21,21,20,20,20,20,20,20,21,21,21,19,19,19,20,20,20,18,18,18,14,14,14,12,12,12,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,11,11,11,8,8,8,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,2,3,3,3,5,5,5,4,4,4,5,5,5,7,7,7,10,10,10,10,10,10,12,12,12,13,13,13,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,13,13,13,18,18,18,14,14,14,19,19,19,20,20,20,17,17,17,19,19,19,22,22,22,17,17,17,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,9,9,9,5,5,5,5,5,5,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,2,3,3,3,3,3,3,5,5,5,4,4,4,4,4,4,9,9,9,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,21,21,21,17,17,17,10,10,10,12,12,12,16,16,16,12,12,12,12,12,12,12,12,12,13,13,13,12,12,12,12,12,12,12,12,12,11,11,11,8,8,8,7,7,7,4,4,4,2,2,2,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,3,3,3,3,3,3,4,4,4,4,4,4,5,5,5,6,6,6,10,10,10,11,11,11,10,10,10,6,6,6,7,7,7,12,12,12,13,13,13,14,14,14,13,13,13,13,13,13,13,13,13,12,12,12,11,11,11,12,12,12,12,12,12,10,10,10,6,6,6,5,5,5,4,4,4,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,3,3,3,5,5,5,3,3,3,3,3,3,4,4,4,6,6,6,6,6,6,6,6,6,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,3,3,3,3,3,3,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,2,4,4,4,5,5,5,6,6,6,6,6,6,5,5,5,5,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

static std::string vsString{
"#version 410\n"
"uniform mat4 MVP;\n"
"layout (location = 0) in vec3 vPos;\n"
"layout (location = 1) in vec4 vColor;\n"
"out vec4 color;\n"
"void main() {\n"
"	gl_Position = MVP * vec4(vPos, 1.0);\n"
"   color = vColor;\n"
"}\n"};

static std::string fsString{
"#version 410\n"
"uniform sampler2D sprite;\n"
"in vec4 color;\n"
"out vec4 FragColor;\n"
"void main() {\n"
"    vec4 texValue = texture(sprite, gl_PointCoord).rgbr;\n"
"    FragColor = vec4(color*texValue)*color.a;\n"
"}\n"};

AbstractParticleSystem::AbstractParticleSystem(float pointSize) :
	pointSize(pointSize), 
	prog{GLProgram::createFromString(vsString, fsString)},
	mvpLocation{prog.getUniformLocation("MVP")},
	texLocation{prog.getUniformLocation("sprite")},
	sprite{GL_LINEAR, GL_LINEAR},
	particleArray{},
	vbPosColor{GL_ARRAY_BUFFER}	
{

	// setup texture
	sprite.setData(spritePixel, 64, 64 , 3);
		
	std::vector<float> empty;
	vbPosColor.setData(empty,7,GL_DYNAMIC_DRAW);
	
	// setup geometry
	particleArray.bind();
	particleArray.connectVertexAttrib(vbPosColor, prog, "vPos", 3);
	particleArray.connectVertexAttrib(vbPosColor, prog, "vColor", 4, 3);
}

void AbstractParticleSystem::render(const Mat4& v, const Mat4& p) {
    if (getParticleCount() == 0) return;
    
	prog.enable();
	prog.setUniform(mvpLocation, v*p);
	prog.setTexture(texLocation, sprite, 0);		

	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);
	glBlendEquation(GL_FUNC_ADD);
	glDisable(GL_CULL_FACE);
	glDepthMask(GL_FALSE);
			
	glPointSize(pointSize);

	particleArray.bind();
	vbPosColor.setData(getData(),7,GL_DYNAMIC_DRAW);

	glDrawArrays(GL_POINTS, 0, GLsizei(getParticleCount()));

	glDisable(GL_BLEND);
	glEnable(GL_CULL_FACE);
	glDepthMask(GL_TRUE);
}

Vec3 AbstractParticleSystem::computeColor(const Vec3& c) {
    if (c == RANDOM_COLOR)
        return Vec3::random();
    else
        return c;
}
