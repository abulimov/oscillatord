#ifndef SRC_OSCILLATOR_FACTORY_H_
#define SRC_OSCILLATOR_FACTORY_H_
#include "oscillator.h"
#include "config.h"

struct oscillator_factory {
	oscillator_new_cb new;
	oscillator_destroy_cb destroy;
	struct oscillator_class class;
};

struct oscillator *oscillator_factory_new(struct config *config);
__attribute__((__format__(printf, 3, 4)))
void oscillator_factory_init(const char *factory_name,
		struct oscillator *oscillator, const char *fmt, ...);
int oscillator_factory_register(const struct oscillator_factory *factory);
void oscillator_factory_destroy(struct oscillator **oscillator);

#endif /* SRC_OSCILLATOR_FACTORY_H_ */
