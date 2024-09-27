#define CLSM_INCLUDES
#include "cellsim.h"

int main(void) {
	clsm_ent* ent = ce_new_ent();
	printf("%lu", ent->id);
	clsm_free(ent);
	return 0;
}
