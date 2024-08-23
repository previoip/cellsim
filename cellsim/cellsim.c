#define CLSM_INCLUDES
#include "cellsim.h"

int main(void) {
	clsm_ent* ent = (clsm_ent*)clsm_malloc(sizeof(clsm_ent));
	clsm_ent_init(ent);
	printf("%f\n", ent->v3pos[0]);
	printf("%f\n", ent->v3pos[1]);
	printf("%f\n", ent->v3pos[2]);
	if (ent == NULL) exit(1); clsm_free(ent);
	return 0;
}
